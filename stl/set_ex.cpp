#include <iostream>
#include <set>

using namespace std;

template<class T>
void printSet(const set<T> &set) {
    for (const auto &start: set) {
        cout << start << " ";
    }
    cout << endl;
}

class comparator {
public:
    // 二元谓词
    bool operator()(int var1, int var2) {
        return var1 > var2;
    }
};

void insert() {
    // 插入会做排序操作 所以插入顺序并不是容器中元素实际顺序
    // 默认是从小到大 可以自定义排序规则 使用仿函数
    set<string> s;
    s.insert("Maria");
    s.insert("Jelly");
    s.insert("John");
    printSet(s);
}

void del() {
    set<int> set;
    set.insert(2);
    set.insert(5);
    set.insert(9);
    printSet(set);
    set.erase(set.begin());
    printSet(set);
    set.erase(9);
    printSet(set);
    set.erase(set.begin(), set.end());
    printSet(set);
    set.clear();
}

void find() {
    set<int> s;
    s.insert(2);
    s.insert(5);
    s.insert(9);
    auto pos = s.find(2);
    if (pos != s.end()) {
        cout << "find!" << endl;
    } else {
        cout << "not find!" << endl;
    }
    // 统计 key 的出现次数
    cout << s.count(5) << endl;
}

void multiSet() {
    multiset<int> ms;
    set<int> s;
    pair<set<int>::iterator, bool> ret = s.insert(2);
    cout << boolalpha << ret.second << endl;
    // 允许插入重复的值
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    for (auto &item: ms) {
        cout << item << " ";
    }
    cout << endl;

}

void set_cmp() {
    set<int, comparator> s;
    s.insert(10);
    s.insert(2);
    s.insert(99);
    s.insert(-4);
    s.insert(8);
    for (const auto &item: s) {
        cout << item << " ";
    }
    cout << endl;
}

int main() {

    // 其他操作同其他容器
    set_cmp();
}

