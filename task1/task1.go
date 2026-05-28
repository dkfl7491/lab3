package main

import (
	"fmt"
	"math"
)

// Функция
func f(x float64) float64 {

	if x < -2 {
		return x*x + 1
	} else if x <= 2 {
		return math.Sin(x)
	} else {
		return math.Sqrt(x)
	}
}

func main() {

	var xStart float64
	var xEnd float64
	var dx float64

	fmt.Print("Введите X начальное: ")
	fmt.Scan(&xStart)

	fmt.Print("Введите X конечное: ")
	fmt.Scan(&xEnd)

	fmt.Print("Введите шаг: ")
	fmt.Scan(&dx)

	// Проверка шага
	if dx <= 0 {
		fmt.Println("Ошибка: шаг должен быть больше 0")
		return
	}

	fmt.Println("\n---------------------")
	fmt.Println("|    x    |    y    |")
	fmt.Println("---------------------")

	for x := xStart; x <= xEnd; x += dx {

		y := f(x)

		fmt.Printf("| %7.3f | %7.3f |\n", x, y)
	}

	fmt.Println("---------------------")
}
