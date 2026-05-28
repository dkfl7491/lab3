#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double f(double x)
{
    if (x < -4)
    {
        // Левая ветка графика
        return -sqrt(-x - 4) - 1;
    }
    else if (x <= 4)
    {
        // Средняя часть графика
        return -sin(M_PI * x / 4.0);
    }
    else
    {
        // Правая ветка графика
        return sqrt(x - 4) + 1;
    }
}

int main()
{
    double xStart, xEnd, dx;

    cout << "Введите начало интервала: ";
    cin >> xStart;

    cout << "Введите конец интервала: ";
    cin >> xEnd;

    cout << "Введите шаг: ";
    cin >> dx;

    cout << fixed << setprecision(3);

    cout << "\n---------------------\n";
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
