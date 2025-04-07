#include <cstdio>
#include "Graph.h"

namespace graph {
    Edge *Graph::createEdge(int vertex, int weight, Edge *next) {
        Edge *newEdge = new Edge;
        newEdge->vertex = vertex;
        newEdge->weight = weight;
        newEdge->next = next;
        return newEdge;
    }

    bool Graph::edgeExists(int u, int v) {
        Edge *temp = adjList[u];
        while (temp) {
            if (temp->vertex == v) return true;
            temp = temp->next;
        }
        return false;
    }

    bool Graph::removeDirectedEdge(int u, int v) {
        Edge *curr = adjList[u];
        Edge *prev = nullptr;

        while (curr) {
            if (curr->vertex == v) {
                if (prev) prev->next = curr->next;
                else adjList[u] = curr->next;
                delete curr;
                return true;
            }
            prev = curr;
            curr = curr->next;
        }
        return false;
    }

    void Graph::sort(int src) {
        Edge *curr = adjList[src];
        if (!curr) return;
        while (curr) {
            Edge *min = findMin(curr);
            if (min->vertex != curr->vertex) {
                std::swap(*min, *curr);
            }
            curr = curr->next;
        }
    }

    Edge *Graph::findMin(Edge *src) {
        Edge *curr = src;
        Edge *min = curr;
        while (curr) {
            if (curr->vertex < min->vertex) {
                min = curr;
            }
            curr = curr->next;
        }
        return min;
    }

    Graph::Graph(int n) {
        numVertices = n;
        adjList = new Edge *[n + 1];
        for (int i = 1; i <= n; ++i) {
            adjList[i] = nullptr;
        }
    }

    Graph::~Graph() {
        for (int i = 1; i <= numVertices; ++i) {
            Edge *curr = adjList[i];
            while (curr) {
                Edge *temp = curr;
                curr = curr->next;
                delete temp;
            }
        }
        delete[] adjList;
    }

    void Graph::addEdge(int u, int v, int w) {
        if (u < 1 || u > numVertices || v < 1 || v > numVertices) {
            printf("Error: Vertex out of range\n");
            return;
        }

        if (edgeExists(u, v)) {
            printf("Edge (%d, %d) already exists. Not adding again.\n", u, v);
            return;
        }

        adjList[u] = createEdge(v, w, adjList[u]);
        adjList[v] = createEdge(u, w, adjList[v]);
    }

    void Graph::removeEdge(int u, int v) {
        if (!edgeExists(u, v)) {
            printf("Error: Edge (%d, %d) does not exist\n", u, v);
            return;
        }
        removeDirectedEdge(u, v);
        removeDirectedEdge(v, u);
    }

    void Graph::printGraph() {
        for (int i = 1; i <= numVertices; ++i) {
            printf("Vertex %d:", i);
            Edge *curr = adjList[i];
            while (curr) {
                printf(" -> (%d, w=%d)", curr->vertex, curr->weight);
                curr = curr->next;
            }
            printf("\n");
        }
    }
} // namespace graph
