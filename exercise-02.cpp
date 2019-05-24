/*
Program		: BST
Nama		: Anugerah Prima Bagaskara
NPM			: 140810180006
Deskripsi	: Program ini berfungsi untuk mencetak semua Tree, kedalaman, level, dan anak dari Tree.
Tanggal		: 15/05/2019
*/
#include <iostream>
using namespace std;

struct Tree{
    int data;
    Tree *left,*right;
};

void createTree(Tree* &newTree, int data);
void insertBST(Tree* &root, Tree* newTree);
void printPreOrder(Tree *root);
void printInOrder(Tree *root);
void printPostOrder(Tree *root);
int height(Tree* root);
void printByLevel(Tree* root, int level);
void printLevelOrder(Tree* root);
void printChildren(Tree* root);

int main(){
    Tree *tree=NULL, *newTree;
    int pil,temp; bool loop=true;
    createTree(newTree, 7);
    insertBST(tree, newTree);
    createTree(newTree, 11);
    insertBST(tree, newTree);
    createTree(newTree, 3);
    insertBST(tree, newTree);
    createTree(newTree, 4);
    insertBST(tree, newTree);
    createTree(newTree, 5);
    insertBST(tree, newTree);
    createTree(newTree, 9);
    insertBST(tree, newTree);
    createTree(newTree, 12);
    insertBST(tree, newTree);
    createTree(newTree, 15);
    insertBST(tree, newTree);
    createTree(newTree, 1);
    insertBST(tree, newTree);
    createTree(newTree, 10);
    insertBST(tree, newTree);
    createTree(newTree, 2);
    insertBST(tree, newTree);
    createTree(newTree, 25);
    insertBST(tree, newTree);
    createTree(newTree, 8);
    insertBST(tree, newTree);
    createTree(newTree, 14);
    insertBST(tree, newTree);
    createTree(newTree, 19);
    insertBST(tree, newTree);
    while(loop){
        system("CLS");
        cout<<"1. InsertBST\t5. Kedalaman"<<endl
        <<"2. PreOrder\t6. Level"<<endl
        <<"3. InOrder\t7. Anak"<<endl
        <<"4. PostOrder\t8. Exit"<<endl;
        do cin>>pil; while(pil<1 || pil>8);
        switch(pil){
            case 1:
                cout<<endl<<"Nilai Tree baru : ";cin>>temp;
                createTree(newTree,temp);
                insertBST(tree, newTree);
                cout<<endl<<"InsertBST berhasil!"<<endl;
                break;
            case 2:
                cout<<endl<<"print Pre-Order : "<<endl;
                printPreOrder(tree);
                break;
            case 3:
                cout<<endl<<"print In-Order : "<<endl;
                printInOrder(tree);
                break;
            case 4:
                cout<<endl<<"print Post-Order : "<<endl;
                printPostOrder(tree);
                break;
            case 5:
                cout<<endl<<"Kedalaman dari Tree adalah "
                <<height(tree)-1;
                break;
            case 6:
                cout<<endl<<"Level dari Tree adalah "
                <<height(tree);
                break;
            case 7:
                cout<<endl<<"print Anak-anak dari Tree : "<<endl;
                printChildren(tree);
                break;
            case 8:
                cout<<endl<<"Terima Kasih!"<<endl;
                loop=false;
                break;
        }
        cout<<endl<<endl;system("pause");
    }
}

void createTree(Tree* &newTree, int data){
    newTree = new Tree;
    newTree->data=data;
    newTree->left=NULL;
    newTree->right=NULL;
}
void insertBST(Tree* &root, Tree* newTree){
    if (root==NULL) root=newTree;
    else if (root->data>newTree->data) insertBST(root->left, newTree);
    else insertBST(root->right, newTree);
}
void printPreOrder(Tree *root){
    if(root!=NULL){
        cout<<root->data<<" ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}
void printInOrder(Tree *root){
    if(root!=NULL){
        printInOrder(root->left);
        cout<<root->data<<" ";
        printInOrder(root->right);
    }
}
void printPostOrder(Tree *root){
    if(root!=NULL){
        printPostOrder(root->left);
        printPostOrder(root->right);
        cout<<root->data<<" ";
    }
}
int height(Tree* root){
    if(root==NULL){
        return 0;
    }else{
        int lheight=height(root->left);
        int rheight=height(root->right);
        if (lheight>rheight) return (lheight+1);
        else return (rheight+1);
    }
}
void printByLevel(Tree* root, int level){
    if(root==NULL) return;
    else if(level==1) cout<<root->data<<" ";
    else{
        printByLevel(root->left, level-1);
        printByLevel(root->right, level-1);
    }
}
void printLevelOrder(Tree* root){
    int h=height(root);
    for(int i=1; i<=h; i++) printByLevel(root, i);
}
void printChildren(Tree* root){
    int h=height(root);
    for(int i=3; i<=h; i++) printByLevel(root, i);
}
