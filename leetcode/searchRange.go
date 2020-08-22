/*
 * Complexity should be about O(log(n) + k), we do a binary search to find target in nums[], then we go one step for each occurence of target in nums[]
 */

package leetcode

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func searchRange(nums []int, target int) []int {
	i := len(nums) / 2

	result := []int{-1, -1}

	if len(nums) == 0 {
		return result
	}

	old_n := nums[i]
	g := max(i/2, 1)

	for {
		if nums[i] < target {
			i = i + g
		} else if nums[i] > target {
			i = i - g
		} else {
			break
		}

		if i < 0 || i > len(nums)-1 {
			return result
		}

		/* when we reach the point when steps can't be smaller, coming across two numbers
		respectively greater than and less than target means that we won't find target in nums[] */
		if g == 1 && ((old_n < target && target < nums[i]) || (old_n > target && target > nums[i])) {
			return result
		}

		g = max(g/2, 1)

		old_n = nums[i]
	}

	j := i

	for i > 0 && nums[i-1] == target {
		i--
	}

	for j < len(nums)-1 && nums[j+1] == target {
		j++
	}

	result[0] = i
	result[1] = j

	return result
}
