#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    //constructor
    node(int d){
        this -> data = d;
        this -> next = NULL;
    }
    //destructor
    ~node(){
        int value = this -> data;
        if(this -> next != NULL){
            delete next;
            next = NULL;
        }
        cout << "memory is freed for node with data "<< value << endl;
    }
};

void insertNode(node* &tail , int element, int d){
    
    
    //empty list
    if(tail == NULL){
        node* newnode = new node(d);
        newnode -> next = newnode;
        tail = newnode;
    }else{
        // non - empty list
        // assuming that the element is present in the list
        node* curr = tail;

        while(curr -> data != element ){
            curr = curr -> next;
        }
        node* temp = new node(d);
        temp -> next = curr -> next;
        curr -> next = temp;
    }
}
void printnode(node* &tail){
    node* temp = tail;
    do{
        cout << tail -> data << " ";
        tail = tail -> next;
    }while(tail != temp);
    cout << endl;
}

void deletenode(node* &tail , int value){
    //empty list
    if(tail == NULL){
        cout << "list is already empty "<< endl;
    }
    else{
        //non - empty list
        node* prev = tail;
        node* curr = prev -> next;
        while(curr -> data != value){
            prev = curr;
            curr = curr -> next;
        }
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}

int main(){
    node* tail = NULL;

    insertNode(tail,5,3);
    insertNode(tail,3,4);
    insertNode(tail,4,5);
    insertNode(tail,5,6);
    
    printnode(tail);
    insertNode(tail,4,100);
    printnode(tail);

    insertNode(tail,6,600);
    printnode(tail);

    deletenode(tail , 600);
    printnode(tail);
}