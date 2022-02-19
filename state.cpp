#include <iostream>
#include <string>
using namespace std;

class HomeOfficeContext;

// State
class State
{
public:
    virtual ~State() {}
    void setContext(HomeOfficeContext* f_pContext)
    {
        m_pContext = f_pContext;
    }

    virtual void switchState() = 0;

protected:
    HomeOfficeContext* m_pContext;
};

// Context
class HomeOfficeContext
{
public:
    HomeOfficeContext(State* f_pState) : m_pState(nullptr) 
    {
        this->transitionTo(f_pState);
    }
    ~HomeOfficeContext() 
    {
        if (0 != m_pState)
        {
            delete m_pState;
            m_pState = nullptr;
        }
    }

    void transitionTo(State* f_pState)
    {
        if (m_pState != nullptr)
        {
            delete m_pState;
            m_pState = nullptr;
        }
        m_pState = f_pState;
        m_pState->setContext(this);
    }

    void changeState()
    {
        m_pState->switchState();
    }

private:
    State* m_pState;
};

// Concrete state rest
class RestState : public State
{
public:
    void switchState() override;
};

// Concrete state work
class WorkState : public State
{
public:
    void switchState() override;
};

void RestState::switchState()
{
    cout << "Now is rest state" << endl;
    cout << "Switch to work" << endl;
    this->m_pContext->transitionTo(new WorkState);
}

void WorkState::switchState()
{
    cout << "Now is working state" << endl;
    cout << "Switch to work" << endl;
    this->m_pContext->transitionTo(new RestState);
}

int main()
{
    HomeOfficeContext* l_ho = new HomeOfficeContext(new RestState);
    l_ho->changeState();
    l_ho->changeState();

    delete l_ho;
    l_ho = nullptr;
    return 0;
}