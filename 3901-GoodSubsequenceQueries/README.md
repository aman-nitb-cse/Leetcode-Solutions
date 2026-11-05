# 3901. Good Subsequence Queries

**Difficulty:** Hard  
[View on LeetCode](https://leetcode.com/problems/good-subsequence-queries/)

---

You are given an integer array `nums` of length `n` and an integer `p`.

A **non-empty subsequence** of `nums` is called **good** if:

- Its length is **strictly less** than `n`.
- The **greatest common divisor (GCD)** of its elements is **exactly** `p`.

You are also given a 2D integer array `queries` of length `q`, where each `queries[i] = [ind_i, val_i]` indicates that you should update `nums[ind_i]` to `val_i`.

After each query, determine whether there exists **any good subsequence** in the current array.

Return the **number** of queries for which a **good subsequence** exists.

The term `gcd(a, b)` denotes the **greatest common divisor** of `a` and `b`.

**Example 1:**

**Input:** nums = [4,8,12,16], p = 2, queries = [[0,3],[2,6]]

**Output:** 1

**Explanation:**

<table style="border: 1px solid black;">
	<thead>
		<tr>
			<th style="border: 1px solid black;">i</th>
			<th style="border: 1px solid black;"><code>[ind<sub>i</sub>, val<sub>i</sub>]</code></th>
			<th style="border: 1px solid black;">Operation</th>
			<th style="border: 1px solid black;">Updated <code>nums</code></th>
			<th style="border: 1px solid black;">Any good Subsequence</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;"><code>[0, 3]</code></td>
			<td style="border: 1px solid black;">Update <code>nums[0]</code> to <code>3</code></td>
			<td style="border: 1px solid black;"><code>[3, 8, 12, 16]</code></td>
			<td style="border: 1px solid black;">No, as no subsequence has GCD exactly <code>p = 2</code></td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">1</td>
			<td style="border: 1px solid black;"><code>[2, 6]</code></td>
			<td style="border: 1px solid black;">Update <code>nums[2]</code> to <code>6</code></td>
			<td style="border: 1px solid black;"><code>[3, 8, 6, 16]</code></td>
			<td style="border: 1px solid black;">Yes, subsequence <code>[8, 6]</code> has GCD exactly <code>p = 2</code></td>
		</tr>
	</tbody>
</table>

Thus, the answer is 1.

**Example 2:**

**Input:** nums = [4,5,7,8], p = 3, queries = [[0,6],[1,9],[2,3]]

**Output:** 2

**Explanation:**

<table style="border: 1px solid black;">
	<thead>
		<tr>
			<th style="border: 1px solid black;">i</th>
			<th style="border: 1px solid black;"><code>[ind<sub>i</sub>, val<sub>i</sub>]</code></th>
			<th style="border: 1px solid black;">Operation</th>
			<th style="border: 1px solid black;">Updated <code>nums</code></th>
			<th style="border: 1px solid black;">Any good Subsequence</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;"><code>[0, 6]</code></td>
			<td style="border: 1px solid black;">Update <code>nums[0]</code> to <code>6</code></td>
			<td style="border: 1px solid black;"><code>[6, 5, 7, 8]</code></td>
			<td style="border: 1px solid black;">No, as no subsequence has GCD exactly <code>p = 3</code></td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">1</td>
			<td style="border: 1px solid black;"><code>[1, 9]</code></td>
			<td style="border: 1px solid black;">Update <code>nums[1]</code> to <code>9</code></td>
			<td style="border: 1px solid black;"><code>[6, 9, 7, 8]</code></td>
			<td style="border: 1px solid black;">Yes, subsequence <code>[6, 9]</code> has GCD exactly <code>p = 3</code></td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">2</td>
			<td style="border: 1px solid black;"><code>[2, 3]</code></td>
			<td style="border: 1px solid black;">Update <code>nums[2]</code> to <code>3</code></td>
			<td style="border: 1px solid black;"><code>[6, 9, 3, 8]</code></td>
			<td style="border: 1px solid black;">Yes, subsequence <code>[6, 9, 3]</code> has GCD exactly <code>p = 3</code></td>
		</tr>
	</tbody>
</table>

Thus, the answer is 2.

**Example 3:**

**Input:** nums = [5,7,9], p = 2, queries = [[1,4],[2,8]]

**Output:** 0

**Explanation:**

<table style="border: 1px solid black;">
	<thead>
		<tr>
			<th style="border: 1px solid black;">i</th>
			<th style="border: 1px solid black;"><code>[ind<sub>i</sub>, val<sub>i</sub>]</code></th>
			<th style="border: 1px solid black;">Operation</th>
			<th style="border: 1px solid black;">Updated <code>nums</code></th>
			<th style="border: 1px solid black;">Any good Subsequence</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;"><code>[1, 4]</code></td>
			<td style="border: 1px solid black;">Update <code>nums[1]</code> to <code>4</code></td>
			<td style="border: 1px solid black;"><code>[5, 4, 9]</code></td>
			<td style="border: 1px solid black;">No, as no subsequence has GCD exactly <code>p = 2</code></td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">1</td>
			<td style="border: 1px solid black;"><code>[2, 8]</code></td>
			<td style="border: 1px solid black;">Update <code>nums[2]</code> to <code>8</code></td>
			<td style="border: 1px solid black;"><code>[5, 4, 8]</code></td>
			<td style="border: 1px solid black;">No, as no subsequence has GCD exactly <code>p = 2</code></td>
		</tr>
	</tbody>
</table>

Thus, the answer is 0.

**Constraints:**

- `2 <= n == nums.length <= 5 * 10^4`
- `1 <= nums[i] <= 5 * 10^4`
- `1 <= queries.length <= 5 * 10^4`
- `queries[i] = [ind_i, val_i]`
- `1 <= val_i, p <= 5 * 10^4`
- `0 <= ind_i <= n - 1`
