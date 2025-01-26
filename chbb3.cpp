#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* prev;
    node* next;

    //constructor
    node(int d){
        this -> data = d;
        this -> prev = NULL;
        this -> next = NULL;
    }
    //destructor
    ~node(){
        int val = this -> data;
        if(this -> next!= NULL){
            delete next;
            next = NULL;
        }
        cout<< " memory successfully freed ";
    }
};

void insertAtHead(node* &head, int d){
    node* temp = new node(d);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
}
void print(node* head){
    node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}


void insertAtPosition(int position , node* &head, int d){
    if(position == 1){
        insertAtHead(head,d);
        return;
    }else{
        node* temp = head;
    int cnt = 1;
    while(cnt < position -1){
        temp = temp -> next;
        cnt++;
    }
    node* nodetoinsert = new node(d);
    nodetoinsert -> next = temp -> next;
    temp -> next -> prev = nodetoinsert;
    temp -> next = nodetoinsert;
    nodetoinsert -> prev = temp;
    }    
} 

void deletenode(int position, node* &head){
    node* temp = head;
    int cnt = 1;
    node* curr = temp -> next;
    while(cnt < position - 1){
        temp = temp -> next;
        curr = temp -> next;
        cnt++;
    }
    curr -> prev = NULL;
    temp -> next = curr -> next;
    curr -> next -> prev = temp;
    delete curr;
}


int main(){
    node* head = new node(5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);

    print(head);
    deletenode(3,head);
    print(head);
    
    // insertAtHead(head, 10);
    // insertAtHead(head, 15);
    // print(head);
    // insertAtHead(head, 20);
    // insertAtHead(head, 25);
    // print(head);

    // insertAtPosition(2,head,1000);
    // print(head);



}