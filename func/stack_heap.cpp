#include <iostream>
#include <string>
using namespace std;
int* heap_func() {
    // 使用 new 关键字将数据开辟到堆区
    int *p = new int(10);
    return p;
}
int* stack_func() {
    int a = 10;
    return &a;
}
void heap_array() {
    int *array = new int[10];
    for(int i = 0; i < 10;i++) {
        array[i] = i;
    }
    cout << array[0] << endl;
    // 使用 delete 关键字释放堆区数据;
    delete[] array;
}
int main( ){
    int* p = heap_func();
    cout << *p << endl;
    cout << *p << endl;

    // error
    // p = stack_func();
    // cout << *p << endl;
    // cout << *p << endl;

    heap_array();

}
