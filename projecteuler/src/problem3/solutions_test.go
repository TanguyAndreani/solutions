package problem3

import "testing"

func TestAllSolutionsAreEquivalent(t *testing.T) {
	solutions := []int{killmeSolution(600851475143),
		competitiveSolution(600851475143),
		6857}
	for idx, _ := range solutions {
		if solutions[0] != solutions[idx] {
			t.Error("Wrong result", solutions)
		}
	}
}

func BenchmarkKillmeSolution(b *testing.B) {
	for i := 0; i < b.N; i++ {
		killmeSolution(600851475143)
	}
}

func BenchmarkCompetitiveSolution(b *testing.B) {
	for i := 0; i < b.N; i++ {
		competitiveSolution(600851475143)
	}
}
