#include "clock_algorithm.hpp"
#include <iostream>
#include <vector>

class Page
{
public:
    int number;
    bool referenceBit;

    Page(int num) : number(num), referenceBit(false) {}
};

void printPages(const std::vector<Page>& pages, size_t hand)
{
    std::cout << "Pages: | ";
    for (size_t i = 0; i < pages.size(); ++i)
    {
        std::cout << pages[i].number << " (" << (pages[i].referenceBit ? "true" : "false") << ") " << (i == hand ? "<- | " : "| ");
    }
    std::cout << '\n';
}

ClockAlgorithm::ClockAlgorithm(const std::vector<int>& referenceString, size_t frameSize)
{
    std::vector<Page> pages;
    int pageFaults = 0;
    size_t hand = 0;

    for (const int pageNumber : referenceString)
    {
        std::cout << "> " << pageNumber << '\n';

        bool found = false;

        for (auto& page : pages)
        {
            if (page.number == pageNumber)
            {
                page.referenceBit = true;
                found = true;
                break;
            }
        }

        if (!found)
        {
            if (pages.size() < frameSize)
            {
                Page newPage(pageNumber);
                newPage.referenceBit = true;
                pages.push_back(newPage);
            }
            else
            {
                while (pages[hand].referenceBit)
                {
                    pages[hand].referenceBit = false;
                    hand = (hand + 1) % frameSize;
                    printPages(pages, hand);
                }
                pages[hand].number = pageNumber;
                pages[hand].referenceBit = true;
                hand = (hand + 1) % frameSize;
                pageFaults++;
            }
        }

        printPages(pages, hand);
    }

    std::cout << "Clock Algorithm Page Faults: " << pageFaults << '\n';
}