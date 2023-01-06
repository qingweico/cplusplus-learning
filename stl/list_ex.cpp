#include <iostream>
#include <list>

using namespace std;

template<class T>
void printList(const list<T> &l) {
    for (const auto &start: l) {
        cout << start << " ";
    }
    cout << endl;
}
void ope_list() {
    list<int> list;
    list.push_back(3);
    list.push_back(99);
    list.push_back(-1);
    list.push_back(13);
    list.push_back(7);
    printList<int>(list);
    list.reverse();
    printList<int>(list);
    list.sort();
    printList(list);
}
// C++ 中list 是双向链表
int main() {
    // 和其他容器操作一样
    list<string> list;
    list.emplace_back("Maria");
    // 移除容器中所有和指定元素相同的元素
    list.remove("Maria");
    printList(list);
    ope_list();
}


