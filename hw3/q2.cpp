// Book Shop
// https://xjoi.net/contest/5119/problem/2
/*
You are in a book shop which sells n different books. You know the price and number of pages of each book.
You have decided that the total price of your purchases will be at most x. What is the maximum number of pages you can buy? 
You can buy each book at most once.

Input
The first input line contains two integers n and x: the number of books and the maximum total price.
The next line contains n integers h1,h2,…,hn: the price of each book.
The last line contains n integers s1,s2,…,sn: the number of pages of each book.

Output
Print one integer: the maximum number of pages.

Constraints
1≤n≤1000
1≤x≤10^5
1≤hi,si≤1000

Sample Input:
4 10
4 8 5 3
5 12 8 1

Sample Output:
13

Explanation: You can buy books 1 and 3. Their price is 4+5=9 and the number of pages is 5+8=13.

Hint:
Try to implement all the problems using the most efficient method: iterative with 1-D dp array.
*/