package problem2

func obviousSolution(n int) int {
	n1 := 1
	n2 := 2

	sum := 2

	for n1 < n {
		n1 = n1 + n2
		n2 = n1 + n2

		if n1 % 2 == 0 {
			sum += n1
		}

		if n2 % 2 == 0 {
			sum += n2
		}
	}
	return sum
}

func mySolution(n int) int {
	n1 := 0
	n2 := 1

	sum := 0

	for n1 < n {
		old_n1 := n1
		sum += n1
		n1 = n1 + n2 * 2
		n2 = n1 + n2 + old_n1
	}

	return sum
}
