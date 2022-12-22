// 运算符重载
// 概念: 对已有的运行符进行重新定义, 赋予其另一种功能, 以适应不同的数据类型
// tips: 不要滥用运算符重载
#include <iostream>

using namespace std;

class Student {
private:
    string name;
    int age;
    int *no;
public:

    Student() {
        // 指针变量一定要初始化
        this->no = nullptr;
    }

    Student(string name, int age) {
        this->name = name;
        this->age = age;
    }

    void setNo(int no) {
        this->no = new int(no);
    }

    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    int getNo() {
        return *no;
    }
    // 成员函数实现赋值运算符重载
    // 解决由于堆区数据因为浅拷贝引发的内存安全问题

    Student &operator=(Student &student) {
        // 如果存在旧值 先释放
        if (no != nullptr) {
            delete no;
            no = nullptr;
        }
        this->name = student.name;
        this->age = student.age;
        // 深拷贝
        this->no = new int(student.getNo());
        return *this;
    }

    ~Student() {
        if (no != nullptr) {
            delete no;
            no = nullptr;
        }
    }

};

// > 全局函数实现Student类型之间比较运算符重载
bool operator>(Student &s1, Student &s2) {
    // compare 函数会首先比较两个字符串的长度 如果长度长自然就大
    // 如果长度一样 则从左至右依次比较 ascii
    int result = s1.getName().compare(s2.getName());
    if (result == 0) {
        return s1.getAge() - s2.getAge() > 0;
    }
    return result > 0;
}

// << 全局函数实现左移运算符重载
ostream &operator<<(ostream &count, Student &student) {
    count << "{no: " + to_string(student.getNo()) + ", name: " + student.getName() + ", " + "age: " +
             to_string(student.getAge()) + "}";
    return count;
}


// 仿函数
// 函数调用运算符重载
class Print {
public:
    void operator()(const string& text) {
        cout << text << endl;
    }

    void operator()(int var1, int var2) {
        cout << var1 + var2 << endl;
    }
};
int main() {
    Student s1{"Maruy Tyoiop", 22};
    s1.setNo(001);
    Student s2{"Kiro Jity", 23};
    s2.setNo(002);
    cout << boolalpha << (s1 > s2) << endl;

    cout << s1 << endl;
    cout << s2 << endl;

    cout << "----------------------------------" << endl;

    Student s3;
    s3 = s2 = s1;
    cout << s3 << endl;
    cout << s2 << endl;
    cout << s1 << endl;


    Print()("C++");
    Print()(1, 2);
}
