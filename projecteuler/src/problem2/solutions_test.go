package problem2

import "testing"

func BenchmarkObviousSolution(b *testing.B) {
	for i := 0; i < b.N; i++ {
		obviousSolution(4000000)
	}
}

func BenchmarkMySolution(b *testing.B) {
	for i := 0; i < b.N; i++ {
		mySolution(4000000)
	}
}

func TestAllSolutionsAreEquivalent(t *testing.T) {
	solutions := []int{obviousSolution(4000000),
		mySolution(4000000),
		4613732}
	for idx, _ := range solutions {
		if solutions[0] != solutions[idx] {
			t.Error("Wrong result", solutions)
		}
	}
}
