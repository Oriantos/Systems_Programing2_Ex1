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

        bool removeDirectedEdge(int u, int v);

        void sort(int src);

        Edge *findMin(Edge *src);

    public:
        Graph(int n);

        ~Graph();

        bool edgeExists(int u, int v);

        int getNumVertices() const {
            return numVertices;
        }

        Edge **getAdjList() const {
            return adjList;
        }

        void addEdge(int u, int v, int w);

        void removeEdge(int u, int v);

        void print();
    };
} // namespace graph

#endif // GRAPH_H
