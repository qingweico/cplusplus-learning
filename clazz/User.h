#include <iostream>

using namespace std;

class User {
public:
    int id;
    string name;

    // 构造函数

    User() {
        id = 1;
        name = "Maytd Poirds";
    }

    User(int id, string name) {
        this->id = id;
        this->name = name;
    }

    // 拷贝构造函数
    User(const User &user) {
        cout << "Copy User()" << endl;
        this->id = user.id;
        this->name = user.name;
    }

    // 析构函数 对象在销毁前 会自动调用该函数
    ~User() {
        // 析构函数 将堆区开辟的空间做释放操作
        cout << "~User()" << endl;
    }

    // 一个类中的构造函数, 拷贝构造函数, 析构函数, 默认编译器会自动生成

    // 显示提供覆盖优先级 拷贝构造函数 > 有参构造函数 > 默认构造函数

    int getId() const {
        return id;
    }

    void setId(int id) {
        User::id = id;
    }

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        User::name = name;
    }

    string toString() const {
        return "User:{id :  " + to_string(id) + ", name : " + name + "}";
    }
};


