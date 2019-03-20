#ifndef BST_MULTI_MAP
#define BST_MULTI_MAP

#include "BSTNode.hpp"
#include "BSTForwardIterator.hpp"

template <class key_t,class val_t>
class BSTMultimap
{
  protected:
    virtual bool contains1(BSTNode<key_t, val_t>* x, const key_t& key) const;
    virtual void clear1(BSTNode<key_t, val_t>* x) const;

    //we can just have one function here with a boolean 
    virtual BSTNode<key_t, val_t>* ff(BSTNode<key_t, val_t>* curr,const key_t& key) const;
    virtual BSTNode<key_t, val_t>* fl(BSTNode<key_t, val_t>* curr,const key_t& key) const;

    virtual void insertNode(BSTNode<key_t, val_t>* z);

    BSTNode<key_t, val_t>* root;
    BSTNode<key_t, val_t>* sentinel;
    int numItems;
    
  public:

    BSTMultimap();
    virtual ~BSTMultimap();

    virtual void insert(const key_t& key,const val_t& val);
    virtual int getSize();
    virtual bool isEmpty();
    virtual string toString();
    virtual bool contains(const key_t& key) const;
    virtual void clear();


    virtual BSTForwardIterator<key_t, val_t> getMin() const;
    virtual BSTForwardIterator<key_t, val_t> getMax() const;

    virtual BSTForwardIterator<key_t, val_t> findFirst(const key_t& key) const;
    virtual BSTForwardIterator<key_t, val_t> findLast(const key_t& key) const;

    virtual BSTForwardIterator<key_t, val_t> remove(const BSTForwardIterator<key_t, val_t>& pos);
};

#include "BSTMultimap.tpp"

#endif