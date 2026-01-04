#include "../exercise.h"
#include <vector>

using udim = unsigned int;

std::vector<udim> strides(std::vector<udim> const &shape) {
    std::vector<udim> strides(shape.size());
    udim current_stride = 1;
    // 方案一：分开声明两个auto迭代器，避免MSVC同一行推导不同类型的错误
    auto s_it = shape.rbegin();   // 常量逆向迭代器
    auto st_it = strides.rbegin();// 普通逆向迭代器
    for (; s_it != shape.rend() && st_it != strides.rend(); ++s_it, ++st_it) {
        *st_it = current_stride;
        current_stride *= *s_it;
    }
    return strides;
}

// ---- 不要修改以下代码 ----
int main(int argc, char **argv) {
    ASSERT((strides({2, 3, 4}) == std::vector<udim>{12, 4, 1}), "Make this assertion pass.");
    ASSERT((strides({3, 4, 5}) == std::vector<udim>{20, 5, 1}), "Make this assertion pass.");
    ASSERT((strides({1, 3, 224, 224}) == std::vector<udim>{150528, 50176, 224, 1}), "Make this assertion pass.");
    ASSERT((strides({7, 1, 1, 1, 5}) == std::vector<udim>{5, 5, 5, 5, 1}), "Make this assertion pass.");
    return 0;
}