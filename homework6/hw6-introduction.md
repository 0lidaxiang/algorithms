# Introduction to Homework6 of Algorithm
> Author : 大祥  
> StartTime: 2017-06-23 ，ModifyTime：2017-06-23

## Requirement
**Chap24 Kruskal's and Prim's algorithm**

### Problem definition:  
Give two programs that implement Kruskal’s and Prim’s algorithm.

### Input:
First line is N, denotes the amount of test case, then there are Ns graph data with an option number (determine whether output the selected edges or not).

Each graph is undirected and connected, it is composed of V (the number of vertices, <= 1000), E (the number of edges, <=10000), then followed by Es edges which are denoted by pair of vertex and weight (e.g., 2  4  10 means an edge connecting vertices 2 and 4, and its weight is 10).

The first data’s weight of each graph is option number. It could be 1 or 2, output the selected edge and the sum of all minimum spanning tree’s weight if it is 1, or only the sum if it is 2.

We restrict that selected node of Prim always start from 0, and there is no “tree edge” with same weight.

### Output:

If option is 1:  
The selected edges which forms the spanning tree. Order is important! The sum of all edges weight in minimum spanning tree. Note that the edge should put smaller node first, e.g., if the edge (4, 2) is selected, it should be output by 2 4, not 4 2.

If option is 2:  
The sum of all edges weight in minimum spanning tree.

### Other:
1.    The program is submitted directly to the e-Tutor system platform for verification.

2.    Documentation (HW6_Student ID.pdf) is submitted to Moodle system platform, the content must include:  
  1. A summary of the logic, principles, compiler environment and language used in this program.  
  2. Details of the program content (source code and its notes) and with the flow chart or pseudo code explanation.

## Test Example
### Input:
2  
5 7 1  
0 2 1  
2 1 6  
4 2 7  
1 4 2  
1 3 5  
3 0 3  
3 2 4

6 12 2  
1 0 5  
0 4 1  
4 5 10  
4 3 4  
3 0 9  
0 5 2  
2 0 8  
2 1 3  
5 2 11  
2 3 6  
3 5 7  
1 5 12

### Output:
**(Using Kruskal’s algorithm)**  
0 2  
1 4  
0 3  
1 3  
11  
15

**(Using Prim’s algorithm)**  
0 2  
0 3  
1 3  
1 4  
11  
15

## Introduction to My Program code
### a.此程式所使用之邏輯、原理及語言之概要性說明。
** 1. 程式语言说明**  
此 program 用 python 语言编写。

**2. 数据结构**  
kruskal algotithms 用一个 graph 变数存放图,graph.vertexs 存放节点,graph.edges 存放所有的 edge。
prim algotithms 用一个 g 变数存放图,如果一个 input 是 a、b、w 这样格式,那么 g[a]存放(w, b),g[b]存放(w, a)。方便后面 algorithm 运算,但在输出结果时就要留心如何输出。

**3. 基本逻辑原理**  
对于 kruskal algotithms,基本和书上类似,不作详细说明。
对于 prim algotithms,graph 的 data structure 设计有点特别,并用 python 中的
heapq 堆模块来保存 minimum priority queue。
