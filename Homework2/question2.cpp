//Name: Filippo Jason Budiyanto
//Student ID: 1123541
//Date of Submission: 28-11-2024

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct Task {
    string name;
    int priority;

    bool operator<(const Task& other) const {
        return priority < other.priority; 
    }
};

int main() {
    int n; 
    cin >> n;
    cin.ignore(); 

    priority_queue<Task> taskQueue; 
    vector<string> outputs;       

    
    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        string operation;
        ss >> operation;

        if (operation == "ADD") {
            string taskName;
            int priority;
            ss >> taskName >> priority;
            taskQueue.push({taskName, priority});
        } else if (operation == "GET") {
            if (!taskQueue.empty()) {
                outputs.push_back(taskQueue.top().name);
                taskQueue.pop();
            }
        }
    }

   
    for (const string& output : outputs) {
        cout << output << endl;
    }

  
    vector<pair<string, int>> remainingTasks;
    while (!taskQueue.empty()) {
        Task t = taskQueue.top();
        remainingTasks.push_back({t.name, t.priority});
        taskQueue.pop();
    }

    
    cout << "Remaining tasks: [";
    for (size_t i = 0; i < remainingTasks.size(); ++i) {
        cout << "('" << remainingTasks[i].first << "', " << remainingTasks[i].second << ")";
        if (i != remainingTasks.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
