package main

const (
	INT32_MIN_DIV10 = -214748364
	INT32_MAX_DIV10 = 214748364
)

func reverse(x int) int {
	var result int
	var sign = 1

	if x < 0 {
		sign = -1
		x *= -1
	}

	for x > 0 {
		if sign == 1 && result > INT32_MAX_DIV10 {
			return 0
		}

		if sign == -1 && -result < INT32_MIN_DIV10 {
			return 0
		}
		result *= 10
		result += x % 10
		x /= 10
	}

	return result * sign
}
