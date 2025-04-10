//
// Created by dembi on 07/04/2025.
//

#include "DataStrauctures.h"

namespace graph {
    //UnionFind
    UnionFind::UnionFind(int n) {
        size = n;
        parent = new int[size];
        rank = new int[size];

        for (int i = 0; i < size; ++i) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    UnionFind::~UnionFind() {
        delete[] parent;
        delete[] rank;
    }

    int UnionFind::find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    void UnionFind::unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return;

        // Union by rank
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }

    bool UnionFind::connected(int x, int y) {
        return find(x) == find(y);
    }
} // graph
