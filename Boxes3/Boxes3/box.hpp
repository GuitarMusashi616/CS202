#pragma once
#ifndef Box_hpp
#define Box_hpp
//box.hpp
//Austin Williams
//March 29, 2018
//declares the box classes and derived box classes

#include <iostream>
#include <string>
#include <memory>

class Box
{
	//abstract class for box types
	friend std::ostream &operator<<(std::ostream &, const Box &);
public:
	Box();
	Box(int, int);
	virtual ~Box() = 0;
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

class FilledBox : public Box
{
	//Derived class for filled boxes
public:
	FilledBox();
	FilledBox(int, int);
	~FilledBox();
	std::string type() const override;
	void print(std::ostream &) const override;
};

class HollowBox : public Box
{
	//Derived class for hollow boxes
public:
	HollowBox();
	HollowBox(int, int);
	~HollowBox();
	std::string type() const override;
	void print(std::ostream &) const override;
};

class CheckeredBox : public Box
{
	//Derived class for checkered boxes
public:
	CheckeredBox();
	CheckeredBox(int, int);
	~CheckeredBox();
	std::string type() const override;
	void print(std::ostream &) const override;
};

//function for returning unique_pointers to derived boxes
std::unique_ptr<Box> boxFactory(char, int, int);

#endif
