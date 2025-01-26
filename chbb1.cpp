#include<iostream>
using namespace std;
class node{
    public:

    int data;
    node *next;

    //constructor
    node(int data){ // constructor is of same name as class
        this -> data = data; // "this" is nothing but the object's address and 
                            //data is current object's property being assigned with i/p parameter
        this -> next = NULL;    
    }
};


void insert_at_head(node* &head , int d){

    // new node creation
    node* temp = new node(d);
    temp -> next = head;
    head = temp;


}

void print_list(node* &head){
    node* temp = head; // temp is new pointer which is pointing to the head of given node
    while(temp != NULL){
        std::cout << temp -> data << " ";
        temp = temp -> next; // temp = temp ka next
    }
    std::cout<<endl;

}



int main(){

    // creating a new node
    node* node1 = new node(5);
    std::cout << node1 -> data << std::endl;// (*node1).data == dereferincing node1
    cout << node1 -> next << endl; 

    // head pointed to node1
    node* head = node1;
    insert_at_head(head, 13);

    node* node2 = new node(10);
    insert_at_head(head,18);
    print_list(head);



}