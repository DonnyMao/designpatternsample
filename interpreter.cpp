#include <iostream>
#include <string>

class Context
{
private:
    std::string m_strInput;
public:
    void setInput(std::string f_str)
    {
        m_strInput = f_str;
    }
    std::string getInput()
    {
        return m_strInput;
    }
};

class AbstractExp
{
public:
    AbstractExp() {}
    virtual ~AbstractExp() {}
    virtual bool interpret(Context f_context) = 0;
};

class TerminalExp : public AbstractExp
{
private:
    std::string m_strData;
public:
    TerminalExp(std::string f_str) : m_strData(f_str) {}
    bool interpret(Context f_context)
    {
        if (f_context.getInput().find(m_strData) != std::string::npos)
        {
            return true;
        }
        return false;
    }
};

class NonterminalExp: public AbstractExp
{
private:
    AbstractExp* m_exp1;
    AbstractExp* m_exp2;
public:
    NonterminalExp(AbstractExp* f_exp1, AbstractExp* f_exp2)
    {
        m_exp1 = f_exp1;
        m_exp2 = f_exp2;
    }
    ~NonterminalExp() {}
    bool interpret(Context f_context)
    {
        return m_exp1->interpret(f_context) 
            + m_exp2->interpret(f_context);
    }
};

int main()
{
    AbstractExp* exp1 = new TerminalExp("Lily");
    AbstractExp* exp2 = new TerminalExp("girl");

    Context l_test;
    l_test.setInput("Lily is a girl");

    AbstractExp* exp3 = new NonterminalExp(exp1, exp2);
    std::string result = (exp3->interpret(l_test)) ? "yes" : "no";
    std::cout << "Is Lily a girl? " << result << std::endl;
    delete exp1;
    delete exp2;
    delete exp3;
    exp1 = nullptr;
    exp2 = nullptr;
    exp3 = nullptr;
    return 0;
}