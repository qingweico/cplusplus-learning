#include <iostream>
#include <deque>
#include <cmath>
using namespace std;

void printDeque(deque<int> &d) {
    for (int &item: d) {
        cout << item << " ";
    }
    cout << endl;
}

void construct() {
    // deque 构造函数
    deque<int> d;
    // 和 vector 一样
}

void assign() {
    // deque 赋值操作

    deque<int> d;
    for (int i = 0; i < 5; i++) {
        d.push_back(i);
    }
    deque<int> d1(d.begin(), d.end());
    deque<int> d2;
    d2.assign(10, 5);
    printDeque(d1);
    printDeque(d2);
}

void sz_operate() {
    // deque 大小操作

    deque<int> d;
    // deque 容器没有容量概念 没有capacity()函数


    d.size();
    d.resize(10);
    d.empty();


}

// deque 插入删除操作
void insertAndDel() {
    deque<int> d;
    for (int i = 0; i < 5; i++) {
        d.push_back(i);
        d.push_front(i);
    }
    printDeque(d);
    d.pop_back();
    d.pop_front();
    printDeque(d);
    deque<int> d1;
    d1.push_back(99);
    d1.insert(d1.begin(), 10);
    printDeque(d1);
    d1.insert(d1.begin(), 5, 8);
    printDeque(d1);
    d1.insert(d1.begin(), d.begin(), d.end());
    printDeque(d1);

    // 按照迭代器位置删除元素
    d1.erase(d1.begin());
    printDeque(d1);
    d1.erase(d1.begin(), d1.end() - 1);
    printDeque(d1);
    d1.clear();
    printDeque(d1);
}
void visit() {
    // deque 元素访问操作
    deque<int> d;
    for (int i = 0; i < 5; i++) {
        d.push_back(i);
    }
    for(int i = 0;i < d.size();i++) {
        cout << d.at(i) << " ";
        cout << d[i] << " ";
    }
    cout << endl;
    cout << d.front() << endl;
    cout << d.back() << endl;
}
int main() {
    cout << sqrt(16);
}
