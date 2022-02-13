#include <iostream>
#include <memory>
#include <list>

// Component Class: defauly interfaces of company
class Company
{
protected:
    std::string m_name;

public:
    Company(const std::string& f_strName) : m_name(f_strName) {}

    virtual void Add(std::shared_ptr<Company> c) = 0;
    virtual void Remove(std::shared_ptr<Company> c) = 0;
    virtual void getChild(int depth) = 0;
};

// Composite : concrete implementation of compony
class ConcreteCompany : public Company
{
private:
    std::list<std::shared_ptr<Company>> m_children;

public:
    ConcreteCompany(const std::string& f_strName) : Company(f_strName) {}

    virtual void Add(std::shared_ptr<Company> c)
    {
        m_children.push_back(c);
    }

    virtual void Remove(std::shared_ptr<Company> c)
    {
        m_children.remove(c);
    }

    virtual void getChild(int depth)
    {
        std::cout << std::string(depth, '-').c_str() << m_name.c_str() << std::endl;
        for (std::shared_ptr<Company> c : m_children)
        {
            c->getChild(depth + 2);
        }
    }
};

// Leaf : department of concrete company
class FinanceDepartment : public Company
{
public:
    FinanceDepartment(const std::string& f_strName) : Company(f_strName) {}
    virtual void Add(std::shared_ptr<Company> c) {}
    virtual void Remove(std::shared_ptr<Company> c) {}

    virtual void getChild(int depth) {
        std::cout << std::string(depth, '-').c_str() << m_name.c_str() << std::endl;
    }
};

int main()
{
    std::shared_ptr<ConcreteCompany> root = std::make_shared<ConcreteCompany>("Headquarter in Beijing");
    root->Add(std::make_shared<FinanceDepartment>("Finance department of Headquarter"));

    std::shared_ptr<ConcreteCompany> comp = std::make_shared<ConcreteCompany>("Branch company in Shanghai");
    comp->Add(std::make_shared<FinanceDepartment>("Finance department of Shanghai branch"));
    root->Add(comp);

    std::shared_ptr<ConcreteCompany> office1 = std::make_shared<ConcreteCompany>("Office in Suzhou");
    office1->Add(std::make_shared<FinanceDepartment>("Finance department of Suzhou office"));
    comp->Add(office1);

    std::shared_ptr<ConcreteCompany> office2 = std::make_shared<ConcreteCompany>("Office in Hangzhou");
    office2->Add(std::make_shared<FinanceDepartment>("Finance department of Hangzhou office"));
    comp->Add(office2);

    std::cout << "O-Chart：" << std::endl;
    root->getChild(1);

    return 0;
}