#include <iostream>
using namespace std;

class BST{
    BST *rchild, *lchild;
    int key;
    public:
    BST();
    BST(int);
    BST* insert(int);
    void inorder(BST*);
};

BST::BST():key(0),rchild(NULL),lchild(NULL){}

BST::BST(int x){
    key = x;
    lchild = rchild = NULL;
}

int main(){
    
}