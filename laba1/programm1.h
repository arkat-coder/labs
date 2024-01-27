#ifndef OOP_PROGRAMM1_H
#define OOP_PROGRAMM1_H

namespace programm1 {
 
    struct Line {
        int n = 0;
        double* a = nullptr;
    };
    struct Matrix {
        int n = 0;
        Line* line = nullptr;
    };
    Matrix input();
    Line process(const Matrix& matrix);
    template<class T> T getNum(T min = std::numeric_limits<T>::lowest(), T max = std::numeric_limits<T>::max());
     void output(const char* msg, const Matrix& matrix);
     void output(const char* msg, const Line& line);
     void erase(Matrix& matrix);
     void erase(Line& line);
     double count_average(const Matrix&matrix,const int i);

}

#endif 