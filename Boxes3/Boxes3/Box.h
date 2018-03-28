#pragma once
#ifndef Box_h
#define Box_h

#include <iostream>
#include <string>

class Box
{
	friend std::ostream &operator<<(std::ostream &, const Box &);
public:
	Box();
	Box(int, int);
	~Box();
	int getWidth() const;
	int getHeight() const;
	void setWidth(int);
	void setHeight(int);
	void virtual print(std::ostream &) const = 0;
	std::string virtual type() const = 0;
	static std::string repString(std::string, int);
protected:
	int _height;
	int _width;
};

#endif
