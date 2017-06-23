# Introduction to Homework5 of Algorithm
> Author : 大祥  
> StartTime: 2017-06-23 ，ModifyTime：2017-06-23

## Requirement
**Exercises 22.3-13 singly connected problem**

A directed graph G = (V, E) is singly connected if u ->v implies that G contains at most one simple path from u to v for all vertices u, v ∊ V . Give an efficient algorithm to determine whether or not a directed graph is singly connected.

### Problem definition:
A directed graph G is singly connected if there is at most one simple (i.e. no repeated vertex) path from u to v for every vertex in G. Given an algorithm to determine whether or not a directed graph is singly connected.

### Input:
First line is N, denotes the amount of test case, then there are Ns graph data followed by N. Second line is V, each graph data is composed of V (the number of vertices, <= 1000). Third line is E, the number of edges, it does no size limitation, then followed by Es edges which are denoted by pair of vertex (e.g., 2 4 is vertex 2->4, the first vertex number is 0 of all the vertex). Each vertex is an integer in [0, n-1], also notes that the input edge is not ordered by the start vertex.

### Output:
If the input graph is singly connected, output the ”YES”, or “NO” if not.
The test case number should be printed before the answer.
Please use the blank key to separate test case number and answer.

## Test Example
### input:  
8 5 7  
0 1 0 2 0 3  0 4  1 2   2 3  3 4  
 4 4  
0 1 1 2     1 3 3 2  
 4 4  
0 1 1 2 1 3 2 0  
 4 4  
0 1 0 3 1 2 1 3  
 **6 8**  
**0 1 0 4 1 2 2 0 2 1 3 2 4 5 5 4 **  
 4 3  
0 1 0 3 1 2  
 3  3  
0 1 2 0 2 1  
 3 2  
0 1 2 0  

### output:  
1 NO  
2 NO  
3 YES  
4 NO  
**5 NO**  
6 YES  
7 NO  
8 YES  

**(PS:The 5th output is teacher's example)**

## Introduction to My Program code
### a.此程式所使用之邏輯、原理及語言之概要性說明。
1. 程式语言说明
此 program 用 C++ 语言编写。
2. Data Struct 说明(开始的时候,直觉设计 data struct 成这样:
```
// 节点 node
struct Node {
int id;
int parentIndex;
int child_id;
int d;
int f;
int color;
vector<int> adjId;
};
// 树或图
vector<Node> current_graph_for_add;
struct MoreGraph {
int is_singly_connected;
int edges;
vector<Node> graph;
};
// 存储所有笔资料
vector<MoreGraph> graphList;
```
后来发现这样设计会大大增加时间和空间复杂度,**然后把 struct 全部拆掉**,把 id 作为 index,设计成如下的 data struct:  
用 vector< vector<int> > graph(1000) 存放 node ,用 vector<int> color(1000 , 0)
来存放 graph 的每个 node 的颜色(也就是被搜到的次数),用 vector<int>
result(1000 , 1) 存放所有的 trees 的判定结果。  
vector<int> color(1000 , 0) 中 0、1、2 分别对应了书上的 white、gray、black。  
按照书上定义,**只有当第一次访问(u, v) 时,v 的颜色是黑色时,表明该条边是一条前向边或横向边**。也就是表明这个图不是 singly-connected。

3. 重新设计 data struct 效果
速度有了提升,但是造成新的“无效记忆体引用”问题,苦苦寻找仍未找到,
只好先上传。而且个人猜测,第 3 个测试的超时问题可能也是由于 memory 泄漏导致的。

4. 基本逻辑原理:
本次作业目标是判断一个 graph 是否是 singly connected。
nodes 之间的父子关系已经确定,而且不确定是否只有一棵树。
所以可以使用书上的 DFS 方法:  
**(1) 循环地对每个 graph 操作**  
**(2) 对于当前的 graph :**  
  (2.1) 任意挑选一个 node 作为出发点,开始并设置 node.color 为 1,根据邻接表里的每个 node.child 向下找它的 child_node (color==0) 并将其 child_node.color 设置为 1。如果 node.child 向下找它的
child_node(color==1),那么将设置当前graph.is_singly_connnected =0 并跳出步骤 2 的循环。  
(2.2) 如果这时 child_node 没有 child_node,则标记颜色为 2 后返回上一层即 node 寻找 node 是否还有其它 child_node。  
(2.3) 如果这时 child_node 还有 child_node,则一路向下,直到找到最底层的 child_node。然后再重复(2.2) 的步骤。  
(2.4) 当一路回退到最初的出发点 node,那么接下来回到调用该递归过程
的地方,也就是回到步骤(2.1) 挑选下一个 node.color=0 的出发点。  
**(3) 找完了当前的 graph,储存结果是否是 single connected graph 到 result 中。** 然后回到步骤 1,继续下一个 tree 的输入以及判定。
