#include <iostream>
using namespace std;

// 类外函数模板实现
template <class T> class Ex {
private:
    T name;
public:
    explicit Ex(T name);
    void func();

};

template <class T> Ex<T>::Ex(T name) {
    cout << name << endl;
}
template <class T> void Ex<T>::func() {
    cout << "func" << endl;
}

int main() {
    Ex ex("ex");
    ex.func();
}