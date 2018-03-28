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
			os << repString("X", _width);
		}
		else {
			os << "X" << repString(" ", _width - 2) << "X" << std::endl;
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
}
