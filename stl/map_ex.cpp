#include <iostream>
#include <map>

using namespace std;

template<class T, class E>
void paintMap(map<T, E> &map) {
    for (const auto &item: map) {
        cout << "key : " << item.first << ", ";
        cout << "value : " << item.second << endl;
    }
    cout << endl;
}

void insert() {
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(make_pair(2, 20));
    m.insert(map<int, int>::value_type(3, 30));
    // 对于存在的key 并不会做插入操作 即不会出现key覆盖value的情况
    m.insert(map<int, int>::value_type(3, 40));
    cout << m.size() << endl;
    cout << m.empty() << endl;
    // 对于访问不存在的key会插入该key
    cout << m[4] << endl;
    paintMap(m);
}
void del() {
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));
    paintMap(m);
    // 根据key删除数据
    m.erase(1);
    paintMap(m);
    // 根据迭代器
    m.erase(m.begin());
    paintMap(m);
    // 根据区间
    m.erase(m.begin(), m.end());
    paintMap(m);
    m.clear();
}
void sort() {
    // 可以使用仿函数自定义排序规则 同其他容器 默认根据key从小到大排序
}
int main() {
    // map 的 find() 和 count() 操作参考 set

    insert();
}
