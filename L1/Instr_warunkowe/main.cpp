#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    char znak;
    do {
        std::cout << "Czy chcesz kontynuowac? (t/n) ";
        znak = getchar();
    } while (!(znak == 't' || znak == 'T' || znak == 'n' || znak == 'N'));

    //    for (; warunek;){
    //    std::fstream str("plik.txt", std::ios::in);
    //    while (!str.eof()) {
    //        int zmienna;
    //        str >> zmienna;
    //        cout << zmienna;
    //    }

    return 0;
}
