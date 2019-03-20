#include <iostream>
#include <string>

#include "BSTForwardIterator.hpp"

using namespace std;

template <class key_t,class val_t>
BSTMultimap<key_t, val_t>::BSTMultimap()
{
    this->sentinel=0;
    this->numItems=0;
    this->root=this->sentinel;
}

template <class key_t,class val_t>
void BSTMultimap<key_t, val_t>::insertNode(BSTNode<key_t, val_t>* z)
{
    BSTNode<key_t, val_t>* x=this->root;
    
    BSTNode<key_t, val_t>* y=this->sentinel;

    while(x!=this->sentinel)
    {
        y=x;

        if(z->getKey()<x->getKey())
        {
            x=x->getLeftChild();
        }
        else
        {
            x=x->getRightChild();
        }
    }

    z->setParent(y);

    if(y==this->sentinel)
    {
        this->root=z;
    }

    else if(z->getKey()<y->getKey())
    {
        y->setLeftChild(z);
    }

    else
    {
        y->setRightChild(z);
    }

    numItems++;
}


template <class key_t,class val_t>
void BSTMultimap<key_t, val_t>::insert(const key_t& key,const val_t& val)
{
    BSTNode<key_t, val_t>* z=new BSTNode<key_t, val_t>(key,val);
    this->insertNode(z);
}

template <class key_t,class val_t>
int BSTMultimap<key_t, val_t>::getSize()
{
    return this->numItems;
}


template <class key_t,class val_t>
bool BSTMultimap<key_t, val_t>::isEmpty()
{
    return this->numItems==0;
}


template <class key_t,class val_t>
string BSTMultimap<key_t, val_t>::toString()
{
    return "0";
}


template <class key_t,class val_t>
bool BSTMultimap<key_t, val_t>::contains1(BSTNode<key_t, val_t>* x ,const key_t& key) const
{
    if(x==nullptr)
    {
        return false;
    }

    if(key==x->getKey())
    {
        return true;
    }
    if(key<x->getKey())
    {
        return contains1(x->getLeftChild(),key);
    }

    else
    {
        return contains1(x->getRightChild(),key);
    }
}



template <class key_t,class val_t>
bool BSTMultimap<key_t, val_t>::contains(const key_t& key) const
{
    BSTNode<key_t, val_t>* x=this->root;


//why do i have this nullptr thing here???
    if(x==nullptr || key==x->getKey())
    {
        return true;
    }

    if(key<x->getKey())
    {
        return contains1(x->getLeftChild(),key);
    }

    else
    {
        return contains1(x->getRightChild(),key);
    }
}


template <class key_t,class val_t>
void BSTMultimap<key_t, val_t>::clear1(BSTNode<key_t, val_t>* x) const
{
    if(x!=sentinel)
    {
        if(x->getLeftChild()!=sentinel)
        {
            clear1(x->getLeftChild());
        }

        if(x->getRightChild()!=sentinel)
        {
            clear1(x->getRightChild());
        }
        delete x;
    }
}

template <class key_t,class val_t>
void BSTMultimap<key_t, val_t>::clear()
{
    if(root!=sentinel)
    {
        if(root->getLeftChild()!=sentinel)
        {
            clear1(root->getLeftChild());
        }

        if(root->getRightChild()!=sentinel)
        {
            clear1(root->getRightChild());
        }
        delete root;
    }
    this->root=this->sentinel;
    this->numItems=0;
}

template <class key_t,class val_t>
BSTMultimap<key_t, val_t>::~BSTMultimap()
{
    this->clear();
}

template <class key_t,class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap<key_t, val_t>::getMin() const
{
    BSTNode<key_t, val_t>* curr=this->root;

    while(curr->getLeftChild()!=this->sentinel)
    {
        curr=curr->getLeftChild();
    }

    BSTForwardIterator<key_t, val_t> x(curr,this->sentinel);

    return x;
}

template <class key_t,class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap<key_t, val_t>::getMax() const
{   

    BSTNode<key_t, val_t>* curr=this->root;

    while(curr->getRightChild()!=this->sentinel)
    {
        curr=curr->getRightChild();
    }
    
    BSTForwardIterator<key_t, val_t> x(curr,this->sentinel);

    return x;
}

