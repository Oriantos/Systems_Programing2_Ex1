#include <iostream>
#include "Graph.h"
#include "DataStrauctures.h"
#include "Algorithms.h"

int main() {
    // Create a graph with 5 nodes
    graph::Graph g(5);

    // Add some edges
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 7);
    g.addEdge(2, 4, 3);
    g.addEdge(3, 4, 1);

    std::cout << "Graph created.\n";
    g.print();
    std::cout << "Running BFS from node 0:\n";
    graph::Graph bfs = graph::Algorithms::bfs(g, 0);
    bfs.print();

    std::cout << "\nRunning DFS from node 0:\n";
    graph::Graph dfs = graph::Algorithms::dfs(g, 0);
    dfs.print();

    std::cout << "\nRunning Dijkstra from node 0:\n";
    graph::Graph d = graph::Algorithms::dijkstra(g, 0);
    d.print();

    std::cout << "\nRunning Prim's MST:\n";
    graph::Graph prim = graph::Algorithms::prim(g);
    prim.print();

    std::cout << "\nRunning Kruskal's MST:\n";
    graph::Graph kruskal = graph::Algorithms::kruskal(g);
    kruskal.print();

    return 0;
}
