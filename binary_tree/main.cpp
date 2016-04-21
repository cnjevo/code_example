//
//  main.cpp
//  binary_tree
//
//  Created by CHUN CHEN on 2016/4/18.
//  Copyright © 2016年 CHUN CHEN. All rights reserved.
//

#include <iostream>
const int SUCCESS = 0;
const int ERROR = 1;

typedef struct _node
{
    _node* lchild;
    _node* rchild;
    int data;
} node;

int addpt(node** npoint,int idata);
void preorder(node * root);
void inorder(node * root);
void postorder(node * root);
void release_memory(node ** root);

const int size_of_node = 10;

int main(int argc, const char * argv[])
{
    int number[size_of_node]={40, 60, 20, 50, 30, 10, 70, 45, 55, 52};
    node* root = NULL;
    
    for (int i = 0; i < size_of_node; i++)
    {
        if( addpt(&root, number[i]) )
        {
            std::cout << "Same Element Value" << std::endl;
            break;
        }
    }
    std::cout << "pre order :";
    preorder(root);
    std::cout << std::endl << "in order";
    inorder(root);
    std::cout << std::endl << "post order:";
    postorder(root);
    release_memory(&root);
    return 0;
}

int addpt(node** npoint,int idata)
{
    while(1)
    {
        if(*npoint==NULL)
        {
            *npoint=new node;
            (*npoint)->lchild = NULL;
            (*npoint)->rchild = NULL;
            (*npoint)->data=idata;
            return SUCCESS;
        }
        else if((*npoint)->data > idata)
        {
            npoint=&(*npoint)->lchild;
        }
        else if((*npoint)->data < idata)
        {
            npoint=&(*npoint)->rchild;
        }
    }
    return ERROR;
}

void preorder(node * root)
{
    if(root)
    {
        std::cout<<root->data<<"  ";
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void inorder(node * root)
{
    if(root)
    {
        inorder(root->lchild);
        std::cout<<root->data<<"  ";
        inorder(root->rchild);
    }
}

void postorder(node * root)
{
    if(root)
    {
        inorder(root->lchild);
        inorder(root->rchild);
        std::cout<<root->data<<"  ";
    }
}

void release_memory(node ** root)
{
    if(*root)
    {
        release_memory(&(*root)->lchild);
        release_memory(&(*root)->rchild);
        delete *root;
        *root = NULL;
    }
}

