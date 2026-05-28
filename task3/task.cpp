#include <iostream>
#include <numeric>

using namespace std;

long long power(long long a, long long b)
{
    long long result = 1;

    for (long long i = 0; i < b; i++)
        result *= a;

    return result;
}

int main()
{
    int a, b;
    cin >> a >> b;

    // Если ряд расходится
    if (b == 1)
    {
        cout << "infinity";
        return 0;
    }

    // Формулы для первых степеней
    long long numerator = 0;
    long long denominator = 1;

    if (a == 1)
    {
        numerator = b;
        denominator = (b - 1) * (b - 1);
    }
    else if (a == 2)
    {
        numerator = b * (b + 1);
        denominator = power(b - 1, 3);
    }
    else if (a == 3)
    {
        numerator = b * (b * b + 4 * b + 1);
        denominator = power(b - 1, 4);
    }

    long long g = gcd(numerator, denominator);

    numerator /= g;
    denominator /= g;

    cout << numerator << "/" << denominator;

    return 0;
}
