#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double f(double x)
{
    if (x < -4)
    {
        // Левая ветка
        return -sqrt(-x - 4);
    }
    else if (x <= 4)
    {
        // Средняя часть
        return -sin(M_PI * x / 4.0);
    }
    else
    {
        // Правая ветка
        return sqrt(x - 4) + 1;
    }
}

int main()
{
    double xStart = -6;
    double xEnd = 6;
    double dx = 0.5;

    cout << fixed << setprecision(3);

    cout << "---------------------\n";
    cout << "|    x    |    y    |\n";
    cout << "---------------------\n";

    for (double x = xStart; x <= xEnd; x += dx)
    {
        cout << "| "
             << setw(7) << x
             << " | "
             << setw(7) << f(x)
             << " |\n";
    }

    cout << "---------------------\n";

    return 0;
}
