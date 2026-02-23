# Deep Dive: Task 4 Deep Dive — Iterative Strategy (O(1) Space)

## Concept

Keep only the last two Fibonacci numbers and iterate forward. This yields optimal space and is usually fastest in
practice.

- Start: `prev2 = 0`, `prev1 = 1`
- Loop `i = 2..n`: `cur = prev1 + prev2`, then shift.

## Time & Space Complexity

- **Time:** O(_n_)
- **Space:** O(1)

## Pseudocode

```text
if n <= 1: return n
prev2 = 0
prev1 = 1
for i in [2..n]:
    cur = prev1 + prev2
    prev2 = prev1
    prev1 = cur
return prev1
```

## Strengths

- Minimal memory footprint
- No indexing (no bounds warnings) and no recursion

## Caveats

- Still linear time—consider fast doubling for very large `n`.
- Overflow remains at `n > 92` for 64-bit signed integers.
