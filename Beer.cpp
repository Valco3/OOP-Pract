#include "Beer.h"

void Beer::erase(){
    delete[] this->name;
}

void Beer::copy(const Beer& other){
    setName(other.name);
    setSize(other.size);
}


const char* Beer::getName() const {
    return this->name;
}

int Beer::getSize() const {
    return this->size;
}

void Beer::setName(const char *name) {
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

void Beer::setSize(int size){
    this->size=size;
}

Beer::Beer() {
    setName("");
    setSize(0);
}

Beer::Beer(const char *name, const int size)
{
    setName(name);
    setSize(size);
}

Beer::Beer(const Beer& other)
{
    this->copy(other);
}

Beer &Beer::operator=(const Beer& other){
    if(this != &other){
        this->erase();
        this->copy(other);
    }
    return *this;
}

Beer::~Beer(){
    erase();
}

void Beer::printBeer() const {
    std::cout<<"The name of the beer is : " << name << std::endl;
    std::cout<<"The size of the beer is : " << size << std::endl;
}


void Beer::addBeer(Beer& other, const int amount) {
    char *tempName = new char[strlen(this->name) + strlen(other.name) + 1];
    strcpy(tempName, this->name);
    strcat(tempName, "&");
    strcat(tempName, other.name);

    delete[] this->name;

    this->name = new char[strlen(tempName) + 1];
    strcpy(name, tempName);
    delete[] tempName;

    this->size += amount;
    other.setSize(other.size - amount);
}