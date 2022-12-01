#include <stdio.h>
#include <iostream>
#include <filesystem>
#include <vector>
#include <string>
#include <fstream>

class elf
{
private:
    int _total_calories;

public:
    // Initialisation Constructor
    elf() : _total_calories(0)
    {
    }
    // Deep Copy Constructor
    elf(const elf& t)
    {
        this->_total_calories = t._total_calories;
    }
    void add_calorie(int cal)
    {
        _total_calories += cal;
    }

    int total_calories(void)
    {
        return _total_calories;
    }
};

int main(void)
{

    std::ifstream ReadInput;

    ReadInput.open("./inputs/input.txt");
    if (!ReadInput.good())
    {
        std::cout << "Unable to open text file" << std::endl;
        return -1;
    }

    std::string buff;
    std::vector<elf> all_elves;
    elf* this_elf = new elf();
    while (std::getline(ReadInput, buff))
    {
        try {
            this_elf->add_calorie(std::stoi(buff));
        }
        catch (std::exception& e)
        {
            all_elves.push_back(*this_elf);
            delete (this_elf);
            this_elf = new elf();
        }
    }
    //Close out file
    ReadInput.close();
    // Memory cleanup
    delete (this_elf);

    // Find highest value;
    int elf_number = 0;
    int highest_calories = 0;
    for (unsigned int i = 0; i < all_elves.size(); i++)
    {
        if (all_elves[i].total_calories() > highest_calories)
        {
            highest_calories = all_elves[i].total_calories();
            elf_number = i;
        }
    }

    std::cout << "Elf with the highest calories: " << elf_number << std::endl;
    std::cout << "Highest calorie count: " << highest_calories << std::endl;

}