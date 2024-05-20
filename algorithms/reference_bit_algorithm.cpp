#include "reference_bit_algorithm.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

class Page
{
public:
    int number;
    unsigned char referenceBit;

    Page(int num) : number(num), referenceBit(0) {}
};

void shiftBits(std::vector<Page>& pages)
{
    for (auto& page : pages)
    {
        page.referenceBit >>= 1;
    }
}

Page& findVictim(std::vector<Page>& pages)
{
    return *std::min_element(pages.begin(), pages.end(), [](const Page& a, const Page& b)
    {
        return a.referenceBit < b.referenceBit;
    });
}

void printPages(const std::vector<Page>& pages)
{
    std::cout << "Pages: | ";
    for (const auto& page : pages)
    {
        std::cout << page.number << " (" << std::bitset<8>(page.referenceBit) << ") | ";
    }
    std::cout << '\n';
}

ReferenceBitAlgorithm::ReferenceBitAlgorithm(const std::vector<int>& referenceString, size_t frameSize)
{
    std::vector<Page> pages;
    int pageFaults = 0;

    for (const int pageNumber : referenceString)
    {
        shiftBits(pages);

        std::cout << "> " << pageNumber << '\n';

        bool found = false;

        for (auto& page : pages)
        {
            if (page.number == pageNumber)
            {
                page.referenceBit |= 0b10000000;
                found = true;
                break;
            }
        }

        if (!found)
        {
            if (pages.size() < frameSize)
            {
                Page newPage(pageNumber);
                newPage.referenceBit |= 0b10000000;
                pages.push_back(newPage);
            }
            else
            {
                Page& victim = findVictim(pages);
                victim.number = pageNumber;
                victim.referenceBit = 0b10000000;
                pageFaults++;
            }
        }

        printPages(pages);
    }

    std::cout << "Reference Bit Algorithm Page Faults: " << pageFaults << '\n';
}