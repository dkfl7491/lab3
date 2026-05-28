package main

import (
	"fmt"
	"math"
)

func f(x float64) float64 {

	if x < -4 {

		// Левая ветка графика
		return -math.Sqrt(-x-4) - 1

	} else if x <= 4 {

		// Средняя часть графика
		return -math.Sin(math.Pi * x / 4.0)

	} else {

		// Правая ветка графика
		return math.Sqrt(x-4) + 1
	}
}

func main() {

	var xStart, xEnd, dx float64

	fmt.Print("Введите начало интервала: ")
	fmt.Scan(&xStart)

	fmt.Print("Введите конец интервала: ")
	fmt.Scan(&xEnd)

	fmt.Print("Введите шаг: ")
	fmt.Scan(&dx)

	fmt.Println("\n---------------------")
	fmt.Println("|    x    |    y    |")
	fmt.Println("---------------------")

	for x := xStart; x <= xEnd; x += dx {

		fmt.Printf("| %7.3f | %7.3f |\n",
			x,
			f(x))
	}

	fmt.Println("---------------------")
}
