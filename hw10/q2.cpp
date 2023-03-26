// MooTube
// https://xjoi.net/contest/5450/problem/2
/*
In his spare time, Farmer John has created a new video-sharing service, which he names MooTube. On MooTube, Farmer John's cows 
can record, share, and discover many amusing videos. His cows already have posted N videos (1≤N≤5000), conveniently numbered 1…N. 
However, FJ can't quite figure out how to help his cows find new videos they might like.

FJ wants to create a list of "suggested videos" for every MooTube video. This way, cows will be recommended the videos most 
relevant to the ones they already watch.

FJ devises a metric of "relevance," which determines, as the name suggests, how relevant two videos are to each other. He picks 
N−1 pairs of videos and manually computes their pairwise relevance. Then, FJ visualizes his videos as a network, where each video 
is a node and the N−1 pairs of videos he manually considered are connected. Conveniently, FJ has picked his N−1 pairs so that any 
video can be reached from any other video along a path of connections in exactly one way. FJ decides that the relevance of any 
pair of videos should be defined as the minimum relevance of any connection along this path.

Farmer John wants to pick a value K so that next to any given MooTube video, all other videos with relevance at least K to that 
video will be suggested. However, FJ is worried that too many videos will be suggested to his cows, which could distract them from 
milk production! Therefore, he wants to carefully set an appropriate value of K. Farmer John would like your help answering a 
number of questions about the suggested videos for certain values of K.

INPUT FORMAT (file mootube.in):
The first line of input contains N and Q (1≤Q≤5000).
The next N−1 lines each describe a pair of videos FJ manually compares. Each line includes three integers pi, qi, and ri 
(1≤pi,qi≤N,1≤ri≤1,000,000,000), indicating that videos pi and qi are connected with relevance ri.

The next Q lines describe Farmer John's Q questions. Each line contains two integers, ki and vi (1≤ki≤1,000,000,000,1≤vi≤N), 
indicating that FJ's ith question asks how many videos will be suggested to viewers of video vi if K=ki.

OUTPUT FORMAT (file mootube.out):
Output Q lines. On line i, output the answer to FJ's ith question.

SAMPLE INPUT:
4 3
1 2 3
2 3 2
2 4 4
1 2
4 1
3 1

SAMPLE OUTPUT:
3
0
2

Farmer John finds that videos one and two have relevance three, that videos two and three have relevance two, and that videos two 
and four have relevance four. Based on this, videos one and three have relevance min(3, 2) = 2, videos one and four have relevance 
min(3, 4) = 3, and videos three and four have relevance min(2, 4) = 2.

Farmer John wants to know how many videos will be suggested from video two if K=1, from video one if K=3, and from video one if K=4. 
We see that with K=1, videos 1, 3, and 4 will be suggested on video two. With K=4, no videos will be suggested from video one. 
With K=3, however, videos 2 and 4 will be suggested from video one.

Problem credits: Jay Leeds
*/