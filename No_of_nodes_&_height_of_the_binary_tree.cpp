#include <iostream>
using namespace std;

class Node{
    public:
    Node* lchild;
    int data;
    Node* rchild;
};

class Queue{
    private:
        int rear, front, size;
        Node **Q;
    public:
        Queue(){ rear=front=0; size=10; Q = new Node*[size]; }
        Queue(int size){rear=front=0; this->size=size; Q = new Node*[this->size];}
        void enqueue(Node* x);
        Node* dequeue();
        int isEmpty();
};

int Queue :: isEmpty(){
    if(front==rear)
        return 1;
    else
        return 0;
}

void Queue :: enqueue(Node* x){
    if((rear+1)%size==front)
        cout<<"The Queue is Full.\n";
    else{
        rear = (rear+1)%size;
        Q[rear] = x;
    }
        
}

Node* Queue :: dequeue(){
    Node* x = NULL;
    if(front==rear)
        cout<<"The Queue is Empty.\n";
    else{
        front = (front+1)%size;
        x = Q[front];
    }
    return x;
}

class Tree{
    public:
    Node* root;
    Tree(){ root = NULL;}
    void create_Tree();
    int tree_height(Node* p);
    int No_of_node(Node* p);
};

void Tree :: create_Tree(){
    Node *p, *t;
    int x;
    Queue q(100);
    
    cout<<"Enter the data element to be inserted in the root node : ";
    cin>>x;
    root  = new Node;
    root->data = x;
    q.enqueue(root);
    while(!q.isEmpty()){
        p = q.dequeue();
        cout<<"Enter the element to be inserted in the left node : ";
        cin>>x;
        if(x!=-1){
            t = new Node;
            t->data = x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            q.enqueue(t);
        }
        cout<<"Enter the element to be inserted in the right node : ";
        cin>>x;
        if(x!=-1){
            t = new Node;
            t->data = x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            q.enqueue(t);
        }
    }
}

int Tree :: tree_height(Node* p){
    int x, y;
    if(p==0)
        return 0;
    else{
        x = No_of_node(p->lchild);
        y = No_of_node(p->rchild);
        if(x>y)
            return x+1;
        else
            return y+1;
    }
    
}

int Tree :: No_of_node(Node* p){
    int x, y;
    if(p){
        x = No_of_node(p->lchild);
        y = No_of_node(p->rchild);
        return x+y+1;
    }
    return 0;
}

int main()
{
    Tree tree;
    tree.create_Tree();
    cout<<"No. of nodes in the Tree : ";
    cout<<tree.No_of_node(tree.root)<<endl;
    cout<<"Height of the Tree is : ";
    cout<<tree.tree_height(tree.root);
    return 0;
}
