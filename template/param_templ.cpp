#include <iostream>
using namespace std;

// 类模板对象做函数参数
template<class T, class R> class Single {
private:
    T elem;
public:
    explicit Single(T e) {
        this->elem = e;
    }
    R to_string() {
        return elem;
    }
};
void print(Single<string, string> &single) {
    cout << single.to_string() << endl;
}
template <class T, class R> void print(Single<T, R> &single) {
    cout << single.to_string() << endl;
}
template <class T> void print(T &single) {
    cout << single.to_string() << endl;
}
int main() {
    Single<string, string> single("single");
    print(single);
    print(single);
    print(single);
}
