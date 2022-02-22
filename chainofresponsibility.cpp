#include <iostream>
#include <string>
using namespace std;

// Handler
class Handler
{
public:
    Handler() : m_next(nullptr) {}
    virtual ~Handler() {}
    Handler* setNext(Handler* f_pHandler) 
    {
        m_next = f_pHandler;
        return f_pHandler;
    }
    virtual void handleRequest(string f_task)
    {
        if (0 != this->m_next)
        {
            this->m_next->handleRequest(f_task);
        }
        else
        {
            cout << "Nobody will handle this!" << endl;
        }
    }

protected:
    Handler* m_next;
};

// Concrete Handler: Developer
class DeveloperHandler : public Handler
{
public:
    void handleRequest(string f_task) override
    {
        if (f_task == "develop")
        {
            cout << "I will take " << f_task << " job!" << endl;
        }
        else
        {
            Handler::handleRequest(f_task);
        }
    }
};

// Concrete Handler: Tester
class TesterHandler : public Handler
{
public:
    void handleRequest(string f_task) override
    {
        if (f_task == "test")
        {
            cout << "I will take " << f_task << " job!" << endl;
        }
        else
        {
            Handler::handleRequest(f_task);
        }
    }
};

// Concrete Handler: Application
class ApplicationHandler : public Handler
{
public:
    void handleRequest(string f_task) override
    {
        if (f_task == "application")
        {
            cout << "I will take " << f_task << " job!" << endl;
        }
        else
        {
            Handler::handleRequest(f_task);
        }
    }
};

int main()
{
    Handler* l_developer   = new DeveloperHandler;
    Handler* l_tester      = new TesterHandler;
    Handler* l_application = new ApplicationHandler;
    // set the chain, develooer as the 1st one
    l_developer->setNext(l_tester)->setNext(l_application);
    l_developer->handleRequest("develop");
    l_developer->handleRequest("test");
    l_developer->handleRequest("application");

    delete l_developer;
    delete l_tester;
    delete l_application;
    l_developer   = nullptr;
    l_tester      = nullptr;
    l_application = nullptr;
    return 0;
}