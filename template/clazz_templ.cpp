#include <iostream>
#include "../clazz/User.h"
using namespace std;
template <class T, class R = string> class TypeHolder {
private:
    T type;
public:
    explicit TypeHolder(T t) {
        this->type = t;
    }
    R getType() {
        return typeid(type).name();
    }
};
int main() {
    TypeHolder<int> it(1);
    TypeHolder<string> st("str");
    User u;
    TypeHolder<User> ut(u);
    cout << it.getType() << endl;
    cout << st.getType() << endl;
    cout << ut.getType() << endl;

    // tips: 类模板和函数模板的区别
    // 类模板不能够自动类型推到,即必须使用钻石操作符
    // 类模板可以有默认的参数类型
}