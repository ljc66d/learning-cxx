#include "../exercise.h"
#include <algorithm>
#include <string>
#include <vector>

// READ: `std::transform` <https://zh.cppreference.com/w/cpp/algorithm/transform>
// READ: `std::vector::begin` <https://zh.cppreference.com/w/cpp/container/vector/begin>

int main(int argc, char **argv) {
    std::vector<int> val{8, 13, 21, 34, 55};
    // 步骤1：定义输出容器ans，大小与val一致（确保有足够空间存储转换结果）
    std::vector<std::string> ans(val.size());

    // 步骤2：调用std::transform，完成元素乘2并转换为字符串
    std::transform(
        val.begin(),                     // 输入范围起始迭代器
        val.end(),                       // 输入范围结束迭代器
        ans.begin(),                     // 输出范围起始迭代器
        [](int x) {                      // 一元操作lambda，封装复合逻辑
            return std::to_string(x * 2);// 先乘2，再转换为std::string
        });

    ASSERT(ans.size() == val.size(), "ans size should be equal to val size");
    ASSERT(ans[0] == "16", "ans[0] should be 16");
    ASSERT(ans[1] == "26", "ans[1] should be 26");
    ASSERT(ans[2] == "42", "ans[2] should be 42");
    ASSERT(ans[3] == "68", "ans[3] should be 68");
    ASSERT(ans[4] == "110", "ans[4] should be 110");
    return 0;
}