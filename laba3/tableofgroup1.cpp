#pragma once
#include "tableofgroup1.h"

 void TableOfGroup::addStudent(const std::shared_ptr<Student>& student) //throw invalid size
 {
        auto it = std::lower_bound(tableOfStudents.begin(), tableOfStudents.end(), student,
            [](const std::shared_ptr<Student>& a, const std::shared_ptr<Student>& b) {
                return a->getName() < b->getName();
            });

       tableOfStudents.insert(it, student);
 }

 int TableOfGroup::getgroupIndex() const
 {
     return groupIndex;
 }

 int    TableOfGroup::getNumberOfDisciplines() const
 {
     return numberofDisciplines;
 }

 void TableOfGroup::deleteStudent(std::shared_ptr<Student>& student)
 {
     auto it = std::remove_if(tableOfStudents.begin(), tableOfStudents.end(),
         [student](const std::shared_ptr<Student>& s) {
             return s == student;
         });

     tableOfStudents.erase(it, tableOfStudents.end());
 } 


 TableOfGroup::TableOfGroup(int groupIndex, int numberofDisciplines, Student* typeOfGroup) :
 groupIndex(groupIndex), numberofDisciplines(numberofDisciplines)

 {
         seniorStudent * a= dynamic_cast<seniorStudent*>(typeOfGroup);
        juniorStudent* b=dynamic_cast<juniorStudent*>(typeOfGroup);
        if (a == nullptr && b == nullptr)
            throw std::invalid_argument(" typeofgroup is not correct");
        if (a)
            this->typeOfGroup = new seniorStudent();
        if (b)
            this->typeOfGroup = new juniorStudent();
 }


  Student* TableOfGroup::getTypeOfGroup() const
 {
    return typeOfGroup;
 }

 void TableOfGroup::printTable() const    
 {
     std::cout << "----------------------------------------" << std::endl;
     //std::cout << "push" << std::endl;
      for (auto i : tableOfStudents)
         {
          i->printStudent();
         }

     std::cout << "----------------------------------------"<<std::endl;
 }

 

 const std::vector<std::shared_ptr<Student>>& TableOfGroup::getTableOfStudents() const
 {
     return tableOfStudents;
 }

 int countTwos(std::weak_ptr<Student >& Student) {
     // Подсчет количества двоек в векторе ratings

     return std::count_if(Student.lock()->getRatings().begin(), Student.lock()->getRatings().end(), [](double rating) {
         return rating <= 2;
         });
 }

 std::vector < std::weak_ptr<Student>>& TableOfGroup::getUnderPerformingStudents(std::vector <std::weak_ptr<Student>>& vectorUnder) const
 {
     for (auto& i : tableOfStudents)
     {
         std::weak_ptr<Student> weakPtr=i;
         if (countTwos(weakPtr) >= 3)
         {
             vectorUnder.push_back(weakPtr);
         }
     }
     return vectorUnder;
 }


 TableOfGroup::TableOfGroup(const TableOfGroup& T)
 {
     Student* copy = T.getTypeOfGroup();

     tableOfStudents = T.tableOfStudents;
     groupIndex = T.getgroupIndex();
     this->typeOfGroup = T.getTypeOfGroup()->cloneStudent();
     numberofDisciplines = T.getNumberOfDisciplines();


 }
 
 TableOfGroup ::~TableOfGroup()
 {
     tableOfStudents.clear();
     delete[] typeOfGroup;
 }





 /*     seniorStudent* a = dynamic_cast<seniorStudent*>(copy);
     juniorStudent* b = dynamic_cast<juniorStudent*>(copy);
     
          if (a)
         this->typeOfGroup = new seniorStudent();
     if (b)
         this->typeOfGroup = new juniorStudent();*/