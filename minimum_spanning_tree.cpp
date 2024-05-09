#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>
#include <climits>

using namespace std;

typedef pair<double, int> pdi; // pair of (distance, vertex)

class Graph {
private:
    int V;
    vector<vector<double>> adj;

public:
    Graph(int V) : V(V), adj(V, vector<double>(V, 0)) {}

    void addEdge(int u, int v, double weight) {
        adj[u][v] = weight;
        adj[v][u] = weight;
    }

    double primMST() {
        priority_queue<pdi, vector<pdi>, greater<pdi>> pq;
        vector<bool> visited(V, false);
        double minCost = 0;

        // Start from vertex 0
        pq.push({0, 0});

        while (!pq.empty()) {
            int u = pq.top().second; // Vertex
            double d = pq.top().first;  // Distance
            pq.pop();

            // Skip if already visited
            if (visited[u])
                continue;

            minCost += d; // Add distance to MST
            visited[u] = true;

            // Add all adjacent vertices of u to the priority queue
            for (int v = 0; v < V; ++v) {
                if (!visited[v] && adj[u][v] != 0)
                    pq.push({adj[u][v], v});
            }
        }

        return minCost;
    }
};

int main() {
    int V; // Number of vertices
    cout << "Enter the number of points: ";
    cin >> V;

    Graph g(V);

    // Input points
    vector<pair<double, double>> points(V);
    cout << "Enter the coordinates of each point (x y):" << endl;
    for (int i = 0; i < V; ++i) {
        double x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }

    // Calculate distances between points and add edges to the graph
    for (int i = 0; i < V; ++i) {
        for (int j = i + 1; j < V; ++j) {
            double distance = sqrt(pow(points[i].first - points[j].first, 2) +
                                   pow(points[i].second - points[j].second, 2));
            g.addEdge(i, j, distance);
        }
    }

    double minCost = g.primMST();
    cout << "Minimum Cost of MST: " << minCost << endl;

    return 0;
}
