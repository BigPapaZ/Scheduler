#include <iostream>
#include <string>

using namespace std;

template <class item_t>
ArrayList<item_t>::ArrayList()
{
    this->size=0;
    this->capacity=10;
    item_t* stuff=new item_t[this->capacity];
    this->items=stuff;
}

template <class item_t>
ArrayList<item_t>::ArrayList(int capacity)
{
    this->size=0;
    this->capacity=capacity;
    item_t* stuff=new item_t[this->capacity];
    this->items=stuff;
}

template <class item_t>
ArrayList<item_t>::~ArrayList()
{
    delete[] items; //might not be deleting stuff...items is a pointer
}


template <class item_t>
void ArrayList<item_t>::Array_Copier(int start_index)
{

    if(this->size==this->capacity)
    {
        this->capacity*=2;
    }

    item_t* stuff=new item_t[this->capacity];

    for(int i=0;i<size;i++)
    {
        stuff[i+start_index]=this->items[i];
    }

    delete[] items;

    this->items=stuff;
}


template <class item_t>
void ArrayList<item_t>::pushBack(const item_t& item)
{
    if(this->size==this->capacity)
    {
        this->Array_Copier(0);
    }
    this->items[size]=item;
    this->size++;
}

template <class item_t>
void ArrayList<item_t>::popBack()
{
    size--;
}

template <class item_t>
const item_t& ArrayList<item_t>::getBack() const
{
    return this->items[size-1];
}

template <class item_t>
void ArrayList<item_t>::pushFront(const item_t& item)
{   
    this->Array_Copier(1);

    this->items[0]=item;

    size++;
}

template <class item_t>
void ArrayList<item_t>::Array_Backer(int start_index)
{
    //need to account for things which came before the index
    item_t* stuff=new item_t[this->capacity];
    for(int i=0;i<start_index;i++)
    {
        stuff[i]=this->items[i];
    }
    for(int i=start_index+1;i<this->size;i++) 
    {
        stuff[i-1]=this->items[i];
    }

    delete[] items;
    
    this->items=stuff;
}

template <class item_t>
void ArrayList<item_t>::popFront()
{
    this->Array_Backer(0);
    size--;
}


template <class item_t>
const item_t& ArrayList<item_t>::getFront() const
{
    return this->items[0];
}


template <class item_t>
const item_t& ArrayList<item_t>::getItem(int index) const
{
    return items[index];
}

template <class item_t>
void ArrayList<item_t>::setItem(int index, const item_t& item)
{
    this->items[index]=item;
}

template <class item_t>
void ArrayList<item_t>::insert(int index, const item_t& item)
{
    if(this->size==this->capacity)
    {
        this->capacity*=2;
    }

    item_t* stuff=new item_t[this->capacity];

    for(int i=0;i<index;i++)
    {
        stuff[i]=this->items[i];
    }

    for(int i=index;i<size;i++)
    {
        stuff[i+1]=this->items[i];
    }

    delete[] items;

    this->items=stuff;

    this->items[index]=item;
    size++;
}

template <class item_t>
void ArrayList<item_t>::remove(int index)
{
    this->Array_Backer(index);
    size--;
}

template <class item_t>
int ArrayList<item_t>::getSize() const
{
    return this->size;
}

template <class item_t>
bool ArrayList<item_t>::isEmpty() const
{
    if(this->size!=0)
    {
        return 0;
    }
    return 1;
}

template <class item_t>
int ArrayList<item_t>::getCapacity() const
{
    return this->capacity;
}