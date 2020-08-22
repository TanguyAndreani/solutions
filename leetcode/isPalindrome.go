package leetcode

func isPalindrome(x int) bool {
	if x < 0 {
		return false
	}

	tmp := x
	rev := 0
	for tmp != 0 {
		rev = rev*10 + tmp%10
		tmp /= 10
	}

	if x != rev {
		return false
	}

	return true
}
