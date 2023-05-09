#include "roastType.h"
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


list<Coffee> createSubscription(vector<Coffee> &stock) {
    // Task 1: count the number of coffees with "Creamy" or "Full Bodied" flavor profile
    auto numCreamyFullbodied = count_if(stock.begin(), stock.end(),
        [](const Coffee &coffee) { return coffee.flavorProfile == "Creamy" || coffee.flavorProfile == "Full Bodied"; });
    cout << "Number of coffees with Creamy or Full Bodied flavor profile: " << numCreamyFullbodied << std::endl;

    // Task 2: sort the stock based on roastType
    sort(stock.begin(), stock.end(), [](const Coffee& lhs, const Coffee& rhs) {
        return lhs.roast < rhs.roast;
        });

    // Task 3: create a list of light and medium roasts where price is less than 10 dollars per KG
    list<Coffee> subscription;
    copy_if(stock.begin(), stock.end(), back_inserter(subscription), [](const Coffee& coffee) {
        return (coffee.roast == roastType::light || coffee.roast == roastType::medium) && coffee.pricePerKG < 10.0;
        });

    // Task 4: add the first dark roast coffee to the subscription
    auto dark_roast_it = std::find_if(stock.begin(), stock.end(), [](const Coffee& coffee) {
        return coffee.roast == roastType::dark;
        });
    if (dark_roast_it != stock.end()) {
        subscription.push_back(*dark_roast_it);
    }

    // Task 5: tally up the total price per KG of all the coffees in the subscription
    auto total_price = std::accumulate(subscription.begin(), subscription.end(), 0.0, [](double sum, const Coffee& coffee) {
        return sum + coffee.pricePerKG;
        });
    cout << "Total price per KG of subscription: " << total_price << std::endl;

    return subscription;
}