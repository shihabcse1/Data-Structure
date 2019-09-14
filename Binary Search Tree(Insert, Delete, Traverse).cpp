#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int key;
    Node *left;
    Node *right;
};

Node *create_node(int item){
    Node *newNode = new Node();
    newNode->key = item;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/*------------Insert Start----------------*/

Node *insert_node(Node *node, int key){
    if(node == NULL)
        return create_node(key);
    if(key < node->key){
        node->left = insert_node(node->left, key);
    }else if(key > node->key){
        node->right = insert_node(node->right, key);
    }
    return node;
}

/*------------Insert End----------------*/

Node *successor_node(Node *node){
    Node *current_node = node;
    while(current_node && current_node->left != NULL){
        current_node = current_node->left;
    }
    return current_node;
}

/*------------Delete Start----------------*/

Node *delete_node(Node *root, int key){
    if(root == NULL){
        return root;
    }
    if(key < root->key){
       root->left = delete_node(root->left, key);
    }else if(key > root->key){
        root->right = delete_node(root->right, key);
    }else{
        if(root->left == NULL){
            Node *temp = root->right;
            free(root);
            return temp;
        }else if(root->right == NULL){
            Node *temp = root->left;
            free(root);
            return temp;
        }
        Node *minimum = successor_node(root->right);
        root->key = minimum->key;
        root->right = delete_node(root->right, minimum->key);
    }
}

/*---------------Delete End----------------*/

/*------------Inorder Traverse Start----------------*/

void inorder(Node *root){
    if(root != NULL){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}

/*------------Inorder Traverse End----------------*/

/*------------Preorder Traverse Start----------------*/

void preorder(Node *root){
    if(root != NULL){
        cout<<root->key<<" ";
        inorder(root->left);
        inorder(root->right);
    }
}

/*------------Preorder Traverse End----------------*/

/*------------Postorder Traverse Start----------------*/

void postorder(Node *root){
    if(root != NULL){
        inorder(root->left);
        inorder(root->right);
        cout<<root->key<<" ";
    }
}

/*------------Postorder Traverse End----------------*/

Node *minimum_node(Node *node){
    Node *current = node;
    while(current && current->left != NULL){
        current = current->left;
    }
    return current;
}


int main(){

    int choice, n, data;
    Node *search_result;
    Node *root = NULL;
    do{
        cout<<"Insert : 1"<<endl;
        cout<<"Delete : 2"<<endl;
        cout<<"In order Traverse : 3"<<endl;
        cout<<"Preorder Traverse : 4"<<endl;
        cout<<"Post order Traverse : 5"<<endl;
        cin>>choice;
        switch(choice){
        case 1:
            cout<<"How many node you want to insert : "<<endl;
            cin>>n;
            for(int i = 0; i < n; i++){
                cin>>data;
                root = insert_node(root, data);
            }
            break;

        case 2:
            cout<<"Which data want to delete : "<<endl;
            cin>>data;
            root = delete_node(root, data);
            break;
        case 3:
            inorder(root);
            cout<<endl;
            break;
        case 4:
            preorder(root);
            cout<<endl;
            break;
        case 5:
            postorder(root);
            cout<<endl;
            break;
        case 6:
            cout<<endl;
            break;
        default:
            break;
        }

    }while(choice != 0);

    return 0;
}

