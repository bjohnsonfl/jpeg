//
//  binaryTree.hpp
//  jpeg
//
//  Created by Blake Johnson on 9/16/19.
//  Copyright © 2019 Blake Johnson. All rights reserved.
//

#ifndef binaryTree_hpp
#define binaryTree_hpp

#include <iostream>
#include <memory>
#include <queue>
#include <stdio.h>



template<class T>
struct BinaryTreeNode {
    T data;
    BinaryTreeNode<T> * left;
    BinaryTreeNode<T> * right;
    
    BinaryTreeNode(){left = NULL; right = NULL;}
    BinaryTreeNode(const T& element){
        data = element;
        left = NULL;
        right = NULL;
    }
    BinaryTreeNode(const T& element, BinaryTreeNode<T>*leftChild, BinaryTreeNode<T>*rightChild){
        data = element;
        left = leftChild;
        right = rightChild;
    }
};



template<class T>
class BinaryTree {
    
protected:
    int treeSize;
    BinaryTreeNode<T> * root;
    //std::shared_ptr<BinaryTreeNode<T>> root;
    std::queue<BinaryTreeNode<T> *> levelQueue;
    
public:
    BinaryTree(){root = NULL; treeSize = 0;};
    ~BinaryTree(){erase(root);};
   
    void makeTree( const T element, BinaryTree<T> & left, BinaryTree<T> & right);
    BinaryTreeNode<T> * getRoot() const {return root;};
    int getTreeSize () const {return treeSize;};
    void erase(BinaryTreeNode<T> * node);
    void insert(const T element) {levelOrderInsert(root, element);};
    void levelOrder(BinaryTreeNode<T> * node);
    void preOrder (BinaryTreeNode<T> * node);
    void inOrder (BinaryTreeNode<T> * node);
    void postOrder (BinaryTreeNode<T> * node);
    void levelOrderInsert(BinaryTreeNode<T> * node, const T element);
    
     
   
    
};

template<class T>
void BinaryTree<T>::makeTree(const T element, BinaryTree<T> &left, BinaryTree<T> &right){
    root = new BinaryTreeNode<T>(element, left.root, right.root);
    left.root = NULL;
    right.root = NULL;
    treeSize = left.treeSize + right.treeSize + 1;
    left.treeSize = 0;
    right.treeSize = 0;
   
}

template<class T>
void BinaryTree<T>::levelOrder(BinaryTreeNode<T> * node){
    
    if(node -> left != NULL) levelQueue.push(node -> left);
    if(node -> right != NULL) levelQueue.push(node -> right);
   
    std::cout << (node -> data).prob << " ";
    
    if(levelQueue.size() > 0) {
        BinaryTreeNode<T> * nextNode = levelQueue.front();
        levelQueue.pop();
        levelOrder(nextNode);
    }
   
}

template<class T>
void BinaryTree<T>::preOrder(BinaryTreeNode<T> * node){
    if(node != NULL){
        std::cout << node -> data;
        preOrder(node -> left);
        preOrder(node -> right);
    }
}

template<class T>
void BinaryTree<T>::inOrder(BinaryTreeNode<T> * node){
    if(node != NULL){
        inOrder(node -> left);
        std::cout << node -> data;
        inOrder(node -> right);
    }
}

template<class T>
void BinaryTree<T>::postOrder(BinaryTreeNode<T> * node){
    if(node != NULL){
        postOrder(node -> left);
        postOrder(node -> right);
        std::cout << node -> data;
    }
}

template<class T>
void BinaryTree<T>::erase(BinaryTreeNode<T> * node){
    if(node != NULL){
        erase(node -> left);
        erase(node -> right);
        treeSize--;
        //std::cout<<node -> data << " " << treeSize << "\n";
        delete node;
        
    }
}


template<class T>
void BinaryTree<T>::levelOrderInsert(BinaryTreeNode<T> * node, const T element){
    
    if(root == NULL){
        root = new BinaryTreeNode<T>(element);
        //root = std::make_shared<BinaryTreeNode<T>>(element);
        treeSize++;
        return;
    }
    std::queue<BinaryTreeNode<T> *> nodeQueue;
    nodeQueue.push(root);
    BinaryTreeNode<T> * nextNode;
    
    while(nodeQueue.size() > 0){
        nextNode = nodeQueue.front();
        nodeQueue.pop();
        
        if(nextNode -> left != NULL) nodeQueue.push(nextNode -> left);
        else{
            nextNode -> left = new BinaryTreeNode<T>(element);
            treeSize++;
            //This clears anything in the queue for next time the function is called
            //while(nodeQueue.size()) nodeQueue.pop();
            return;
        }
        if(nextNode -> right != NULL) nodeQueue.push(nextNode -> right);
        else{
            nextNode -> right = new BinaryTreeNode<T>(element);
            treeSize++;
            //while(nodeQueue.size()) nodeQueue.pop();
            return;
        }
    }
}





#endif /* binaryTree_hpp */
