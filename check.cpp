#include <iostream>
using namespace std;

class BST{
    BST *rchild, *lchild;
    int key;
    public:
    BST();
    BST(int);
    BST* insert(BST*,int);
    void inorder(BST*);
};

BST::BST():key(0),rchild(NULL),lchild(NULL){}

BST::BST(int x){
    key = x;
    lchild = rchild = NULL;
}
BST* BST::insert(BST* root, int key){
    if(!root){
        return new BST(key);
    }
    if(key > root->key){
        root->rchild = insert(root->rchild,key);
    }
    else if(key < root->key){
        root->lchild = insert(root->lchild, key);
    }
    return root;

}

int main(){
    
}