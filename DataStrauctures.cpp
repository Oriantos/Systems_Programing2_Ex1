//
// Created by dembi on 07/04/2025.
//

#include "DataStrauctures.h"

namespace graph {
    // LIST
    template<typename T>
    DynamicArray<T>::DynamicArray() : data(nullptr), capacity(0), size(0) {
    }

    template<typename T>
    DynamicArray<T>::~DynamicArray() {
        delete[] data;
    }

    template<typename T>
    void DynamicArray<T>::resize(int newCapacity) {
        T *newData = new T[newCapacity];
        for (int i = 0; i < size; ++i)
            newData[i] = data[i];
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

    template<typename T>
    void DynamicArray<T>::push_back(const T &value) {
        if (size == capacity)
            resize(capacity == 0 ? 1 : capacity * 2);
        data[size++] = value;
    }

    template<typename T>
    void DynamicArray<T>::pop_back() {
        if (size > 0) --size;
    }

    template<typename T>
    T &DynamicArray<T>::operator[](int index) {
        return data[index];
    }

    template<typename T>
    const T &DynamicArray<T>::operator[](int index) const {
        return data[index];
    }

    template<typename T>
    int DynamicArray<T>::get_size() const {
        return size;
    }

    template<typename T>
    bool DynamicArray<T>::is_empty() const {
        return size == 0;
    }

    template<typename T>
    void DynamicArray<T>::clear() {
        delete[] data;
        data = nullptr;
        size = 0;
        capacity = 0;
    }

    //priorityQueue
    template<typename T>
    PriorityQueue<T>::PriorityQueue() {
    }

    template<typename T>
    bool PriorityQueue<T>::compare(const T &a, const T &b) {
        return a < b; // Min-heap
    }

    template<typename T>
    void PriorityQueue<T>::heapify_up(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (compare(heap[index], heap[parent])) {
                T temp = heap[index];
                heap[index] = heap[parent];
                heap[parent] = temp;
                index = parent;
            } else {
                break;
            }
        }
    }

    template<typename T>
    void PriorityQueue<T>::heapify_down(int index) {
        int n = heap.get_size();
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            if (left < n && compare(heap[left], heap[smallest])) smallest = left;
            if (right < n && compare(heap[right], heap[smallest])) smallest = right;

            if (smallest != index) {
                T temp = heap[index];
                heap[index] = heap[smallest];
                heap[smallest] = temp;
                index = smallest;
            } else {
                break;
            }
        }
    }

    template<typename T>
    void PriorityQueue<T>::push(const T &value) {
        heap.push_back(value);
        heapify_up(heap.get_size() - 1);
    }

    template<typename T>
    void PriorityQueue<T>::pop() {
        if (heap.get_size() == 0) return;
        heap[0] = heap[heap.get_size() - 1];
        heap.pop_back();
        heapify_down(0);
    }

    template<typename T>
    const T &PriorityQueue<T>::top() const {
        return heap[0];
    }

    template<typename T>
    bool PriorityQueue<T>::empty() const {
        return heap.is_empty();
    }

    template<typename T>
    int PriorityQueue<T>::size() const {
        return heap.get_size();
    }

    //Up PriorityQueue
    template<typename T>
    UpPriorityQueue<T>::UpPriorityQueue() {
    }

    template<typename T>
    bool UpPriorityQueue<T>::compare(const T &a, const T &b) {
        return a > b; // Max-heap: parent is greater than children
    }

    template<typename T>
    void UpPriorityQueue<T>::heapify_up(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (compare(heap[index], heap[parent])) {
                T temp = heap[index];
                heap[index] = heap[parent];
                heap[parent] = temp;
                index = parent;
            } else {
                break;
            }
        }
    }

    template<typename T>
    void UpPriorityQueue<T>::heapify_down(int index) {
        int n = heap.get_size();
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < n && compare(heap[left], heap[largest])) largest = left;
            if (right < n && compare(heap[right], heap[largest])) largest = right;

            if (largest != index) {
                T temp = heap[index];
                heap[index] = heap[largest];
                heap[largest] = temp;
                index = largest;
            } else {
                break;
            }
        }
    }

    template<typename T>
    void UpPriorityQueue<T>::push(const T &value) {
        heap.push_back(value);
        heapify_up(heap.get_size() - 1);
    }

    template<typename T>
    void UpPriorityQueue<T>::pop() {
        if (heap.get_size() == 0) return;
        heap[0] = heap[heap.get_size() - 1];
        heap.pop_back();
        heapify_down(0);
    }

    template<typename T>
    const T &UpPriorityQueue<T>::top() const {
        return heap[0];
    }

    template<typename T>
    bool UpPriorityQueue<T>::empty() const {
        return heap.is_empty();
    }

    template<typename T>
    int UpPriorityQueue<T>::size() const {
        return heap.get_size();
    }

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
