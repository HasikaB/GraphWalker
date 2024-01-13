# GRAPHWALKER

This C++ code represents a program that works with graphs, which are a way to model relationships between entities. 

1. Graph Representation:
   - The code uses a class named `Graph` to represent an undirected graph.
   - Vertices and edges of the graph are stored in an adjacency list.

2. Graph Operations:
   - The code provides implementations for common graph operations, including Dijkstra's algorithm for finding the shortest paths, Bellman-Ford algorithm for the same purpose with support for negative weights, and both Depth-First Search (DFS) and Breadth-First Search (BFS) for traversing the graph.

3. Algorithm Implementations:
   - Dijkstra's Algorithm: Finds the shortest paths from a starting node to all other nodes in the graph using a priority queue to efficiently select the next node to explore.
   - Bellman-Ford Algorithm: Similar to Dijkstra's but works with graphs that may have negative-weight edges. It iteratively updates distance estimates for each node.
   - Depth-First Search (DFS): Traverses the graph in a depthward motion, exploring as far as possible along each branch before backtracking.
   - Breadth-First Search (BFS): Traverses the graph level by level, exploring all neighbors of a node before moving on to their neighbors.

4. Menu-Driven Interface:
   - The code provides a user-friendly menu in the `main()` function, allowing the user to choose which algorithm to execute or to exit the program.

5. Example Graph:
   - An example graph is created in the `main()` function with 5 vertices and specific edges, demonstrating how the implemented algorithms work on a simple dataset.

6. User Interaction:
   - The user is prompted with a menu where they can choose the algorithm they want to run on the example graph.

7. Output:
   - The program outputs the results of the chosen algorithm, displaying information such as the shortest distances from a starting node to all other nodes.

 This code provides a flexible framework for working with graphs and efficiently computing various properties using well-known algorithms. It demonstrates the versatility of C++ in implementing complex data structures and algorithms.
