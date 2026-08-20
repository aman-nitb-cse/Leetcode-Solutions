# 3597. Partition String 

**Difficulty:** Medium  
[View on LeetCode](https://leetcode.com/problems/partition-string/)

---

Given a string `s`, partition it into **unique segments** according to the following procedure:

- Start building a segment beginning at index 0.
- Continue extending the current segment character by character until the current segment has not been seen before.
- Once the segment is unique, add it to your list of segments, mark it as seen, and begin a new segment from the next index.
- Repeat until you reach the end of `s`.

Return an array of strings `segments`, where `segments[i]` is the `i^th` segment created.

**Example 1:**

**Input:** s = "abbccccd"

**Output:** ["a","b","bc","c","cc","d"]

**Explanation:**

<table style="border: 1px solid black;">
	<tbody>
		<tr>
			<th style="border: 1px solid black;">Index</th>
			<th style="border: 1px solid black;">Segment After Adding</th>
			<th style="border: 1px solid black;">Seen Segments</th>
			<th style="border: 1px solid black;">Current Segment Seen Before?</th>
			<th style="border: 1px solid black;">New Segment</th>
			<th style="border: 1px solid black;">Updated Seen Segments</th>
		</tr>
		<tr>
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">&quot;a&quot;</td>
			<td style="border: 1px solid black;">[]</td>
			<td style="border: 1px solid black;">No</td>
			<td style="border: 1px solid black;">&quot;&quot;</td>
			<td style="border: 1px solid black;">[&quot;a&quot;]</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">1</td>
			<td style="border: 1px solid black;">&quot;b&quot;</td>
			<td style="border: 1px solid black;">[&quot;a&quot;]</td>
			<td style="border: 1px solid black;">No</td>
			<td style="border: 1px solid black;">&quot;&quot;</td>
			<td style="border: 1px solid black;">[&quot;a&quot;, &quot;b&quot;]</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">2</td>
			<td style="border: 1px solid black;">&quot;b&quot;</td>
			<td style="border: 1px solid black;">[&quot;a&quot;, &quot;b&quot;]</td>
			<td style="border: 1px solid black;">Yes</td>
			<td style="border: 1px solid black;">&quot;b&quot;</td>
			<td style="border: 1px solid black;">[&quot;a&quot;, &quot;b&quot;]</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">3</td>
			<td style="border: 1px solid black;">&quot;bc&quot;</td>
			<td style="border: 1px solid black;">[&quot;a&quot;, &quot;b&quot;]</td>
			<td style="border: 1px solid black;">No</td>
			<td style="border: 1px solid black;">&quot;&quot;</td>
			<td style="border: 1px solid black;">[&quot;a&quot;, &quot;b&quot;, &quot;bc&quot;]</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">4</td>
			<td style="border: 1px solid black;">&quot;c&quot;</td>
			<td style="border: 1px solid black;">[&quot;a&quot;, &quot;b&quot;, &quot;bc&quot;]</td>
			<td style="border: 1px solid black;">No</td>
			<td style="border: 1px solid black;">&quot;&quot;</td>
			<td style="border: 1px solid black;">[&quot;a&quot;, &quot;b&quot;, &quot;bc&quot;, &quot;c&quot;]</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">5</td>
			<td style="border: 1px solid black;">&quot;c&quot;</td>
			<td style="border: 1px solid black;">[&quot;a&quot;, &quot;b&quot;, &quot;bc&quot;, &quot;c&quot;]</td>
			<td style="border: 1px solid black;">Yes</td>
			<td style="border: 1px solid black;">&quot;c&quot;</td>
			<td style="border: 1px solid black;">[&quot;a&quot;, &quot;b&quot;, &quot;bc&quot;, &quot;c&quot;]</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">6</td>
			<td style="border: 1px solid black;">&quot;cc&quot;</td>
			<td style="border: 1px solid black;">[&quot;a&quot;, &quot;b&quot;, &quot;bc&quot;, &quot;c&quot;]</td>
			<td style="border: 1px solid black;">No</td>
			<td style="border: 1px solid black;">&quot;&quot;</td>
			<td style="border: 1px solid black;">[&quot;a&quot;, &quot;b&quot;, &quot;bc&quot;, &quot;c&quot;, &quot;cc&quot;]</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">7</td>
			<td style="border: 1px solid black;">&quot;d&quot;</td>
			<td style="border: 1px solid black;">[&quot;a&quot;, &quot;b&quot;, &quot;bc&quot;, &quot;c&quot;, &quot;cc&quot;]</td>
			<td style="border: 1px solid black;">No</td>
			<td style="border: 1px solid black;">&quot;&quot;</td>
			<td style="border: 1px solid black;">[&quot;a&quot;, &quot;b&quot;, &quot;bc&quot;, &quot;c&quot;, &quot;cc&quot;, &quot;d&quot;]</td>
		</tr>
	</tbody>
</table>

Hence, the final output is `["a", "b", "bc", "c", "cc", "d"]`.

**Example 2:**

**Input:** s = "aaaa"

**Output:** ["a","aa"]

**Explanation:**

<table style="border: 1px solid black;">
	<tbody>
		<tr>
			<th style="border: 1px solid black;">Index</th>
			<th style="border: 1px solid black;">Segment After Adding</th>
			<th style="border: 1px solid black;">Seen Segments</th>
			<th style="border: 1px solid black;">Current Segment Seen Before?</th>
			<th style="border: 1px solid black;">New Segment</th>
			<th style="border: 1px solid black;">Updated Seen Segments</th>
		</tr>
		<tr>
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">&quot;a&quot;</td>
			<td style="border: 1px solid black;">[]</td>
			<td style="border: 1px solid black;">No</td>
			<td style="border: 1px solid black;">&quot;&quot;</td>
			<td style="border: 1px solid black;">[&quot;a&quot;]</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">1</td>
			<td style="border: 1px solid black;">&quot;a&quot;</td>
			<td style="border: 1px solid black;">[&quot;a&quot;]</td>
			<td style="border: 1px solid black;">Yes</td>
			<td style="border: 1px solid black;">&quot;a&quot;</td>
			<td style="border: 1px solid black;">[&quot;a&quot;]</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">2</td>
			<td style="border: 1px solid black;">&quot;aa&quot;</td>
			<td style="border: 1px solid black;">[&quot;a&quot;]</td>
			<td style="border: 1px solid black;">No</td>
			<td style="border: 1px solid black;">&quot;&quot;</td>
			<td style="border: 1px solid black;">[&quot;a&quot;, &quot;aa&quot;]</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">3</td>
			<td style="border: 1px solid black;">&quot;a&quot;</td>
			<td style="border: 1px solid black;">[&quot;a&quot;, &quot;aa&quot;]</td>
			<td style="border: 1px solid black;">Yes</td>
			<td style="border: 1px solid black;">&quot;a&quot;</td>
			<td style="border: 1px solid black;">[&quot;a&quot;, &quot;aa&quot;]</td>
		</tr>
	</tbody>
</table>

Hence, the final output is `["a", "aa"]`.

**Constraints:**

- `1 <= s.length <= 10^5`
- `s` contains only lowercase English letters.
