#include "../exercise.h"
#include <cassert>
#include <cstring>

// READ: 类模板 <https://zh.cppreference.com/w/cpp/language/class_template>

template<class T>
struct Tensor4D {
    unsigned int shape[4];
    T *data;

    Tensor4D(unsigned int const shape_[4], T const *data_) {
        unsigned int size = 1;
        // TODO: 填入正确的 shape 并计算 size
        // 1. 拷贝输入形状到当前对象的shape数组（4个维度）
        std::memcpy(shape, shape_, 4 * sizeof(unsigned int));
        // 2. 计算4维张量的总元素个数（各维度乘积）
        for (int i = 0; i < 4; ++i) {
            size *= shape[i];
        }
        // 3. 分配内存并拷贝数据（原有代码保留，size已正确计算）
        data = new T[size];
        std::memcpy(data, data_, size * sizeof(T));
    }

    ~Tensor4D() {
        delete[] data;
    }

    // 为了保持简单，禁止复制和移动
    Tensor4D(Tensor4D const &) = delete;
    Tensor4D(Tensor4D &&) noexcept = delete;

    // 这个加法需要支持“单向广播”。
    // 具体来说，`others` 可以具有与 `this` 不同的形状，形状不同的维度长度必须为 1。
    // `others` 长度为 1 但 `this` 长度不为 1 的维度将发生广播计算。
    // 例如，`this` 形状为 `[1, 2, 3, 4]`，`others` 形状为 `[1, 2, 1, 4]`，
    // 则 `this` 与 `others` 相加时，3 个形状为 `[1, 2, 1, 4]` 的子张量各自与 `others` 对应项相加。
    Tensor4D &operator+=(Tensor4D const &others) {
        // 步骤1：计算当前张量和others的总元素个数及各维度步长（用于一维索引转4维坐标）
        unsigned int this_size = 1;
        unsigned int this_stride[4] = {1, 1, 1, 1};// 各维度的步长（从后往前计算）
        for (int i = 3; i >= 0; --i) {
            this_size *= shape[i];
            if (i < 3) {
                this_stride[i] = this_stride[i + 1] * shape[i + 1];
            }
        }

        unsigned int others_size = 1;
        unsigned int others_stride[4] = {1, 1, 1, 1};
        for (int i = 3; i >= 0; --i) {
            others_size *= others.shape[i];
            if (i < 3) {
                others_stride[i] = others_stride[i + 1] * others.shape[i + 1];
            }
        }

        // 步骤2：合法性检查（符合单向广播规则：others维度要么和this相等，要么为1）
        for (int i = 0; i < 4; ++i) {
            assert(shape[i] == others.shape[i] || others.shape[i] == 1 && "Invalid broadcast shape");
        }

        // 步骤3：遍历当前张量的每个元素，实现广播加法
        for (unsigned int i = 0; i < this_size; ++i) {
            // 3.1 将当前张量的一维索引i转换为4维坐标（x0, x1, x2, x3）
            unsigned int x0 = i / this_stride[0];
            unsigned int rem0 = i % this_stride[0];
            unsigned int x1 = rem0 / this_stride[1];
            unsigned int rem1 = rem0 % this_stride[1];
            unsigned int x2 = rem1 / this_stride[2];
            unsigned int x3 = rem1 % this_stride[2];
            unsigned int this_4d[4] = {x0, x1, x2, x3};

            // 3.2 根据广播规则，计算others对应的4维坐标（o0, o1, o2, o3）
            unsigned int others_4d[4] = {0, 0, 0, 0};
            for (int j = 0; j < 4; ++j) {
                // others维度为1时，取0（重复使用唯一元素）；否则取和this相同的坐标
                others_4d[j] = (others.shape[j] == 1) ? 0 : this_4d[j];
            }

            // 3.3 将others的4维坐标转换为一维索引
            unsigned int others_idx = 0;
            for (int j = 0; j < 4; ++j) {
                others_idx += others_4d[j] * others_stride[j];
            }

            // 3.4 执行广播加法（当前元素 += others对应元素）
            data[i] += others.data[others_idx];
        }

        return *this;
    }
};

// ---- 不要修改以下代码 ----
int main(int argc, char **argv) {
    {
        unsigned int shape[]{1, 2, 3, 4};
        // clang-format off
        int data[]{
             1,  2,  3,  4,
             5,  6,  7,  8,
             9, 10, 11, 12,

            13, 14, 15, 16,
            17, 18, 19, 20,
            21, 22, 23, 24};
        // clang-format on
        auto t0 = Tensor4D(shape, data);
        auto t1 = Tensor4D(shape, data);
        t0 += t1;
        for (auto i = 0u; i < sizeof(data) / sizeof(*data); ++i) {
            ASSERT(t0.data[i] == data[i] * 2, "Tensor doubled by plus its self.");
        }
    }
    {
        unsigned int s0[]{1, 2, 3, 4};
        // clang-format off
        float d0[]{
            1, 1, 1, 1,
            2, 2, 2, 2,
            3, 3, 3, 3,

            4, 4, 4, 4,
            5, 5, 5, 5,
            6, 6, 6, 6};
        // clang-format on
        unsigned int s1[]{1, 2, 3, 1};
        // clang-format off
        float d1[]{
            6,
            5,
            4,

            3,
            2,
            1};
        // clang-format on

        auto t0 = Tensor4D(s0, d0);
        auto t1 = Tensor4D(s1, d1);
        t0 += t1;
        for (auto i = 0u; i < sizeof(d0) / sizeof(*d0); ++i) {
            ASSERT(t0.data[i] == 7.f, "Every element of t0 should be 7 after adding t1 to it.");
        }
    }
    {
        unsigned int s0[]{1, 2, 3, 4};
        // clang-format off
        double d0[]{
             1,  2,  3,  4,
             5,  6,  7,  8,
             9, 10, 11, 12,

            13, 14, 15, 16,
            17, 18, 19, 20,
            21, 22, 23, 24};
        // clang-format on
        unsigned int s1[]{1, 1, 1, 1};
        double d1[]{1};

        auto t0 = Tensor4D(s0, d0);
        auto t1 = Tensor4D(s1, d1);
        t0 += t1;
        for (auto i = 0u; i < sizeof(d0) / sizeof(*d0); ++i) {
            ASSERT(t0.data[i] == d0[i] + 1, "Every element of t0 should be incremented by 1 after adding t1 to it.");
        }
    }
}