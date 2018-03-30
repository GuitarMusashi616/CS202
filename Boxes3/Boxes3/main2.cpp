#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include "Box.hpp"
#include "DerivedBox.hpp"
#include <memory>
#include <string>
using std::unique_ptr;
using std::string;
using std::make_unique;
#include <vector>
using std::vector; 

unique_ptr<Box> boxFactory(char c, int w, int h) {
	//creates and returns a unique_pointer to derivedBox based on input.  
	switch(c) {
	case 'f':
		return make_unique<FilledBox>(w,h);
	case 'h':
		return make_unique<HollowBox>(w,h);
	case 'c':
		return make_unique<CheckeredBox>(w,h);
	}
}

int main() {
	FilledBox amazon{5,7};
	amazon.setHeight(10);
	cout << amazon.type() << endl;
	cout << amazon.getHeight() << endl;
	vector<char> args{ 'f','c','h' };

	for (auto letter : args) {
		auto factory = boxFactory(letter, 10, 5);
		factory->print(cout);
	}
	//HollowBox paperBox{ 7,4 };
	//FilledBox metalBox{ 10,5 };
	//CheckeredBox marbleBox{ 6,4 };
	//cout << endl << paperBox << endl << metalBox << endl << marbleBox << endl;
	//metalBox.print(cout);

	while (cin.get() != '\n');
}