// 友元
#include <iostream>

using namespace std;

class Tea {
    // 1 全局函数做友元 可访问类中的私有内容
    // 2 类做友元 可以访问类中的私有内容
    // 3 成员函数做友元 其他类中的成员函数可以访问类中的私有内容
    friend void details(Tea *tea);
public:
    string name;

    Tea(string name) {
        this->name = name;
    }

private:
    double price = 100.6;
};

void details(Tea *tea) {
    cout << tea->name << " : " << tea->price << endl;
}

int main() {
    Tea tea{"Longjing"};
    details(&tea);
}