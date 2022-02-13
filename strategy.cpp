#include <iostream>
#include <string>
using namespace std;

typedef enum StrategyType
{
    SELFDRIVE,
    HIGHSPEEDRAIL,
    FLIGHT
} STRATEGYTYPE;

// Strategy
class Strategy
{
public:
    Strategy() {}
    virtual ~Strategy() {}
    virtual void transport() = 0;
};

// Concrete strategy 1
class SelfDriveStrategy : public Strategy
{
public:
    void transport() override
    {
        cout << "Self dirve to the destination!" << endl;
    }
};

// Concrete strategy 2
class HighspeedRailwayStrategy : public Strategy
{
public:
    void transport() override
    {
        cout << "Take high-speed railway to the destination!" << endl;
    }
};

// Concrete strategy 3
class FlightStrategy : public Strategy
{
public:
    void transport() override
    {
        cout << "Fly to the destination!" << endl;
    }
};

// Context, with simple factory
class TravelContext
{
public:
    TravelContext() : m_strategy(nullptr) {}
    ~TravelContext() 
    {
        if (0 != m_strategy)
        {
            delete m_strategy;
            m_strategy = nullptr;
        }
    }

    void createTransStrategy(STRATEGYTYPE f_type)
    {
        switch (f_type)
        {
        case SELFDRIVE:
            m_strategy = new SelfDriveStrategy();
            break;
        case HIGHSPEEDRAIL:
            m_strategy = new HighspeedRailwayStrategy();
            break;
        case FLIGHT:
            m_strategy = new FlightStrategy();
            break;
        default:
            cout << "Strategy not supported yet!" << endl;
            break;
        }
    }

    void contextInterface()
    {
        if (0 != m_strategy)
        {
            m_strategy->transport();
        }
        else
        {
            cout << "No strategy created!" << endl;
        }
    }

private:
    Strategy* m_strategy;
};

int main()
{
    TravelContext* l_travel = new TravelContext();
    l_travel->createTransStrategy(FLIGHT);
    l_travel->contextInterface();

    delete l_travel;
    l_travel = nullptr;
    return 0;
}