#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
    public:
        int val;
        TreeNode *left, *right;
};

// Assuming the given 2 nodes always exist
TreeNode* LCA_binaryTree(TreeNode* root, int n1, int n2) {
    if(!root)
        return NULL;
    if(root->val == n1 || root->val == n2)
        return root;
    
    TreeNode* left_lca = LCA_binaryTree(root->left,n1,n2);
    TreeNode* right_lca = LCA_binaryTree(root->right,n1,n2);

    // if both left and right gives a ptr then root must be LCA
    if(left_lca and right_lca)
        return root;
    // Left must give LCA
    if(left_lca)
        return left_lca;
    else
        return right_lca;
}
// For special case of BST
TreeNode* LCA_bst(TreeNode* root, int n1, int n2) {
    if(!root)
        return NULL;
    if(n1 < root->val and n2 < root->val)
        return LCA_bst(root->left,n1,n2);
    if(n1 > root->val and n2 > root->val)
        return LCA_bst(root->right,n1,n2);
    
    // n1 < root->val and n2 > root->val
    return root;
}


// -------------------------------- Helpers ---------------------

TreeNode* newNode(int val)
{
    TreeNode* Node = new TreeNode();
    Node->val = val;
    Node->left = Node->right = NULL;
    return(Node);
}

int main(){
    TreeNode *root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
 
    int n1 = 10, n2 = 14;
    TreeNode *t = LCA_binaryTree(root, n1, n2);
    cout << "LCA of " << n1 << " and " << n2 << " is " << t->val<<endl;
 
    t = LCA_bst(root, n1, n2);
    cout << "LCA of " << n1 << " and " << n2 << " is " << t->val<<endl;
}