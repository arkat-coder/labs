#include "dice_hard.h"

namespace Prog22{

    int  Dice::getRandomNumber()
    {   
        double result = (float)rand() / RAND_MAX;

        double tmp = 0;
        for (int i = 0; i < 6; i++)
        {
            tmp += probabilities[i];
            if (result < tmp) return i + 1;
        }
    }

    Dice& Dice::operator=(const Dice& dice)
    {
        if (this == &dice)
            return *this;
        delete[] probabilities;
        value = dice.value;

        if (dice.probabilities)
        {
            probabilities = new double[6];
            for (int i = 0; i < 6; ++i)
                probabilities[i] = dice.probabilities[i];
        }
        else
            probabilities = nullptr;
        return *this;
    }

    void Dice::reRollDice()
    {
        value = getRandomNumber();
    }

    bool operator==(const Dice& d1, const Dice& d2)
    {
        return d1.value == d2.value;
    }
    std::ostream& operator<<(std::ostream& out, const Dice& d)
    {
        for (int i = 0; i < 5; i++)
        {
            if (i == 0 || i == 4)
            {
               out << "---------" << std::endl;
                continue;
            }
            if (i == 2)
            {
                out << "|   " << d.value << "   |" << std::endl;
                continue;
            }
            out << "|       |" << std::endl;
        }
        return out;
    }
    std::ostream& operator<<(std::ostream& out, const DiceArray& dA)
    {
        for (int i = 0; i < dA.size; i++)
        {
            out << dA.massivOfDices[i];
        }
        return out;
    }
    std::istream& operator>>(std::istream& in, DiceArray& dA)
    {
        std::cout << "Enter number" << std::endl;
        int value = getNum();
        int* arr = new int[value];
        for (int i = 0; i < value; i++)
        {
            arr[i] = getNum(1, 6);
        }
        dA.createmassivOfDices(value, arr);
        return in;
    }

    void Dice::setDefault()
    {
        delete[]probabilities;
        probabilities = new double[6] { 1.0 / 6, 1.0 / 6, 1.0 / 6, 1.0 / 6, 1.0 / 6, 1.0 / 6 };
        setProbabilities(probabilities);
    }

    double Dice::sumOfArray(double* arr)
    {
        double sum = 0;
        for (int i = 0; i < 6; i++)
        {
            sum += arr[i];
        }

        return sum;
    }

    void Dice::normalizeProbability()
    {
        double sum = sumOfArray(probabilities);
        for (int i = 0; i < 6; i++)
        {
            probabilities[i] /= sum;
        }
    }

    double* Dice::createProbabilities()
    {
        double probability;
        double* arr = new double[6];
        for (int i = 0; i < 6; i++)
        {
            probability = getNum<double>(0);
            arr[i] = probability;
        }
        return arr;
    }

    void createProbabilitiesDialog(Dice &d) {
        std::cout << "Enter Probabilities"<<std::endl;
        std::cin >> d;
        while (!d.approximatelyEqual(d.sumOfArray(d.probabilities), 1.0, 0.01))
        {
            d.normalizeProbability();
            d.printArrayofProbabilities();
            std::cout << "Do you want this probabilities?" << std::endl;
            std::cout << "1. Yes\n"
                << "2.No" << std::endl;
            int a = getNum();
            if (a == 2)
            {
                std::cout << "Enter array of probabilities" << std::endl;
                d.createProbabilities();
            }
            else if (a == 1)
            {
                break;
            }
            else {
                std::cout << "No such command" << std::endl;
            }
        }
       d. printArrayofProbabilities();
    }

    std::istream& operator>>(std::istream& in, Dice& d)
    {
        try
        {
            d.setProbabilities(d.createProbabilities());
        }
        catch (const std::bad_alloc& ex)
        {
            in.setstate(std::ios::badbit);
            return in;
        }
        return in;
    }

    bool Dice::approximatelyEqual(double a, double b, double epsilon)
    {
        return fabs(a - b) <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
    }

    void Dice::printArrayofProbabilities()
    {
        for (int i = 0; i < 6; i++)
            std::cout << probabilities[i] << " ";
        std::cout << std::endl;
    }
    void DiceArray::createmassivOfDices(int countFairDices)
    {
        if (massivOfDices != nullptr)
        {
            delete[]massivOfDices;
        }
        massivOfDices = new Dice[countFairDices];
        size = countFairDices;
        for (int i = 0; i < size; i++)
        {
            massivOfDices[i] = Dice();
        }
    }

    void DiceArray::createmassivOfDices(int countFairDices, int *arr)
    {
        if (massivOfDices != nullptr)
        {
            delete[]massivOfDices;
        }
        massivOfDices = new Dice[countFairDices];
        size = countFairDices;
        for (int i = 0; i < size; i++)
        {
            massivOfDices[i] = Dice(arr[i]);
        }
    }



    DiceArray& DiceArray::operator()()
    {
        for (int i = 0; i < size; i++)
        {
            massivOfDices[i].reRollDice();
        }
        return *this;
    }

    bool DiceArray::isDiceExist(int n)
    {
        if (n < 0 || n>6)
            throw std::invalid_argument("n is <0 or >6");
        for (int i = 0; i < size; i++)
        {
            if (massivOfDices[i].getValue() == n)
                return true;
        }
        return false;
    }

    int DiceArray::sumOfPoints()
    {
        int sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += massivOfDices[i].getValue();
        }
        return sum;
    }

    DiceArray& DiceArray::operator-=(int n)
    {
        if (n < 0 || n>6)
            throw std::invalid_argument("n is <0 or >6");

        int j = 0;

        for (int i = 0; i < size; i++)
        {
            if (massivOfDices[i].getValue() != n)
            {
                massivOfDices[i - j] = massivOfDices[i];
            }
            else
            {
                j++;
            }
        }
        Dice* tmp = new Dice[size - j];
        size -= j;
        for (int i = 0; i < size; i++)
        {
            tmp[i] = massivOfDices[i];
        }
        delete[] massivOfDices;
        massivOfDices = tmp;
        return *this;
    }

    DiceArray& DiceArray::operator()(int n)
    {
        (*this)[n].reRollDice();
        return *this;
    }

     Dice& DiceArray::operator[](int n)
    {
        if (n < 0)
            throw std::invalid_argument("n is <0");
        if (n >=size)
            throw std::invalid_argument("n is >=size");
        return massivOfDices[n];
    }

    DiceArray& DiceArray::operator+=(Dice& d)
    {
        if (&d == nullptr)
        {
            throw std::invalid_argument("nullptr");// обычно рекомундуется nullpointer не кидать вручную
        }
        Dice* tmp = new Dice[++size];
        for (int i = 0; i < size - 1; i++)
        {
            tmp[i] = massivOfDices[i];
        }
        tmp[size - 1] = d;
        massivOfDices = tmp;
        return *this;
    }
}

template<class T>
T getNum(T min, T max) {
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

int getNum(int min,int max) { //  для свича
    int a;
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



