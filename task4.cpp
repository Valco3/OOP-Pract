#include <iostream>

struct Doctor 
{
    char lastName[32];
    int yearsWorkExperience;
    char hospitalName[32];
    char gender[8];

    void print() const 
    {
        std::cout << "Last name: " << lastName << std::endl;
        std::cout << "Work experience: " << yearsWorkExperience << " years" << std::endl;
        std::cout << "Hospital name: " << hospitalName << std::endl;
        std::cout << "Gender: " << gender << std::endl;
    }

    void changeLastName(Doctor& doctor) 
    {
        std::cout << "Input new last name for doctor " << doctor.lastName << " : ";
        std::cin.getline(doctor.lastName, 32);    
    }

    void changeHospitalName(Doctor& doctor)
    {
        std::cout << "Input new workplace for doctor " << doctor.lastName << " : ";
        std::cin.getline(doctor.hospitalName, 32);
    }
};

int main()
{
    Doctor doctors[2];
    for(int i = 0; i < 2; i++)
    {
        std::cout<<"Input doctor's last name: ";
        std::cin.getline(doctors[i].lastName, 32);
        std::cout << "Input doctor's work experience(in years): ";
        std::cin >> doctors[i].yearsWorkExperience;
        std::cin.ignore();
        std::cout << "Input doctor's workplace name(name of hospital): ";
        std::cin.getline(doctors[i].hospitalName, 32);
        std::cout << "Input doctor's gender: ";
        std::cin.getline(doctors[i].gender, 8);
        std::cout<< std::endl;
    }

    doctors[0].changeLastName(doctors[0]);
    std::cout << std::endl;

    doctors[1].changeHospitalName(doctors[1]);
    std::cout << std::endl;

    for(int i = 0; i < 2; i++)
    {
        doctors[i].print();
        std::cout<<std::endl;
    }
}