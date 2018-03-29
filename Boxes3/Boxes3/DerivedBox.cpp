#include "DerivedBox.h"

FilledBox::FilledBox() : Box{}
{
	std::cout << "creating FilledBox" << std::endl;
}

FilledBox::FilledBox(int width, int height) : Box{ width,height }
{
	std::cout << "creating FilledBox with height " << height << " and width " << width << std::endl;
}

std::string FilledBox::type() const
{
	return "Filled";
}

void FilledBox::print(std::ostream &os) const
{
	for (int i = 0; i < _height; i++) {
		os << repString("x", _width) << std::endl;
	}
}

HollowBox::HollowBox() : Box{}
{
}

HollowBox::HollowBox(int width, int height) : Box{width, height}
{
}

std::string HollowBox::type() const
{
	return "Hollow";
}

void HollowBox::print(std::ostream &os) const
{
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
{
}

CheckeredBox::CheckeredBox(int width, int height) : Box{width, height}
{
}

std::string CheckeredBox::type() const
{
	return "Checkered";
}

void CheckeredBox::print(std::ostream &os) const
{
	for (int i = 0; i < _height; i++) {
		if (i % 2 == 1) {
			os << repString("x ", _width/2);
		} else {
			os << repString(" x", _width/2);
		}
		os << std::endl;
	}
}
