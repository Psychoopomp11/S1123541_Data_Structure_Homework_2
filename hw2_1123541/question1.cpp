//Name: Filippo Jason Budiyanto
//Student ID: 1123541
//Date of Submission: 28-11-2024

#include <iostream>
#include <queue>
#include <vector>
#include <sstream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return NULL;

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);

    size_t i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (nodes[i] != -1) {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != -1) {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}


int calculateDiameter(TreeNode* root, int& diameter) {
    if (!root) return 0;

    int leftHeight = calculateDiameter(root->left, diameter);
    int rightHeight = calculateDiameter(root->right, diameter);

   
    diameter = max(diameter, leftHeight + rightHeight);

    
    return max(leftHeight, rightHeight) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    calculateDiameter(root, diameter);
    return diameter;
}

int main() {
  
    string inputLine;
    getline(cin, inputLine);

 
    vector<int> nodes;
    stringstream ss(inputLine);
    int num;
    while (ss >> num) {
        nodes.push_back(num);
    }

    TreeNode* root = buildTree(nodes);

  
    cout << diameterOfBinaryTree(root) << endl;

    return 0;
}
