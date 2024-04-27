#include <iostream>
#include <string>
using namespace std;

/* 基类只需要提供接口功能, 实现交给子类*/
class Logger
{
public:
    virtual void log() = 0;
};

class Logger_1 : public Logger
{
public:
    virtual void log()
    {
        cout << "Logger_1 log" << endl;
    }
};

class Logger_2 : public Logger
{
public:
    virtual void log()
    {
        cout << "Logger_2 log" << endl;
    }
};

/* 简单工厂模式: 根据不同的参数, 返回不同派生类对象*/
/* 如果需要添加新的日志器, 就需要修改代码, 不符合开闭原则*/
class LoggerFactory
{
public:
    static Logger *getLogger(string str)
    {
        Logger *log = NULL;
        if (str == "Logger_1")
        {
            log = new Logger_1;
        }
        else if (str == "Logger_2")
        {
            log = new Logger_2;
        }
        return log;
    }
};

int main()
{
    Logger *log = LoggerFactory::getLogger("Logger_1");
    log->log();
    delete log;
    log = LoggerFactory::getLogger("Logger_2");
    log->log();
    delete log;
    log = NULL;
}