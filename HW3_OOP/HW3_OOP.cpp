#include <iostream>
#include <string>
#include <vector>
#include <algorithm>	
using namespace std;

class Computer {
public:
	string name;
	double frequancy;
	int ram;
	bool dvd;
	double price;

	Computer() : name(""), frequancy(0.0), ram(0), dvd(false), price(0.0) {}
	Computer(string n, double f, int r, bool d, double p) 
		: name(n), frequancy(f), ram(r), dvd(d), price(p) {
	}
	~Computer() {}
};
