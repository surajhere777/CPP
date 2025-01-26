#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int data){//constructor
        this -> data = data;
        this -> next = NULL;

    }
};

void insert_at_head(node* &head, int data){
    node* temp = new node(data);
    temp -> next = head;
    head = temp;

}
void insert_at_tail(node* &tail, int data){
    node* temp = new node(data);
    tail -> next = temp;
    tail = temp;

}

void print_list(node* &head){
    node* temp = head; 
    while(temp != NULL){
        cout << temp -> data<< " ";
        temp = temp -> next;
    }cout << endl;
}

void insert_at_position(node* &head, int position , int d){
    node* temp = head;
    int count{1};
    while(count < position - 1){
        temp = temp -> next;
        count++;
    }

    //creating a node for d
    node* nodetoinsert = new node(d);
    nodetoinsert -> next = temp -> next;
    temp -> next = nodetoinsert;

}


int main(){
    node* node1 = new node(5);
    node* head = node1;
    node* tail = node1;
    insert_at_tail(tail,10);
    
    
    insert_at_tail(tail,20);
    print_list(head);
    insert_at_tail(tail,30);
    print_list(head);
    insert_at_position(head, 2,100);
    print_list(head);
    insert_at_position(head, 6,500);
    print_list(head);
    insert_at_position(head, 7,700);
    print_list(head);
    
    
    //insert_at_head(head , 10);
    //print_list(head);
    //insert_at_head(head , 15);
    //print_list(head);
   

}