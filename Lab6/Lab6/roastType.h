#pragma once
#include <string>
#include <list>
#include <vector>

enum class roastType
{
	light, medium, dark
};

struct Coffee
{
    std::string name;
    roastType roast;
    std::string flavorProfile;
    double pricePerKG{};
};

std::list<Coffee> createSubscription(std::vector<Coffee>& stock);
