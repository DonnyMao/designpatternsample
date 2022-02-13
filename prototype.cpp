#include <iostream>
using namespace std;

// This is abstract prototype student class
class StudentPrototype{
    private:
        int m_id;
        char* m_name;
    public:
        StudentPrototype()
            : m_id()
            , m_name(nullptr)
        {
            cout << "Abstract prototype is constructed!" << endl;
        }
    
        virtual ~StudentPrototype(){
            cout << "Abstract prototype is deconstructed!" << endl;
        }

        virtual StudentPrototype* clone() = 0;
        
        void setID(int f_id){
            m_id = f_id;   
        };
        void setName(char* f_name){
            m_name = f_name;
        }
        void showInfo(){
            cout << "Student ID: " << m_id <<
                " Student Name: " << m_name << endl;
        }
};

// This is concrete realize prototype student class
class StudentRealizetype : public StudentPrototype
{
    public:
        StudentRealizetype(){
            cout << "Realize prototype is constructed!" << endl;
        }
        ~StudentRealizetype(){
            cout << "Realize prototype is deconstructed!" << endl;
        }
    
        StudentPrototype* clone(){
            StudentPrototype* pStudent = new StudentRealizetype();
            *pStudent = *this;
            return pStudent;
        }
};

int main() {
    cout << "Main function gets started!" << endl;
    StudentRealizetype studentA;
    studentA.setID(1);
    studentA.setName("Tom");
    studentA.showInfo();
    
    StudentPrototype* studentB = studentA.clone();
    studentB->showInfo();
    studentB->setID(2);
    studentB->setName("Jerry");
    studentB->showInfo();
    
    delete studentB;
    studentB = nullptr;
    return 0;
}