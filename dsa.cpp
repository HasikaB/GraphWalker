#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Node {
    int destination;
    int weight;
};

class Graph {
    int numVertices;
    vector<vector<Node> > adjacencyList;

public:
    Graph(int V) : numVertices(V) {
        adjacencyList.resize(V);
    }

    void addEdge(int source, int destination, int weight) {
        Node newNode;
        newNode.destination = destination;
        newNode.weight = weight;
        adjacencyList[source].push_back(newNode);
        newNode.destination = source; // For undirected graph
        adjacencyList[destination].push_back(newNode);
    }

    void dijkstra(int start) {
        vector<int> distances(numVertices, INF);
        distances[start] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

        pq.push(make_pair(0, start));

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (vector<Node>::iterator it = adjacencyList[u].begin(); it != adjacencyList[u].end(); ++it) {
    const Node &neighbor = *it;
    // ... Rest of your code here


                int v = neighbor.destination;
                int weight = neighbor.weight;

                if (distances[v] > distances[u] + weight) {
                    distances[v] = distances[u] + weight;
                    pq.push(make_pair(distances[v], v));
                }
            }
        }

        cout << "Shortest distances using Dijkstra's from node " << start << ":\n";
        for (int i = 0; i < numVertices; ++i) {
            cout << "Node " << i << ": ";
            if (distances[i] == INF) {
                cout << "INF\n";
            } else {
                cout << distances[i] << "\n";
            }
        }
    }

    void bellmanFord(int start) {
        vector<int> distances(numVertices, INF);
        distances[start] = 0;

        for (int i = 1; i <= numVertices - 1; ++i) {
            for (int u = 0; u < numVertices; ++u) {
                for (vector<Node>::iterator it = adjacencyList[u].begin(); it != adjacencyList[u].end(); ++it) {
    const Node &neighbor = *it;
    // ... Rest of your code here


                    int v = neighbor.destination;
                    int weight = neighbor.weight;

                    if (distances[u] != INF && distances[u] + weight < distances[v]) {
                        distances[v] = distances[u] + weight;
                    }
                }
            }
        }

        cout << "Shortest distances using Bellman-Ford from node " << start << ":\n";
        for (int i = 0; i < numVertices; ++i) {
            cout << "Node " << i << ": ";
            if (distances[i] == INF) {
                cout << "INF\n";
            } else {
                cout << distances[i] << "\n";
            }
        }
    }

    void dfsUtil(int node, vector<bool> &visited) {
        visited[node] = true;
        cout << node << " ";

        for (vector<Node>::const_iterator it = adjacencyList[node].begin(); it != adjacencyList[node].end(); ++it) {
    const Node &neighbor = *it;
    // ... Rest of your code here


            if (!visited[neighbor.destination]) {
                dfsUtil(neighbor.destination, visited);
            }
        }
    }

    void dfs(int start) {
        vector<bool> visited(numVertices, false);
        cout << "Depth-First Search (DFS) traversal: ";
        dfsUtil(start, visited);
        cout << endl;
    }

    void bfs(int start) {
        vector<bool> visited(numVertices, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "Breadth-First Search (BFS) traversal: ";
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";

            for (vector<Node>::const_iterator it = adjacencyList[u].begin(); it != adjacencyList[u].end(); ++it) {
    const Node &neighbor = *it;
    


                int v = neighbor.destination;
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    int numVertices = 5; // Number of vertices in the graph
    Graph graph(numVertices);

    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 2);
    graph.addEdge(1, 4, 3);
    graph.addEdge(2, 3, 2);
    graph.addEdge(3, 4, 3);

    int startNode = 0; // Starting node for algorithms

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Dijkstra's Algorithm\n";
        cout << "2. Bellman-Ford Algorithm\n";
        cout << "3. Depth-First Search (DFS)\n";
        cout << "4. Breadth-First Search (BFS)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                graph.dijkstra(startNode);
                break;
            case 2:
                graph.bellmanFord(startNode);
                break;
            case 3:
                graph.dfs(startNode);
                break;
            case 4:
                graph.bfs(startNode);
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}

