#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
};

class LinkedList : public Node{
public:
    Node *head;
    LinkedList(){
        head = NULL;
    }
    void prepend(int item);
    void insert(int item, int key);
    void append(int item);
    void delete_node();
    void search(int item);
    void sorting();
    void display();

};

//---------------------Append-----------------------

void LinkedList :: append(int item){

    Node *newNode = new Node();
    newNode->data = item;
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

//---------------Prepends---------------

void LinkedList :: prepend(int item){

    Node *newNode = new Node();
    newNode->data = item;
    newNode->next = NULL;

    if(head == NULL){
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

//---------------Insert node before a specific value---------------

void LinkedList :: insert(int item, int key){

        Node *newNode = new Node();
        newNode->data = item;
        newNode->next = NULL;

        if(head == NULL){
            head = newNode;
            return;
        }
        Node *current_node = head;
        Node *previous_node;
        while(current_node->next != NULL){
            previous_node = current_node;
            current_node = current_node->next;
            if(key == current_node->data){
                break;
            }
        }
        previous_node->next = newNode;
        newNode->next = current_node;
}

//---------------------Delete From front-----------------------

void LinkedList :: delete_node(){

    if(head == NULL){
        cout<<"There is no node for deleting"<<endl;
        return;
    }
    head = head->next;
}

//---------------search------------------------

void LinkedList :: search(int item){
    Node *temp = head;
    while(temp != NULL){
        if(temp->data == item){
            break;
        }
        temp = temp->next;
    }
    if(temp == NULL){
        cout<<"Item not found"<<endl;
    }else{
        cout<<"Item found"<<endl;
    }
}

//------------------sorting--------------------

void LinkedList :: sorting(){
    Node *i, *j;
    int temp;
    for(i = head; i->next != NULL; i = i->next){
        for(j = i; j != NULL; j = j->next){
            if(i->data < j->data){
                temp = j->data;
                j->data = i->data;
                i->data = temp;
            }
        }
    }
}

//-------------------Display---------------

void LinkedList :: display(){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){

    LinkedList ob;
    int choice, n, value, keyValue;

    do{
        cout<<"Press 1 for Append "<<endl;
        cout<<"Press 2 for Prepends "<<endl;
        cout<<"Press 3 for Delete "<<endl;
        cout<<"Press 4 for display "<<endl;
        cout<<"Press 5 for Insert "<<endl;
        cout<<"Press 6 for Search "<<endl;
        cout<<"Press 7 for Sorting "<<endl;
        cout<<"Press 0 for Exit "<<endl;
        cin>>choice;

        switch(choice){
        case 1:
            cout<<"How many nodes you want to append : "<<endl;
            cin>>n;
            for(int i = 0; i < n; i++){
                cin>>value;
                ob.append(value);
            }
            break;

        case 2:
            cout<<"How many nodes you want to prepends : "<<endl;
            cin>>n;
            for(int i = 0; i < n; i++){
                cin>>value;
                ob.prepend(value);
            }
            break;

        case 3:
            ob.delete_node();
            break;

        case 4:
            ob.display();
            break;

        case 5:
            cout<<"After which nodes you want to insert(Enter NewNode First, Then Enter key) ? "<<endl;
            cin>>value>>keyValue;
            ob.insert(value, keyValue);
            break;

        case 6:
            cout<<"Which node you want to search ? "<<endl;
            cin>>value;
            ob.search(value);
            break;

        case 7:
            ob.sorting();
            break;

        default:
            cout<<"default"<<endl;
            break;
        }

    }while(choice != 0);

    return 0;
}
