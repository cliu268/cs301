// Taking numbers in cells
// https://xjoi.net/contest/5451/problem/2
/*
Given a N*N table (N<=1000), we put positive integers in some of the cells and put 0 in the rest. A person will start from point 
A (1,1) in the upper left. He can go down or go right until he reaches point B (N,N) in the lower right part of the table. 
When he goes through a certain cell, he can take the number in the cell (thus the number in the cell becomes 0).

Please find out the maximum sum of numbers he can get from A to B.
For example:
A
    0  0  0  0  0  0  0  0
    0  0 13  0  0  6  0  0
    0  0  0  0  7  0  0  0
    0  0  0 14  0  0  0  0
    0 21  0  0  0  4  0  0
    0  0 15  0  0  0  0  0
    0 14  0  0  0  0  0  0
    0  0  0  0  0  0  0  0
                            B
Sample answer: 36
    0
    0
    0
    0
    0 21
       0 15
          0
          0  0  0  0  0  0

Input：
The first line contains an integer N（N≤1000），representing the table of N×N.

The next each line contains three integers-- the number of the row and the column, and the number given in that cell.  
“0 0 0”in a line means the end.

Output：
an integer, which means the maximum sum of numbers from A to B.

Sample input：
8
2 3 13
2 6 6
3 5 7
4 4 14
5 2 21
5 6 4
6 3 15
7 2 14
0 0 0

Sample output：
36
*/