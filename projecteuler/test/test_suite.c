#define MINIUNIT_MAIN
#include "miniunit.h"

/* library to test */
#include "../lib/utils.h"

int main()
{
    test_case("Min", {
        expect("minl(1, 2) = 1", minl(1, 2) == 1);
        expect("minl(132, -8) = -8", minl(132, -8) == -8);
        expect("minl(0, 0) = 0", minl(0, 0) == 0);
    });

    test_case("Max", {
        expect("maxl(1, 2) = 2", maxl(1, 2) == 2);
        expect("maxl(132, -8) = 132", maxl(132, -8) == 132);
        expect("maxl(0, 0) = 0", maxl(0, 0) == 0);
    });

    test_case("Abs", {
        expect("absl(1) = 1", absl(1) == 1);
        expect("absl(-10) = 10", absl(-10) == 10);
    });

    test_case("Abs", {
        expect("absl(1) = 1", absl(1) == 1);
        expect("absl(-10) = 10", absl(-10) == 10);
    });

    long q, r;

    test_case("Euclidean division", {
        euclidean_division(32, 3, &q, &r);
        expect("euclidean_division(32, 3, ...)  -> q = 10, r = 2", q == 10 && r == 2);
        euclidean_division(30, 3, &q, &r);
        expect("euclidean_division(32, 3, ...)  -> q = 10, r = 0", q == 10 && r == 0);
        euclidean_division(-32, 3, &q, &r);
        expect("euclidean_division(-32, 3, ...) -> q = -11, r = 1", q == -11 && r == 1);
        euclidean_division(32, -3, &q, &r);
        expect("euclidean_division(32, -3, ...) -> q = -10, r = 2", q == -10 && r == 2);
    });

    test_case("GCD", {
        expect("gcd(147, 126) = 21", gcd(147, 126) == 21);
        expect("gcd(180, 36) = 36", gcd(180, 36) == 36);
        expect("gcd(-147, 126) = 21", gcd(-147, 126) == 21);
        expect("gcd(180, -36) = 36", gcd(180, -36) == 36);
    });

    return 0;
}