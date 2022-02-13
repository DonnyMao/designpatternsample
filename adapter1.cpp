#include <iostream>
#include <string>
using namespace std;

enum CONNECTOR {TYPE_USB, TYPE_RJ45};

//Adaptee Class USB
class USB
{
public:
    virtual void connect()
    {
        cout << "USB connected!" << endl;
    }
};

//Adaptee Class RJ45
class RJ45
{
public:
    virtual void connect()
    {
        cout << "RJ45 connected!" << endl;        
    }
};

// Adapter Class
class Adapter : public USB, public RJ45
{
public:
    Adapter(CONNECTOR f_type) 
    {
       m_type = f_type; 
    }

    void connect() override
    {
        switch (m_type)
        {
        case TYPE_USB:
            USB::connect();
            break;
        case TYPE_RJ45:
            RJ45::connect();
        default:
            break;
        }
    }
    
private:
    CONNECTOR m_type;
};
 
int main()
{
    cout << "Main function gets started!" << endl;
    Adapter* adapter1 = new Adapter(TYPE_USB);
    adapter1->connect();
    Adapter* adapter2 = new Adapter(TYPE_RJ45);
    adapter2->connect();
    
    delete adapter1;
    delete adapter2;
    adapter1 = nullptr;
    adapter2 = nullptr;
    return 0;
}