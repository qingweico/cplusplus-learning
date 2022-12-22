#include <iostream>

using namespace std;

class Set {
public:
    int a;
    int b;
    int c;
    // 初始化列表 初始化属性
    Set(int var1, int var2, int var3):a(var1), b(var2), c(var3) {

    }
};

int main() {
    Set set(1, 2, 3);
    cout << set.a << endl;
    cout << set.b << endl;
    cout << set.c << endl;
}
