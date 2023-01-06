#include <iostream>
#include <algorithm>

using namespace std;


void init() {
    // string 初始化的几种方法
    string s1 = "c++";

    string s2("jelly");

    string s3(5, 's');

    const string &s4(s1);

    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
}

// string 赋值操作
void assign() {
    string s;
    s.assign("Maria");
    cout << s << endl;
    s.assign("Maria", 2);
    cout << s << endl;
    s.assign("x", 5);
    cout << s << endl;
}

// string 添加操作
void append() {
    string s;
    s.append("John");
    s.append(" like c++, python", 9);
    s.append("!, hhh", 0, 1);
    cout << s << endl;
}

// string 查找和替换操作
void findAndRepl() {
    string s("abcdefbc");
    // find 查找串第一次出现的位置
    cout << s.find("de") << endl;
    cout << s.find("df", 1, 3) << endl;
    // rfind 是从右向左查找该串第一次出现的位置 但是下标仍然是从左开始计算
    cout << s.rfind("bc") << endl;

    // 从pos=1处将新串(不管原串有多长)替换掉原来的3个元素
    s.replace(1, 3, "ABCDEF");
    cout << s << endl;
}

// string 比较操作
void cmp() {
    string s1 = "abc";
    string s2 = "ab";
    // ascii 逐个比较(两串长度相等) 当不相等时, 长度长的串直接返回较大 不用比较了
    cout << s1.compare(s2);

}

// string 存取操作
void access() {
    string s("rachel");
    for (int i = 0; i < s.size(); i++) {
        cout << s[i] << " ";
        cout << s.at(i) << " ";
        // string 内容可以修改
        s[i] = toupper(s[i]);
    }
    cout << s << endl;
}

// string 插入和删除操作
void insertAndDel() {
    string s("java");
    s.insert(1, "c++");
    cout << s << endl;
    s.insert(1, 5, 'a');
    cout << s << endl;
    s.erase(1, 8);
    cout << s << endl;
}

// string 子串
void substr() {
    string s("zhou@sina.com");
    string name = s.substr(0, s.find('@'));
    cout << name << endl;
}

int main() {

    substr();
}