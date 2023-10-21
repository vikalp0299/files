#include <iostream>
using namespace std;

class BST{
    BST *rchild, *lchild;
    int key;
    public:
    BST();
    BST(int);
    BST* insert(BST* , int);
    BST* delnode(BST*, int);
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
BST* BST::delnode(BST* root, int key){
    if (!root){
        return NULL;
    }

    if(root->key > key){
        root->lchild = delnode(root->lchild,key);
        return root;
    }else
    if(root->key < key){
        root->rchild = delnode(root->rchild,key);
        return root;
    }else if(root->key == key){
        if(root->lchild == NULL){
            BST *temp = root->lchild;
            delete(root);
            return temp;
        }
        else if(root->rchild == NULL){
            BST *temp = root->rchild;
            delete(root);
            return temp;
        }
        else{
            BST* successorParent = root;
            BST *successor = root->rchild;

            while(successor->lchild != NULL){
                successorParent = successor;
                successor = successor->lchild;
            }

            if(successorParent != root){
                successorParent->lchild = successor->rchild;    
            }else
                successorParent->lchild = successor->rchild;

            root->key = successor->key;
            delete(successor);
            return root;
        }
    }else{
        cout<<" The number does not exists "<<endl;
        return root;
    }
    return root;
}

void BST::inorder(BST* root){
    if (!root){
        return;
    }
    inorder(root->lchild);
    cout<< root->key<< " " ;
    inorder(root->rchild);
}
int main(){
    BST b , *root=NULL;
/*     root = b.insert(root,50);
    root = b.insert(root,60);
    root = b.insert(root,55);
    root = b.insert(root,70);
    root = b.insert(root,20);
    root = b.insert(root,10);
    root = b.insert(root,25);
    b.inorder(root);
 */
    bool cond1 = true;
    do{
        int cond2=0;
        cout<<"Choose from the following options \n1. Insert \n2. Delete \n4. Inorder view \n5. Exit "<<endl;
        cin>> cond2;
        switch(cond2){
            case 1:{
                int k=0;
                cout << "Enter the number to be inserted"<<endl;
                cin >> k;
                root = b.insert(root,k);
                break;}
            case 2:{
                int k=0;
                cout << "Enter the number to be deleted" << endl;
                cin >> k;
                break;}
            case 3:{
                
                break;}
            case 4:{
                b.inorder(root);
                cout<<endl;
                break;}
            case 5: {cond1 = false;cout<<"conditioncheck";break;}
        }
    }while(cond1 == true);

    
    return 0;
}