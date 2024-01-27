
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "programm1.h"


namespace programm1 {

	template<class T>
	T getNum(T min , T max) {
		T a;
		while (true) {
			std::cin >> a;
			if (std::cin.eof()) 
				throw std::runtime_error("Failed to read number: EOF");
			else if (std::cin.bad()) 
				throw std::runtime_error(std::string("Failed to read number: ") + strerror(errno));
			else if (std::cin.fail() || a < min || a > max) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "You are wrong; repeat please!" << std::endl;
			}
			else 
				return a;
		}
	}

	void output(const char* msg, const Matrix& matrix) {
		std::cout << msg << ":\n";
		for (int i = 0; i < matrix.n; i++)
		{
			for (int j = 0; j < matrix.line[i].n; j++)
			{
				std::cout  << matrix.line[i].a[j]<<" ";
			}
			for (int k = i + 1; k < matrix.n; k++)
			{
				std::cout << matrix.line[k].a[i]<<" " ;
			}
			std::cout << std::endl;
		}	
	}

	void output(const char* msg, const Line& line) {
		std::cout << msg << ":\n";
			for (int i = 0; i < line.n; ++i)
				std::cout << line.a[i] << " ";
			std::cout << std::endl;
	}

	double count_average(const Matrix &matrix,const int i)
	{
		double average = 0;
			for (int j = 0; j < matrix.line[i].n; j++)
			{
				average += matrix.line[i].a[j];
			}
			for (int k = i+1 ; k < matrix.n; k++)
			{
				average += matrix.line[k].a[i];
			}
		average= average/matrix.n;
		return average;
	}



	// матрица симметричная, ток треугольник держим в памяти
	Line process(const Matrix& matrix)    
	{
		Line line;
		line.n = matrix.n;
		line.a = new double[line.n];
		double average = 0;
		double sum = 0;
		for (int i = 0; i < matrix.n; i++)
		{
			sum = 0;
			average = count_average(matrix,i);
			for (int j = 0; j < matrix.line[i].n; j++)
			{
				if (matrix.line[i].a[j] > average)
				{
					sum += matrix.line[i].a[j];
				}
			}
			for (int k = i+1 ; k < matrix.n; k++)
			{
				if (matrix.line[k].a[i] > average)
				{
					sum += matrix.line[k].a[i];
				}
			}
			line.a[i] = sum;
		}
		return line;
	}

	

	Matrix input() {
		Matrix matrix;
		try {
			std::cout << "Enter number of lines: ";
			matrix.n = getNum<int>(0);
			matrix.line = new Line[matrix.n];
			for (int i = 0; i < matrix.n; i++) {
				Line& line = matrix.line[i];
				line.n = i+1;
				line.a = new double[matrix.line[i].n];
				std::cout << "Enter items for matrix line #" << (i + 1) << ":" << std::endl;
				for (int j = 0; j < line.n; j++) {
					line.a[j] = getNum<double>();
				}
			}
		}
		catch (...) { 
			erase(matrix);
			throw; 
		}
		return matrix;
	}

	void erase(Matrix& matrix) {
		if (matrix.line != nullptr) {
			for (int i = 0; i < matrix.n; i++)
				erase( matrix.line[i]);
		}
		delete[] matrix.line;
		matrix.line = nullptr;
		matrix.n = 0;
	}

	void erase(Line &line) {
		line.n = 0;
		delete[]line.a;
	}
	

	
}


 
