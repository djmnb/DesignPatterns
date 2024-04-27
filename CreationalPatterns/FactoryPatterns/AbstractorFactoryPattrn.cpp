#include <iostream>
using namespace std;

class AbstractProductA
{
public:
    virtual void show() = 0;
};

class ConcreteProductA1 : public AbstractProductA
{
public:
    virtual void show()
    {
        cout << "ConcreteProductA1 show" << endl;
    }
};

class ConcreteProductA2 : public AbstractProductA
{
public:
    virtual void show()
    {
        cout << "ConcreteProductA2 show" << endl;
    }
};

class AbstractProductB
{
public:
    virtual void log() = 0;
};

class ConcreteProductB1 : public AbstractProductB
{
public:
    virtual void log()
    {
        cout << "ConcreteProductB1 log" << endl;
    }
};

class ConcreteProductB2 : public AbstractProductB
{
public:
    virtual void log()
    {
        cout << "ConcreteProductB2 log" << endl;
    }
};

class AbstractFactory
{
public:
    virtual AbstractProductA *createAbstactProductA() = 0;
    virtual AbstractProductB *createAbstactProductB() = 0;
};

class ConcreteFactoryA : public AbstractFactory
{
public:
    virtual AbstractProductA *createAbstactProductA()
    {
        return new ConcreteProductA1;
    }
    virtual AbstractProductB *createAbstactProductB()
    {
        return new ConcreteProductB1;
    }
};

class ConcreteFactoryB : public AbstractFactory
{
public:
    virtual AbstractProductA *createAbstactProductA()
    {
        return new ConcreteProductA2;
    }
    virtual AbstractProductB *createAbstactProductB()
    {
        return new ConcreteProductB2;
    }
};

void run(AbstractFactory *factory)
{
    AbstractProductA *A;
    AbstractProductB *B;

    A = factory->createAbstactProductA();
    B = factory->createAbstactProductB();

    A->show();
    B->log();

    delete A;
    delete B;
}

int main()
{
    AbstractFactory *factory = new ConcreteFactoryA;
    run(factory);
    delete factory;
    cout << "--------------" << endl;
    factory = new ConcreteFactoryB;
    run(factory);
    delete factory;
}