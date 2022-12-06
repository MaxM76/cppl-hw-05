#include <iostream>
#include <vector>
#include <algorithm>


class functor {
private:
    int sum;
    int count;
public:
    functor() : sum{ 0 }, count{ 0 } {}
    int get_sum() const {
        return sum;
    }

    int get_count() const {
        return count;
    }

    void operator()(int inputValue) {
        if ((inputValue % 3) == 0) {
            count++;
            sum += inputValue;
        }
    }
};


int main()
{
    functor fun;
/*
    std::cout << "[IN]: ";
    for (int i = 0; i < 10; i++) {
        int input;
        std::cin >> input;
        fun(input);
    }
    std::cout << "[OUT]: get_sum() = " << fun.get_sum() << " \n";
    std::cout << "[OUT]: get_count() = " << fun.get_count() << " \n";
*/
    std::vector<int> vec{ 4, 1, 3, 6, 25, 54 };

    fun = std::for_each(vec.begin(), vec.end(), fun);
    std::cout << "[OUT]: get_sum() = " << fun.get_sum() << " \n";
    std::cout << "[OUT]: get_count() = " << fun.get_count() << " \n";
}