#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    cout << queue.size() << endl;
    cout << queue.front() << endl;
    cout << queue.back() << endl;

    while (!queue.empty()) {
        cout << queue.front() << " ";
        // 移除队头第一个元素
        queue.pop();
    }
}

