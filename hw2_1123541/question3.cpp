//Name: Filippo Jason Budiyanto
//Student ID: 1123541
//Date of Submission: 28-11-2024


#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm> 

using namespace std;

struct HeapNode {
    int value;     
    int arrayIdx; 
    int elementIdx;
};

struct Compare {
    bool operator()(const HeapNode& a, const HeapNode& b) {
        return a.value > b.value; // Min-heap
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>& arrays) {
    priority_queue<HeapNode, vector<HeapNode>, Compare> minHeap;
    vector<int> mergedArray;

    for (auto& array : arrays) {
        sort(array.begin(), array.end());
    }

    for (int i = 0; i < arrays.size(); i++) {
        if (!arrays[i].empty()) {
            minHeap.push({arrays[i][0], i, 0});
        }
    }

    while (!minHeap.empty()) {
        HeapNode current = minHeap.top();
        minHeap.pop();
        mergedArray.push_back(current.value);

        int nextIdx = current.elementIdx + 1;
        if (nextIdx < arrays[current.arrayIdx].size()) {
            minHeap.push({arrays[current.arrayIdx][nextIdx], current.arrayIdx, nextIdx});
        }
    }

    return mergedArray;
}

int main() {
    int k;
    cout << "Enter the number of arrays: ";
    cin >> k;
    cin.ignore(); 

    vector<vector<int>> arrays(k);
    cout << "Enter the arrays (one per line):\n";
    for (int i = 0; i < k; i++) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int num;
        while (ss >> num) {
            arrays[i].push_back(num);
        }
    }

    vector<int> result = mergeKSortedArrays(arrays);
    cout << "Merged Array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
