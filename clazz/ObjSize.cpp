#include <iostream>
// 成员变量和成员函数是分开存储的
using namespace std;
// 对于空对象 C++ 会为其分配一个字节的内存空间
class Obj {
    // 非静态成员变量 在对象上开辟空间
    int int_m;
    // 静态成员变量 不在对象上开辟空间
    static int int_static_m;
    // 成员函数 不在对象上开辟空间
    void f(){}
};
int main(){

    // 4个字节 即int型成员变量
    cout << sizeof(Obj) << endl;
}
