#include <iostream>
#include <string>
#include <algorithm>
#include <list>

class Element;

class Visitor
{
public:
    Visitor() {};
    virtual ~Visitor() {};

    virtual void visit(Element* f_element) = 0;
};

class Element
{
public:
    Element() {}
    virtual ~Element() {}
    virtual void accept(Visitor* f_visitor) = 0;
    virtual void updateFirmware() = 0;
};

class CpuElement : public Element
{
public:
    void accept(Visitor* f_visitor) override
    {
        f_visitor->visit(this);
    }

    void updateFirmware() override
    {
        std::cout << "Update the firmware of CPU" << std::endl;
    }
};

class GpuElement : public Element
{
public:
    void accept(Visitor* f_visitor) override
    {
        f_visitor->visit(this);
    }

    void updateFirmware() override
    {
        std::cout << "Update the firmware of GPU" << std::endl;
    }
};

class UpdateVistor : public Visitor
{
public:
    void visit(Element* f_element) override
    {
        f_element->updateFirmware();
    }
};

class ObjectStructure
{
private:
    std::list<Element*> m_listElements;
public:
    ObjectStructure() {}
    ~ObjectStructure()
    {
        m_listElements.clear();
    }

    void attach(Element* f_element)
    {
        m_listElements.push_back(f_element);
    }

    void detach(Element* f_element)
    {
        std::list<Element*>::iterator it = 
            find(m_listElements.begin(), m_listElements.end(), f_element);
        if (it != m_listElements.end())
        {
            m_listElements.erase(it);
        }
    }

    void acceptVisitor(Visitor* f_visitor)
    {
        for(std::list<Element*>::iterator it = m_listElements.begin(); it != m_listElements.end(); ++it)
        {
            (*it)->accept(f_visitor);
        }
    }
};

int main()
{
    ObjectStructure* l_pObject = new ObjectStructure();

    CpuElement* l_pCpu = new CpuElement();
    GpuElement* l_pGpu = new GpuElement();
    l_pObject->attach(l_pCpu);
    l_pObject->attach(l_pGpu);
    Visitor* l_pVisitor = new UpdateVistor();
    l_pObject->acceptVisitor(l_pVisitor);

    l_pObject->detach(l_pCpu);
    l_pObject->detach(l_pGpu);
    delete l_pObject;
    l_pObject = nullptr;
    delete l_pCpu;
    delete l_pGpu;
    l_pCpu = nullptr;
    l_pGpu = nullptr;

    return 0;
}