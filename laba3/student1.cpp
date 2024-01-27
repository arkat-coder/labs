#pragma once
#include "student1.h"

Student::Student(const std::string& name, const std::vector<double>& rating):name(name),ratings(rating)
{
	
}

const std::vector<double>& Student::getRatings() const
{
	return ratings;
}
void Student::setRatings(const std::vector<double>& rating)
{
	ratings = rating;
}

const std::string& Student::getName() const
{
	return name;
}
void Student::setName(const std::string& name)
{
	this->name = name;
}

void Student::printVector() const
{
	std::cout << "Grades: ";
	for (double value : ratings) {
		std::cout << value << " ";
	}
	std::cout << std::endl;
}