package problem4

func competitiveSolution(n int) int {
	/* if n = 3, max = 999 */
	max := 0
	for i := 1; i <= n; i++ {
		max = max * 10 + 9
	}

	/* if n = 3, min = 999/10 + 1 = 100 */
	min := 1 + max / 10

	result := 0
	for i := max; i >= min; i-- {
		/* from i to min but stop as soon as i*j is less than current largest palyndrome */
		for j := i; j >= min; j-- {
			prod := i * j

			/* optional, but huge impact on performance */
			if prod < result { /* no point in computing reverse of products that won't match anyway */
				break
			}

			/* if n == reverse(n) then we have a palyndrome */

			tmp := prod
			reverse := 0
			for tmp != 0 {
				reverse = reverse * 10 + tmp % 10
				tmp /= 10
			}

			if prod == reverse && prod > result {
				result = prod
			}
		}
	}

	return result
}

/* same function but we iterate from 0 to max everytime and we don't assume that j <= i */
func unoptimizedSolution(n int) int {
	max := 0
	for i := 1; i <= n; i++ {
		max = max * 10 + 9
	}

	result := 0
	for i := 0; i <= max; i++ {
		for j := 0; j <= max; j++ {
			prod := i * j

			tmp := prod
			reverse := 0
			for tmp != 0 {
				reverse = reverse * 10 + tmp % 10
				tmp /= 10
			}

			if prod == reverse && prod > result {
				result = prod
			}
		}
	}

	return result
}
