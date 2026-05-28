package main

import (
	"fmt"
	"math"
)

func f(x float64) float64 {

	if x < -4 {
		// Левая ветка
		return -math.Sqrt(-x - 4)
	} else if x <= 4 {
		// Средняя часть
		return -math.Sin(math.Pi * x / 4.0)
	} else {
		// Правая ветка
		return math.Sqrt(x-4) + 1
	}
}

func main() {

	xStart := -6.0
	xEnd := 6.0
	dx := 0.5

	fmt.Println("---------------------")
	fmt.Println("|    x    |    y    |")
	fmt.Println("---------------------")

	for x := xStart; x <= xEnd; x += dx {

		fmt.Printf("| %7.3f | %7.3f |\n",
			x,
			f(x))
	}

	fmt.Println("---------------------")
}
