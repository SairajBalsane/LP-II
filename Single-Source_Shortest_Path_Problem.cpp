#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int destination;
    int weight;
    
    Edge(int dest, int w) : destination(dest), weight(w) {}
};

// Structure to represent a vertex in the graph
struct Vertex {
    vector<Edge> edges;
};

// Function to perform Greedy Search for Single-Source Shortest Path
vector<int> greedyShortestPath(const vector<Vertex>& graph, int source) {
    int n = graph.size(); // Number of vertices in the graph
    vector<int> distances(n, numeric_limits<int>::max()); // Initialize distances to infinity
    vector<bool> visited(n, false); // Initialize all vertices as not visited
    
    distances[source] = 0; // Distance to source vertex is 0
    
    // Priority queue to store vertices based on their distances
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, source));
    
    while (!pq.empty()) {
        // Extract the vertex with minimum distance
        int u = pq.top().second;
        pq.pop();
        
        // If vertex is already visited, skip it
        if (visited[u])
            continue;
        
        visited[u] = true; // Mark vertex as visited
        
        // Update distances to adjacent vertices
        for (const Edge& edge : graph[u].edges) {
            int v = edge.destination;
            int weight = edge.weight;
            if (!visited[v] && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                pq.push(make_pair(distances[v], v));
            }
        }
    }
    
    return distances;
}

int main() {
    int numVertices = 5;
    vector<Vertex> graph(numVertices);
    
    // Add edges to the graph (example graph)
    graph[0].edges.push_back(Edge(1, 10));
    graph[0].edges.push_back(Edge(2, 5));
    graph[1].edges.push_back(Edge(2, 2));
    graph[1].edges.push_back(Edge(3, 1));
    graph[2].edges.push_back(Edge(1, 3));
    graph[2].edges.push_back(Edge(3, 9));
    graph[2].edges.push_back(Edge(4, 2));
    graph[3].edges.push_back(Edge(4, 4));
    
    int source = 0; // Source vertex
    
    // Perform Greedy Search for Single-Source Shortest Path
    vector<int> distances = greedyShortestPath(graph, source);
    
    // Print shortest distances from source
    cout << "Shortest distances from source " << source << ":" << endl;
    for (int i = 0; i < numVertices; ++i) {
        cout << "Vertex " << i << ": " << distances[i] << endl;
    }
    
    return 0;
}
