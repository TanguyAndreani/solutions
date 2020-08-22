/*
 * Runtime: 4 ms, faster than 99.45% of Go online submissions for Find First and Last Position of Element in Sorted Array.
 * Memory Usage: 4.1 MB, less than 99.73% of Go online submissions for Find First and Last Position of Element in Sorted Array.
 *
 * Complexity should be about O(log(n) + k), we do a binary search to find target in nums[], then we go one step for each occurence of target in nums[]
 */

package searchrange

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

	result[0] = i

	for j < len(nums)-1 && nums[j+1] == target {
		j++
	}

	result[1] = j

	return result
}
