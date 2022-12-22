// 如果有属性在堆区空间开辟,显示提供拷贝构造函数, 使用深拷贝解决浅拷贝带来的问题
#include <iostream>

using namespace std;

class Data {
public:
    int value;
    int *v;

    Data(int value, int v) {
        this->value = value;
        this->v = new int(v);
    }

    ~Data() {
        if (v != nullptr) {
            delete v;
            v = nullptr;
        }
    }

    Data(const Data &data) {
        this -> value = data.value;
        // 默认为 this -> v = data.v; 浅拷贝, 解引用已释放掉空间的内存地址:出错
        this -> v = new int(*data.v);
    }

    string toString() {
        return "Data:{value :  " + to_string(value) + ", *v : " + to_string(*v) + "}";
    }

};

int main() {

    Data d1(1, 2);
    cout << d1.toString() << endl;

    Data d2(d1);
    cout << d2.toString() << endl;
}

