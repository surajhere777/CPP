#include<iostream>
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
void addtohead(node* &head , int d){
    // if(head == NULL){
    //     node* newnode = new node(d);
    //     return;
    // }else{
        
        node* newnode = new node(d);
        newnode -> next = head;
        head = newnode;
    //}
}
void print(node* &head){
    node* temp = head;
    while(temp != NULL){
        std:: cout << temp -> data << " ";
        temp = temp -> next;    
    }
}

//reverse linked list using recursion method
node* reverse1(node* head){
    if(head == NULL || head -> next == NULL){
        return head;
    }else{
        node* chhotahead = reverse1(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return chhotahead; 
    }
}



// void checkptr(node* head){ what we are sending head in this parameter is jusst coppy of head not the real head
//     head = NULL;             changing here in the function about the head is not going to be reflected in the
//                                main function
// }

int main(){
    node* head = new node(5);
    addtohead(head,10);
    addtohead(head,15);
    addtohead(head,20);
    //checkptr(head);
    addtohead(head,25);
    print(head);

    node* x = reverse1(head);
    print(x);
}