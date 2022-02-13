#include<iostream>
#include<string>
using namespace std;
 
//Product Class
class Product
{
public:
    virtual ~Product() {}
    // Show product info
    virtual void showInfo() = 0;
};

// One of the ConcreteProduct
class ConcreteProduct1 : public Product
{
public:
    void showInfo() override
    {
        cout << "ProductA is created!" << endl;
    }
};
 
// Another ConcreteProduct
class ConcreteProduct2 : public Product
{
public:
    void showInfo() override
    {
        cout << "ProductB is created!" << endl;
    }
};

// Simple Factory
class SimpleFactory
{
public:
    Product* createProduct(string f_name)
    {
        if (f_name == "product_a")
        {
            return new ConcreteProduct1;
        }
        else if (f_name == "product_b")
        {
            return new ConcreteProduct2;
        }
        else
        {
            return nullptr;
        }
    }
};
 
int main()
{
    cout << "Main function gets started!" << endl;
    SimpleFactory* sf = new SimpleFactory();
    Product* pA = sf->createProduct("product_a");
    Product* pB = sf->createProduct("product_b");
    pA->showInfo();
    pB->showInfo();
    
    delete sf;
    delete pA; 
    delete pB;
    sf = nullptr;
    pA = nullptr;
    pB = nullptr;
    return 0;
}