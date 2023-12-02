#include <iostream>

using namespace std;

struct node{
    int val;
    struct node *left, *right;
};

struct node* newNode(int val){
    struct node * temp = new struct node;

    temp-> val = val;
    temp->left = temp->right = nullptr;
    return temp;
}

struct node* insert(struct node* node, int val){
    if (node == nullptr){
        return newNode(val);
    }
    if (val < node-> val){
        node-> left = insert(node->left,val);
    }
    if (val > node -> val){
        node-> right = insert(node->right, val);
    }
    return node;
}

int getSubtreeSize(struct node* root, int target){
    if (root == nullptr){
        return 0;
    }
    if (root-> val == target){
        return 1 + (root-> left ? root->left->val :0)+ (root -> right ? root -> right-> val :0);
    }
    else if (target >  root -> val){
        return getSubtreeSize(root-> right, target);
    }
    else {
        return getSubtreeSize(root -> left, target);
    }
}


int main (){
    int n;
    cin >>n;

    struct node* root = nullptr;

    for (int i = 0; i < n; i++){
        int value;
        cin >> value;
        root = insert(root, value);
    }
    int target;
    cin >> target;

    int subtreeSize = getSubtreeSize(root, target);
    cout << subtreeSize << endl;

    return 0;
}