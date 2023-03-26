// Intersection Points
// https://xjoi.net/contest/5451/problem/1
/*
Given n horizontal and vertical line segments, your task is to calculate the number of their intersection points.
You can assume that no parallel line segments intersect, and no endpoint of a line segment is an intersection point.

Input
The first input line has an integer n: the number of line segments.
Then there are n lines describing the line segments. Each line has four integers: x1, y1, x2 and y2: a line segment begins at 
point (x1,y1) and ends at point (x2,y2).

Output
Print the number of intersection points.

Constraints
1≤n≤105
−10^6 ≤ x1 ≤ x2 ≤ 10^6
−10^6 ≤ y1 ≤ y2 ≤ 10^6
(x1,y1) ≠ (x2,y2)

Example
Input:
3
2 3 7 3
3 1 3 5
6 2 6 6

Output:
2
*/