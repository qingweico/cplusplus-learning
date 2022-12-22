#include <cstdio>

// 指针: 32位操作系统中占用4个字节;64位操作系统中占用8个字节
int main() {
    int a = 1;
    int b = 2;


    // const pointer: 常量指针
    // The point of a pointer can be changed, but the value of a pointer cannot be changed.
    const int *p = &a;
    p = &b;
    printf("%d\n", *p);
    // error
    // *p = 100;

    // pointer const: 指针常量
    // The point of a pointer cannot be changed, but the value of a pointer can be changed.
    int *const t = &b;
    *t = 100;
    printf("%d", *t);
    // error
    // t = &b;
}
