#include <iostream>
#include <string>
using namespace std;

// Component Class
class Coffee
{
public:
    virtual ~Coffee() {};
    virtual string getDescription() = 0;
    virtual unsigned int cost() = 0;
};

// Concrete Component Class
class Espresso : public Coffee
{
public:
    string getDescription() {
        return "Standard Espresso";
    };
    unsigned int cost() {
        return 10;
    };
};

// Decorator Base Class
class DecoratorCoffee : public Coffee {};

// Decorator Concrete Class
class LatteCoffee : public DecoratorCoffee
{
private:
    Coffee* m_coffee;
public:
    LatteCoffee(Coffee* f_coffee) {
        m_coffee = f_coffee;
    }
    string getDescription() {
        return "Latte: " + m_coffee->getDescription() + " + milk!";
    };
    unsigned int cost() {
        return m_coffee->cost() + 12;
    };
};

// Decorator Concrete Class
class CappuccinoCoffee : public DecoratorCoffee
{
private:
    Coffee* m_coffee;
public:
    CappuccinoCoffee(Coffee* f_coffee) {
        m_coffee = f_coffee;
    }
    string getDescription() {
        return "Cappuccino: " + m_coffee->getDescription() + " + milk bubble!";
    };
    unsigned int cost() {
        return m_coffee->cost() + 10;
    };
};
 
int main()
{
    cout << "Main function gets started!" << endl;
    Coffee* coffee = new Espresso();
    LatteCoffee* latte = new LatteCoffee(coffee);
    CappuccinoCoffee* cappuccino = new CappuccinoCoffee(coffee);
    
    cout << latte->getDescription() << " ￥："<< latte->cost() << endl;
    cout << cappuccino->getDescription() << " ￥："<< cappuccino->cost() << endl;
    
    delete coffee;
    delete latte; 
    delete cappuccino;
    coffee = nullptr;
    latte = nullptr;
    cappuccino = nullptr;
    return 0;
}