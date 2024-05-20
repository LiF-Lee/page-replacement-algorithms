#include <iostream>
#include <vector>
#include "./algorithms/reference_bit_algorithm.hpp"
#include "./algorithms/clock_algorithm.hpp"

int main()
{
    const std::vector<int> referenceString = { 1, 2, 3, 2, 1, 5, 2, 1, 6, 2, 5, 6, 3, 1, 3, 6, 1, 2, 4, 3 };
    constexpr size_t frameSize = 3;

    // 참조 비트 알고리즘
    std::cout << "[Reference Bit Algorithm]\n";
    ReferenceBitAlgorithm(referenceString, frameSize);

    std::cout << "\n----------------------------------------\n\n";

    // 시계 알고리즘
    std::cout << "[Clock Algorithm]\n";
    ClockAlgorithm(referenceString, frameSize);

    return 0;
}