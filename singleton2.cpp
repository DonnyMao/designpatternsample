#include <iostream>
using namespace std;

class HungrySingleton{
    private: 
        static HungrySingleton* m_instance;
    protected:
        HungrySingleton(){
            cout << "HungrySingleton instance is created!" << endl;
        }
    public:
        static HungrySingleton* getInstance(){
            return m_instance;
        }
        ~HungrySingleton(){
            cout << "HungrySingleton instance is deleted!" << endl;
        }
};

HungrySingleton* HungrySingleton::m_instance = new HungrySingleton;

int main() {
    cout << "Main function gets Singleton!" << endl;
    HungrySingleton* sgn = HungrySingleton::getInstance();
    delete sgn;
    sgn = nullptr;
    return 0;
}