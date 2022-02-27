#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// Observer
class Observer
{
public:
    virtual ~Observer() {}
    virtual void takeTest() = 0;
};

// Concrete Observer
class Resident : public Observer
{
public:
    Resident(string f_name) : m_name(f_name) {}
    void takeTest() override
    {
        cout << m_name << " is going downstairs for nucleic acid test" << endl;
    }

private:
    string m_name;
};

// Subject
class Subject
{
public:
    virtual ~Subject() {}

    virtual void Add(Observer* f_ob) = 0;
    virtual void Remove(Observer* f_ob) = 0;
    virtual void Notify() = 0;
};

// Concrete Subject
class PropertyManager : public Subject
{
private:
    vector<Observer*> m_ob;
public:
    ~PropertyManager()
    {
        vector<Observer*>().swap(m_ob);
    }

    void Add(Observer* f_ob) override
    {
        m_ob.push_back(f_ob);
    }

    void Remove(Observer* f_ob) override
    {
        auto found_ob = find(m_ob.begin(), m_ob.end(), f_ob);
        if (found_ob != m_ob.end())
        {
            m_ob.erase(found_ob);
        }
    }

    void Notify() override
    {
        cout << "Notice: Everyone, please take nucleic acid test!" << endl;
        for (const auto& l_ob:m_ob)
        {
            l_ob->takeTest();
        }
    }
};

int main()
{
    PropertyManager l_pm;
    Resident* l_person1 = new Resident("Tom");
    Resident* l_person2 = new Resident("Jerry");
    Resident* l_person3 = new Resident("Lily");

    l_pm.Add(l_person1);
    l_pm.Add(l_person2);
    l_pm.Add(l_person3);
    l_pm.Notify();

    delete l_person1;
    delete l_person2;
    delete l_person3;
    l_person1 = nullptr;
    l_person2 = nullptr;
    l_person3 = nullptr;

    return 0;
}