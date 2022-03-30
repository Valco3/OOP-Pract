#ifndef BEER_H
#define BEER_H

#include <iostream>
#include <cstring>

class Beer
{
private:
    char *name;
    int size;

    void erase();
    void copy(const Beer& other);
public:
    const char *getName() const;
    int getSize() const;

    void setName(const char *name);
    void setSize(int size);

    Beer();
    Beer(const char *, const int );
    Beer(const Beer& other);
    Beer &operator=(const Beer& other);
    ~Beer();

    void printBeer() const;

      void addBeer(Beer& other, const int amount);
};
#endif 
