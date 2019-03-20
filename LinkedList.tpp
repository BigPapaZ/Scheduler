#include <iostream>
#include <string>

using namespace std;

template <class item_t>
LinkedList<item_t>::LinkedList()
{
    //might be wrong
    this->size=0;

    this->head=new LinkedListNode<item_t>(0,0);
    this->tail=new LinkedListNode<item_t>(0,0);
}

template <class item_t>
LinkedList<item_t>::~LinkedList()
{
    for(int i=0;i<size;i++)
    {
        this->popBack();
    }
}

template <class item_t>
void LinkedList<item_t>::pushBack(const item_t& item)
{
    LinkedListNode<item_t>* Item=new LinkedListNode<item_t>(tail->getNext(),item);

    this->tail->setNext(Item);

    this->tail=Item;
    
    if(this->size==0){this->head=Item;}
    
    this->size++;
}

template <class item_t>
void LinkedList<item_t>::popBack()
{
    if(size==1)
    {
        delete head;
        delete tail;//this might be wrong
        head=new LinkedListNode<item_t>(0, 0);
        tail=new LinkedListNode<item_t>(0, 0);
    }
    else
    {
        LinkedListNode<item_t>* Item=head;
        
        for(int i=0;i<size-2;i++)
        {
            Item=Item->getNext();
        }
        tail=new LinkedListNode<item_t>(0,Item->getItem());
        delete Item;
    }
    size--;
}

template <class item_t>
const item_t& LinkedList<item_t>::getBack() const
{
    return this->tail->getItem();
}

template <class item_t>
void LinkedList<item_t>::pushFront(const item_t& item)
{
    if(size==0){pushBack(item);}
    else
    {
        LinkedListNode<item_t>* Item=new LinkedListNode<item_t>(head,item);

        this->head=Item;
        this->size++;
    }
}

template <class item_t>
void LinkedList<item_t>::popFront()
{
    if(size==1)
    {
        delete head;
        delete tail;        
        head=new LinkedListNode<item_t>(0, 0);
        tail=new LinkedListNode<item_t>(0, 0);
    }
    else
    {
        LinkedListNode<item_t>* Item=this->head->getNext();
        head=Item;
    }

    size--;
}


template <class item_t>
const item_t& LinkedList<item_t>::getFront() const
{
    return this->head->getItem();
}


template <class item_t>
const item_t& LinkedList<item_t>::getItem(int index) const
{
    LinkedListNode<item_t>* Item=head;

    for(int i=0;i<index;i++)//index =0, will it go through?
    {
        Item=Item->getNext();
    }
    return Item->getItem();
}

template <class item_t>
void LinkedList<item_t>::setItem(int index, const item_t& item)
{
    LinkedListNode<item_t>* Item=head;

    for(int i=0;i<index;i++)//index =0, will it go through?
    {
        Item=Item->getNext();
    }
    Item->setItem(item);
//    delete Item;//I want to delete the pointer...not the actual thing in the LinkedList
}

template <class item_t>
void LinkedList<item_t>::insert(int index, const item_t& item)
{
    LinkedListNode<item_t>* Item=head;

    for(int i=0;i<index-1;i++)
    {
        Item=Item->getNext();
    }

    LinkedListNode<item_t>* Item2=Item->getNext();

    LinkedListNode<item_t>* New_Item=new LinkedListNode<item_t>(Item2,item);


    Item->setNext(New_Item);

    size++;
}

template <class item_t>
void LinkedList<item_t>::remove(int index)
{
    LinkedListNode<item_t>* Item=head;

    for(int i=0;i<index-1-1;i++)//index =0, will it go through?
    {
        Item=Item->getNext();
    }

    LinkedListNode<item_t>* Item1=Item->getNext();

    LinkedListNode<item_t>* Item2=Item1->getNext();//memory leak...need to delete the Item1...
    
    Item->setNext(Item2);

    this->size--;

    delete Item1;
}

template <class item_t>
int LinkedList<item_t>::getSize() const
{
    return this->size;
}

template <class item_t>
bool LinkedList<item_t>::isEmpty() const
{
    return this->size==0;
}

template <class item_t>
int LinkedList<item_t>::getCapacity() const
{
    return this->size;
}