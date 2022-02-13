#include <iostream>
using namespace std;


//--------------------------
// Abstract product class 1
//--------------------------
class AbstractShoes
{
public:
    virtual ~AbstractShoes(){};
    virtual void show() = 0;
};

// Concreate product class 11
class SportShoes : public AbstractShoes
{
public:
    void show()
    {
        cout << "Sport shoes are made!" << endl;
    }
};

// Concreate product class 12
class LeatherShoes : public AbstractShoes
{
public:
    void show()
    {
        cout << "Leather shoes are made!" << endl;
    }
};

//--------------------------
// Abstract product class 2
//--------------------------
class AbstractClothes
{
public:
    virtual ~AbstractClothes(){};
    virtual void show() = 0;
};

// Concreate product class 21
class CasualClothes : public AbstractClothes
{
public:
    void show()
    {
        cout << "Casual clothes are made!" << endl;
    }
};

// Concreate product class 22
class SuitClothes : public AbstractClothes
{
public:
    void show()
    {
        cout << "Suit clothes are made!" << endl;
    }
};

//------------------------
// Abstract factory class
//------------------------
class Factory
{
public:
    virtual ~Factory(){};
    virtual AbstractShoes* createShoes() = 0;
    virtual AbstractClothes* createClothes() = 0;
};


// Concreate factory class 1
class CasualFactory : public Factory
{
public:
    AbstractShoes* createShoes()
    {
        return new SportShoes();
    }

    AbstractClothes* createClothes()
    {
        return new CasualClothes();
    }
};

// Concreate factory class 2
class FormalFactory : public Factory
{
public:
    AbstractShoes* createShoes()
    {
        return new LeatherShoes();
    }

    AbstractClothes* createClothes()
    {
        return new SuitClothes();
    }
};


int main()
{
    cout << "Main function starts here!" << endl;
    
    CasualFactory factory1;
    FormalFactory factory2;

    AbstractShoes* sportShoes = factory1.createShoes();
    AbstractShoes* leatherShoes = factory2.createShoes();

    AbstractClothes* casualClothes = factory1.createClothes();
    AbstractClothes* suitClothes = factory2.createClothes();
    
    sportShoes->show();
    leatherShoes->show();

    casualClothes->show();
    suitClothes->show();
    
    delete sportShoes;
    delete leatherShoes;
    sportShoes = nullptr;
    leatherShoes = nullptr;
    
    delete casualClothes;
    delete suitClothes;
    casualClothes = nullptr;
    suitClothes = nullptr;
    return 0;
}