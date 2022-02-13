#include <iostream>
#include <string>
using namespace std;

// Receiver
class Chef
{
public:
    void cook(string f_name)
    {
        cout << "Chef is ready to make " << f_name << endl;
    }
};

// Command class
class Command
{
public:
    Command(Chef* f_chef) {}
    virtual ~Command() { cout << "CMD is deleted"; }
    virtual void excute() = 0;
    Chef* getChef() { return m_chef; }

private:
    Chef* m_chef;
};

// Concrete Command
class WontonCommand : public Command
{
public:
    WontonCommand(Chef* f_chef) : Command(f_chef) {}

    void excute() override
    {
        this->getChef()->cook("Wonton");
    }
};

// Concrete Command
class DumplingCommand : public Command
{
public:
    DumplingCommand(Chef* f_chef) : Command(f_chef) {}

    void excute() override
    {
        this->getChef()->cook("Dumpling");
    }
};

// Invoker
class Waiter
{
public:
    void receiveCmd(Command* f_cmd)
    {
        m_cmd = f_cmd;
    }

    void sendCmd()
    {
        m_cmd->excute();
    }

private:
    Command* m_cmd;
};


int main()
{
    Waiter* l_waiter = new Waiter();
    Chef*   l_chef   = new Chef();

    Command* l_wontonCmd   = new WontonCommand(l_chef);
    Command* l_dumplingCmd = new DumplingCommand(l_chef);

    l_waiter->receiveCmd(l_wontonCmd);
    l_waiter->sendCmd();
    l_waiter->receiveCmd(l_dumplingCmd);
    l_waiter->sendCmd();

    delete l_waiter; 
    delete l_chef;
    delete l_wontonCmd;
    delete l_dumplingCmd;
    l_waiter = nullptr;
    l_chef   = nullptr;
    l_wontonCmd   = nullptr;
    l_dumplingCmd = nullptr;

    return 0;
}