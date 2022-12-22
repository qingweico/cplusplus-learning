// 继承
#include <iostream>

using namespace std;

class BaseService {
private:
    string name = "BaseService";

    static string message;
public:
    void getName() {
        cout << name << endl;
    }
    static string getMessage() {
        return message;
    }
};

class AbstractService {

};
// 多继承 (会导致菱形继承问题[子类继承两份相同的数据 导致资源浪费] 使用虚继承解决[virtual关键字])
class UserService : public BaseService, public AbstractService{
public:
    string name = "UserService";
    void getName() {
        cout << name << endl;
    }
};
int main() {
    UserService us;
    us.getName();
    // 对于子类中已经重写过的方法调用需要加上作用域
    us.BaseService::getName();
}
