#include <iostream>
using namespace std;
// 引用作为函数参数
void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}
int main() {
    int a = 1;
    int b = 2;
    swap(a, b);
    cout << a << endl;
    cout << b << endl;
}
