// 类模板继承
template <class T> class Base {};
// 子类需要执行父类中T的数据类型
class Impl : public Base<int>{};

// 或者子类本身也是模板类型
template <class R, class T> class AbstractBase : public Base<T>{};
