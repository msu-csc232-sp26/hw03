# Deep Dive: Task 1 Deep Dive — Naïve Recursive Strategy

## Concept
The naïve recursive Fibonacci directly follows the mathematical recurrence:

- Base cases: \(F(0) = 0\), \(F(1) = 1\)
- Recurrence: \(F(n) = F(n-1) + F(n-2)\) for \(n \ge 2\)

This mirrors the definition but recomputes overlapping subproblems exponentially many times.

## Time & Space Complexity
- **Time:** Exponential, approximately \(O(\varphi^n)\) where \(\varphi \approx 1.618\)
- **Space:** \(O(n)\) stack depth (due to recursion)

## Why Study It?
- Establishes the baseline and highlights the cost of overlapping subproblems.
- Sets the stage for memoization and tabulation.

## Pitfalls
- Extremely slow beyond modest n (e.g., n ≈ 40 can already be sluggish).
- Risk of **integer overflow** if using 64-bit integers beyond \(n=92\).
- Deep recursion may cause stack issues for very large n (even before overflow).

## Pseudocode
```text
function fib_naive(n):
    if n < 0: error "n must be non-negative"
    if n <= 1: return n
    return fib_naive(n-1) + fib_naive(n-2)
```

## What You Should Implement
- A class `NaiveRecursiveStrategy` implementing `long long compute(int n)`.
- Throw `std::invalid_argument` for negative `n`.
- Throw `std::overflow_error` for `n > 92` (since F(93) exceeds 64-bit signed range).

## Test Ideas
- Correctness for small cases: n ∈ {0,1,2,5,10}.
- Error conditions: n < 0, n > 92.
