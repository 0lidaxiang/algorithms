#!/usr/bin/python
# -*- coding: UTF-8 -*-

import heapq
import sys
from collections import defaultdict

result_edges = []
result_cost = []

# get the number of data
data = int(raw_input())
# get user input and prim algorithms 
while data > 0:
    result_temp_edges = []
    op = 0
    g = defaultdict(list)
    weight = 0 
    connected = set([])
    pq = []

    # get the user input of vertex number, edges number, weight, and edges 
    # n is the number of nodes m is the number of vertexs
    # m is the number of nodes m is the number of edges
    input1 = sys.stdin.readline()
    if input1 == '\n':
        input1 = sys.stdin.readline()
        inputlist = input1.split("\n")[0].split(" ")
        n = int(inputlist[0])
        m = int(inputlist[1])
        op = int(inputlist[2])
        #create adjacency list from inputs of the form "vertex1 vertex2 weight"
        for e in xrange(0,m):
            inputlist = sys.stdin.readline().split("\n")[0].split(" ")
            a = int(inputlist[0])
            b = int(inputlist[1])
            w = int(inputlist[2])
            g[a].append((w, b))
            g[b].append((w, a))
    else:
        # when not turn line
        inputlist = input1.split("\n")[0].split(" ")
        n = int(inputlist[0])
        m = int(inputlist[1])
        op = int(inputlist[2])
        for e in xrange(0,m):
            inputlist = sys.stdin.readline().split("\n")[0].split(" ")
            a = int(inputlist[0])
            b = int(inputlist[1])
            w = int(inputlist[2])
            g[a].append((w, b))
            g[b].append((w, a))

    # set the start vertex
    connected.add(0)
    # initial minimum priority queue
    for tup in g[0]:
        heapq.heappush(pq, tup)
    # print edges by option value
    if op==1:
        while pq:
            # 
            w, b = heapq.heappop(pq)
            if b not in connected:
                weight += w
                for w_a in g[b]:
                    if w_a[0]==w:
                        if b < w_a[1]:
                            result_edges.append((w, b, w_a[1]))
                        else:
                            result_edges.append((w, w_a[1], b))
                # record the visited vertex
                connected.add(b)
                # update minimum priority queue
                for tup in g[b]:
                    heapq.heappush(pq, tup)
    # not print edges by option value
    if op==2:
        while pq:
            w, b = heapq.heappop(pq)
            if b not in connected:
                weight += w
                # record the visited vertex
                connected.add(b)
                # update minimum priority queue
                for tup in g[b]:
                    heapq.heappush(pq, tup)
    # save the smallest cost
    result_cost.append(weight)   
    data = data - 1

# print result
for res in result_edges:
    print res[1], res[2]
for res in result_cost:
    print res
