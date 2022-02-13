#include <iostream>
#include <string>
using namespace std;

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
    void connect()
    {
        cout << "RJ45 connected!" << endl;        
    }
};

// Adapter Class
class Adapter : public USB
{
public:
    Adapter() {
    m_rj45 = new RJ45();
    }

    void connect() override
    {
       m_rj45->connect();
    }
    
private:
    RJ45* m_rj45;
};
 
int main()
{
    cout << "Main function gets started!" << endl;
    USB* usb_adapter = new Adapter();
    usb_adapter->connect();
    
    delete usb_adapter;
    usb_adapter = nullptr;
    return 0;
}