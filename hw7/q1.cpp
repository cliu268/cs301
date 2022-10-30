// Job Selection
// https://xjoi.net/contest/5229/problem/1 
/*
We have n jobs, where every job is scheduled to be done from startTimei to endTimei, obtaining a profit of profiti.

You're given the startTime, endTime and profit arrays. You need to select some of the jobs to finish. Please find the maximum 
profit you can take such that there are no two selected jobs with overlapping time range.

Note that if you choose a job that ends at time X, you will be able to start another job that starts at time X.

Input
The first line contains an integer n, the number of jobs.
For the following n lines, each line contains 3 integers, startTimei, endTimei and profiti.

Output
An integer, the maximum profit you can take.

Sample Input
5
8 10 5
3 6 8
1 9 1
5 10 8
6 7 4

Sample Output
17

Constraint
1≤n≤1000, 1≤startTimei<endTimei≤1000, 1≤profiti≤1000.
*/