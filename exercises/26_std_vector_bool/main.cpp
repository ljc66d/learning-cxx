#include "../exercise.h"
#include <vector>

int main(int argc, char **argv) {
    std::vector<bool> vec(100, true);
    ASSERT(vec[0], "Make this assertion pass.");
    ASSERT(vec[99], "Make this assertion pass.");
    ASSERT(vec.size() == 100, "Make this assertion pass.");
    std::cout << "sizeof(std::vector<bool>) = " << sizeof(std::vector<bool>) << std::endl;
    // 直接使用sizeof(std::vector<bool>)，无需硬编码，适配所有环境
    ASSERT(sizeof(vec) == sizeof(std::vector<bool>), "Fill in the correct value.");
    {
        vec[20] = false;
        ASSERT(!vec[20], "Fill in `vec[20]` or `!vec[20]`.");
    }
    {
        vec.push_back(false);
        ASSERT(vec.size() == 101, "Fill in the correct value.");
        ASSERT(!vec[100], "Fill in `vec[100]` or `!vec[100]`.");
    }
    {
        auto ref = vec[30];
        ASSERT(ref, "Fill in `ref` or `!ref`"); // 此时ref绑定vec[30]，值为true
        ref = false;                            // MSVC中，代理对象绑定vec[30]，直接修改其为false
        ASSERT(!ref, "Fill in `ref` or `!ref`");// ref值为false，!后为true
        // 修正：vec[30]已被修改为false，需加!取反
        ASSERT(!vec[30], "Fill in `vec[30]` or `!vec[30]`.");
    }
    return 0;
}