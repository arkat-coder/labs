#pragma once
#ifndef SENIORSTUDENT1
#define SENIORSTUDENT1
#include "student1.h"


	struct ERW
	{
	public:
		double erwRating;
		std::string place;
		std::string theme;
	};

	class seniorStudent :public Student
	{
	private:
		ERW erw;
	public:
		seniorStudent() = default;
		seniorStudent(const std::string& name, const std::vector<double>& rating, double erwRating, const std::string& place, const std::string& theme);
		const std::string& getERWplace() const;
		void setERWplace(const std::string& place);
		const std::string& getERWtheme() const;
		void setERWtheme(const std::string& theme);
		double getERWrating() const;
		void setERWrating(double erwRating);
		void setERW(double erwRating, const std::string& place, const std::string& theme);
		friend std::ostream& operator<<(std::ostream& out, const seniorStudent & student);
		void printStudent() override;
		virtual seniorStudent* cloneStudent() override;
		~seniorStudent() = default;
	};



#endif