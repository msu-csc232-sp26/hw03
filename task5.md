# Deep Dive: Task 5 — Fast Doubling Strategy (O(log n))

## Concept

Use the **fast doubling identities** to compute F(n) and F(n+1) together via divide and conquer:

Given `k = floor(n/2)`:

```text
F(2k)   = F(k) * [2F(k+1) - F(k)]
F(2k+1) = F(k)^2 + F(k+1)^2
```

This yields O(log n) time with simple recursion and no dynamic arrays.

## Time & Space Complexity

- **Time:** O(log n)
- **Space:** O(log n) recursion depth

## Pseudocode (returns pair)

```text
function fib_pair(n):
    if n == 0: return (0, 1)
    (a, b) = fib_pair(n // 2)   // a=F(k), b=F(k+1)
    c = a * (2*b - a)           // F(2k)
    d = a*a + b*b               // F(2k+1)
    if n % 2 == 0: return (c, d)
    else: return (d, c + d)

function fib_fast_doubling(n):
    if n < 0: error
    if n > 92: overflow
    return fib_pair(n).first
```

Similar to task 2, here this solution requires two methods to implement. The helper function, in this case, is the 
`fib_pair` member function. To create a literal pair, we can 

```c++
std::pair<big_number, big_number> pair = {2, 3};       // creates a pair of big_number values
std::cout << pair.first << " " << pair.second << "\n"; // prints 2 3
```

Since the method signature for `fib_pair` indicates it returns a `std::pair<big_number, big_number>`, the type inference
engine can infer the following `return` statement as returning a `std::pair`

```c++
return {1, 2} // returns 1 as the first element of the pair, 2 as the second
```

If you want to immediate assign values of the pair when calling a function that returns a pair, that could be done as
follows:

```c++
auto [ first_result, second_result ] = some_function_that_returns_a_pair( );
```

See [Pair in C++ STL](https://www.geeksforgeeks.org/cpp/pair-in-cpp-stl/) for more details on creating and working with
this data structure.

## Advantages

- Asymptotically optimal among exact integer methods without matrix exponentiation constants.
- No table allocations and no bounds-checked indexing required.

## Pitfalls

- Easy to make arithmetic mistakes in the identities—write tests!
- Still subject to 64-bit overflow at `n > 92`; use big integers if needed.
