// 内建仿函数
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

template<class T>
void print(vector<T> &v) {
    for (const auto &item: v) {
        cout << item << " ";
    }
    cout << endl;
}

// 内建算术仿函数
void arith_functor() {
    cout << "---------- arith_functor() ----------" << endl;
    negate<int> n;
    cout << n(10) << endl;

    plus<int> p;
    cout << p(1, 2) << endl;
}

// 内建关系仿函数
void relation_functor() {
    cout << "---------- relation_functor() ----------" << endl;
    vector<int> v;
    v.push_back(99);
    v.push_back(0);
    v.push_back(2);
    v.push_back(-10);
    sort(v.begin(), v.end(), greater<int>());
    print(v);

}

// 内建逻辑仿函数
void logical_functor() {
    cout << "---------- logical_functor() ----------" << endl;
    vector<bool> v;
    v.push_back(false);
    v.push_back(true);
    v.push_back(true);
    v.push_back(false);
    print(v);
    vector<int> v2;
    v2.resize(v.size());
    transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
    print(v2);
}

int main() {
    arith_functor();
    relation_functor();
    logical_functor();
}
