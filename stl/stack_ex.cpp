#include <iostream>
#include <stack>

using namespace std;
int main() {
    stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout << stack.size() << endl;
    cout << stack.empty() << endl;
    cout << stack.top() << endl;
}
