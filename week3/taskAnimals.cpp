#include <iostream>
#include <fstream>

enum TypeOfAnimal
{
    Dummy = 0,
    Dog,
    Cat,
    Rabbit
};

enum Gender
{
    D = 0,
    Male,
    Female
};

struct Animal
{
    TypeOfAnimal type;
    char name[32];
    int age;
    Gender gender;

    void createAnimal()
    {
        int userInputForType;
        char userInputForGender;
        std::cout << "Choose the type of animal (1 -dog, 2-cat, 3-rabbit) : ";
        std::cin >> userInputForType;
        type = getTypeOfAnimal(userInputForType);
        std::cout << "Enter the name of the animal: ";
        std::cin.ignore();
        std::cin.getline(name, 32);
        std::cout << "Enter the age of the animal: ";
        std::cin >> age;
        std::cout << "Enter the gender of the animal (M - Male, F - Female) : ";
        std::cin.ignore();
        std::cin >> userInputForGender;
        gender = getGenderOfAnimal(userInputForGender);
    }

    TypeOfAnimal getTypeOfAnimal(int userInputForType)
    {
        switch(userInputForType)
        {
            case 1:
                return Dog;
            case 2:
                return Cat;
            case 3:
                return Rabbit;
            default:
                return Dummy;
        }
    }
     Gender getGenderOfAnimal(char userInputForGender)
        {
            switch(userInputForGender)
            {
                case 'M':
                    return Male;
                case 'F':
                    return Female;
                default:
                    return D;
            }
        }
    void writeInFile(std::ofstream &file)
    {
        file.open("animal.txt", std::ios::binary);
        file.write((char*) &type, sizeof(type));
        file.close();
    }

    void readFromFile(std::ifstream &file)
    {
        file.open("animal.txt", std::ios::binary);
        file.read((char*) &type, sizeof(type));
        std::cout << (TypeOfAnimal)type << " ";
        file.read((char*) &name, sizeof(name));
        std::cout << name << " ";
        file.read((char*) &age, sizeof(age));
        std::cout << age << " ";
        file.read((char*) &gender, sizeof(gender));
        std::cout << (Gender)gender << " ";
        file.close();
    }
};

int main()
{
    std::ofstream outFile;
    std::ifstream inFile;
    Animal animal1;
    animal1.createAnimal();
    animal1.writeInFile(outFile);
    animal1.readFromFile(inFile);
}
