#include <iostream>
#include <vector>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

// Быстрое возведение в степень по модулю
long long modPow(long long a, long long power, long long mod)
{
    long long result = 1;

    while (power > 0)
    {
        if (power % 2 == 1)
            result = (result * a) % mod;

        a = (a * a) % mod;
        power /= 2;
    }

    return result;
}

// Разложение числа на простые множители
vector<long long> factorize(long long n)
{
    vector<long long> factors;

    for (long long i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            factors.push_back(i);

            while (n % i == 0)
                n /= i;
        }
    }

    if (n > 1)
        factors.push_back(n);

    return factors;
}

// Тест Миллера
bool millerTest(long long n, int checks)
{
    if (n < 2)
        return false;

    if (n % 2 == 0 && n != 2)
        return false;

    vector<long long> factors = factorize(n - 1);

    for (int i = 0; i < checks; i++)
    {
        long long a = 2 + rand() % (n - 3);

        // Проверка по малой теореме Ферма
        if (modPow(a, n - 1, n) != 1)
            return false;

        bool ok = false;

        for (long long q : factors)
        {
            if (modPow(a, (n - 1) / q, n) != 1)
            {
                ok = true;
                break;
            }
        }

        if (!ok)
            return false;
    }

    return true;
}

// Генерация нечётного числа
long long generateCandidate(long long start, long long end)
{
    long long candidate =
        start + rand() % (end - start);

    // Делаем число нечётным
    candidate |= 1;

    return candidate;
}

int main()
{
    srand(time(0));

    int bits;

    cout << "Введите разрядность числа (bits): ";
    cin >> bits;

    // Проверка корректности
    if (bits < 2 || bits > 30)
    {
        cout << "Ошибка: некорректная разрядность";

        return 0;
    }

    long long start = 1LL << (bits - 1);
    long long end = (1LL << bits) - 1;

    cout << "\n";

    cout << "------------------------------------------------\n";
    cout << "| №  | Число | Результат | Rejected attempts |\n";
    cout << "------------------------------------------------\n";

    for (int i = 1; i <= 10; i++)
    {
        long long candidate;

        // rejected отдельно для каждого числа
        int rejected = 0;

        while (true)
        {
            candidate = generateCandidate(start, end);

            if (millerTest(candidate, 5))
                break;

            rejected++;
        }

        cout << "| "
             << setw(2) << i
             << " | "
             << setw(6) << candidate
             << " | "
             << setw(9) << "true"
             << " | "
             << setw(17) << rejected
             << " |\n";
    }

    cout << "------------------------------------------------\n";

    return 0;
}
