#!/usr/bin/python
# -*- coding: UTF-8 -*-
import sys

parent = dict()
rank = dict()
# mark the vertex parent(This means distinguishing trees.)
def make_set(vertex):
    parent[vertex] = vertex
    rank[vertex] = 1000
# check two vertex whether belongs to one tree
def find(vertex):
    if parent[vertex] != vertex:
        parent[vertex] = find(parent[vertex])
    return parent[vertex]
# union two trees
def union(vertex1, vertex2):
    root1 = find(vertex1)
    root2 = find(vertex2)
    if root1 != root2:
        if rank[root1] > rank[root2]:
            parent[root2] = root1
        else:
            parent[root1] = root2
            if rank[root1] == rank[root2]: rank[root2] += 1
# kruskal algorithms (nondecresing order by weight)
def kruskal(graph):
    minimum_spanning_tree = set()
    for vertex in graph['vertexs']:
        make_set(vertex)
    
    edges = list(graph['edges'])
    edges.sort(reverse=False)
    for edge in edges:
        weight, vertex1, vertex2 = edge
        if find(vertex1) != find(vertex2):
            union(vertex1, vertex2)
            minimum_spanning_tree.add(edge)
    return minimum_spanning_tree

# get the number of data
n = int(raw_input())
initial_n = n

option=0
result_cost = []
result_edges = []
result_temp_edges = []
while n > 0: 
        graph = {
        'vertexs': [],
        'edges': []
        }

        # get the user input of vertex number, edges number, weight, and edges  
        input1 = sys.stdin.readline()
        if input1 == '\n':
            input1 = sys.stdin.readline()
            input1list = input1.split(" ")
            vertex_num = int(input1list[0])
            edge_num = int(input1list[1])
            option = int(input1list[2])
        else:
            input1list = input1.split(" ")
            vertex_num = int(input1list[0])
            edge_num = int(input1list[1])
            option = int(input1list[2])

        # initial the vertexs of graph by vertext number
        for v in xrange(0,vertex_num):
            graph['vertexs'].append(str(v))

        # initial the edges of graph by getting from user input
        for e in xrange(0,edge_num):
            input2 = sys.stdin.readline()
            input2 = input2.split("\n")[0]
            input2list = input2.split(" ")
            w = int(input2list[2])
            v1 = input2list[0]
            v2 = input2list[1]
            graph['edges'].append((w, v1, v2))
        
        # initial the minimum_spanning_tree
        minimum_spanning_tree = set([])
        minimum_spanning_tree = kruskal(graph) 

        # anyway,we should complete the cost when in shortest path
        temp_cost = 0
        for edge in minimum_spanning_tree:
                temp_cost += edge[0]
        result_cost.append(temp_cost)

        # if option=1,we should record the edges when in shortest path
        if option==1:
            # sort the temp result_edges by weight nondecreseing
            for e in minimum_spanning_tree:
                result_temp_edges.append((e[0], e[1], e[2]))
            result_temp_edges.sort()

            # result
            for e in result_temp_edges:
                # small edge will at first station
                if e[1] < e[2]:
                    result_edges.append((e[1], e[2]))
                else:
                    result_edges.append((e[2], e[1]))
        n = n -1
# print the result of edges and cost
for res in result_edges:
    print res[0], res[1]
for res in result_cost:
    print res