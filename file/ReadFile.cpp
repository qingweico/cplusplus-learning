#include <fstream>
#include <iostream>

using namespace std;

int main() {
    ifstream in;
    in.open("text.txt", ios::in);
    if (!in.is_open()) {
        return 0;
    }
//    char buf[1024] = {0};
//    while (in >> buf) {
//        cout << buf << endl;
//    }
//
//    // ----------------
//    while (in.getline(buf, sizeof(buf))) {
//        cout << buf << endl;
//    }
//    // ----------------
//    string line;
//    while (getline(in, line)) {
//        cout << line << endl;
//    }
    // ----------------
    int c;
    while ((c = in.get()) != EOF) {
        cout << (char) c;
    }

    in.close();
}
