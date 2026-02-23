# Deep Dive: Task 3 Deep Dive — Bottom-Up Strategy (Tabulation)

## Concept
**Tabulation** builds solutions from the ground up. Start from base cases and iteratively fill a table until you reach `F(n)`.

- Initialize: `dp[0] = 0`, `dp[1] = 1`
- For `i` from 2 to `n`: `dp[i] = dp[i-1] + dp[i-2]`

## Time & Space Complexity
- **Time:** \(O(n)\)
- **Space:** \(O(n)\) for the DP array (can be optimized to \(O(1)\))

## Implementation Notes
- Allocate `std::vector<long long> dp(n+1)` and use `dp.at(i)` for safety.
- Input validation: `n < 0` ⇒ invalid; `n > 92` ⇒ overflow.

## Pseudocode
```text
dp = array of size n+1
if n <= 1: return n
dp.at(0) = 0
dp.at(1) = 1
for i in [2..n]:
    dp.at(i) = dp.at(i-1) + dp.at(i-2)
return dp.at(n)
```

## When to Prefer Tabulation
- You want predictable iteration without recursion overhead.
- You need access to all intermediate states (e.g., for tracing/visualization).

## Pitfalls
- Off-by-one errors when sizing `dp`.
- Forgetting to handle small `n` early.
