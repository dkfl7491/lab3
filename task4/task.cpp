#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int pavel = 0;
    int vika = 0;

    int pos = 0;

    // Предыдущие ходы игроков
    int prevPavel = -1;
    int prevVika = -1;

    bool pavelTurn = true;

    while (pos < n)
    {
        int bestSum = -1000000000;
        int bestCount = 1;

        int currentSum = 0;

        for (int k = 1; k <= m && pos + k <= n; k++)
        {
            // Проверка ограничения
            if (pavelTurn && k == prevPavel)
                continue;

            if (!pavelTurn && k == prevVika)
                continue;

            currentSum += a[pos + k - 1];

            // Выбираем максимальную сумму
            // При равенстве — минимальное количество
            if (currentSum > bestSum)
            {
                bestSum = currentSum;
                bestCount = k;
            }
        }

        currentSum = 0;

        for (int i = 0; i < bestCount; i++)
        {
            currentSum += a[pos];
            pos++;
        }

        if (pavelTurn)
        {
            pavel += currentSum;
            prevPavel = bestCount;
        }
        else
        {
            vika += currentSum;
            prevVika = bestCount;
        }

        pavelTurn = !pavelTurn;
    }

    if (pavel > vika)
        cout << 1 << endl;
    else
        cout << 0 << endl;

      cout << endl;

    return 0;
}
