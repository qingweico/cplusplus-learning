#include <iostream>
using namespace std;
// 引用的作用: 给变量起别名
// 引用的本质在C++内部实现是指针常量 可以和Java中的引用作比较,其实差不多;
// 在Java中对象一旦new出来,地址就不可再更改,但是对象的内容可以变化
// int & --> int * const --> pointer const(指针常量)
void print(int &val) {
    cout << val << endl;
    val = 100;
}

// read-only(常量引用 防止形参改变实参)
void print(const int &val) {
    cout << val << endl;
    // error
    // val = 133;
}
int main() {
    int a = 10;
    print(a);
    cout << a << endl;

    
    int b = 100;

    // 引用必须初始化
    // int &c;

    // 引用在初始化后不可改变 (相当于指针常量 指针指向不可改变 指向的值可以改变)

    int& alise = b;
    int c = 20;
    // 赋值操作 并不是更改引用
    alise = c;
    // 都是20
    cout << b << endl;
    cout << alise << endl;
    cout << c << endl;

    // 引用必须指向一块合法的内存空间(堆或者栈),但是11是一个字面量常量,在常量区中
    // int &ref = 11;
 
    const int& refs = 11;

    cout << refs << endl;
    print(refs);
}
