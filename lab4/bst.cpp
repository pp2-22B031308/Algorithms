#include <iostream>

using namespace std;


struct node{
    int val;
    struct node *left, *right;
};

struct node *newNode(int val){
    struct node* temp =(struct node*)malloc(sizeof(struct node));

    temp->val = val;
    temp->left = temp->right = NULL;
    return temp;
}

struct node *insert(struct node* node, int val){
    if (node == NULL)
        return newNode(val);
    if (val < node->val)
        node->left = insert(node-> left, val);
    else if (val > node->val)
        node->right = insert(node->right, val);

    return node;
}

void inorder(struct node* root){
    if (root != NULL){
        inorder(root -> right);
        cout << root-> val << " ";
        inorder(root -> left);
    }
}

int maxDepth(struct node* root){
    if (root ==NULL){
        return 0;
    }
    int l = maxDepth(root -> left);
    int r = maxDepth(root -> right);

    return 1 + max(l,r);
}

int main (){
    struct node * root = NULL;
    root = insert (root, 1);

    insert(root, 5);
    insert(root, 2);
    insert(root, 10);
    insert(root, 4);


    inorder(root);
}





