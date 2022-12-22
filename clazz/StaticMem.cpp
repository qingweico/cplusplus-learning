#include <iostream>
// 静态成员 全局共享
using namespace std;

class Person {
public:
    int no;
    static int age;

    mutable int gender;

    static void func() {
        cout << "func()" << endl;
    };

    // 常函数 : 此处加 const 的作用: 修饰 this 指针
    // 本来 this 指针本质就是 指针常量, 再加 const 修饰,使得 this 修饰的变量的值也不能被修改
    void getNo() const {
        // error
        // this = nullptr;

        // error
        // this -> no = 10;

        // 例外的情况是被mutable修饰的变量可以被修改
        this -> gender = 1;
        cout << "getNo(): " << no << endl;
    }
};

// 静态成员变量 类内声明 类外初始化操作 否则出错
int Person::age = 10;

int main() {
    cout << Person::age << endl;
    Person::age = 20;
    cout << Person::age << endl;

    Person *p = nullptr;
    p->func();
    // 出错了 空指针访问成员函数 即 this -> no
    // p->getNo();

    // 常对象
    // 常对象只能调用常函数
    const Person p1{};
    p1.getNo();
}
