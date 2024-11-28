//Name: Filippo Jason Budiyanto
//Student ID: 1123541
//Date of Submission: 28-11-2024

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


struct Task {
    int profit, deadline;
};


bool compareTasks(const Task& t1, const Task& t2) {
    return t1.profit > t2.profit;
}

int main() {
    int N; 
    cout << "Enter number of tasks: ";
    cin >> N;

    vector<Task> tasks(N);

    cout << "Enter profit and deadline for each task:" << endl;
    for (int i = 0; i < N; ++i) {
        cin >> tasks[i].profit >> tasks[i].deadline;
    }

  
    sort(tasks.begin(), tasks.end(), compareTasks);

    priority_queue<int, vector<int>, greater<int>> pq;

    int maxProfit = 0;
    vector<int> scheduledTasks;

    vector<bool> used(N + 1, false); 

    
    for (const auto& task : tasks) {
        for (int slot = min(N, task.deadline); slot > 0; slot--) {
            if (!used[slot]) { 
                used[slot] = true;
                maxProfit += task.profit;
                scheduledTasks.push_back(task.profit);
                break;
            }
        }
    }


    cout << "Maximum Profit: " << maxProfit << endl;
    cout << "Scheduled Tasks: [";
    for (size_t i = 0; i < scheduledTasks.size(); ++i) {
        cout << scheduledTasks[i];
        if (i < scheduledTasks.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
