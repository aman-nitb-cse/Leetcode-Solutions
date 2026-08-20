# 3821. Find Nth Smallest Integer With K One Bits

**Difficulty:** Hard  
[View on LeetCode](https://leetcode.com/problems/find-nth-smallest-integer-with-k-one-bits/)

---

You are given two positive integers `n` and `k`.

Return an integer denoting the `n^th` smallest positive integer that has **exactly** `k` ones in its binary representation. It is guaranteed that the answer is **strictly less** than `2^50`.

**Example 1:**

**Input:** n = 4, k = 2

**Output:** 9

**Explanation:**

The 4 smallest positive integers that have exactly `k = 2` ones in their binary representations are:

- `3 = 11_2`
- `5 = 101_2`
- `6 = 110_2`
- `9 = 1001_2`

**Example 2:**

**Input:** n = 3, k = 1

**Output:** 4

**Explanation:**

The 3 smallest positive integers that have exactly `k = 1` one in their binary representations are:

- `1 = 1_2`
- `2 = 10_2`
- `4 = 100_2`

**Constraints:**

- `1 <= n <= 2^50`
- `1 <= k <= 50`
- The answer is strictly less than `2^50`.
