#include <iostream>
#include <string>
using namespace std;
 
//Subject Class
class Factory
{
public:
    virtual ~Factory() {}
    virtual void makeProduct() = 0;
};

// Real Subject Class
class RealFactory : public Factory
{
public:
    RealFactory() {}
    void makeProduct() override
    {
    cout << "Real Product is created!" << endl;
    }
};

// Proxy
class ProxyFactory : public Factory
{
public:
    ProxyFactory(Factory* f_factory) 
    {
       m_realFactory = f_factory; 
    }

    void makeProduct() override
    {
        preRequest();
        m_realFactory->makeProduct();
        postRequest();
    }
    
    void preRequest()
    {
        cout << "PreRequest of creating..." << endl;
    }
    
    void postRequest()
    {
        cout << "PostRequest of creating..." << endl;
    }
    
private:
    Factory* m_realFactory;
};
 
int main()
{
    cout << "Main function gets started!" << endl;
    Factory* real = new RealFactory();
    ProxyFactory* proxy = new ProxyFactory(real);
    proxy->makeProduct();
    
    delete proxy;
    proxy = nullptr;
    delete real;
    real = nullptr;
    return 0;
}