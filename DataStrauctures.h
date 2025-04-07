//
// Created by dembi on 07/04/2025.
//

#ifndef DATASTRAUCTURES_H
#define DATASTRAUCTURES_H

namespace graph {
    template<typename T>
    class DynamicArray {
    private:
        T *data;
        int capacity;
        int size;

        void resize(int newCapacity);

    public:
        DynamicArray();

        ~DynamicArray();

        void push_back(const T &value);

        void pop_back();

        T &operator[](int index);

        const T &operator[](int index) const;

        int get_size() const;

        bool is_empty() const;

        void clear();
    };

    template<typename T>
    class PriorityQueue {
    private:
        DynamicArray<T> heap;

        void heapify_up(int index);

        void heapify_down(int index);

        bool compare(const T &a, const T &b); // Min-heap by default

    public:
        PriorityQueue();

        void push(const T &value);

        void pop();

        const T &top() const;

        bool empty() const;

        int size() const;
    };

    template<typename T>
    class UpPriorityQueue {
    private:
        DynamicArray<T> heap;

        void heapify_up(int index);

        void heapify_down(int index);

        bool compare(const T &a, const T &b); // Max-heap logic

    public:
        UpPriorityQueue();

        void push(const T &value);

        void pop();

        const T &top() const;

        bool empty() const;

        int size() const;
    };

    class UnionFind {
    private:
        int *parent;
        int *rank;
        int size;

    public:
        UnionFind(int n);

        ~UnionFind();

        int find(int x);

        void unite(int x, int y);

        bool connected(int x, int y);
    };
} // graph

#endif //DATASTRAUCTURES_H
