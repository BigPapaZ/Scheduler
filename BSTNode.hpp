#ifndef BST_NODE
#define BST_NODE

template <class key_t,class val_t>
class BSTNode
{
  protected:
    key_t  key;
    val_t val;

    BSTNode<key_t, val_t>* leftChild;
    BSTNode<key_t, val_t>* rightChild; 
    BSTNode<key_t, val_t>* Parent;


  public:
    BSTNode(const key_t& key, const val_t& value);
    virtual ~BSTNode();

    virtual const val_t& getValue() const;
    virtual void setValue(const val_t& newValue);

    virtual const key_t& getKey() const;
    virtual void setKey(const key_t& newValue);

    virtual BSTNode<key_t, val_t>* getLeftChild() const;   
    virtual void setLeftChild(BSTNode<key_t, val_t>* newNext);

    virtual BSTNode<key_t, val_t>* getRightChild() const;     
    virtual void setRightChild(BSTNode<key_t, val_t>* newNext);

    virtual BSTNode<key_t, val_t>* getParent() const;     
    virtual void setParent(BSTNode<key_t, val_t>* newNext);
};

#include "BSTNode.tpp"

#endif