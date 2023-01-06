
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(int val) {
    cout << val << " ";
}

void printVector(vector<int> &v) {
    for (int &item: v) {
        cout << item << " ";
    }
    cout << endl;
}

void cap_size() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    cout << v.size() << endl;
    cout << v.empty() << endl;
    cout << v.capacity() << endl;

    // 使用指定元素填充剩余空间
    v.resize(5, 10);
    printVector(v);
    // 舍弃多余的元素
    v.resize(2);
    printVector(v);

}

void construct() {
    // vector 容器构造
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(9);
    v1.push_back(3);

    vector<int> v2(v1.begin(), v1.end());

    vector<int> v3(10, 0);

    vector<int> v4(v2);

    printVector(v1);
    printVector(v2);
    printVector(v3);
    printVector(v4);
}

void assign() {
    // vector 容器赋值操作

    // 可以使用等号赋值

    // 使用 assign() 函数赋值

    vector<int> v1;
    v1.assign(4, 3);

    vector<int> v2;
    v2.assign(v1.begin(), v1.end());
    printVector(v1);
    printVector(v2);
}

void travel() {
    // vector 容器的遍历
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    auto start = v.begin();
    // 执行最后一个元素的下一个元素
    auto end = v.end();
    while (start != end) {
        cout << *start << " ";
        start++;
    }
    cout << endl;


    for (int &item: v) {
        cout << item << " ";
    }
    cout << endl;

    //
    for_each(v.begin(), v.end(), print);
}

// vector 插入和删除操作
void insertAndDel() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    printVector(v);
    v.pop_back();
    printVector(v);
    v.insert(v.begin() + 1, 4);
    printVector(v);
    v.insert(v.begin(), 8, 4);
    printVector(v);
    v.erase(v.end() - 1);
    printVector(v);
    // 删除迭代器指定的元素
    v.erase(v.begin() + 1, v.end());
    printVector(v);
    v.clear();
    printVector(v);
}

void visit() {
    // vector 容器中元素的访问
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
        cout << v.at(i) << " ";
    }
    cout << endl;
    cout << v.front() << endl;
    cout << v.back() << endl;
}

void swap() {
    // vector 容器交换

    vector<int> v;
    for (int i = 0; i < 10000; i++) {
        v.push_back(i);
    }
    cout << "capacity : " << v.capacity() << endl;
    cout << "size : " << v.size() << endl;

    v.resize(3);

    vector<int>(v).swap(v);
    cout << "capacity : " << v.capacity() << endl;
    cout << "size : " << v.size() << endl;
}

void reserve() {
    // vector 预留空间
    vector<int> v;

    // 使用 reserve 预留空间 一次为vector分配够空间
    v.reserve(100000);
    int *p = nullptr;
    int num = 0;
    for (int i = 0; i < 100000; i++) {
        v.push_back(i);
        if (p != &v[0]) {
            p = &v[0];
            num++;
        }
    }
    // 100000个数字 vector需要重新开辟空间18次;
    // 使用reserve后num为1
    cout << num << endl;
}

int main() {
    reserve();
}