template <class key_t,class val_t>
BSTNode<key_t, val_t>* BSTMultimap<key_t, val_t>::ff(BSTNode<key_t, val_t>* curr,const key_t& key) const
{
    if(curr->getLeftChild()==sentinel&&curr->getRightChild()==sentinel)
    {
        if(curr->getKey()==key)
        {
            return curr;
        }

        return this->sentinel;
    }

    if(curr->getLeftChild()!=sentinel)
    {
        BSTNode<key_t, val_t>* x=ff(curr->getLeftChild(),key);
        
        if(x!=this->sentinel&&x->getKey()==key)
        {
            return x;
        }
    }

    if(curr->getKey()==key)
    {
        return curr;
    }

    else if(curr->getRightChild()!=sentinel)
    {
        BSTNode<key_t, val_t>* x=ff(curr->getRightChild(),key);
        if(x!=this->sentinel&&x->getKey()==key)
        {
            return x;
        }
    }

    return this->sentinel;
}


template <class key_t,class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap<key_t, val_t>::findFirst(const key_t& key) const
{   
    if(this->root==this->sentinel)
    {
        return BSTForwardIterator<key_t, val_t>(sentinel,this->sentinel);
    }

    BSTNode<key_t, val_t>* curr=this->root;

    if(curr->getLeftChild()==sentinel&&curr->getRightChild()==sentinel)
    {
        if(curr->getKey()==key)
        {            
            BSTForwardIterator<key_t, val_t>* x=new BSTForwardIterator<key_t, val_t>(curr,this->sentinel);
            return *x;
        }

        return BSTForwardIterator<key_t, val_t>(sentinel,this->sentinel);
    }

    if(curr->getLeftChild()!=sentinel)
    {
        BSTNode<key_t, val_t>* x=ff(curr->getLeftChild(),key);
        if(x!=this->sentinel&&x->getKey()==key)
        {
            BSTForwardIterator<key_t, val_t>* a=new BSTForwardIterator<key_t, val_t>(x,this->sentinel);
            return *a;
        }
    }

    if(curr->getKey()==key)
    {
        return BSTForwardIterator<key_t, val_t>(curr,this->sentinel);
    }

    else if(curr->getRightChild()!=sentinel)
    {
        BSTNode<key_t, val_t>* x=ff(curr->getRightChild(),key);
        if(x!=this->sentinel&&x->getKey()==key)
        {
            return BSTForwardIterator<key_t, val_t>(x,this->sentinel);
        }
    }
    return BSTForwardIterator<key_t, val_t>(sentinel,this->sentinel);
}


template <class key_t,class val_t>
BSTNode<key_t, val_t>* BSTMultimap<key_t, val_t>::fl(BSTNode<key_t, val_t>* curr,const key_t& key) const
{
    if(curr->getLeftChild()==sentinel&&curr->getRightChild()==sentinel)
    {
        if(curr->getKey()==key)
        {
            return curr;
        }

        return this->sentinel;
    }

    if(curr->getRightChild()!=sentinel)
    {
        BSTNode<key_t, val_t>* x=fl(curr->getRightChild(),key);
        if(x!=this->sentinel&&x->getKey()==key)
        {
            return x;
        }
    }

    if(curr->getKey()==key)
    {
        return curr;
    }

    else if(curr->getLeftChild()!=sentinel)
    {
        BSTNode<key_t, val_t>* x=fl(curr->getLeftChild(),key);
        
        if(x!=this->sentinel&&x->getKey()==key)
        {
            return x;
        }
    }

    return this->sentinel;
}

template <class key_t,class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap<key_t, val_t>::findLast(const key_t& key) const
{

    if(this->root==this->sentinel)
    {
        return BSTForwardIterator<key_t, val_t>(sentinel,this->sentinel);
    }

    BSTNode<key_t, val_t>* curr=this->root;

    if(curr->getLeftChild()==sentinel&&curr->getRightChild()==sentinel)
    {
        if(curr->getKey()==key)
        {            

            BSTForwardIterator<key_t, val_t> x=BSTForwardIterator<key_t, val_t>(curr,this->sentinel);
            return x;

            // BSTForwardIterator<key_t, val_t>* x=new BSTForwardIterator<key_t, val_t>(curr,this->sentinel);
            // return *x;
        }

        return BSTForwardIterator<key_t, val_t>(sentinel,this->sentinel);
    }

    if(curr->getRightChild()!=sentinel)
    {
        BSTNode<key_t, val_t>* x=fl(curr->getRightChild(),key);
        if(x!=this->sentinel&&x->getKey()==key)
        {
            return BSTForwardIterator<key_t, val_t>(x,this->sentinel);
        }
    }

    if(curr->getKey()==key)
    {
        return BSTForwardIterator<key_t, val_t>(curr,this->sentinel);
    }

    else if(curr->getLeftChild()!=sentinel)
    {
        BSTNode<key_t, val_t>* x=fl(curr->getLeftChild(),key);
        if(x!=this->sentinel&&x->getKey()==key)
        {
            BSTForwardIterator<key_t, val_t>* a=new BSTForwardIterator<key_t, val_t>(x,this->sentinel);
            return *a;
        }
    }

    return BSTForwardIterator<key_t, val_t>(sentinel,this->sentinel);
}

