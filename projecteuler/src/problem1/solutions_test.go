package problem1

import "testing"

func BenchmarkObviousSolution(b *testing.B) {
	for i := 0; i < b.N; i++ {
		obviousSolution(1000)
	}
}

func BenchmarkMySolution(b *testing.B) {
	for i := 0; i < b.N; i++ {
		mySolution(1000)
	}
}

func BenchmarkBestSolution(b *testing.B) {
	for i := 0; i < b.N; i++ {
		bestSolution(1000)
	}
}

func TestAllSolutionsAreEquivalent(t *testing.T) {
	solutions := []int{obviousSolution(1000),
		bestSolution(1000),
		mySolution(1000),
		233168}
	for idx, _ := range solutions {
		if solutions[0] != solutions[idx] {
			t.Error("Wrong result", solutions)
		}
	}
}
