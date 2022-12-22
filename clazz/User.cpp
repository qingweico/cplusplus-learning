#include "User.h"
#include <iostream>

using namespace std;

// 值传递的方式
// ==> User u(user) 会调用拷贝构造函数
void copy(User user) {
    cout << user.toString() << endl;
}

// 值返回局部变量
User copy() {
    User u;
    cout << (int *) &u << endl;
    // 返回值优化 [地址是一样的]
    return u;
}

int main() {

    User u1 = {1, "Maria"};
    cout << u1.toString() << endl;

    // 默认构造函数调用
    User u2;
    cout << u2.toString() << endl;
    // 有参构造函数调用
    User u3(2, "David");
    cout << u3.toString() << endl;

    copy(u3);

    User u4 = copy();
    cout << (int *) &u4 << endl;


}
