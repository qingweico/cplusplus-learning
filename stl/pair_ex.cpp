#include <iostream>
using namespace std;
int main() {
    // 创建 pair
    pair<string, int> p("Jelly", 23);
    cout << p.first << " " << p.second << endl;
    p = make_pair("Maria", 24);
    cout << p.first << " " << p.second << endl;
}