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

    void resize(int newCapacity) {
        T *newData = new T[newCapacity];
        for (int i = 0; i < size; ++i)
            newData[i] = data[i];
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

    public:
        DynamicArray() : data(nullptr), capacity(0), size(0) {
    }

        ~DynamicArray() {
        delete[] data;
    }

        void push_back(const T &value) {
        if (size == capacity)
            resize(capacity == 0 ? 1 : capacity * 2);
        data[size++] = value;
    }

        void pop_back(){
        if (size > 0) --size;
    }

        T &operator[](int index){
        return data[index];
    }

        const T &operator[](int index) const{
        return data[index];
    }

        int get_size() const{
        return size;
    }

        bool is_empty() const{
        return size == 0;
    }

        void clear(){
        delete[] data;
        data = nullptr;
        size = 0;
        capacity = 0;
    }
    };

    template<typename T>
    class PriorityQueue {
    private:
        DynamicArray<T> heap;

        void heapify_up(int index){
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

        void heapify_down(int index){
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

        bool compare(const T &a, const T &b){
        return a < b; // Min-heap
    }

    public:
        PriorityQueue(){}

        void push(const T &value){
        heap.push_back(value);
        heapify_up(heap.get_size() - 1);
    }

        void pop(){
        if (heap.get_size() == 0) return;
        heap[0] = heap[heap.get_size() - 1];
        heap.pop_back();
        heapify_down(0);
    }

        const T &top() const{
        return heap[0];
    }

        bool empty() const{
        return heap.is_empty();
    }

        int size() const{
        return heap.get_size();
    }
    };

    template<typename T>
    class UpPriorityQueue {
    private:
        DynamicArray<T> heap;

        void heapify_up(int index){
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

        void heapify_down(int index){
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

        bool compare(const T &a, const T &b) {
        return a > b; // Max-heap
    }

    public:
        UpPriorityQueue(){}

        void push(const T &value){
        heap.push_back(value);
        heapify_up(heap.get_size() - 1);
    }

        void pop(){
        if (heap.get_size() == 0) return;
        heap[0] = heap[heap.get_size() - 1];
        heap.pop_back();
        heapify_down(0);
    }

        const T &top() const{
        return heap[0];
    }

        bool empty() const{
        return heap.is_empty();
    }

        int size() const{
        return heap.get_size();
    }
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
