#include <iostream>

class TreeNode {
public:
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
    void test() {}
    TreeNode *left, *right;
    int val;
};

void morris(TreeNode *root) {
    while (root) {
        if (!root->right) {
            std::cout << root->val << std::endl;
            root = root->left;
        } else {
            TreeNode *node = root->right;
            while (node->left && node->left != root) {
                node = node->left;
            }
            if (!node->left) {
                node->left = root;
                root = root->right;
            } else {
                node->left = nullptr;
                std::cout << root->val << std::endl;
                root = root->left;
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    TreeNode node1(8);
    TreeNode node2(7, nullptr, &node1);
    TreeNode node3(5);
    TreeNode node4(6, &node3, &node2);
    TreeNode node5(3);
    TreeNode node6(2, nullptr, &node5);
    TreeNode node7(0);
    TreeNode node8(1, &node7, &node6);
    TreeNode node9(4, &node8, &node4);
    morris(&node6);
    return 0;
}
