#pragma once
#include "juniorStudent1.h"
juniorStudent::juniorStudent(const std::string& name, const std::vector<double>& rating) :Student(name, rating)
{
}
//juniorStudent(const std::string& name, const std::vector<double>& rating)
std::ostream& operator<<(std::ostream& out, const juniorStudent& student)
{
	out << "junior " << student.getName() << " ";
	student.printVector();
	return out;
}
	void juniorStudent::printStudent()
	{
		std::cout << *this;
	}

	
	juniorStudent* juniorStudent::cloneStudent() 
	{
			juniorStudent* ptr = new juniorStudent();
			ptr->setName(this->getName());
			ptr->setRatings(this->getRatings());
			return ptr;
	}