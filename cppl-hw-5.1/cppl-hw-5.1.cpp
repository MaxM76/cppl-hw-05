#include <iostream>
#include <vector>
#include <algorithm>

template <class T>
T square(T a)
{
    return a * a;
}

template <>
std::vector<int> square(std::vector<int> data) {
    std::vector<int> result;
    std::for_each(data.begin(), data.end(), [&result](int& i) {
        result.push_back(i * i);
    });
    return result;
}


int main()
{
    int intArg = 4;
    std::cout << "[IN]: " << intArg << "\n";
    std::cout << "[OUT]: " << square(intArg) << "\n";
    std::vector<int> intVectorArg = { -1, 4, 8 };
    std::cout << "[OUT]: ";
    std::for_each(intVectorArg.begin(), intVectorArg.end(), [](int i) {
        std::cout << i << " ";
    });
    std::cout << "\n";
    std::vector<int> intVectorResult = square(intVectorArg);
    std::cout << "[OUT]: ";
    std::for_each(intVectorResult.begin(), intVectorResult.end(), [](int i) {
        std::cout << i << " ";
    });
    std::cout << "\n";
}