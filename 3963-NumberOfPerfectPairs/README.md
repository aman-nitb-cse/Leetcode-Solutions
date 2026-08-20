# 3649. Number of Perfect Pairs

**Difficulty:** Medium  
[View on LeetCode](https://leetcode.com/problems/number-of-perfect-pairs/)

---

You are given an integer array `nums`.

A pair of indices `(i, j)` is called **perfect** if the following conditions are satisfied:

- `i < j`
- Let `a = nums[i]`, `b = nums[j]`. Then:

- `min(|a - b|, |a + b|) <= min(|a|, |b|)` - `max(|a - b|, |a + b|) >= max(|a|, |b|)`

Return the number of **distinct** perfect pairs.

**Note:** The absolute value `|x|` refers to the **non-negative** value of `x`.

**Example 1:**

**Input:** nums = [0,1,2,3]

**Output:** 2

**Explanation:**

There are 2 perfect pairs:

<table style="border: 1px solid black;">
	<thead>
		<tr>
			<th style="border: 1px solid black;"><code>(i, j)</code></th>
			<th style="border: 1px solid black;"><code>(a, b)</code></th>
			<th style="border: 1px solid black;"><code>min(|a &minus; b|, |a + b|)</code></th>
			<th style="border: 1px solid black;"><code>min(|a|, |b|)</code></th>
			<th style="border: 1px solid black;"><code>max(|a &minus; b|, |a + b|)</code></th>
			<th style="border: 1px solid black;"><code>max(|a|, |b|)</code></th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td style="border: 1px solid black;">(1, 2)</td>
			<td style="border: 1px solid black;">(1, 2)</td>
			<td style="border: 1px solid black;"><code>min(|1 &minus; 2|, |1 + 2|) = 1</code></td>
			<td style="border: 1px solid black;">1</td>
			<td style="border: 1px solid black;"><code>max(|1 &minus; 2|, |1 + 2|) = 3</code></td>
			<td style="border: 1px solid black;">2</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">(2, 3)</td>
			<td style="border: 1px solid black;">(2, 3)</td>
			<td style="border: 1px solid black;"><code>min(|2 &minus; 3|, |2 + 3|) = 1</code></td>
			<td style="border: 1px solid black;">2</td>
			<td style="border: 1px solid black;"><code>max(|2 &minus; 3|, |2 + 3|) = 5</code></td>
			<td style="border: 1px solid black;">3</td>
		</tr>
	</tbody>
</table>

**Example 2:**

**Input:** nums = [-3,2,-1,4]

**Output:** 4

**Explanation:**

There are 4 perfect pairs:

<table style="border: 1px solid black;">
	<thead>
		<tr>
			<th style="border: 1px solid black;"><code>(i, j)</code></th>
			<th style="border: 1px solid black;"><code>(a, b)</code></th>
			<th style="border: 1px solid black;"><code>min(|a &minus; b|, |a + b|)</code></th>
			<th style="border: 1px solid black;"><code>min(|a|, |b|)</code></th>
			<th style="border: 1px solid black;"><code>max(|a &minus; b|, |a + b|)</code></th>
			<th style="border: 1px solid black;"><code>max(|a|, |b|)</code></th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td style="border: 1px solid black;">(0, 1)</td>
			<td style="border: 1px solid black;">(-3, 2)</td>
			<td style="border: 1px solid black;"><code>min(|-3 - 2|, |-3 + 2|) = 1</code></td>
			<td style="border: 1px solid black;">2</td>
			<td style="border: 1px solid black;"><code>max(|-3 - 2|, |-3 + 2|) = 5</code></td>
			<td style="border: 1px solid black;">3</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">(0, 3)</td>
			<td style="border: 1px solid black;">(-3, 4)</td>
			<td style="border: 1px solid black;"><code>min(|-3 - 4|, |-3 + 4|) = 1</code></td>
			<td style="border: 1px solid black;">3</td>
			<td style="border: 1px solid black;"><code>max(|-3 - 4|, |-3 + 4|) = 7</code></td>
			<td style="border: 1px solid black;">4</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">(1, 2)</td>
			<td style="border: 1px solid black;">(2, -1)</td>
			<td style="border: 1px solid black;"><code>min(|2 - (-1)|, |2 + (-1)|) = 1</code></td>
			<td style="border: 1px solid black;">1</td>
			<td style="border: 1px solid black;"><code>max(|2 - (-1)|, |2 + (-1)|) = 3</code></td>
			<td style="border: 1px solid black;">2</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">(1, 3)</td>
			<td style="border: 1px solid black;">(2, 4)</td>
			<td style="border: 1px solid black;"><code>min(|2 - 4|, |2 + 4|) = 2</code></td>
			<td style="border: 1px solid black;">2</td>
			<td style="border: 1px solid black;"><code>max(|2 - 4|, |2 + 4|) = 6</code></td>
			<td style="border: 1px solid black;">4</td>
		</tr>
	</tbody>
</table>

**Example 3:**

**Input:** nums = [1,10,100,1000]

**Output:** 0

**Explanation:**

There are no perfect pairs. Thus, the answer is 0.

**Constraints:**

- `2 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`
