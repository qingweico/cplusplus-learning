#include <iostream>
#include "../clazz/User.h"
// 普通函数比模板函数优先级高
// 可以使用<>钻石操作符强制调用模板函数
// 模板函数也可以发生重载
// 优先调用对于参数数据类型接近的函数
using namespace std;
template <class T> T add(T a, T b) {
    cout << "template" << endl;
    return a + b;
}
int add(int a, int b) {
    cout << "func" << endl;
    return  a + b;
}

template <typename T> bool compare(T &t1, T &t2);
// 具体化的模板
template <> bool compare(User &u1, User &u2) {
    return u1.name == u2.name && u1.id == u2.id;
}
int main() {
    cout << add(10 , 20) << endl;
    cout << add<>(1 , 0) << endl;
    User u1;
    User u2;
    cout << boolalpha << compare(u1, u2) << endl;
}
