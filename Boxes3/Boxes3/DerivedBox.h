#pragma once
#ifndef DerivedBox_h
#define DerivedBox_h

#include "Box.h"

class FilledBox : public Box
{
public:
	FilledBox();
	FilledBox(int, int);
	std::string type() const override;
	void print(std::ostream &) const override;
};

class HollowBox : public Box 
{
public:
	HollowBox();
	HollowBox(int, int);
	std::string type() const override;
	void print(std::ostream &) const override;
};

class CheckeredBox : public Box
{
public:
	CheckeredBox();
	CheckeredBox(int, int);
	std::string type() const override;
	void print(std::ostream &) const override;
};

#endif
