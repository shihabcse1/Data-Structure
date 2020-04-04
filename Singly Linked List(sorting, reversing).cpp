#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
};

Node *head = NULL;

/*----------------Insert a data from end of Linked list--------------*/

void append(int value){

    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL){
        head = newNode;
        return;
    }

    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

/*----------------------For Display Linked list----------------------*/

void print(){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

/*------------------Searching an item from Linked list--------------*/

void search_node(int value){
    Node *temp = head;
    while(temp != NULL){
        if(temp->data == value){
            cout<<"Item found"<<endl;
            break;
        }
        temp = temp->next;
    }
    if(temp == NULL){
        cout<<"Item not found"<<endl;
        return;
    }
}

/*----------------Counting how many nodes the linked list has--------------*/

void count_node(){
    Node *temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        temp = temp->next;
    }
    cout<<"The total number of Nodes : "<<cnt<<endl;
}

/*----------------Delete a specific node of a Linked list--------------*/

void delete_node(int value){
    Node *previous_node;
    Node *temp = head;
    while(temp->data != value){
        previous_node = temp;
        temp = temp->next;
    }
    previous_node->next = temp->next;
}

/*----------------Reversing Linked list by iterative method--------------*/

void reverse_linked_list(){
    Node *prev = NULL;
    Node *current_node = head;
    Node *Next;
    while(current_node != NULL){
        Next = current_node->next;
        current_node->next = prev;
        prev = current_node;
        current_node = Next;
    }
    head = prev;
}

/*----------------Reversing Linked list by Recursive method--------------*/

void reverse_recursive(Node *temp){
    if(temp == NULL){
        return;
    }
    reverse_recursive(temp->next);
    cout<<temp->data<<" ";
}

/*------------------Sorting a Linked list according to the values--------------*/

void sorting(){
    Node *i, *j;
    int temp;
    for(i = head; i->next != NULL; i=i->next){
        for(j = i; j != NULL; j=j->next){
            if(i->data < j->data){
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}




int main(){
    append(5);
    append(7);
    append(14);
    append(9);
    print();
    count_node();
    cout<<"After deleting : ";
    delete_node(9);
    print();
    search_node(14);
    count_node();
    append(99);
    sorting();
    print();
    reverse_linked_list();
    print();
    reverse_recursive(head);

    return 0;
}
