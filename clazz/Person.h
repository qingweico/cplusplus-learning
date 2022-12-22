
#include "iostream"

using namespace std;

class Person {
public:
    char name[128];
    int age;

    void toString() {
        cout << "name: " << name << ", " << "age: " << age << endl;
    }
};

