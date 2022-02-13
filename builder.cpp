#include<iostream>
#include<vector>
#include<string>
using namespace std;

//Product Class
class Product
{
private:
    vector<string> parts;
public:
    // Add parts
    void Add(string part)
    {
        parts.push_back(part);
    }
    // Show parts
    void Show()
    {
        for_each(parts.cbegin(), parts.cend(), [](const string &s) {cout << s << " "; });
        cout << endl;
    }
};
 
//Builder
class Builder
{
public:
    virtual ~Builder() = default;
    virtual void BuildPartA() = 0;
    virtual void BuildPartB() = 0;
    virtual Product* getResult() = 0;
};


// One of the Concrete Builder
class ConcreteBuilder1 : public Builder
{
private:
    Product* product = new Product;
public:
    void BuildPartA()override
    {
        product->Add("Part A");
    }
    void BuildPartB()override
    {
        product->Add("Part B");
    }
    Product* getResult()override
    {
        return product;
    }
};
 
// Another Concrete Builder
class ConcreteBuilder2 : public Builder
{
private:
    Product* product = new Product;
public:
    void BuildPartA()override
    {
        product->Add("Part X");
    }
    void BuildPartB()override
    {
        product->Add("Part Y");
    }
    Product* getResult()override
    {
        return product;
    }
};

class Director
{
public:
    void construct(Builder *const b)
    {
        b->BuildPartA();
        b->BuildPartB();
    }
};
 
 
int main()
{
    Director director;
    Builder *b1 = new ConcreteBuilder1;
    Builder *b2 = new ConcreteBuilder2;

    cout << "ConcreteBuilder1 to build: " << endl;
    director.construct(b1);
    Product *p1 = b1->getResult();
    p1->Show();
 
    cout << "ConcreteBuilder2 to build: " << endl;
    director.construct(b2);
    Product *p2 = b2->getResult();
    p2->Show();
 
    delete p2;
    delete p1;
    delete b1;
    delete b2;
    p2 = nullptr;
    p1 = nullptr;
    b1 = nullptr;
    b2 = nullptr;

    return 0;
}