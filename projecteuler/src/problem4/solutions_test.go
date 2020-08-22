package problem4

import "testing"

func BenchmarkCompetitiveSolution(b *testing.B) {
	for i := 0; i < b.N; i++ {
		competitiveSolution(3)
	}
}

func BenchmarkUnoptimizedSolution(b *testing.B) {
	for i := 0; i < b.N; i++ {
		unoptimizedSolution(3)
	}
}

func TestAllSolutionsAreEquivalent(t *testing.T) {
	solutions := []int{competitiveSolution(3),
		unoptimizedSolution(3),
		906609}
	for idx, _ := range solutions {
		if solutions[0] != solutions[idx] {
			t.Error("Wrong result", solutions)
		}
	}
}
