# The Go Programming Language

[On libgen](http://libgen.is/search.php?req=The+go+programming+language&lg_topic=libgen&open=0&view=simple&res=25&phrase=1&column=def)

## Chapter 1 - Tutorial

Exercises for this chapter are on page 8 of the book.

**Exercise 1.1**: Modify the echo program to also print `os.Args[0]`, the name of the command that invoked it.

**Solution**: Just change `os.Args[1:]` to `os.Args[0:]`.

**Exercise 1.2**: Modify the echo program to print the index and value of its arguments, one per line.

**Solution**:

```go
func main() {
  for i := 0; i < len(os.Args); i = i + 1 {
    fmt.Println(i, os.Args[i])
  }
}
```

**Exercise 1.3**: Experiment to measure the difference in running time between
our potentially inefficient versions and the one that uses `strings.Join`.

**Solution**: After 1000000 iterations, I got the following benchmark:

```
Inefficient method: 65.7ms
Efficient method: 45.3ms
```

Here is a function that takes another and run it many times:

```go
func run_times(f func(), n int) {
  for i := 0; i < n; i++ {
    f()
  }
}
```
