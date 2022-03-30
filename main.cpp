
#include "Beer.cpp"
int main()
{
    //program stops after second object
    Beer beer1("Stella Artois", 500);
    beer1.printBeer();
    Beer beer2("Heineken", 500);
    beer2.printBeer();
    beer1.addBeer(beer2, 250);
    beer1.printBeer();
}