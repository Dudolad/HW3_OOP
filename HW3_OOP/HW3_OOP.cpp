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

private:
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

int main()
{
	vector<Computer> computers = {
		{"Lenovo", 3.2, 8, true, 500},
		{"HP", 2.4, 16, false, 450},
		{"Dell", 1.8, 4, true, 300},
		{"Asus", 3.5, 32, true, 800},
		{"Acer", 2.9, 16, true, 600}
	};


	cout << "Initial list of computers:" << endl;
	printVector(computers);

	string searchName = "Dell";
	auto it = find_if(computers.begin(), computers.end(),
		[&](const Computer& c) { return c.name == searchName; });

	if (it != computers.end()) {
		cout << "Computer found by name \"" << searchName << "\":" << endl;
		it->print();
	}
	else {
		cout << "Computer by name \"" << searchName << "\" not found." << endl;
	}


	auto minIt = min_element(
		computers.begin(),
		computers.end(),
		[](const Computer& a, const Computer& b) { return a.frequancy < b.frequancy; });

		if (minIt != computers.end())
		{
			cout << "\nThe computer with the lowest frequency: " << endl;
			minIt->print();
			computers.erase(minIt);
		}
		cout << "\nList of computers after removing the one with the lowest frequency:" << endl;
		printVector(computers);


	int countDVD = count_if(computers.begin(), computers.end(),
		[](const Computer& c) { return c.dvd; });

	cout << "Number of computers with DVD: " << countDVD << endl;


	for_each(computers.begin(), computers.end(),
		[](Computer& c) {
			if (c.ram > 16) c.price *= 1.1;
		});

	cout << "\nAfter the price increase (RAM > 16):" << endl;
	printVector(computers);


	sort(computers.begin(), computers.end(),
		[](const Computer& a, const Computer& b) { return a.price < b.price; });

	cout << "Sorting by ascending price:" << endl;
	printVector(computers);



	sort(computers.begin(), computers.end(),
		[](const Computer& a, const Computer& b) { return a.frequancy > b.frequancy; });

	cout << "Sorting by descending price:" << endl;
	printVector(computers);

	return 0;
}


