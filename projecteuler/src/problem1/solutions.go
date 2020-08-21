package problem1

/* The most obvious solution */

func obviousSolution(n int) int {
	sum := 0
	for i := 0; i < n; i++ {
		if i%3 == 0 || i%5 == 0 {
			sum += i
		}
	}
	return sum
}

/* The solution I came up with, I just tried to get read of as many modulos */

func mySolution(n int) int {
	sum := 0
	for i := 0; i < n; i += 3 {
		sum += i
	}

	for i := 0; i < n; i += 5 {
		if i%3 != 0 {
			sum += i
		}
	}

	return sum
}

/* The optimal solution */

func sumUpto(n int) int {
	return (n * (n + 1)) / 2
}

func sumOfMultiplesBelow(mod int, n int) int {
	return mod * sumUpto(n/mod)
}

func bestSolution(n int) int {
	n = n - 1
	return sumOfMultiplesBelow(3, n) + sumOfMultiplesBelow(5, n) - sumOfMultiplesBelow(15, n)
}
