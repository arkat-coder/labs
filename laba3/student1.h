#pragma once
#ifndef STUDENT1
#define STUDENT1
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>
#include <iostream>

class Student
	{
	protected:
		std::string name;
		std::vector<double> ratings;
	public:
		Student(const std::string& name, const std::vector<double>& rating);
		Student() = default;
		const std::vector<double>& getRatings() const;
		void setRatings(const std::vector<double>& rating);
		//bool isUnderperforming();
		const std::string& getName() const;
		void setName(const std::string& name);
		virtual ~Student() {};
		virtual void printStudent() = 0;
		void printVector() const;
		virtual Student* cloneStudent()=0;
	};




#endif STUDENT1
