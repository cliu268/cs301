// Fill the Backpack Completely
// https://xjoi.net/contest/5119/problem/3
/*
There are n items and a backpack that can hold max weight of W. Is there a way to choose some of these n items to make the total 
weight exactly equal to W?

Input format:
First line: 2 integers n, W
Second line: n integers, representing the weight of the n items

Output format:
If there's solution, output "yes", otherwise "no"

Sample input:
5 10
8 4 3 5 1

Sample output:
yes

Explanation:
Let's say there are 5 items, with weights of 8 kg, 4 kg, 3 kg, 5 kg, and 1 kg. The backpack can hold up to 10 kg. 
We can pick the items weighing 4 kg, 5 kg, and 1 kg to make 10 kg, the same weight as the backpack. 
So, the answer would be "yes".

Hint:
Try to implement all the problems using the most efficient method: iterative with 1-D dp array.
*/