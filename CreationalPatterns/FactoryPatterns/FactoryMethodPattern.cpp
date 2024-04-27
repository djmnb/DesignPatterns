#include <iostream>
using namespace std;

/* 工厂方法模式 是为每个对象创建一个工厂类*/
/* 这样的好处是每次新增新的对象, 不需要修改原先代码, 但是每次都需要创建一个工厂方法*/

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

class LoggerFactory
{
public:
    virtual Logger *getLogger() = 0;
    void log(){
        Logger *logger = getLogger();
        logger->log();
        delete logger;
    }
};

class Logger_1_Factory : public LoggerFactory
{
public:
    virtual Logger *getLogger()
    {
        return new Logger_1;
    }
};

class Logger_2_Factory : public LoggerFactory
{
public:
    virtual Logger *getLogger()
    {
        return new Logger_2;
    }
};

int main()
{
    // 方式一
    LoggerFactory *factory = new Logger_1_Factory;
    Logger *logger = factory->getLogger();
    logger->log();

    delete logger;
    delete factory;

    factory = new Logger_2_Factory;
    logger = factory->getLogger();
    logger->log();

    delete logger;
    delete factory;
    

    // 方式二, 我们直接在factory里面直接定义log方法,直接完成打印
    factory = new Logger_1_Factory;
    factory->log();
    delete factory;

    factory = new Logger_2_Factory;
    factory->log();
    delete factory;
}
