# 3906. Count Good Integers on a Grid Path

**Difficulty:** Hard  
[View on LeetCode](https://leetcode.com/problems/count-good-integers-on-a-grid-path/)

---

You are given two integers `l` and `r`, and a string `directions` consisting of **exactly** three `'D'` characters and three `'R'` characters.

For each integer `x` in the range `[l, r]` (inclusive), perform the following steps:

1. If `x` has fewer than 16 digits, pad it on the left with **leading zeros** to obtain a 16-digit string.
2. Place the 16 digits into a `4 &times; 4` grid in **row-major** order (the first 4 digits form the first row from left to right, the next 4 digits form the second row, and so on).
3. Starting at the **top-left** cell (`row = 0`, `column = 0`), apply the 6 characters of `directions` in order:

 `'D'` increments the row by 1.
4. `'R'` increments the column by 1.
5. Record the sequence of digits visited along the path (including the starting cell), producing a sequence of length 7.

The integer `x` is considered **good** if the recorded sequence is **non-decreasing**.

Return an integer representing the number of good integers in the range `[l, r]`.

**Example 1:**

**Input:** l = 8, r = 10, directions = "DDDRRR"

**Output:** 2

**Explanation:**

The grid for `x = 8`:

<table style="border: 1px solid black;">
	<tbody>
		<tr style="background:none;">
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">0</td>
		</tr>
		<tr style="background:none;">
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">0</td>
		</tr>
		<tr style="background:none;">
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">0</td>
		</tr>
		<tr style="background:none;">
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">8</td>
		</tr>
	</tbody>
</table>

- Path: `(0,0) &rarr; (1,0) &rarr; (2,0) &rarr; (3,0) &rarr; (3,1) &rarr; (3,2) &rarr; (3,3)`
- The sequence of digits visited is `[0, 0, 0, 0, 0, 0, 8]`.
- As the sequence of digits visited is non-decreasing, 8 is a good integer.

The grid for `x = 9`:

<table style="border: 1px solid black;">
	<tbody>
		<tr style="background:none;">
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">0</td>
		</tr>
		<tr style="background:none;">
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">0</td>
		</tr>
		<tr style="background:none;">
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">0</td>
		</tr>
		<tr style="background:none;">
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">9</td>
		</tr>
	</tbody>
</table>

- The sequence of digits visited is `[0, 0, 0, 0, 0, 0, 9]`.
- As the sequence of digits visited is non-decreasing, 9 is a good integer.

The grid for `x = 10`:

<table style="border: 1px solid black;">
	<tbody>
		<tr style="background:none;">
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">0</td>
		</tr>
		<tr style="background:none;">
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">0</td>
		</tr>
		<tr style="background:none;">
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">0</td>
		</tr>
		<tr style="background:none;">
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">1</td>
			<td style="border: 1px solid black;">0</td>
		</tr>
	</tbody>
</table>

- The sequence of digits visited is `[0, 0, 0, 0, 0, 1, 0]`.
- As the sequence of digits visited is not non-decreasing, 10 is not a good integer.
- Hence, only 8 and 9 are good, giving a total of 2 good integers in the range.

**Example 2:**

**Input:** l = 123456789, r = 123456790, directions = "DDRRDR"

**Output:** 1

**Explanation:**

The grid for `x = 123456789`:

<table style="border: 1px solid black;">
	<tbody>
		<tr style="background:none;">
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">0</td>
		</tr>
		<tr style="background:none;">
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">1</td>
		</tr>
		<tr style="background:none;">
			<td style="border: 1px solid black;">2</td>
			<td style="border: 1px solid black;">3</td>
			<td style="border: 1px solid black;">4</td>
			<td style="border: 1px solid black;">5</td>
		</tr>
		<tr style="background:none;">
			<td style="border: 1px solid black;">6</td>
			<td style="border: 1px solid black;">7</td>
			<td style="border: 1px solid black;">8</td>
			<td style="border: 1px solid black;">9</td>
		</tr>
	</tbody>
</table>

- Path: `(0,0) &rarr; (1,0) &rarr; (2,0) &rarr; (2,1) &rarr; (2,2) &rarr; (3,2) &rarr; (3,3)`
- The sequence of digits visited is `[0, 0, 2, 3, 4, 8, 9]`.
- As the sequence of digits visited is non-decreasing, 123456789 is a good integer.

The grid for `x = 123456790`:

<table style="border: 1px solid black;">
	<tbody>
		<tr style="background:none;">
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">0</td>
		</tr>
		<tr style="background:none;">
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">1</td>
		</tr>
		<tr style="background:none;">
			<td style="border: 1px solid black;">2</td>
			<td style="border: 1px solid black;">3</td>
			<td style="border: 1px solid black;">4</td>
			<td style="border: 1px solid black;">5</td>
		</tr>
		<tr style="background:none;">
			<td style="border: 1px solid black;">6</td>
			<td style="border: 1px solid black;">7</td>
			<td style="border: 1px solid black;">9</td>
			<td style="border: 1px solid black;">0</td>
		</tr>
	</tbody>
</table>

- The sequence of digits visited is `[0, 0, 2, 3, 4, 9, 0]`.
- As the sequence of digits visited is not non-decreasing, 123456790 is not a good integer.
- Hence, only 123456789 is good, giving a total of 1 good integer in the range.

**Example 3:**

**Input:** l = 1288561398769758, r = 1288561398769758, directions = "RRRDDD"

**Output:** 0

**Explanation:**

The grid for `x = 1288561398769758`:

<table style="border: 1px solid black;">
	<tbody>
		<tr style="background:none;">
			<td style="border: 1px solid black;">1</td>
			<td style="border: 1px solid black;">2</td>
			<td style="border: 1px solid black;">8</td>
			<td style="border: 1px solid black;">8</td>
		</tr>
		<tr style="background:none;">
			<td style="border: 1px solid black;">5</td>
			<td style="border: 1px solid black;">6</td>
			<td style="border: 1px solid black;">1</td>
			<td style="border: 1px solid black;">3</td>
		</tr>
		<tr style="background:none;">
			<td style="border: 1px solid black;">9</td>
			<td style="border: 1px solid black;">8</td>
			<td style="border: 1px solid black;">7</td>
			<td style="border: 1px solid black;">6</td>
		</tr>
		<tr style="background:none;">
			<td style="border: 1px solid black;">9</td>
			<td style="border: 1px solid black;">7</td>
			<td style="border: 1px solid black;">5</td>
			<td style="border: 1px solid black;">8</td>
		</tr>
	</tbody>
</table>

- Path: `(0,0) &rarr; (0,1) &rarr; (0,2) &rarr; (0,3) &rarr; (1,3) &rarr; (2,3) &rarr; (3,3)`
- The sequence of digits visited is `[1, 2, 8, 8, 3, 6, 8]`.
- ​​​​​​​As the sequence of digits visited is not non-decreasing, 1288561398769758 is not a good integer.
- No numbers are good, giving a total of 0 good integers in the range.

**Constraints:**

- `1 <= l <= r <= 9 &times; 10^15`
- `directions.length == 6`
- `directions` consists of **exactly** three `'D'` characters and three `'R'` characters.
