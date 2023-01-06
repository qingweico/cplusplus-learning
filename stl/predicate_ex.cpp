#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 返回类型为bool的仿函数即为谓词
class AnyNegative {
public:
    bool operator()(int val) {
        return val < 0;
    }
};

// 一元谓词
void unary_predicate() {
    vector<int> v;
    v.push_back(99);
    v.push_back(0);
    v.push_back(-1);
    v.push_back(10);

    auto iterator = find_if(v.begin(), v.end(), AnyNegative());
    if (iterator != v.end()) {
        cout << "find negative! val = " << (*iterator) << endl;
    } else {
        cout << "not find negative!" << endl;
    }
}

int main() {
    unary_predicate();
}
