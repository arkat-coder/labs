#pragma once
#include "seniorStudent1.h"


seniorStudent::seniorStudent(const std::string& name, const std::vector<double>& rating, double erwRating, const std::string& place, const std::string& theme) :
	Student(name, rating)
{
	setERW(erwRating, place, theme);
}
void seniorStudent::printStudent() 
{
	std::cout << *this;
}

const std::string& seniorStudent::getERWplace() const
{
	return erw.place;
}

void seniorStudent::setERWplace(const std::string& place)
{
	erw.place = place;
}

const std::string& seniorStudent::getERWtheme() const
{
	return erw.theme;
}

void seniorStudent::setERWtheme(const std::string& theme)
{
	erw.theme = theme;
}

double seniorStudent::getERWrating() const
{
	return erw.erwRating;
}

void seniorStudent::setERWrating(double erwRating)
{
	erw.erwRating = erwRating;
}

void seniorStudent::setERW(double erwRating, const std::string& place, const std::string& theme)
{
	erw.erwRating = erwRating;
	erw.place = place;
	erw.theme = theme;
}


std::ostream& operator<<(std::ostream& out, const seniorStudent& student)
{
	out << "senior " << student.getName() << " "<< student.getERWrating() << " " << student.getERWplace() << " " << student.getERWtheme()<< " ";
	student.printVector();
	return out;
}

 seniorStudent* seniorStudent::cloneStudent()
{
	seniorStudent* ptr = new seniorStudent(*this);


	return ptr;
}