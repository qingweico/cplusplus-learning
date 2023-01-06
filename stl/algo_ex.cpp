#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <numeric>
// ************************** 常用算法 **************************
using namespace std;

template<class T>
void printVector(vector<T> &v) {
    for (auto &item: v) {
        cout << item << " ";
    }
    cout << endl;
}
template<class T>
void printArray(T &t) {
    for(const auto &v : t) {
        cout << v << " ";
    }
    cout << endl;
}

class AllNegative {
public:
    bool operator()(int val) {
        return val < 0;
    }
};

void for_each() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    for_each(v.begin(), v.end(), [](int val) {
        cout << val << " ";
    });
}
// transfer() 见 built_in_functor.cp
// find() 见 set_ex.cpp
// find_if() 见 predicate_ex.cpp


void adjacent_find() {
    // 查找相邻重复元素 返回相邻元素第一个位置的迭代器
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(3);
    v.push_back(2);
    v.push_back(3);
    auto ret = adjacent_find(v.begin(), v.end());
    if (ret != v.end()) {
        cout << "find, val = " << *ret << endl;
    } else {
        cout << "not find!" << endl;
    }
}

void binary_search_fn() {
    // 有序序列
    vector<int> v;
    v.reserve(10);
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    cout << boolalpha << binary_search(v.begin(), v.end(), 6) << endl;
}

void count_fn() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(2);
    cout << count(v.begin(), v.end(), 2) << endl;
}

void count_if_fn() {
    vector<int> v;
    v.push_back(-9);
    v.push_back(10);
    v.push_back(-6);
    v.push_back(10);
    cout << "Negative count : " << count_if(v.begin(), v.end(), AllNegative()) << endl;
}

void r_shuffle() {
    // 将指定范围内的元素顺序打乱
    srand((unsigned int) time(nullptr));
    vector<int> v;
    v.reserve(10);
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    random_shuffle(v.begin(), v.end());

    printVector(v);
}
// reverse() 和 merge() copy()

void replace_fn() {
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    printVector(v);
    replace(v.begin(), v.end(), 2, 99);
    printVector(v);
}

void replace_if_fn() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(-9);
    v.push_back(-4);
    printVector(v);
    // 将所有的负数替换成0
    replace_if(v.begin(), v.end(), [](int val) {
        return val < 0;
    }, 0);
    printVector(v);
}

void swap_fn() {
    int a[] = {1, 2, 3};
    int b[] = {4, 5, 6};
    swap(a, b);
    printArray(a);
    printArray(b);
}

void accumulate_fn() {
    // 累加
    vector<int> v;
    v.reserve(10);
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    cout << accumulate(v.begin(), v.end(), 0) << endl;
}

void fill_fn() {
    vector<double> v;
    v.resize(10, 0.01);
    printVector(v);
    fill(v.begin(), v.end(), 9.99);
    printVector(v);
}

// 集合交集

void intersection_fn() {
    vector<int> v1;
    v1.push_back(9);
    v1.push_back(-1);
    v1.push_back(3);
    v1.push_back(0);

    vector<int> v2;
    v2.push_back(9);
    v2.push_back(-1);
    v2.push_back(66);
    v2.push_back(8);

    vector<int> ret;
    ret.resize(min(v1.size(), v2.size()));
    auto last = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), ret.begin());
    for_each(ret.begin(), last, [](int v) {
        cout << v << " ";
    });
}
// 集合并集

void union_fn() {
    vector<int> v1;
    v1.push_back(9);
    v1.push_back(-1);
    v1.push_back(3);
    v1.push_back(0);

    vector<int> v2;
    v2.push_back(9);
    v2.push_back(-1);
    v2.push_back(66);
    v2.push_back(8);

    vector<int> ret;
    ret.resize(v1.size() + v2.size());
    auto last = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), ret.begin());
    for_each(ret.begin(), last, [](int v) {
        cout << v << " ";
    });
}
// 集合差集

void difference_fn() {
    vector<int> v1;
    v1.push_back(9);
    v1.push_back(-1);
    v1.push_back(3);
    v1.push_back(0);

    vector<int> v2;
    v2.push_back(9);
    v2.push_back(-1);
    v2.push_back(66);
    v2.push_back(8);

    vector<int> ret;
    ret.resize(max(v1.size(), v2.size()));
    // v1 和 v2 的差集 : v1 - (v1 和 v2 的交集)
    auto last = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), ret.begin());
    for_each(ret.begin(), last, [](int v) {
        cout << v << " ";
    });
}

int main() {
    swap_fn();
}
