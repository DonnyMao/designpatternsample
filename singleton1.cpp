#include <iostream>
using namespace std;

class LazySingleton{
    private: 
        static LazySingleton* m_instance;
    protected:
        LazySingleton(){
            cout << "LazySingleton instance is created!" << endl;
        }
    public:
        static LazySingleton* getInstance(){
            if (m_instance== nullptr) {
                m_instance= new LazySingleton;
            }
            return m_instance;
        }
        ~LazySingleton(){
            cout << "LazySingleton instance is deleted!" << endl;
        }
};

LazySingleton* LazySingleton::m_instance = nullptr;

int main() {
    cout << "Main function gets Singleton!" << endl;
    LazySingleton* sgn = LazySingleton::getInstance();
    delete sgn;
    sgn = nullptr;
    return 0;
}