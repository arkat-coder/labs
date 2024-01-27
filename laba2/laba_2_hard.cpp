#include "dice_hard.h"


int main() {

    srand(static_cast<unsigned int>(time(0)));
    rand();  // для Visual Studio
    int parametr;
    Prog22::DiceArray massivDice{ 1 };
    try
    {
        while (true)
        {
            std::cout << "1.the number of fair dice, which are filled with random values\n" <<
                "2. the number of fair dices and an array of their initial values\n" <<
                "3. print Dice Array\n" <<
                "4. Reroll all\n" <<
                "5. Reroll by number\n"
                "6. Add dice\n" << 
                "7.Take away dice\n" << 
                "8. Is exist this dice\n" << 
                "9.Sum of dices" << std::endl;
            parametr = getNum();
            try
            {
                switch (parametr)
                {
                case 1:
                {
                    std::cout << "Enter number" << std::endl;
                    int value = getNum();
                    massivDice.createmassivOfDices(value);
                }
                break;
                case 2:
                {
                    std::cin >> massivDice;
                }
                break;
                case 3:
                {
                    std::cout << massivDice<<std::endl;
                }
                break;
                case 4:
                {
                    massivDice();
                }
                break;
                case 5:
                {
                    std::cout << "Enter number" << std::endl;
                    int value = getNum();
                    massivDice(value);

                }
                
                break;
                case 6:
                {
                    Prog22:: Dice d;
                    createProbabilitiesDialog(d);
                    massivDice += d;
                    break;
                }
                case 7:
                {
                    std::cout << "Enter value of Dice" << std::endl;
                    int value = getNum();
                    massivDice -=(value);
                    break;
                }
                case 8:
                {
                    std::cout << "Enter value of Dice" << std::endl;
                    int value = getNum();
                    if (massivDice.isDiceExist(value))
                    {
                        std::cout << "Yes" << std::endl;
                        break;
                    }
                    std::cout << "No" << std::endl;
                    break;
                }
                case 9:
                {
                    std::cout <<"Sum= "<< massivDice.sumOfPoints() << std::endl;
                    break;
                }

                break;
                default:
                    std::cout << "No such command" << std::endl;
                }
            }
            catch (const std::invalid_argument)
            {
                std::cout << "Please try again" << std::endl;
                continue;
            }
            catch (const std::bad_alloc& ex)
            {
                std::cerr << "Not enough memory" << std::endl;
            }

        }
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
