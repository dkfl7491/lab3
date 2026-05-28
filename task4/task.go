package main

import (
	"fmt"
)

func main() {

	var n, m int

	fmt.Scan(&n, &m)

	a := make([]int, n)

	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	pavel := 0
	vika := 0

	pos := 0

	// Предыдущие ходы игроков
	prevPavel := -1
	prevVika := -1

	pavelTurn := true

	for pos < n {

		bestSum := -1000000000
		bestCount := 1

		currentSum := 0

		for k := 1; k <= m && pos+k <= n; k++ {

			// Проверка ограничения
			if pavelTurn && k == prevPavel {
				continue
			}

			if !pavelTurn && k == prevVika {
				continue
			}

			currentSum += a[pos+k-1]

			// Выбор максимальной суммы
			if currentSum > bestSum {
				bestSum = currentSum
				bestCount = k
			}
		}

		currentSum = 0

		for i := 0; i < bestCount; i++ {
			currentSum += a[pos]
			pos++
		}

		if pavelTurn {
			pavel += currentSum
			prevPavel = bestCount
		} else {
			vika += currentSum
			prevVika = bestCount
		}

		pavelTurn = !pavelTurn
	}

	if pavel > vika {
		fmt.Println(1)
	} else {
		fmt.Println(0)
	}
	
	fmt.Println()
}
