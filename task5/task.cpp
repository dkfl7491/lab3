#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double coffeeTemp;
    double roomTemp;
    double r;
    double dt;
    int timeMinutes;

    cout << "Начальная температура кофе: ";
    cin >> coffeeTemp;

    cout << "Температура окружающей среды: ";
    cin >> roomTemp;

    cout << "Коэффициент охлаждения: ";
    cin >> r;

    cout << "Шаг времени (мин): ";
    cin >> dt;

    cout << "Время моделирования (мин): ";
    cin >> timeMinutes;

    double currentTime = 0;

    cout << fixed << setprecision(2);

    cout << "\n+--------------+------------------+\n";
    cout << "| Время (мин) | Температура (C) |\n";
    cout << "+--------------+------------------+\n";

    while (currentTime <= timeMinutes)
    {
        cout << "| "
             << setw(11) << currentTime
             << " | "
             << setw(16) << coffeeTemp
             << " |\n";

        // Закон охлаждения Ньютона
        coffeeTemp = coffeeTemp -
                     r * (coffeeTemp - roomTemp) * dt;

        currentTime += dt;
    }

    cout << "+--------------+------------------+\n";

    cout << endl;

    return 0;
}
