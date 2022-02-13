#include <iostream>
#include <string>
#include <map>

using namespace std;

// Flyweight
class BikeFlyweight
{
public:
    BikeFlyweight() : m_isAvailable(true) {}
    virtual ~BikeFlyweight() {}

    virtual void rideOut(string f_user) = 0;
    virtual void returnBack() = 0;
    virtual bool getState() = 0;

protected:
    bool m_isAvailable;
};

// Concrete Flyweight
class Mobike : public BikeFlyweight
{
public:
    Mobike(string f_id)
    : BikeFlyweight()
    , m_id(f_id)
    {
        cout << "Mobike ID: " << m_id << " is created!" << endl;
    }
    ~Mobike() {}

    void rideOut(string f_user)
    {
        m_isAvailable = false;
        cout << "User: " << f_user << " is using Mobike ID: " << m_id << endl;
    }

    void returnBack()
    {
        m_isAvailable = true;
    }

    bool getState()
    {
        return m_isAvailable;
    }

private:
    string m_id;
};

// Flyweight Factory
class BikeFactory
{
public:
    BikeFactory() {}
    ~BikeFactory() 
    {
        for (auto it = m_mapBike.begin(); it != m_mapBike.end(); it++)
        {
            if (it->second != nullptr)
            {
                delete it->second;
                it->second = nullptr;
            }
        }
    }

    BikeFlyweight* createBike(string f_id)
    {
        if (m_mapBike.find(f_id) != m_mapBike.end())
        {
            return m_mapBike[f_id];
        }
        BikeFlyweight* bike = new Mobike(f_id);
        m_mapBike[f_id] = bike;
        return bike;
    }

    BikeFlyweight* getAvailableBike()
    {
        for (auto it = m_mapBike.begin(); it != m_mapBike.end(); it++)
        {
            if (it->second != nullptr && it->second->getState())
            {
                return it->second;
            }
        }
        return nullptr;
    }

private:
    map<string, BikeFlyweight*> m_mapBike;
};


int main()
{
    cout << "Main function gets started!" << endl;
    BikeFactory* bikeFactory = new BikeFactory();
    BikeFlyweight* bike1 = bikeFactory->createBike("M001");
    BikeFlyweight* bike2 = bikeFactory->createBike("M002");

    bike1->rideOut("Tom");
    bike2->rideOut("Jerry");
    bike2->returnBack();

    BikeFlyweight* bike3 = bikeFactory->getAvailableBike();
    if (0 != bike3)
    {
        bike3->rideOut("John");
    }

    delete bikeFactory;
    bikeFactory = nullptr;
    return 0;
}