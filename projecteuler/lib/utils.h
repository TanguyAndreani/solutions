#if !defined(UTILS_H)
#define UTILS_H

long absl(long n);
long gcd(long a, long b);
long minl(long a, long b);
long maxl(long a, long b);
void euclidean_division(long a, long b, long *q, long *r);
long roh_algorithm(long n, long (*f)(long), long start);
long sum(long n);
long sum_of_multiples(long n, long mod);

long prime[1000];

#endif // UTILS_H
