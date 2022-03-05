#include <iostream>
#include <string>
#include <vector>

class Iterator
{
public:
    Iterator() {}
    virtual ~Iterator() {}
    virtual std::string first() = 0;
    virtual bool hasNext() = 0;
    virtual std::string next() = 0;
};

class Aggregate
{
public:
    Aggregate() {}
    virtual ~Aggregate() {}
    virtual int count() = 0;
    virtual void add(const std::string &f_str) = 0;
    virtual std::string getValue(const int f_n) = 0;
    virtual Iterator* createIterator() = 0;
};

class ConcreteIterator : public Iterator
{
private:
    int m_nCurrent;
    Aggregate* m_pAggregate;
public:
    ConcreteIterator(Aggregate* f_pAggregate) : Iterator()
    {
        m_nCurrent = 0;
        m_pAggregate = f_pAggregate;
    }
    ~ConcreteIterator() {}

    std::string first() override
    {
        return m_pAggregate->getValue(0);
    }

    bool hasNext() override
    {
        return (m_nCurrent >= 0 && m_nCurrent < m_pAggregate->count()) ? true : false;
    }

    std::string next() override
    {
        std::string l_ret;
        m_nCurrent++;
        if (hasNext())
        {
            l_ret = m_pAggregate->getValue(m_nCurrent);
        }
        return l_ret;
    }

};

class ConcreteAggregate : public Aggregate
{
private:
    std::vector<std::string> m_vec;
public:
    ConcreteAggregate() : Aggregate()
    {
        m_vec.clear();
    }
    ~ConcreteAggregate()
    {
        std::vector<std::string>().swap(m_vec);
    }

    Iterator* createIterator() override
    {
        return new ConcreteIterator(this);
    }

    int count() override
    {
        return m_vec.size();
    }

    void add(const std::string &f_str) override
    {
        m_vec.push_back(f_str);
    }

    std::string getValue(const int f_n) override
    {
        std::string l_ret;
        if (f_n >= 0 && f_n < count())
        {
            l_ret = m_vec[f_n];
        }
        return l_ret;
    }
};

int main()
{
    ConcreteAggregate* l_pName = new ConcreteAggregate();
    l_pName->add("Tom");
    l_pName->add("Jerry");
    l_pName->add("Lily");

    Iterator* iter = l_pName->createIterator();
    std::cout << iter->first() << " is here!" << std::endl;
    std::cout << iter->next() << " is here!" << std::endl;
    std::cout << iter->next() << " is here!" << std::endl;
    
    delete l_pName;
    delete iter;
    l_pName = nullptr;
    iter = nullptr;
    return 0;
}
