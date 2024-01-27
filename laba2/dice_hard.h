#ifndef DICE_HARD
#define DICE_HARD
#include <iostream>
#include <random>
#include <cmath> 


namespace  Prog22
{
    class Dice
    {
        
    private:
        int getRandomNumber();
        double sumOfArray(double* arr);
        void normalizeProbability();
        bool approximatelyEqual(double a, double b, double epsilon);
        double* createProbabilities();
    private:
        double* probabilities = new double[6] { 1.0 / 6, 1.0 / 6, 1.0 / 6, 1.0 / 6, 1.0 / 6, 1.0 / 6 };
        int value = getRandomNumber();

    public:
        friend class DiceArray;
        friend void createProbabilitiesDialog(Dice& d);
        void printArrayofProbabilities();
        void reRollDice();

        explicit  Dice(int initialValue, double* probabilities = new double[6] { 1.0 / 6, 1.0 / 6, 1.0 / 6, 1.0 / 6, 1.0 / 6, 1.0 / 6 }) :
            value(initialValue), probabilities(probabilities)
        {
            if (value < 1 || value>6)
                throw std::invalid_argument("invalid value");

            if (probabilities == nullptr)
                throw std::invalid_argument("ptr is nullptr"); //не реокмендуется null pointer кидать

            if (!approximatelyEqual(sumOfArray(probabilities), 1.0, 0.01))
                throw std::invalid_argument("probabilities!=1");
        }

        explicit Dice(double* probabilities) :
            probabilities(probabilities)
        {
            if (probabilities == nullptr)
                throw std::invalid_argument("ptr is nullptr");
            if (!approximatelyEqual(sumOfArray(probabilities), 1.0, 0.01))
                throw std::invalid_argument("probabilities!=1");
        }

        Dice() = default;
        void setDefault();
        int getValue()
        {
            return value;
        }

        void setValue(int value)
        {
            if (value < 1 || value>6)
                throw std::invalid_argument("invalid value");
            this->value = value;
        }

        const double* getProbabilities()
        {
            return probabilities;
        }

        void setProbabilities(double* arr)
        {
            if (arr == nullptr)
                throw std::invalid_argument("ptr is nullptr");
            probabilities = arr;
        }

        Dice& operator=(const Dice& dice);
        friend bool operator==(const Dice& d1, const Dice& d2);
        friend std::ostream& operator<<(std::ostream& out, const Dice& d);
        friend std::istream& operator>>(std::istream& in, Dice& d);

        ~Dice()
        {
            delete[]probabilities;
        }

    };


 class DiceArray
    {
    private:
        int size=0;
        Dice* massivOfDices = nullptr;
    public:    
       DiceArray() = default;

       explicit DiceArray(int countFairDices=0) : 
            size(countFairDices)
        {
           if (countFairDices<0)
               throw std::invalid_argument("invalid value");
            createmassivOfDices(countFairDices);
        }

       explicit DiceArray(int *arr, int countFairDices = 0) : 
           size(countFairDices)
       {
           if (countFairDices < 0)
               throw std::invalid_argument("invalid value");
           if(!arr)
               throw std::invalid_argument("ptr is nullptr");
          createmassivOfDices(countFairDices,arr);
       }
      

       DiceArray& operator=(const DiceArray& x)
       {
           
           if (this == &x)
               return *this;
           delete[]  massivOfDices;
           size = x.size;
           massivOfDices = new Dice[size];
           if (x.massivOfDices)
           {
               for (int i = 0; i < size; i++)
                   massivOfDices[i] = x.massivOfDices[i];
           }
           else
           {
               massivOfDices = nullptr;
           }
           
           return *this;
       }

       DiceArray(const DiceArray& x)
       {
           size = x.size;
           massivOfDices = new Dice[size];
           if (x.massivOfDices)
           {
               for (int i = 0; i < size; i++)
                   massivOfDices[i] = x.massivOfDices[i];
           }
           else
           {
               massivOfDices = nullptr;
           }

       }


        DiceArray& operator()();
        DiceArray& operator()(int n);
        DiceArray& operator+=(Dice& d);
        DiceArray& operator-=(int n);
         Dice& operator[](int n);
        int sumOfPoints();
        bool isDiceExist(int n);
        void createmassivOfDices(int countFairDices);
        void createmassivOfDices(int countFairDices, int* arr);
        friend std::ostream& operator<<(std::ostream& out, const DiceArray& dA);
        friend std::istream& operator>>(std::istream& in, DiceArray& dA);

        ~DiceArray()
        {
            delete[] massivOfDices;
        }

            DiceArray& operator=(DiceArray&& dA)
        {
          
            if (&dA == this)
                return *this;
            delete[] massivOfDices;
            size = dA.size;
            massivOfDices = dA.massivOfDices;
            dA.massivOfDices = nullptr;

            return *this;
        }
            DiceArray(DiceArray&& dA)
                : massivOfDices(dA.massivOfDices)
            {
                size = dA.size;
                dA.massivOfDices = nullptr;
            }


         
    };
}

template<class T> T getNum(T min = std::numeric_limits<T>::lowest(), T max = std::numeric_limits<T>::max());
int getNum(int min = std::numeric_limits<int>::lowest(), int max = std::numeric_limits<int>::max());
#endif DICE_HARD