#include <fstream>

using namespace std;

int main() {
    ofstream out;
    out.open("text.txt", ios::out);
    out << "C++" << endl;
    out.close();
}