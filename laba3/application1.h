#pragma once
#include "tableofgroup1.h"
#include "seniorStudent1.h"
#include "juniorStudent1.h"
#include <numeric>
class application
{
private:
	std::vector<TableOfGroup> Groups;
public:

	double calculateAverageGradeInGroup(int groupIndex) const;
	void entranceStudent(int groupIndex, const std::shared_ptr<Student>& s);
	void studentTransfer(int oldGroupIndex, int newGroupIndex, std::shared_ptr<Student>& s); // проверка на индекс
	void addGroup(const TableOfGroup& t);
	 std::vector < std::weak_ptr<Student>> &getUnder(std::vector < std::weak_ptr<Student>>& vectorUnder) ;
	void generateTranscript(int groupIndex);
	void printall() const;
	int getNumberOfDisciplinesOfGroup(int index);
	std::shared_ptr < Student> getByGroupIndexAndPositionStudent(int groupIndex, int position);
};