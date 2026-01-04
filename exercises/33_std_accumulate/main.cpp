#include "../exercise.h"
#include <iterator>// 用于std::begin/std::end（适配数组）
#include <numeric>

// READ: `std::accumulate` <https://zh.cppreference.com/w/cpp/algorithm/accumulate>

int main(int argc, char **argv) {
    using DataType = float;
    int shape[]{1, 3, 224, 224};

    // 步骤1：调用std::accumulate计算shape数组的元素乘积（张量总元素个数）
    // 步骤2：乘以单个DataType的字节数，得到总字节数
    int size = std::accumulate(
                   std::begin(shape),    // 输入范围起始（数组首元素）
                   std::end(shape),      // 输入范围结束（数组尾后位置）
                   1,                    // 累加/乘积初始值（乘积必须初始化为1，而非0）
                   std::multiplies<int>()// 二元操作：替换默认加法为乘法
                   ) *
               sizeof(DataType);// 乘以单个float的字节数（sizeof(float)=4）

    ASSERT(size == 602112, "4x1x3x224x224 = 602112");
    return 0;
}