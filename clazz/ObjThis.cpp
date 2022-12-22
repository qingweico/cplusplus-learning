// this 指针的用途
// this 指针的本质是指针常量: 指针的指向不可修改 指向的值可以修改
#include <string>
#include <iostream>
#include <utility>

using namespace std;

class StringBuilder {
private:
    string content;
public:
    StringBuilder() {
        content = "";
    }

    explicit StringBuilder(string s) {
        content = std::move(s);
    }

    StringBuilder &append(const string &c) {
        content += c;
        return *this;
    }

    string toString() {
        return content;
    }
};

int main() {
    StringBuilder sb("a");
    sb.append("b");
    sb.append("c");
    sb.append("d");
    sb.append("e");
    cout << sb.toString() << endl;
}
