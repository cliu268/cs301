// Packing Limited and Unlimited Items
// https://xjoi.net/contest/5167/problem/2
/*
Time Limit: 1s    Memory  Limit: 128M
Description :
A traveler has a backpack of a maximum capacity V kilograms (kg). There are now n items with weights of W1, W2, ..., Wn. And 
these items each have the values of C1, C2, ..., Cn. Some items can only be taken once (01 items), some items can be taken 
unlimited times (complete items), and some items can be taken up to an upper limit (multiple items) by maximum.

Pelase find a way to package these items to the backpack so that
1, the total weight does not exceed the capacity (V) of the backpage, and meanwhile
2, these items in the backpack in total have the maximum values if you add each individual value to gether.

Input :
The first line: two integers, V (package capacity, V <= 200), N (number of items, N <= 30);
Line 2 to N+1: Each line has three integers Wi, Ci, Pi. The first two integers respectively represents the weight and value of 
each item. Any non-zero Pi means the how many time item-i can be purchased by maximum. Pi=0 means, however, means that item can 
be purchased (and packed into the backpack) unlimited times. 0<=Pi<=20.

Output:
One number as the maximum total value of the items that can be packed to the backpack.

Sample input:
10 3
2 1 0
3 3 1
4 5 4

Sample output:
11

Hint:
Choose 1 piece for the first item and 2 pieces for the third item.
*/