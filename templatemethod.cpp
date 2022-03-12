#include <iostream>
#include <string>

class AbstractDrinking
{
public:
    virtual ~AbstractDrinking() {}

    void brewingMethod()
    {
        operation1();
        operation2();
    }
    virtual void operation1() = 0;
    virtual void operation2() = 0;
};

class MakeTea : public AbstractDrinking
{
public:
    void operation1()
    {
        std::cout << "Make Tea: Prepare a cup of hot water." << std::endl;
    }
    void operation2()
    {
        std::cout << "Make Tea: Soak tea bag into water." << std::endl;
    }
};

class MakeCoffee : public AbstractDrinking
{
public:
    void operation1()
    {
        std::cout << "Make Coffee: Prepare a cup of ice water." << std::endl;
    }
    void operation2()
    {
        std::cout << "Make Coffee: Sprinkle coffee power into water." << std::endl;
    }
};


int main()
{
    AbstractDrinking* tea = new MakeTea();
    tea->brewingMethod();

    AbstractDrinking* coffee = new MakeCoffee();
    coffee->brewingMethod();

    delete tea;
    delete coffee;
    tea = nullptr;
    coffee = nullptr;
    return 0;
}