template <class key_t,class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap<key_t, val_t>::remove(const BSTForwardIterator<key_t, val_t>& pos)
{
    if(pos.current!=this->sentinel)
    {
    this->numItems--;
    BSTForwardIterator<key_t, val_t> stuff(pos.current,this->sentinel);
    stuff.next();
    if(pos.current==this->root&&pos.current->getLeftChild()==this->sentinel&&pos.current->getRightChild()==this->sentinel)
    {
        this->root=this->sentinel;
        return BSTForwardIterator<key_t, val_t>(this->sentinel,this->sentinel);
    }


    else if(pos.current->getLeftChild()==this->sentinel&&pos.current->getRightChild()==this->sentinel)
    {
        if(pos.current->getParent()->getLeftChild()==pos.current)
        {
            pos.current->getParent()->setLeftChild(this->sentinel);
        }
        else
        {
            pos.current->getParent()->setRightChild(this->sentinel);
        }
    }

    else if(pos.current->getLeftChild()==this->sentinel)
    {
        if(pos.current==this->root)
        {
            this->root=pos.current->getRightChild();
        }
        
        else if(pos.current==pos.current->getParent()->getLeftChild())
        {
            pos.current->getParent()->setLeftChild(pos.current->getRightChild());
        }
        else
        {
            pos.current->getParent()->setRightChild(pos.current->getRightChild());
        }

        pos.current->getRightChild()->setParent(pos.current->getParent());
    }

    else if(pos.current->getRightChild()==this->sentinel)
    {
        if(pos.current==this->root)
        {
            this->root=pos.current->getLeftChild();
        }

        else if(pos.current==pos.current->getParent()->getLeftChild())
        {
            pos.current->getParent()->setLeftChild(pos.current->getLeftChild());
        }
        else
        {
            pos.current->getParent()->setRightChild(pos.current->getLeftChild());
        }

        pos.current->getLeftChild()->setParent(pos.current->getParent());    
    }

    else
    {
        BSTNode<key_t, val_t>* y=pos.current->getRightChild();
        while(y->getLeftChild()!=this->sentinel)
        {
            y=y->getLeftChild();
        }
        
        if(pos.current==this->root)
        {
            this->root=y;
        }
        else if(pos.current->getParent()!=this->sentinel && pos.current==pos.current->getParent()->getLeftChild())
        {
            pos.current->getParent()->setLeftChild(y);
        }
        else if(pos.current->getParent()!=this->sentinel)
        {
            pos.current->getParent()->setRightChild(y);            
        }

        if(y!=pos.current->getRightChild())
        {
            y->getParent()->setLeftChild(y->getRightChild());
            if(y->getRightChild()!=this->sentinel)
            {
                y->getRightChild()->setParent(y->getParent());
            }
            y->setRightChild(pos.current->getRightChild());
        }
        y->setLeftChild(pos.current->getLeftChild());
        pos.current->getLeftChild()->setParent(y);
        y->setParent(pos.current->getParent());



        // if(y->getParent()!=pos.current)
        // {
        //     this->Transplant(pos.current,pos.current->getRightChild());
        //     y->setRightChild(pos.current->getRightChild());
        //     y->getRightChild()->setParent(y);
        // }
        // this->Transplant(pos.current,y);

        // y->setLeftChild(pos.current->getLeftChild());
        // y->getLeftChild()->setParent(y);
    }
        delete pos.current;

        return stuff;
    }
    return BSTForwardIterator<key_t, val_t>(this->sentinel,this->sentinel);
}