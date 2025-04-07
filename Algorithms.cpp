//
// Created by dembi on 02/04/2025.
//

#include "Algorithms.h"
#include "DataStrauctures.h"

namespace graph {
    Graph Algorithms::bfs(Graph& graph, int source) {
    int n = graph.getNumVertices();
    Graph tree(n);
    bool* visited = new bool[n + 1]{false};
    DynamicArray<int> queue;

    visited[source] = true;
    queue.push_back(source);

    while (!queue.is_empty()) {
        int u = queue[0];
        queue.pop_back();

        for (Edge* e = graph.getAdjList()[u]; e; e = e->next) {
            int v = e->vertex;
            if (!visited[v]) {
                visited[v] = true;
                queue.push_back(v);
                tree.addEdge(u, v, e->weight);
            }
        }
    }

    delete[] visited;
    return tree;
}

void dfsHelp(Graph& graph, Graph& tree, int u, bool* visited) {
    visited[u] = true;

    for (Edge* e = graph.getAdjList()[u]; e; e = e->next) {
        int v = e->vertex;
        if (!visited[v]) {
            tree.addEdge(u, v, e->weight);
            dfsHelp(graph, tree, v, visited);
        }
    }
}

Graph Algorithms::dfs(Graph& graph, int source) {
    int n = graph.getNumVertices();
    Graph tree(n);
    bool* visited = new bool[n + 1]{false};

    dfsHelp(graph, tree, source, visited);
    delete[] visited;
    return tree;
}

Graph Algorithms::dijkstra(Graph& graph, int source) {
    int n = graph.getNumVertices();
    Graph tree(n);
    int* dist = new int[n + 1];
    int* parent = new int[n + 1];
    bool* visited = new bool[n + 1]{false};

    for (int i = 1; i <= n; ++i) {
        dist[i] = 1e9;
        parent[i] = -1;
    }
    dist[source] = 0;

    PriorityQueue<std::pair<int, int>> pq; // {distance, vertex}
    pq.push({0, source});

    while (!pq.empty()) {
        auto [_, u] = pq.top(); pq.pop();
        if (visited[u]) continue;
        visited[u] = true;

        for (Edge* e = graph.getAdjList()[u]; e; e = e->next) {
            int v = e->vertex;
            int w = e->weight;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({-dist[v], v}); // Negative because we use max-heap
            }
        }
    }

    for (int v = 1; v <= n; ++v) {
        if (parent[v] != -1)
            tree.addEdge(v, parent[v], dist[v] - dist[parent[v]]);
    }

    delete[] dist;
    delete[] parent;
    delete[] visited;
    return tree;
}

Graph Algorithms::prim(Graph& graph) {
    int n = graph.getNumVertices();
    Graph tree(n);
    bool* visited = new bool[n + 1]{false};

    PriorityQueue<std::pair<int, std::pair<int, int>>> pq; // {weight, {u, v}}

    visited[1] = true;
    for (Edge* e = graph.getAdjList()[1]; e; e = e->next) {
        pq.push({e->weight, {1, e->vertex}});
    }

    while (!pq.empty()) {
        auto [w, edge] = pq.top(); pq.pop();
        int u = edge.first, v = edge.second;

        if (visited[v]) continue;

        tree.addEdge(u, v, w);
        visited[v] = true;

        for (Edge* e = graph.getAdjList()[v]; e; e = e->next) {
            if (!visited[e->vertex]) {
                pq.push({e->weight, {v, e->vertex}});
            }
        }
    }

    delete[] visited;
    return tree;
}

Graph Algorithms::kruskal(Graph& graph) {
    int n = graph.getNumVertices();
    Graph mst(n);
    UnionFind uf(n + 1);
    DynamicArray<std::pair<int, std::pair<int, int>>> edges;

    for (int u = 1; u <= n; ++u) {
        for (Edge* e = graph.getAdjList()[u]; e; e = e->next) {
            if (u < e->vertex) {
                edges.push_back({e->weight, {u, e->vertex}});
            }
        }
    }

    // Simple bubble sort (can replace with quicksort if needed)
    for (int i = 0; i < edges.get_size(); ++i) {
        for (int j = i + 1; j < edges.get_size(); ++j) {
            if (edges[j].first < edges[i].first) {
                std::swap(edges[i], edges[j]);
            }
        }
    }

    for (int i = 0; i < edges.get_size(); ++i) {
        auto [w, pair] = edges[i];
        int u = pair.first, v = pair.second;
        if (!uf.connected(u, v)) {
            uf.unite(u, v);
            mst.addEdge(u, v, w);
        }
    }

    return mst;
}
} // graph