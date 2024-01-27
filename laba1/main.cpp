#include <iostream>
#include "programm1.h"
using namespace programm1;

int main() {
	Matrix matrix;
	Line line;
	try {
		matrix =input ();
		line = process(matrix);
		output("Sourced matrix",matrix);
		output("Result",line);
		erase(matrix); 
		erase(line);
	}
	catch (const std::bad_alloc& ba) { 
		std::cerr << "Not enough memory" << std::endl;
		erase(matrix);
		erase(line);
		return 1;
	}
	catch (const std::exception& e) { 
		std::cerr << e.what() << std::endl;
		erase(matrix);
		erase(line);
		return 1;
	}
	return 0;
}