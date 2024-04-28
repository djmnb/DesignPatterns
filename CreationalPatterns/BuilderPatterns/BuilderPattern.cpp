#include <iostream>
#include <string>
using namespace std;

class Actor
{
private:
    string name;  // 名字
    string type;  // 类型
    string words; // 台词
public:
    Actor(string name, string type, string words)
    {
        this->name = name;
        this->type = type;
        this->words = words;
    }
    void show()
    {
        cout << "My name is " << name << endl;
        cout << words << endl;
    }
};

class ActorBuilder
{
protected:
    Actor *actor;

public:
    virtual Actor *construct()
    {
        return actor;
    }
};

class DevilBulder : public ActorBuilder
{
public:
    DevilBulder()
    {
        actor = new Actor("X", "Devil", "I will kill you");
    }
};

int main()
{
    ActorBuilder *builder = new DevilBulder();
    Actor *Actor = builder->construct();
    Actor->show();

    delete Actor;
    delete builder;
}