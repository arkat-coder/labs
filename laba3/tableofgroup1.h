#pragma once
#ifndef TABLE
#define TABLE
#include "student1.h"
#include "juniorStudent1.h"
#include "seniorStudent1.h"
#include <vector>
#include <algorithm>
#include <memory>

class TableOfGroup
{
private:
	int groupIndex ;
	int numberofDisciplines;
	Student* typeOfGroup;
	
	
	
public:
	TableOfGroup() = default;			
	TableOfGroup(int groupIndex, int numberofDisciplines, Student* typeOfGroup);
	std::vector<std::shared_ptr<Student>> tableOfStudents;
	int getgroupIndex() const;

	int getNumberOfDisciplines() const;
	 Student* getTypeOfGroup() const;
	void printTable()	const;
	void deleteStudent(std::shared_ptr<Student>& s);
	void addStudent(const std::shared_ptr<Student>& student);
	const std::vector<std::shared_ptr<Student>>& getTableOfStudents() const;

	std::vector < std::weak_ptr<Student>>& getUnderPerformingStudents(std::vector <std::weak_ptr<Student>>& vectorUnder) const;


	TableOfGroup(const TableOfGroup& T);
	//TableOfGroup& operator =(const TableOfGroup& T);

	virtual ~TableOfGroup();
	
};


#endif