#include <iostream>
using namespace std;

class  Node{
    public:
    int data;
    Node* lchild;
    Node* rchild;
};

class BST{
  public:
  Node* root;
  BST(){
      root = NULL;
  }
  Node* insert(Node* p, int key);
  void In_order(Node* root);
};

void BST :: In_order(Node *p){
    if(p){
        In_order(p->lchild);
        cout<<p->data<<" ";
        In_order(p->rchild);
    }
}

Node* BST :: insert(Node* p, int key){
    Node* t = NULL;
    if(p==NULL){
        t = new Node;
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }else{
        if(p->data>key)
            p->lchild = insert(p->lchild, key);
        else
            p->rchild = insert(p->rchild, key);
    }
    return p;
}

int main()
{
    BST bst;
    bst.root = bst.insert(bst.root, 30);
    bst.insert(bst.root, 20);
    bst.insert(bst.root, 25);
    bst.insert(bst.root, 35);
    bst.insert(bst.root, 40);
    bst.insert(bst.root, 21);
    cout<<"The BST consists as :";
    bst.In_order(bst.root);
    return 0;
}
