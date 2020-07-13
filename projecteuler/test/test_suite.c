#define MINIUNIT_MAIN
#include "miniunit.h"

/* library to test */
#include "../lib/utils.h"

int main()
{
    test_case("Min", {
        expect("min(1, 2) = 1", min(1, 2) == 1);
        expect("min(132, -8) = -8", min(132, -8) == -8);
        expect("min(0, 0) = 0", min(0, 0) == 0);
    });

    test_case("Max", {
        expect("max(1, 2) = 2", max(1, 2) == 2);
        expect("max(132, -8) = 132", max(132, -8) == 132);
        expect("max(0, 0) = 0", max(0, 0) == 0);
    });

    test_case("Abs", {
        expect("abs(1) = 1", abs(1) == 1);
        expect("abs(-10) = 10", abs(-10) == 10);
    });

    test_case("Abs", {
        expect("abs(1) = 1", abs(1) == 1);
        expect("abs(-10) = 10", abs(-10) == 10);
    });

    int q, r;

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