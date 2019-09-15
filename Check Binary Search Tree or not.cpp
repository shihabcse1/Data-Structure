#include<bits/stdc++.h>
#define INT_MAXI 999999
#define INT_MINI -999999
using namespace std;

/* Just guessed a max & min */

class Node{
public:
    int data;
    Node *left;
    Node *right;
};


bool checkBST(Node *root, int mini, int maxi){
    if(root == NULL){
        return true;
    }
    if(root->data < mini || root->data > maxi){
        return false;
    }
    return checkBST(root->left, mini, root->data-1) && checkBST(root->right, root->data+1, maxi);
}

bool isBST(Node *root){
    return checkBST(root, INT_MINI, INT_MAXI);
}

Node *createNode(int value){
    Node *newNode = new Node();
    newNode->data = value;
    newNode->right= NULL;
    newNode->left = NULL;
    return newNode;
}

/*
    Note :
    "In Add node Function"
    "(key > node->data)"
    Here, I have inserted data by using this reverse condition instead of "(key < node->data)" this.
    Because I want show it is not BST. Just reverse that condition to insert data according to BST property.
*/

Node *addNode(Node *root, int key){
    if(root == NULL){
        return createNode(key);
    }
    if(key > root->data){
        root->left = addNode(root->left, key);
    }else{
        root->right = addNode(root->right, key);
    }
    return root;
}

int main(){
    Node *root = NULL;
    /*Creating a binary tree*/
    root = addNode(root,30);
    root = addNode(root,15);
    root = addNode(root,20);
    root = addNode(root,25);
    root = addNode(root,40);
    root = addNode(root,37);
    root = addNode(root,45);

    printf("%s", isBST(root) ? "Yes" : "No" );

/*
    This is another Example to check it is BST or not.
                30
               /  \
              45  35
    It is not BST. So output will be "No".

    root = createNode(30);
    Node *left_node = createNode(45);
    root->left = left_node;
    Node *right_node = createNode(35);
    root->right = right_node;
    printf("%s", isBST(root) ? "Yes" : "No" );

*/

  return 0;
}
