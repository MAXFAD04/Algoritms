#include <iostream>
#include <vector>

using namespace std;

class BinaryHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        while (index > 0 && heap[index] > heap[parent]) {
            swap(heap[index], heap[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < heap.size() && heap[leftChild] > heap[largest])
            largest = leftChild;

        if (rightChild < heap.size() && heap[rightChild] > heap[largest])
            largest = rightChild;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    BinaryHeap() {}

    BinaryHeap(vector<int>& arr) {
        for (int num : arr)
            insert(num);
    }

    void insert(int num) {
        heap.push_back(num);
        heapifyUp(heap.size() - 1);
    }

    int getMax() {
        if (heap.empty())
            return -1;

        int max = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return max;
    }

    void merge(BinaryHeap& otherHeap) {
        for (int num : otherHeap.heap)
            insert(num);

        otherHeap.heap.clear();
    }
};

int main() {
    vector<int> arr = { 3, 5, 1, 8, 10 };
    BinaryHeap heap(arr);

    // lookup maximum
    cout << "Maximum element in heap: " << heap.getMax() << endl;

    // removing the maximum
    heap.getMax();
    cout << "Maximum element after removing one: " << heap.getMax() << endl;

    // adding a new element to the heap
    heap.insert(12);
    cout << "Maximum element after adding 12: " << heap.getMax() << endl;

    // merging two heaps
    vector<int> arr2 = { 7, 6, 9 };
    BinaryHeap heap2(arr2);
    heap.merge(heap2);
    cout << "Maximum element after merging two heaps: " << heap.getMax() << endl;
}
