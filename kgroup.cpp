#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next = NULL;


    //constructor
    node(int data){
        this -> data = data;
        this -> next = NULL;
    }

};

void insert_athead(node* &head, int d ){
    if( head == NULL){
        node* newnode = new node(d);
        head = newnode;
    }else{
        node* newnode = new node(d);
        newnode -> next = head;
        head = newnode;
    }
    

}
void print(node* head){
    while(head != NULL){
        cout << head -> data << " ";
        head = head -> next;
    }cout << endl;
}

node* kgroup(node* &head, int k){
    int cnt = 0;
    node* prev{};
    node* nxt{};
    node* curr = head;
    //reversing the first k nodes
    while( curr != NULL && cnt <= k-1 ){
        nxt = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = nxt;
        cnt++;
    }
    //upto this point  
    //aage kaa kaam recursion dekh lega
    if( nxt != NULL){
        head -> next = kgroup(nxt,k);
    }
    return prev;
}

int main(){
    int k;
    cout << "enter the group : "; 
    cin >> k;
    node* head{};
    insert_athead(head , 8);
    insert_athead(head , 7);
    insert_athead(head , 6);
    insert_athead(head , 5);
    insert_athead(head , 4);
    insert_athead(head , 3);
    //print(head);
    insert_athead(head , 2);
    insert_athead(head , 1);
    print(head);
    node* x = kgroup(head, k);
    print(x);
}