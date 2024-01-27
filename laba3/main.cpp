#pragma once
#include "tableofgroup1.h"
#include "juniorStudent1.h"
#include "seniorStudent1.h"
#include "application1.h"
#define _CRT_SECURE_NO_WARNINGS

template<class T>
T getNum(T min = std::numeric_limits<T>::lowest(), T max = std::numeric_limits<T>::max()) {
    T a;
    while (true) {
        std::cin >> a;
        if (std::cin.eof())
            throw std::runtime_error("Failed to read number: EOF");
        else if (std::cin.bad())
            throw std::runtime_error(std::string("Failed to read number: "));
        else if (std::cin.fail() || a < min || a > max) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "You are wrong; repeat please!" << std::endl;
        }
        else
            return a;
    }
}

std::string getInputString() {
    std::string input;
    std::cin>>input;
    return input;
}


void getGrades (std::vector<double>& s, int numberOfDisciplines)
{
    for (int i = 0; i < numberOfDisciplines; i++)
    {
        std::cout << "Enter grade [" <<i<<"] ";
        double parametr = getNum<double>();
        s.push_back(parametr);
    }
}



int main()
{
	application a;
    TableOfGroup t1(1, 3, new juniorStudent());
    std::vector<double> s1 = { 1,2,2 };
    std::string q1 = "Stas";
    std::shared_ptr<Student> ptr1(new juniorStudent(q1, s1));
    t1.addStudent(ptr1);
    a.addGroup(t1);

   int parametr;
    try
    {
        while (true)
        {
            std::cout << "1.Student entrance\n" <<
                "2.print all\n" <<
                "3.print underperforming\n" <<
                "4.student transfer\n" <<
                "5.calculate average\n"<<
                "6.create table\n"
                "7. generate Transcript"
                "8.exit" << std::endl;

            parametr = getNum<int>();
            try
            {
                switch (parametr)
                {
                case 1:
                {
                    std::vector<double> s;
                    std::cout << "Enter index of group "<< std::endl;
                    int index = getNum<int>();
                    int numberOfDisciplines = a.getNumberOfDisciplinesOfGroup(index);
                    std::cout << "Enter name ";
                    std::string name = getInputString();
                    std::cout << " Type of student\n"
                        << "1 - junior\n"
                        << "2- senior" << std::endl;
                    parametr = getNum<int>();
                    std::shared_ptr<Student> ptr;
                    getGrades(s, numberOfDisciplines);
                    if (parametr == 1) {
                        ptr= std::make_shared<juniorStudent>(name,s);//std::shared_ptr<Student> ptr1(new juniorStudent(q1,s1));
                    }
                    else if (parametr == 2)
                    {
                        std::cout << "Enter place Erw ";
                        std::string erwPlace = getInputString();
                        std::cout << "Enter theme Erw ";
                        std::string erwTheme = getInputString();
                        std::cout << "Enter rating Erw ";
                        double rating = getNum<double>();
                        ptr=std::make_shared<seniorStudent>(name, s,rating,erwPlace,erwTheme);
                    }
                    else
                    {
                        std::cout << "Something went wrong"<<std::endl;  
                    }
                    a.entranceStudent(index, ptr);
                }
                break;
                case 2:
                {
                    a.printall();
                }
                break;
                case 3:
                {
                    std::vector <std::weak_ptr<Student>> vectorUnder;
                    a.getUnder(vectorUnder);
                    std::cout << "vector" << std::endl;
                    for (auto i : vectorUnder)
                    {
                        i.lock()->printStudent();
                    }
                }
                break;
                case 4:
                {
                    std::cout << "Enter Old indexGroup " << std::endl;
                    int OldindexGroup = getNum<int>();
                    std::cout << "Enter New indexGroup " << std::endl;
                    int NewindexGroup = getNum<int>();
                    std::cout << "Enter Position in Table" << std::endl;
                    int position  = getNum<int>();
                    std::shared_ptr<Student> ptr=a.getByGroupIndexAndPositionStudent(OldindexGroup, position);
                    a.studentTransfer(OldindexGroup, NewindexGroup,ptr);
                }
                break;
                case 5:
                {
                    std::cout << "Enter indexGroup " << std::endl;
                    int indexGroup = getNum<int>();
                   std::cout<<"Average"<< a.calculateAverageGradeInGroup(indexGroup) << std::endl;
                }
                break;
                case 6:
                {
                    std::cout << "Enter indexGroup " << std::endl;
                    int indexGroup = getNum<int>();
                    std::cout << "Enter number of Diciplines in group" << std::endl;
                    int numberOfDisciplines = getNum<int>();
                    Student* ptr=nullptr;
                    std::cout << " Type of student\n"
                        << "1 - junior\n"
                        << "2- senior" << std::endl;
                    parametr = getNum<int>();
                    if (parametr == 1)
                    {
                        ptr = new juniorStudent();
                    }
                        
                    
                    else if (parametr == 2)
                    {
                        ptr = new seniorStudent();
                    }
                     
                    else
                    {
                        std::cout << "Something went wrong" << std::endl;
                    }
                    TableOfGroup t(indexGroup,numberOfDisciplines,ptr);
                    a.addGroup(t);
                    break;
                }
                case 7:
                {
                    std::cout << "Enter indexGroup " << std::endl;
                    int indexGroup = getNum<int>();
                    a.generateTranscript(indexGroup);
                    break;
                }
                case 8:
                {
                    return 0;
                }
                break;
                default:
                    std::cout << "No such command" << std::endl;
                }
            }

            catch (const std::invalid_argument)
            {
                std::cout << "Please try again " << std::endl;
                continue;
            }

        }
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

}














/* std::vector<std::shared_ptr<Student>> copiedVector;
   copiedVector.reserve(t.getTableOfStudents().size());
   int i = 0;
   for ( auto sharedPtr : t.getTableOfStudents()) {
       copiedVector.push_back(std::make_shared<juniorStudent>(sharedPtr->getName(),sharedPtr->getRatings())); // прекрасно копируется
       //std::cout <<copiedVector[i]->getName()<<std::endl;
       i++;
   }
   TableOfGroup copy(2, 3, new juniorStudent());
   copy.tableOfStudents.reserve(t.getTableOfStudents().size()) ;
   copy.tableOfStudents = copiedVector;
   std::cout << "haha" << copy.tableOfStudents[0]->getName() << std::endl;*/