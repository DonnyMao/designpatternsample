#include <iostream>
using namespace std;


// Abstract product class
class AbstractShoes
{
public:
    virtual ~AbstractShoes(){};
    virtual void show() = 0;
};

// Concreate product class 1
class SportShoes : public AbstractShoes
{
public:
    void show()
    {
        cout << "Sport shoes are made!" << endl;
    }
};

// Concreate product class 2
class LeatherShoes : public AbstractShoes
{
public:
    void show()
    {
        cout << "Leather shoes are made!" << endl;
    }
};

// Abstract factory class
class ShoesFactory
{
public:
    virtual ~ShoesFactory(){};
    virtual AbstractShoes* createShoes() = 0;
};


// Concreate factory class 1
class SportShoesFactory : public ShoesFactory
{
public:
    AbstractShoes* createShoes()
    {
        return new SportShoes();
    }
};

// Concreate factory class 2
class LeatherShoesFactory : public ShoesFactory
{
public:
    AbstractShoes* createShoes()
    {
        return new LeatherShoes();
    }
};

int main()
{
    cout << "Main function starts here!" << endl;
    
    SportShoesFactory sportSF;
    LeatherShoesFactory leatherSF;

    AbstractShoes* sportShoes = sportSF.createShoes();
    AbstractShoes* leatherShoes = leatherSF.createShoes();

    sportShoes->show();
    leatherShoes->show();

    delete sportShoes;
    delete leatherShoes;
    sportShoes = nullptr;
    leatherShoes = nullptr;
    
    return 0;
}