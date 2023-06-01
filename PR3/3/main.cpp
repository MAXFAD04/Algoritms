#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int connectRopes(vector<int>& ropes) {
    priority_queue<int, vector<int>, greater<int>> minHeap(ropes.begin(), ropes.end());

    int cost = 0;
    while (minHeap.size() > 1) {
        int first = minHeap.top();
        minHeap.pop();

        int second = minHeap.top();
        minHeap.pop();

        int connected = first + second;
        cost += connected;

        minHeap.push(connected);
    }

    return cost;
}

int main() {
    vector<int> ropes = { 4, 3, 2, 6 };

    int totalCost = connectRopes(ropes);

    cout << "Order of tying the ropes: ";
    for (int rope : ropes)
        cout << rope << " ";
    cout << endl;

    cout << "Total cost of tying the ropes: " << totalCost << endl;
}
