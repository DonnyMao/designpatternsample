#include <iostream>
#include <string>

class Memento
{
private:
    std::string m_strState;
public:
    Memento(std::string f_str) : m_strState(f_str) {}
    ~Memento() {}

    std::string getMementoState()
    {
        return m_strState;
    }
};

class Caretaker
{
private:
    Memento* m_pMemento;
public:
    Caretaker() : m_pMemento(nullptr) {}
    ~Caretaker()
    {
        if (nullptr != m_pMemento)
        {
            delete m_pMemento;
            m_pMemento = nullptr;
        }
    }

    void setMemento(Memento* f_m)
    {
        if (nullptr != m_pMemento)
        {
            delete m_pMemento;
            m_pMemento = nullptr;
        }
        m_pMemento = f_m;
    }
    Memento* getMemento()
    {
        return m_pMemento;
    }
};

class Originator
{
private:
    std::string m_strState;
public:
    Originator() {}
    ~Originator() {}

    void showState()
    {
        std::cout << "State is " << m_strState << std::endl;
    }

    void setState(std::string f_str)
    {
        m_strState = f_str;
    }

    Memento* createMemento()
    {
        return new Memento(m_strState);
    }

    void recoveryState(Memento* f_m)
    {
        m_strState = f_m->getMementoState();
    }
};

int main()
{
    Originator* l_pOriginator = new Originator();
    l_pOriginator->setState("On");
    l_pOriginator->showState();

    Caretaker* l_pCaretaker = new Caretaker();
    l_pCaretaker->setMemento(l_pOriginator->createMemento());

    l_pOriginator->setState("Off");
    l_pOriginator->showState();

    l_pOriginator->recoveryState(l_pCaretaker->getMemento());
    l_pOriginator->showState();

    delete l_pOriginator;
    delete l_pCaretaker;
    l_pOriginator = nullptr;
    l_pCaretaker = nullptr;

    return 0;
}