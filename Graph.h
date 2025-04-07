//
// Created by oriantos on 3/26/25.
//

#ifndef GRAPH_H
#define GRAPH_H
#include <stddef.h>
#include <cstdio>
#include <iostream>

namespace graph {
    struct Edge {
        int vertex;
        int weight;
        Edge *next;
    };

    class Graph {
    private:
        int numVertices;
        Edge **adjList;

        Edge *createEdge(int vertex, int weight, Edge *next = nullptr);

        bool edgeExists(int u, int v);

        bool removeDirectedEdge(int u, int v);

        void sort(int src);

        Edge *findMin(Edge *src);

    public:
        Graph(int n);

        ~Graph();

        int Graph::getNumVertices() const {
            return numVertices;
        }

        Edge **Graph::getAdjList() const {
            return adjList;
        }

        void addEdge(int u, int v, int w);

        void removeEdge(int u, int v);

        void printGraph();
    };
} // namespace graph

#endif // GRAPH_H
