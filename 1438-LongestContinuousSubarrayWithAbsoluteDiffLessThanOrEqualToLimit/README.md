# 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit

**Difficulty:** Medium  
[View on LeetCode](https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/)

---

You are given an array of integers `nums` and an integer `limit`.

Return the size of the **longest non-empty subarray** such that the **absolute** difference between **every pair of elements** in this **subarray** is **less than or equal** to `limit`*.*

**Example 1:**

**Input:** nums = [8,2,4,7], limit = 4

**Output:** 2

**Explanation:**

Checking every subarray, where the absolute difference is taken over all pairs of its elements: **`[8]` with maximum absolute diff `|8-8| = 0 <= 4`.  

`[8,2]` with maximum absolute diff `|8-2| = 6 > 4`.  

`[8,2,4]` with maximum absolute diff `|8-2| = 6 > 4`.  

`[8,2,4,7]` with maximum absolute diff `|8-2| = 6 > 4`.  

`[2]` with maximum absolute diff `|2-2| = 0 <= 4`.  

`[2,4]` with maximum absolute diff `|4-2| = 2 <= 4`.  

`[2,4,7]` with maximum absolute diff `|7-2| = 5 > 4`. Note that the pair `(2, 7)` is not adjacent, but it is still compared.  

`[4]` with maximum absolute diff `|4-4| = 0 <= 4`.  

`[4,7]` with maximum absolute diff `|7-4| = 3 <= 4`.  

`[7]` with maximum absolute diff `|7-7| = 0 <= 4`.  

Therefore, the size of the longest subarray is 2.

Example 2:**

**Input:** nums = [10,1,2,4,7,2], limit = 5

**Output:** 4

**Explanation:**

The subarray `[2,4,7,2]` is valid because every pair of its elements differs by at most `5`, the largest being `|7-2| = 5`.

It cannot be extended to the left, since `[1,2,4,7,2]` contains the pair `(1, 7)` with `|7-1| = 6 > 5`. Therefore, the size of the longest subarray is 4.

**Example 3:**

**Input:** nums = [4,2,2,2,4,4,2,2], limit = 0

**Output:** 3

**Explanation:**

Since `limit = 0`, every pair of elements in the subarray must be equal, so only runs of identical values qualify.

The longest such run is `[2,2,2]`, of size 3.

**Constraints:**

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^9`
- `0 <= limit <= 10^9`
