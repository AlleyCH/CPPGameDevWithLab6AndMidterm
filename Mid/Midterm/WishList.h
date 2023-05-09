#ifndef WISHLIST_H
#define WISHLISTH
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>

class WishList {
public:

    WishList();
   
    WishList(const WishList&) = delete;
    WishList &operator=(const WishList&) = delete;

    WishList(WishList&& other);
    
    WishList& operator += (const std::string& gift); //an overload for += operator

    void display(void(*printer)(const std::string&)) const; // query 

    static int howManyLists(); // returns the number of objects of type WishList
   
    ~WishList();
     
    //void printId(const std::string& gift);

    //void printName(const std::string& gift);

   
private:
    std::vector<std::string> gifts;
    static int count;
};

int WishList::count = 0;

#endif

