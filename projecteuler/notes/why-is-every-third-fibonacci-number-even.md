# Why is every third Fibonacci number even?

### Two rules

1. even + even is even, odd + odd is even,
2. even + odd is odd

### Just apply them

Two of the first consecutive terms of the fibonacci sequence are 2 and 3.

So, knowing that a term is just the sum of the two previous ones, we can fillin the following table:

|fib(n)|even or odd|
|-|-|
|2|even|
|3|odd|
|5|odd|
|8|even|
|13|odd|
|21|...|

I stopped at 13 because we are now back in the initial situation
(an odd number following an even number). And because next state
depends only on the previous one, we're now going to eternally cycle around
sequences of odd, then even, then odd, then odd, then even, ...

In fact we could have built the same table without the first column:

|even or odd|
|-|
|even|
|odd|
|odd|
|even|
|odd|
|...|

And then, because 2 and 3 are consecutive terms of Fibonacci sequence,
we know that the whole sequence replicate this structure.
