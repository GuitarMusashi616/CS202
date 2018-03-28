#include "Box.h"

Box::Box() : _height{ 0 }, _width{ 0 }
{
	std::cout << "creating Box" << std::endl;
}

Box::Box(int width, int height) : _height{ height }, _width{ width }
{
	std::cout << "creating Box with height " << _height << " and width " << _width << std::endl;
}

Box::~Box()
{
	std::cout << "destroying Box" << std::endl;
}

int Box::getWidth() const
{
	return _width;
}

int Box::getHeight() const
{
	return _height;
}

void Box::setWidth(int width)
{
	_width = width;
}

void Box::setHeight(int height)
{
	_height = height;
}

std::string Box::repString(std::string rep, int num)
{
	std::string out = rep;
	for (int i = 0; i < num; i++) {
		out = out + rep;
	}
	return out;
}

std::ostream & operator<<(std::ostream &os, const Box &b)
{
	b.print(os);
	return os;
}
