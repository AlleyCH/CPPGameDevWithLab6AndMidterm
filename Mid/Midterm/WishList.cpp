#include "WishList.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <cstdlib>

using namespace std;

WishList::WishList() : gifts{} {
    ++count;
}

WishList::WishList(WishList&& other) {
    gifts = move(other.gifts);
    other.gifts.clear();
}

WishList& WishList::operator+=(const string &gift)
{
    size_t idx = gift.find("##");
    if (idx == string::npos) {
        throw runtime_error("String [" + gift + "] doesn't represent a valid gift.");
    }
    if (find(gifts.begin(), gifts.end(), gift) == gifts.end()) {
        gifts.push_back(gift);
    }
    return *this;
}

void WishList::display(void(*printer)(const std::string&)) const
{
    if (gifts.empty()) {
        cout << "Empty list!" << endl;
        return;
    }
    for (const auto& gift : gifts) {
        printer(gift);
    }
}

int WishList::howManyLists()
{
    return count;
}

WishList::~WishList()
{
    --count;
}

// Prints the SKU component of the `gift`.
// Assumes `gift` represents a valid gift.
void printId(const std::string& gift)
{
    for (auto i = 0; gift[i] != '#'; ++i)
    std::cout << gift[i];
    std::cout << std::endl;

}

// Prints the NAME component of the `gift`.
// Assumes `gift` represents a valid gift.
void printName(const std::string& gift)
{
    size_t idx{};
    for (auto i = 0; gift[i] != '#'; ++i)
        ++idx;
    // skip the "##"
    for (auto i = idx + 2; i < gift.size(); ++i)
    std::cout << gift[i];
    std::cout << std::endl;

}



int main() {
    std::string gifts[]{
        "ABC123##Scarf",
        "AA12##iPhone",
        "invalid_gift",              // missing ##
        "3245HOHOHO##Coffee Maker",
        "ID#Invalid_Gift",           // missing ##
        "EFG##Gaming Headset",
        "987654##Some Book"
    };
    WishList* pLst = new WishList();
    (*pLst += gifts[0]) += gifts[1];
    std::cout << "----\n";
    std::cout << "1. Objects alive: " << WishList::howManyLists() << "\n";
    std::cout << "----\n\n";
    try {
        for (const auto& gift : gifts) {
            *pLst += gift;
        }
    }
    catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    {
        WishList another(std::move(*pLst));
        another.display(printId);

        std::cout << "\n----\n";
        std::cout << "2. Objects alive: " << WishList::howManyLists() << "\n";
        std::cout << "----\n\n";
        another.display(printName);
    }

    std::cout << "\n----\n";
    std::cout << "3. Objects alive: " << WishList::howManyLists() << "\n";
    std::cout << "----\n";
    pLst->display(printId);
    pLst->display(printName);

    delete pLst;

    return 0;

}