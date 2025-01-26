#include<iostream>
using namespace std;
class node {
    public:
    int data;
    node* next;

    //constructor
    node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void insertElement(node* &head, int position, int d){
    //empty list
    if(head == NULL){
        node* newnode = new node(d);
        head = newnode;
    }else{
        node* temp = head;
        node* newnode = new node(d);
        int cnt = 1;
        while(cnt < position - 1){
            temp = temp -> next;
            cnt++;
        }
        newnode -> next = temp -> next;
        temp -> next = newnode;
    }
}
void print(node* &head){
    node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void reverse_ll(node* head){
    node* prev = NULL;
    node* curr = head;
    node* forward = curr -> next;
    while(curr != NULL){
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
        
    }
    head = prev;
    print(head);
}
int main(){
    //node* head = new node(5);
    node* head = NULL;
    insertElement(head , 1 , 10);
    print(head);
    insertElement(head , 2 , 20);
    insertElement(head , 3 , 30);
    insertElement(head , 4 , 40);
    print(head);
    reverse_ll(head);
}