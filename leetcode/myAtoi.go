package leetcode

func isNumerical(b byte) bool {
	return b >= '0' && b <= '9'
}

func myAtoi(str string) int {
	result := 0
	sign := 1
	idx := 0

	if len(str) == 0 {
		return 0
	}

	for idx < len(str) && str[idx] == ' ' {
		idx++
	}

	if idx < len(str) && (str[idx] == '-' || str[idx] == '+') {
		if str[idx] == '-' {
			sign = -1
		}
		idx++
	}

	for idx < len(str) && isNumerical(str[idx]) {
		n := int(str[idx] - '0')

		if sign == 1 && result > (2147483647-n)/10 {
			return 2147483647
		}

		if sign == -1 && -result < (-2147483648+n)/10 {
			return -2147483648
		}

		result *= 10
		result += n

		idx++
	}

	return result * sign
}
