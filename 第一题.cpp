#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : value(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : value(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : value(x), left(left), right(right) {}
};

int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> s;
    while (root || !s.empty()) {
        if (root) {
            s.push(root);
            root = root->left;
        } else {
            root = s.top();
            s.pop();
            if (--k == 0) {
                return root->value;
            }
            root = root->right;
        }
    }
    return -1;
}

int main() {
    TreeNode root = TreeNode(8);
    root.left = new TreeNode(5);
    root.right = new TreeNode(9);
    root.left->left = new TreeNode(3);
    root.left->right = new TreeNode(6);
    root.left->left->left = new TreeNode(1);
    cout << kthSmallest(&root, 4) << endl;
    return 0;
}
