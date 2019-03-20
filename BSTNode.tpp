#include <iostream>
#include <string>

using namespace std;

template <class key_t, class val_t>
BSTNode<key_t, val_t>::BSTNode(const key_t& key, const val_t& value)
{
    this->key=key;
    this->val=value;

    this->leftChild=nullptr;
    this->rightChild=nullptr;
    this->Parent=nullptr;
}


template <class key_t, class val_t>
void BSTNode<key_t, val_t>::setValue(const val_t& newItem)
{
    this->val=newItem;
}


template <class key_t, class val_t>
const val_t& BSTNode<key_t, val_t>::getValue() const
{
    return this->val;
}

template <class key_t, class val_t>
void BSTNode<key_t, val_t>::setKey(const key_t& newItem)
{
    this->key=newItem;
}

template <class key_t, class val_t>
const key_t& BSTNode<key_t, val_t>::getKey() const
{
    return this->key;
}

template <class key_t, class val_t>
void BSTNode<key_t, val_t>::setParent(BSTNode<key_t, val_t>* newNext)
{
    this->Parent=newNext;
}

template <class key_t, class val_t>
void BSTNode<key_t, val_t>::setLeftChild(BSTNode<key_t, val_t>* newNext)
{
    this->leftChild=newNext;
}

template <class key_t, class val_t>
void BSTNode<key_t, val_t>::setRightChild(BSTNode<key_t, val_t>* newNext)
{
    this->rightChild=newNext;
}

template <class key_t, class val_t>
BSTNode<key_t, val_t>* BSTNode<key_t, val_t>::getParent() const
{
   return this->Parent;
}

template <class key_t, class val_t>
BSTNode<key_t, val_t>* BSTNode<key_t, val_t>::getRightChild() const
{
   return this->rightChild;
}

template <class key_t, class val_t>
BSTNode<key_t, val_t>* BSTNode<key_t, val_t>::getLeftChild() const
{
   return this->leftChild;
}

template <class key_t, class val_t>
BSTNode<key_t, val_t>::~BSTNode(){}