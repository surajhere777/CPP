#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* create_BST(node* root , int val){
    if(root == NULL){
        root = new node(val);
        return root;
    }

    if(root -> data < val){
        root -> right = create_BST(root -> right, val);
    }
    else{
        root -> left = create_BST(root -> left, val);
    }
    return root;
}
void take_input(node* &root ){
    int data ;
    cin >> data;
    while(data != -1){
        root = create_BST(root , data);
        cin >> data;
    }
}

void inorder(node* root){
    if(root == NULL) return;

    inorder(root -> left);
    cout << root -> data <<  " ";
    inorder (root -> right);
}

int main(){
    node* root = NULL;
    take_input(root);
    inorder(root);
    return 0;
}