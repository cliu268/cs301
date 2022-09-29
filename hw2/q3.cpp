// the longest incremental subsequence
// https://xjoi.net/contest/5037/problem/3
/*
When a number sequence (series) bi has its elements b_1
For a given series (a_1, a_2, ..., a_n)，we can find some sub-sequence that are incremental series: (a_{i1}, a_{i2}, ..., a_{iK})，
where 1 <= i1 < i2 < ... < iK <= N。

For an instance,  series (1, 7, 3, 5, 9, 4, 8) has some incremental sub-sequence, such as (1, 7), (3, 4, 8), etc. 
The longest length of these sub-sequence is 4 (which corresonds to sub-sequence (1, 3, 5, 8)).

Now you are asked to find the longest incremental subsequence of a given sequence.

The longest Incremental subsequence is 1 3 or 1 2

Input:
The first line has only one integer number n, denoting the length of the series (sequence).
The 2nd line has n integer number for the number sequence.

Output:
Output an integer representing the length of the longest Incremental subsequence

Sample input:
5
5 4 3 2 1

Sample output:
1

Constraints:
1 <= n <= 1000, 1<= each element <=10000
*/