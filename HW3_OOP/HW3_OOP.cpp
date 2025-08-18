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

	void print() const {
		cout << "Name: " << name << ", Frequency: " << frequancy 
			 << " GHz, RAM: " << ram << " GB, DVD: " << (dvd ? "Yes" : "No") 
			<< ", Price: $" << price << endl;
	}
};

void printVector(const vector<Computer>& comps) {
	cout << "=========================" << endl;
	for (const auto& c : comps) {
		c.print();
	}
	cout << "=========================" << endl;
}
