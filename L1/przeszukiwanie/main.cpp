#include <cmath>
#include <iostream>
#include <vector>
//using namespace std;

long long silnia_rec(long long N);
long long silnia_itr(long long N);
double pi(double prec);
bool pierwsza(int N);
void srednia_ocen();
void minimum();

int main()
{
    //ALGRYTMY PRZESZUKIWANIA
    minimum();
    pierwsza(1534);

    //ALGRYTMY AKUMULACJI
    srednia_ocen();

    std::cout << "Wartosc pi: " << pi(0.0001) << std::endl;

    std::cout << "Wartosc silni: " << silnia_rec(5) << std::endl;

    std::cout << "Wartosc silni: " << silnia_itr(5) << std::endl;

    return 0;
}

long long silnia_rec(long long N)
{
    if (N == 0)
        return 1;
    return N * silnia_rec(N - 1);
}

long long silnia_itr(long long N)
{
    long long acc = 1;

    for (int i = 1; i <= N; i++) {
        acc *= i;
    }
    return acc;
}

double pi(double prec)
{
    double acc = 0;
    //    int N = 100000;
    int i = 1;
    double delta;
    do {
        delta = pow(-1, i - 1) / (2 * i - 1);
        acc += delta;
        i++;
    } while (fabs(delta) > prec);

    return acc * 4;
}
void srednia_ocen()
{
    std::vector<double> oceny = {2, 3.5, 5, 2, 4, 3};
    double acc = 0;

    for (size_t i = 0; i < oceny.size(); i++) {
        acc += oceny[i];
    }
    std::cout << "Wartosc srednia ocen:" << acc / oceny.size() << std::endl;
}

bool pierwsza(int N)
{
    bool czy_pierwsza = true;

    for (int i = 2; i <= ceil(sqrt(N)); i++) {
        if (!(N % i)) {
            czy_pierwsza = false;
            break;
        }
    }
    if (czy_pierwsza) {
        std::cout << N << " jest pierwsza" << std::endl;
    } else {
        std::cout << N << " nie jest pierwsza" << std::endl;
    }
    return czy_pierwsza;
}

void minimum()
{
    std::vector<double> values = {1, 5, -10, 12, 15};
    double min = values[0];

    for (size_t i = 0; i < values.size(); i++) {
        if (values[i] < min)
            min = values[i];
    }

    std::cout << "Minimum zbioru wynosi: " << min << std::endl;
}
