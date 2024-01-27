#pragma once
#include "application1.h"

double application::calculateAverageGradeInGroup(int groupIndex) const
{
    double totalAverage = 0.0;
    size_t validStudentCount = 0;
    double studentAverage = 0;
    for (auto i : Groups)
    {
        if (i.getgroupIndex() == groupIndex)
        {
            for (auto& Ptr : i.getTableOfStudents())
            {
                studentAverage = std::accumulate(Ptr->getRatings().begin(), Ptr->getRatings().end(), 0.0);
                    totalAverage += studentAverage;
                    validStudentCount++;
            }
        }
    }
    if (validStudentCount == 0)
        return -1;
    return  totalAverage / validStudentCount;
}

void  application::entranceStudent(int groupIndex, const std::shared_ptr<Student>& s)
{
    for (auto& i : Groups)
    {
        if (i.getgroupIndex() == groupIndex)
        {
            i.addStudent(s);
        }
    }
}

void  application::studentTransfer(int oldGroupIndex, int newGroupIndex, std::shared_ptr<Student>& s)
{
    for (auto& i : Groups)
    {
        if (i.getgroupIndex() == newGroupIndex)
        {
            i.addStudent(s);
        }
        if (i.getgroupIndex() == oldGroupIndex)
        {
            i.deleteStudent(s);
            
        }
    }
}

void application::addGroup(const TableOfGroup& t)
{
    Groups.push_back(t);
}



std::vector < std::weak_ptr<Student>>& application::getUnder(std::vector <std::weak_ptr<Student>>& vectorUnder) 
{
    for (auto& i : Groups)
    {   
        i.getUnderPerformingStudents(vectorUnder); 
    }
    return vectorUnder;
}

void application::printall() const
{
    for (const auto& i : Groups)
    {
      std::cout<<"Index "<<i.getgroupIndex()<<std::endl;
        i.printTable();
    }
}

int application::getNumberOfDisciplinesOfGroup(int index)
{
    for (const auto& i : Groups)
    {
        if (i.getgroupIndex() == index)
            return i.getNumberOfDisciplines();
    }
    return 0;
}

std::shared_ptr < Student> application::getByGroupIndexAndPositionStudent(int groupIndex, int position)
{
    for (const auto& i : Groups)
    {
        if (i.getgroupIndex() == groupIndex)
        {
            return i.getTableOfStudents()[position];
        }
    }
    return 0;
}
void  application::generateTranscript(int groupIndex)
{
    std::vector<double> s;
    double rating = 0;
    for (const auto& i : Groups)
    {
        if (i.getgroupIndex() == groupIndex)
        {
            for (auto j : i.getTableOfStudents())
            {
                std::cout << "Enter Grades for " << j->getName()<<std::endl;
                for (int k=0; k < i.getNumberOfDisciplines(); k++)
                {
                    std::cout << "Enter grade [" << k << "] ";
                    std::cin>>rating;
                    s.push_back(rating);
                }
                j->setRatings(s);
                s.clear();
           }
            
        }
        i.printTable();
        return ;
    }
}

/*void getGrades (std::vector<double>& s, int numberOfDisciplines)
{
    for (int i = 0; i < numberOfDisciplines; i++)
    {
        std::cout << "Enter grade [" <<i<<"] ";
        double parametr = getNum<double>();
        s.push_back(parametr);
    }
}*/