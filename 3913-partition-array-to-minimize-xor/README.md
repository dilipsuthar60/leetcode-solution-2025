<h2><a href="https://leetcode.com/problems/partition-array-to-minimize-xor/description/">3913. Partition Array to Minimize XOR</a></h2><h3>Medium</h3><hr><p>You are given an integer array <code>nums</code> and an integer <code>k</code>.</p>

<p>Your task is to partition <code>nums</code> into <code>k</code><strong> </strong>non-empty <strong><span data-keyword="subarray-nonempty">subarrays</span></strong>. For each subarray, compute the bitwise <strong>XOR</strong> of all its elements.</p>

<p>Return the <strong>minimum</strong> possible value of the <strong>maximum XOR</strong> among these <code>k</code> subarrays.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,2,3], k = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong></p>

<p>The optimal partition is <code>[1]</code> and <code>[2, 3]</code>.</p>

<ul>
	<li>XOR of the first subarray is <code>1</code>.</li>
	<li>XOR of the second subarray is <code>2 XOR 3 = 1</code>.</li>
</ul>

<p>The maximum XOR among the subarrays is 1, which is the minimum possible.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [2,3,3,2], k = 3</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<p>The optimal partition is <code>[2]</code>, <code>[3, 3]</code>, and <code>[2]</code>.</p>

<ul>
	<li>XOR of the first subarray is <code>2</code>.</li>
	<li>XOR of the second subarray is <code>3 XOR 3 = 0</code>.</li>
	<li>XOR of the third subarray is <code>2</code>.</li>
</ul>

<p>The maximum XOR among the subarrays is 2, which is the minimum possible.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,1,2,3,1], k = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p><strong>Explanation:</strong></p>

<p>The optimal partition is <code>[1, 1]</code> and <code>[2, 3, 1]</code>.</p>

<ul>
	<li>XOR of the first subarray is <code>1 XOR 1 = 0</code>.</li>
	<li>XOR of the second subarray is <code>2 XOR 3 XOR 1 = 0</code>.</li>
</ul>

<p>The maximum XOR among the subarrays is 0, which is the minimum possible.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 250</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= n</code></li>
</ul>
