
#include <fstream>
#include <iostream>
#include "../clazz/Person.h"

using namespace std;

int main() {
    ifstream in;
    in.open("text.txt", ios::in | ios::binary);
    if (!in.is_open()) {
        return 0;
    }
    Person person{};
    in.read((char *) &person, sizeof(Person));
    person.toString();
    in.close();
}
