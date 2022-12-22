// 虚析构函数 和 纯析构函数
#include <string>
#include <iostream>
#include <utility>

using namespace std;

///////////////// 虚析构函数
class Cleaner {
public:
    virtual void clean() = 0;

    // 虚析构函数
    virtual ~Cleaner() {
        cout << " ~Cleaner()" << endl;
    }
};

class CleanerImpl : public Cleaner {
public:
    string *name;

    explicit CleanerImpl(string name) {
        this->name = new string(std::move(name));
    }

    ~CleanerImpl() override {
        cout << " ~CleanerImpl()" << endl;
        if (name != nullptr) {
            delete name;
            name = nullptr;
        }
    }

    void clean() override {
        cout << *name << " is Cleaning" << endl;
    }
};

///////////////// 纯虚析构函数
class Clean {
public:
    virtual void clean() = 0;

    virtual ~Clean() = 0;
};

// 纯虚析构需要声明也需要实现
// 有纯虚析构函数的类也是抽象类
Clean::~Clean() {
    cout << "Clean::~Clean()" << endl;
}

class CleanImp : public Clean {
    void clean() override {
        cout << "CleanImp" << endl;
    }
};

int main() {
    Cleaner *cleaner = new CleanerImpl("room");
    cleaner->clean();
    // 父类指针调用析构函数时不会调用子类中的析构函数 会导致子类堆区数据内存泄露
    // 解决: 应该将父类的析构函数变为虚析构函数或者纯虚析构函数
    delete cleaner;

    Clean *clean = new CleanImp;
    clean->clean();
}