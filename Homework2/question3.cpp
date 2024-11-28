//Name: Filippo Jason Budiyanto
//Student ID: 1123541
//Date of Submission: 28-11-2024


#include <iostream>
#include <vector>
#include <queue>
#include <sstream> 

using namespace std;


struct Element {
    int value;      
    int arrayIndex; 
    int elementIndex; 

    bool operator>(const Element &other) const {
        return value > other.value;
    }
};

// Function to merge K sorted arrays
vector<int> mergeKSortedArrays(const vector<vector<int>> &arrays) {
    priority_queue<Element, vector<Element>, greater<Element>> minHeap;
    vector<int> mergedArray;

  
    for (int i = 0; i < arrays.size(); ++i) {
        if (!arrays[i].empty()) {
            minHeap.push({arrays[i][0], i, 0});
        }
    }

   
    while (!minHeap.empty()) {
        Element smallest = minHeap.top();
        minHeap.pop();
        mergedArray.push_back(smallest.value);

       
        int nextIndex = smallest.elementIndex + 1;
        if (nextIndex < arrays[smallest.arrayIndex].size()) {
            minHeap.push({arrays[smallest.arrayIndex][nextIndex], smallest.arrayIndex, nextIndex});
        }
    }

    return mergedArray;
}

int main() {
    int K;
    cout << "Enter the number of sorted arrays: ";
    cin >> K;
    cin.ignore(); 

    vector<vector<int>> arrays(K);
    cout << "Enter the arrays:" << endl;

    for (int i = 0; i < K; ++i) {
        string line;
        getline(cin, line); 

        stringstream ss(line); 
        int num;
        while (ss >> num) {
            arrays[i].push_back(num);
        }
    }

    vector<int> result = mergeKSortedArrays(arrays);


    cout << "Merged Array: [";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
