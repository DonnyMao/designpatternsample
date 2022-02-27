#include <iostream>
#include <string>
using namespace std;

#define SAFE_DELETE(p) if (p) { delete p; p = NULL; }

class Mediator;
// Colleague
class Colleague
{
public:
    Colleague(Mediator* f_mediator) : m_mediator(f_mediator) {}
    virtual ~Colleague() {}
    virtual void send(string f_msg) = 0;
    virtual void notify(string f_msg) = 0;

protected:
    Mediator* m_mediator;
};

// Mediator
class Mediator
{
public:
    virtual ~Mediator() {}
    virtual void send(string f_msg, Colleague* f_colleague) = 0;
};

// Concrete Colleague developer
class ColleagueDev : public Colleague
{
public:
    ColleagueDev(Mediator* f_mediator) : Colleague(f_mediator) {}

    void send(string f_msg) override
    {
        m_mediator->send(f_msg, this);
    }

    void notify(string f_msg) override
    {
        cout << "Developer got msg: " << f_msg << endl;
    }
};

// Concrete Colleague tester
class ColleagueTest : public Colleague
{
public:
    ColleagueTest(Mediator* f_mediator) : Colleague(f_mediator) {}

    void send(string f_msg) override
    {
        m_mediator->send(f_msg, this);
    }

    void notify(string f_msg) override
    {
        cout << "Test got msg: " << f_msg << endl;
    }
};

// Concrete Mediator
class ProjectManager : public Mediator
{
public:
    void addColleague(Colleague* f_developer, Colleague* f_tester)
    {
        m_developer = f_developer;
        m_tester    = f_tester;
    }

    void send(string f_msg, Colleague* f_colleague) override
    {
        if(f_colleague == m_developer)
        {
            m_tester->notify(f_msg);
        }
        else if (f_colleague == m_tester)
        {
            m_developer->notify(f_msg);
        }
        else
        {
            cout << "Unknown colleague" << endl;
        }
    }

private:
    Colleague* m_developer;
    Colleague* m_tester;
};

int main()
{
    ProjectManager*  l_pm        = new ProjectManager();
    Colleague* l_developer = new ColleagueDev(l_pm);
    Colleague* l_tester    = new ColleagueTest(l_pm);

    l_pm->addColleague(l_developer, l_tester);
    l_tester->send("Is the code implemented?");
    l_developer->send("Code was merged, please start to test.");

    SAFE_DELETE(l_pm);
    SAFE_DELETE(l_developer);
    SAFE_DELETE(l_tester);
    return 0;
}