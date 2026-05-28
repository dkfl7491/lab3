#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Функция
double f(double x)
{
    if (x < -2)
        return x * x + 1;
    else if (x <= 2)
        return sin(x);
    else
        return sqrt(x);
}

int main()
{
    double xStart;
    double xEnd;
    double dx;

    cout << "Введите X начальное: ";
    cin >> xStart;

    cout << "Введите X конечное: ";
    cin >> xEnd;

    cout << "Введите шаг: ";
    cin >> dx;

    // Проверка шага
    if (dx <= 0)
    {
        cout << "Ошибка: шаг должен быть больше 0";

        return 0;
    }

    cout << fixed << setprecision(3);

    cout << "\n---------------------\n";
    cout << "|    x    |    y    |\n";
    cout << "---------------------\n";

    for (double x = xStart; x <= xEnd; x += dx)
    {
        double y = f(x);

        cout << "| "
             << setw(7) << x
             << " | "
             << setw(7) << y
             << " |\n";
    }

    cout << "---------------------\n";

    return 0;
}
