// Longest Word Chain
// https://xjoi.net/contest/5168/problem/3
/*
Time limit:1000, Memory Limit: 65536
Description:
Given a list of English words containing only lowercase letters, each of which contains a maximum of 50 letters.
If a table consisting of one word or more words, each word (except the last one) is the prefix of the word after it, the table is 
called a word chain. For example, the following words form a chain of words:
i
int
integer
The following words do not form a word chain:
integer
intern
Please take some words in the given word list to form the longest word chain. The longest word chain is the chain of words that 
contains the most words.
The data guarantees that the words in the given word list are different from each other and the words are arranged in lexicographic 
order.

Input:
The first line is an integer n, indicating the number of words in the word list
Next line is n words per line.

Output:
An integer representing the length of the longest word chain.

Sample input:
5
i
int
integer
intern
internet

Sample output:
4

data range:
50% of the data, n<=1000
100% data, n<=10000
*/