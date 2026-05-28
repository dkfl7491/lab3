package main

import (
	"fmt"
)

// Функция возведения в степень
func power(a, b int64) int64 {

	result := int64(1)

	for i := int64(0); i < b; i++ {
		result *= a
	}

	return result
}

// Функция нахождения НОД
func gcd(a, b int64) int64 {

	for b != 0 {
		a, b = b, a%b
	}

	return a
}

func main() {

	var a, b int64

	// Ввод параметров
	fmt.Print("Введите a и b: ")
	fmt.Scan(&a, &b)

	// Если b = 1, ряд расходится
	if b == 1 {
		fmt.Print("infinity\n\n")
		return
	}

	var numerator int64
	var denominator int64

	// Формула для a = 1
	if a == 1 {

		numerator = b
		denominator = (b - 1) * (b - 1)

	} else if a == 2 {

		// Формула для a = 2
		numerator = b * (b + 1)
		denominator = power(b-1, 3)

	} else if a == 3 {

		// Формула для a = 3
		numerator = b * (b*b + 4*b + 1)
		denominator = power(b-1, 4)
	}

	// Нахождение НОД
	g := gcd(numerator, denominator)

	// Сокращение дроби
	numerator /= g
	denominator /= g

	// Вывод результата
	fmt.Printf("%d/%d\n\n", numerator, denominator)
}
