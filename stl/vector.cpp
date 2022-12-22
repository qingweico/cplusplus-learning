#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    vector<int>::iterator start = v.begin();
    // 执行最后一个元素的下一个元素
    vector<int>::iterator end = v.end();
}
