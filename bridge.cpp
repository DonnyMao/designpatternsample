#include <iostream>
#include <string>
using namespace std;

// Implementor
class OS
{
public:
    OS() {}
    virtual ~OS() {}

    virtual string getName() = 0;
};

// Concrete Implementor 1
class AndriodOS : public OS
{
public:
    string getName() override
    {
        return "System is Andriod";
    }
};

// Concrete Implementor 2
class HarmonyOS : public OS
{
public:
    string getName() override
    {
        return "System is HarmonyOS";
    }
};

// Abstraction
class Phone
{
public:
    Phone() {}
    virtual ~Phone() {}

    void setOS(OS* f_sys)
    {
        m_sys = f_sys;
    }

    virtual void outputOSName() = 0;

protected:
    OS* m_sys;
};

// Refined Abstraction 1
class HuaweiPhone : public Phone
{
public:
    void outputOSName()
    {
        cout << "Huawei Phone's OS is: " << m_sys->getName() << endl;
    }
};

// Refined Abstraction 2
class HonorPhone : public Phone
{
public:
    void outputOSName()
    {
        cout << "Honor Phone's OS is: " << m_sys->getName() << endl;
    }
};

int main()
{
    cout << "Main function starts here!" << endl;
    OS* andriod = new AndriodOS();
    HuaweiPhone* huawei = new HuaweiPhone();
    huawei->setOS(andriod);

    OS* harmonyOS = new HarmonyOS();
    HonorPhone* honor = new HonorPhone();
    honor->setOS(harmonyOS);

    huawei->outputOSName();
    honor->outputOSName();

    delete huawei;
    delete honor;
    delete andriod;
    delete harmonyOS;
    huawei = nullptr;
    honor = nullptr;
    andriod = nullptr;
    harmonyOS = nullptr;

    return 0;
}