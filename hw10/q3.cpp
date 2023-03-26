// Gallery
// https://xjoi.net/contest/5450/problem/3
/*
Peel is a famous theft. After months of careful preparation, Peel plans to steal paintings from a museum. The museum consists of 
hallways and exhibition rooms. A hallway either bifurcates into another two hallways, or leads to an exhibition room. No two 
hallways lead to the same exhibition room. It takes Peel certain amount of time to pass a hallway. There are a certain number of 
paintings in an exhibition room. Once in the exhibition room, it takes Peel 5 seconds to take a painting.

Peel starts his adventure from the front door of the museum. He must return to the front door at the end of his adventure, with 
paintings he is able to steal if any.

Given the complete map of the museum, the time it takes for Peel to pass each hallway, the number of paintings in each exhibition 
room, and the total amount of time that Peel has for his adventure, please calculate the maximum number of paintings that Peel can 
steal and return to his starting location.

1.GIF 

Input：
The first line is the total amount of time, in seconds, Peel has for his adventure.
The second line describes the structure of the museum, which is a string of non-negative integer pairs.
A pair represents a hallway, and the number of paintings in an exhibition room if the hallways leads to an exhibition room. 
The first number of a pair is the time it takes Peel to pass the hallway. The second number of a pair can be either zero or a 
positive number. If the second number is zero, the hallway bifurcates into another two hallways. If the seond number is positive, 
it is the number of paintings in the exhibition room that the hallway leads to.
The pairs are presented in the order of a binary tree's pre-order traversal 
(https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/). See the sample input below.

Output：
The maximum number of paintings Peel can steal and return to his starting location.

Sample input (corresponding to above museum map)：
60
7 0 8 0 3 1 14 2 10 0 12 4 6 2

Sample output：
2

Data range：
The time police arrived <=600

Time limit：
1000

Memory limit：
65536
*/