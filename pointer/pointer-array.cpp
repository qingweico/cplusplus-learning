#include <iostream>

// 使用指针遍历数组
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int *p = arr;
    for (int i = 0; i < 5; i++) {
        std::cout << *p << " ";
        p++;
    }
}