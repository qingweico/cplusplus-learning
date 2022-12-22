#include <iostream>
using namespace std;
int func(int a, int b, int c);
// 如果某个参数有默认值 则那么这个参数右边的都要有默认值
// 函数的定义和实现二者只能存在一个有默认值参数
int func(int a = 10, int b = 10, int c = 10) {
    return a + b + c;
}
int main() {
    cout << func() << endl;
}
