//box.cpp
//Austin Williams
//March 29, 2018
//defines the box and derived box classes

#include "box.hpp"

Box::Box() : _height{ 1 }, _width{ 1 }
{
	//default constructor for abstract box class
}

Box::Box(int width, int height) : _height{ height }, _width{ width }
{
	//constructor that takes width and height arguments for box
}

Box::~Box() {
}

int Box::getWidth() const
{
	//gets the width
	return _width;
}

int Box::getHeight() const
{
	//sets the height
	return _height;
}

void Box::setWidth(int width)
{
	//sets the width
	_width = width;
}

void Box::setHeight(int height)
{
	//sets the height
	_height = height;
}

std::string Box::repString(std::string rep, int num)
{
	//static function used within derivedClass methods to repeat strings
	std::string out = "";
	for (int i = 0; i < num; i++) {
		out = out + rep;
	}
	return out;
}

std::ostream & operator<<(std::ostream &os, const Box &b)
{
	//defines global operator<< to take box and print it
	b.print(os);
	return os;
}


FilledBox::FilledBox() : Box{}
{
	//initializes a default filledbox
}

FilledBox::FilledBox(int width, int height) : Box{ width,height }
{
	//initializes a filled box with the passed values
}

FilledBox::~FilledBox()
{
}

std::string FilledBox::type() const
//returns the type of box
{
	return "Filled";
}

void FilledBox::print(std::ostream &os) const
//prints a fixed box
{
	for (int i = 0; i < _height; i++) {
		os << repString("x", _width) << std::endl;
	}
}

HollowBox::HollowBox() : Box{}
//creates default hollow box
{
}

HollowBox::HollowBox(int width, int height) : Box{ width, height }
//initializes hollow box based on passed values
{
}

HollowBox::~HollowBox()
{
}

std::string HollowBox::type() const
{
	//use to discover the type
	return "Hollow";
}

void HollowBox::print(std::ostream &os) const
{
	//prints the hollow box
	for (int i = 0; i < _height; i++) {
		if (i == 0 || i == _height - 1) {
			os << repString("x", _width);
		}
		else {
			os << "x" << repString(" ", _width - 2) << "x";
		}
		os << std::endl;
	}
}

CheckeredBox::CheckeredBox() : Box{}
//initializes default checkerBox
{
}

CheckeredBox::CheckeredBox(int width, int height) : Box{ width, height }
//initializes checkerBox with passed values
{
}

CheckeredBox::~CheckeredBox()
{
}

std::string CheckeredBox::type() const
{
	//returns type
	return "Checkered";
}

void CheckeredBox::print(std::ostream &os) const
{
	//prints the checkerboard box
	for (int i = 0; i < _height; i++) {
		if (i % 2) {
			for (int j = 0;j < _width;j++) {
				if (j % 2) {
					os << "x";
				} else {
					os << " ";
				}
			}
		} else {
			for (int j = 0;j < _width;j++) {
				if (j % 2) {
					os << " ";
				}
				else {
					os << "x";
				}
			}
		}
		os << std::endl;
	}
}

std::unique_ptr<Box> boxFactory(char c, int w, int h) {
	//creates and returns a unique_pointer to derivedBox based on input.  
	switch (c) {
	case 'f':
		return std::make_unique<FilledBox>(w, h);
	case 'h':
		return std::make_unique<HollowBox>(w, h);
	case 'c':
		return std::make_unique<CheckeredBox>(w, h);
	default:
		std::cout << "ERROR invalid input" << std::endl;
	}
}