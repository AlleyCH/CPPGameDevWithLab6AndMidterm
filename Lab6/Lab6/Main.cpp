#include "Main.h"
#include <iostream>
#include "roastType.h"

using namespace std;
int main() {
	std::vector<Coffee> coffees({
	{ "Pacific Pipeline", roastType::medium, "Full Bodied", 8.99 },
	{ "Three Sisters", roastType::medium, "Tropical Fruit", 7.99 },
	{ "Hola", roastType::light, "Juicy", 11.99 },
	{ "Horse Power", roastType::dark, "Creamy", 8.99 },
	{ "Decaf", roastType::dark, "Creamy", 5.99 },
	{ "Grizzly Claw", roastType::light, "Full Bodied", 9.99 },
		});

	// The resulting coffee subscription
	auto coffee_sub = createSubscription(coffees);
	void(*roastFunc[3])() = {
	[]() { cout << "Light"; },
	[]() { cout << "Medium"; },
	[]() { cout << "Dark"; }
	};
	cout << "\nCoffee Subscription" << endl;
	for (auto& x : coffee_sub) {
		cout << x.name << " | ";
		roastFunc[(int)x.roast]();
		cout << " | " << x.flavorProfile << " | " << x.pricePerKG << endl;
	}
	return 0;
}
