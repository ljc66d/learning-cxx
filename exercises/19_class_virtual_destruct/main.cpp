#include "../exercise.h"
#include <iostream>

// READ: 静态字段 <https://zh.cppreference.com/w/cpp/language/static>
// READ: 虚析构函数 <https://zh.cppreference.com/w/cpp/language/destructor>

struct A {
    // 类内仅声明静态字段，不直接赋值（除constexpr常量外）
    static int num_a;

    A() {
        ++num_a;
    }
    // 补充virtual，将析构函数设为虚析构，支持多态析构
    virtual ~A() {
        --num_a;
    }

    virtual char name() const {
        return 'A';
    }
};
// 类外定义并初始化静态成员变量（核心：静态成员属于类，不属于单个对象）
int A::num_a = 0;

struct B final : public A {
    // 类内仅声明静态字段
    static int num_b;

    B() {
        ++num_b;
    }
    // B是final类，析构函数可加final（可选），继承A的虚析构特性
    ~B() final {
        --num_b;
    }

    char name() const final {
        return 'B';
    }
};
// 类外定义并初始化静态成员变量
int B::num_b = 0;

int main(int argc, char **argv) {
    auto a = new A;
    auto b = new B;
    // 补全断言：A::num_a=2（a是A对象+ b是B对象（调用A构造）），B::num_b=1（仅b是B对象）
    ASSERT(A::num_a == 2, "Fill in the correct value for A::num_a");
    ASSERT(B::num_b == 1, "Fill in the correct value for B::num_b");
    ASSERT(a->name() == 'A', "Fill in the correct value for a->name()");
    ASSERT(b->name() == 'B', "Fill in the correct value for b->name()");

    delete a;
    delete b;
    ASSERT(A::num_a == 0, "Every A was destroyed");
    ASSERT(B::num_b == 0, "Every B was destroyed");

    A *ab = new B;// 派生类指针可以随意转换为基类指针（向上转型，隐式合法）
    // 补全断言：A::num_a=1（B对象调用A构造），B::num_b=1（B对象调用B构造）
    ASSERT(A::num_a == 1, "Fill in the correct value for A::num_a");
    ASSERT(B::num_b == 1, "Fill in the correct value for B::num_b");
    ASSERT(ab->name() == 'B', "Fill in the correct value for ab->name()");

    // 补全正确的转换语句：向下转型（基类→派生类），需显式static_cast（B是final，安全）
    B &bb = static_cast<B &>(*ab);
    ASSERT(bb.name() == 'B', "Fill in the correct value for bb->name()");

    // TODO: ---- 以下代码不要修改，通过改正类定义解决编译问题 ----
    delete ab;// 通过指针可以删除指向的对象，即使是多态对象
    ASSERT(A::num_a == 0, "Every A was destroyed");
    ASSERT(B::num_b == 0, "Every B was destroyed");

    return 0;
}