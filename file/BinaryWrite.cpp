#include <fstream>

using namespace std;

#include "../clazz/Person.h"

int main() {
    ofstream out;
    Person person{"Maria", 22};
    out.open("text.txt", ios::out | ios::binary);
    out.write((const char *) &person, sizeof(person));
    out.close();
}
