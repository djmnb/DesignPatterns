#include <iostream>
#include <mutex>
using namespace std;

/* 单例模式的实现就是依靠私有化构造方法, 然后提供公有静态方法返回对象*/

/* 懒汉式就是在一开始就把对象创建好了*/
class LasySingleton
{
private:
    LasySingleton()
    {
    }
    static LasySingleton *singleton;

public:
    static LasySingleton *getSingleton()
    {
        return singleton;
    }
    void show()
    {
        cout << "LasySingleton show" << endl;
    }
};

LasySingleton *LasySingleton::singleton = new LasySingleton;

class EagerSingleton
{
private:
    EagerSingleton()
    {
    }
    static EagerSingleton *singleton;
    static mutex lock;

public:
    static EagerSingleton *getSingleton()
    {
        if (!singleton)
        {
            lock.lock();
            if (!singleton)
            {
                singleton = new EagerSingleton;
            }
            lock.unlock();
        }
        return singleton;
    }
    void show()
    {
        cout << "EagerSingleton show" << endl;
    }
};

mutex EagerSingleton::lock;
EagerSingleton *EagerSingleton::singleton = NULL;

int main()
{
    // 直接使用是会报错的
    // LasySingleton lasy;
    // EagerSingleton eager;

    LasySingleton *lasy = LasySingleton::getSingleton();
    lasy->show();
    EagerSingleton *eager = EagerSingleton::getSingleton();
    eager->show();
}
