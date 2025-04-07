//
// Created by dembi on 02/04/2025.
//

#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include "Graph.h"

namespace graph {

class Algorithms {
    public:
    static Graph bfs(Graph& graph, int source);
    static Graph dfs(Graph& graph, int source);
    static Graph dijkstra(Graph& graph, int source);
    static Graph prim(Graph& graph);
    static Graph kruskal(Graph& graph);
};

} // graph

#endif //ALGORITHMS_H
