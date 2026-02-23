# Deep Dive: Task 2 Deep Dive — Top-Down Strategy (Memoization)

## Concept
**Memoization** caches results of recursive calls to avoid recomputation. This transforms the exponential naïve recursion into linear time.

- Base cases: \(F(0) = 0\), \(F(1) = 1\)
- Recurrence: \(F(n) = F(n-1) + F(n-2)\)
- Cache each computed \(F(k)\) in a table so it is computed only once.

## Time & Space Complexity
- **Time:** \(O(n)\)
- **Space:** \(O(n)\) for memo table + \(O(n)\) recursion stack

## Implementation Notes
- Use a `std::vector<long long>` memo table of size `n+1`, initialized to `-1`.
- Use **bounds-checked** accessors: `memo.at(i)` when reading/writing.
- Check inputs: `n < 0` (invalid), `n > 92` (overflow).

## Pseudocode
```text
function fib_memo(n):
    if n < 0: error "n must be non-negative"
    if n > 92: error "overflow"
    memo = array of size n+1 filled with -1
    return helper(n, memo)

function helper(n, memo):
    if n <= 1: return n
    if memo.at(n) != -1: return memo.at(n)
    memo.at(n) = helper(n-1, memo) + helper(n-2, memo)
    return memo.at(n)
```

Notice in the pseudocode, the function `fib_memo` has just one parameter (just like the `compute` method). Since this is 
part of an inherited api, you cannot change the signature. For this reason, we create `helper` function that can carry 
out the task using recursion as necessary. As such, you should do the same here for this task. In the `compute` method, 
do your bounds checking on the parameter; create and initialize a vector (or any other structure that can store already 
computed values) to all -1 values and pass that vector and the `num` parameter to your helper function that does the 
actual work. Creating and initializing a vector to the same value is easily done using its two arg constructor, where 
the first argument is the size of the vector to create, and the second is the initial value with which to populate the
elements.

For example, the following creates a vector named `memo` that has a capacity of `num + 1` with each element initialized 
to the value `-1`.

```c++
std::vector<big_number> memo( static_cast<std::size_t>( num ) + 1, -1 );
```

Note: that -1 serves as a sentinel value indicating whether a particular number in the sequence has been calculated yet
or not. 

## Advantages vs. Naïve
- Dramatically faster due to caching.
- Same simple recursive structure—easier to retrofit onto existing recursion.

## Common Mistakes
- Forgetting to size the memo to `n+1`.
- Using `operator[]` instead of `.at()` (clang-tidy bounds warning).
- Not handling `n=0` or `n=1` correctly.
