#include <iostream>
#include <string>
using namespace std;
struct User {
    long id;
    string name;
};
int main() {
    struct User u1;
    u1.id = 1;
    u1.name = "u1";
    cout << u1.id << ", " << u1.name << endl;

    struct User u2 = {2, "u2"};
    cout << u2.id << ", " << u2.name << endl;

    // 利用指针访问结构体
    struct User *user = &u1;
    cout << user -> id << ", " << user -> name << endl;
}
