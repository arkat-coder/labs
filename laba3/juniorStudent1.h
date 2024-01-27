#pragma once
#ifndef JUNIORSTUDENT1
#define JUNIORSTUDENT1
#include "student1.h"


	class juniorStudent : public Student
	{

	public:
		juniorStudent() = default;
		juniorStudent(const std::string& name, const std::vector<double>& rating);
		~juniorStudent() = default;
		friend std::ostream& operator<<(std::ostream& out, const juniorStudent& student);
		void printStudent() override;
		virtual juniorStudent* cloneStudent() override;
	};

#endif