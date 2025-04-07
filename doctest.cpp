//
// Created by oriantos on 4/7/25.
//
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Graph.h"
#include "Algorithms.h"

TEST_CASE("BFS Tree") {
    graph::Graph g(5);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 4, 1);
    g.addEdge(3, 5, 1);

    graph::Graph tree = graph::Algorithms::bfs(g, 1);
    CHECK(tree.edgeExists(1, 2));
    CHECK(tree.edgeExists(1, 3));
    CHECK(tree.edgeExists(3, 5));
}

TEST_CASE("DFS Tree") {
    graph::Graph g(5);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 4, 1);
    g.addEdge(3, 5, 1);

    graph::Graph tree = graph::Algorithms::dfs(g, 1);
    bool b1 = tree.edgeExists(1, 2) || tree.edgeExists(1, 3);
    bool b2 = tree.edgeExists(2, 4) || tree.edgeExists(3, 5);
    CHECK(b1==true);
    CHECK(b2 == true);
}

TEST_CASE("Dijkstra Shortest Path Tree") {
    graph::Graph g(5);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 4);
    g.addEdge(2, 4, 1);
    g.addEdge(3, 5, 1);
    g.addEdge(4, 5, 3);

    graph::Graph tree = graph::Algorithms::dijkstra(g, 1);
    bool or1 = tree.edgeExists(1, 3) || tree.edgeExists(2, 4);
    bool or2 = tree.edgeExists(4, 5) || tree.edgeExists(3, 5);
    CHECK(tree.edgeExists(1, 2));
    CHECK(or1 == true);
    CHECK(or2 == true);
}

TEST_CASE("Prim's MST") {
    graph::Graph g(4);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 3);
    g.addEdge(2, 4, 1);
    g.addEdge(3, 4, 4);

    graph::Graph mst = graph::Algorithms::prim(g);
    CHECK(mst.edgeExists(1, 2));
    CHECK(mst.edgeExists(1, 3));
    CHECK(mst.edgeExists(2, 4));
}

TEST_CASE("Kruskal's MST") {
    graph::Graph g(4);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 3);
    g.addEdge(2, 4, 1);
    g.addEdge(3, 4, 4);

    graph::Graph mst = graph::Algorithms::kruskal(g);
    CHECK(mst.edgeExists(1, 2));
    CHECK(mst.edgeExists(1, 3));
    CHECK(mst.edgeExists(2, 4));
}
