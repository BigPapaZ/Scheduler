#include <iostream>
#include <string>

using namespace std;

template <class key_t, class val_t>
BSTForwardIterator<key_t, val_t>::BSTForwardIterator(BSTNode<key_t, val_t>* node, BSTNode<key_t, val_t>* sentinel)
{
    this->current=node;
    this->sentinel=sentinel;
}

template <class key_t, class val_t>
void BSTForwardIterator<key_t, val_t>::next()
{


    if(this->current!=this->sentinel)
    {
        BSTNode<key_t, val_t>* x=this->current;


        if(current->getRightChild()!=this->sentinel)
        {
            current=current->getRightChild();
            while(current->getLeftChild()!=this->sentinel)
            {
//                cout<<"1"<<endl;
                current=current->getLeftChild();
            }
        }

        else
        {
            BSTNode<key_t, val_t>* y=current->getParent();

            while(y!=this->sentinel&&x==y->getRightChild())
            {
                x=y;
                y=y->getParent();
            }

            this->current=y;
        }
    }

//     cout<<"Begining of next()"<<endl;



//     if(current!=this->sentinel)
//     {
//         if(current->getRightChild()!=this->sentinel)
//         {
//             current=current->getRightChild();
//             while(current->getLeftChild()!=this->sentinel)
//             {
// //                //cout<<"1"<<endl;
//                 current=current->getLeftChild();
//             }
//         }

//         else if(current->getLeftChild()!=this->sentinel)
//         {

//             BSTNode<key_t, val_t>* y=current->getParent();

//             while(y!=this->sentinel && current==y->getRightChild())
//             {
// //                cout<<"2"<<endl;
//                 current=y;
//                 y=y->getParent();
//             }

//             current=y;
//         }

//         else
//         {
//             BSTNode<key_t, val_t>* superparent=current;
//             while(superparent->getParent()!=this->sentinel)
//             {
//                 if(superparent==superparent->getParent())
//                 {
//                     superparent->setParent(this->sentinel);
//                 }
//                 else
//                 {
//                     superparent=superparent->getParent();
//                 }
//             }

//             while(superparent->getRightChild()!=this->sentinel)
//             {
//                 if(superparent==superparent->getRightChild())
//                 {
//                     superparent->setRightChild(this->sentinel);
//                 }

//                 else
//                 {
//                     superparent=superparent->getRightChild();
//                 }
//             }

// //            cout<<"a"<<endl;
//             if(superparent==current)
//             {
//                 current=this->sentinel;
//             }

//             else
//             {
// //                cout<<"c"<<endl;
//                 if(current->getParent()->getLeftChild()==current)
//                 {
// //                    cout<<"d"<<endl;
//                     current=current->getParent();
//                 }
//                 else if(current->getParent()->getRightChild()==current)
//                 {
// //                    cout<<"e"<<endl;
//                     while(current->getParent()->getRightChild()==current)
//                     {
// //                        cout<<"5"<<endl;
//                         current=current->getParent();
//                     }
// //                    cout<<"f"<<endl;
//                     current=current->getParent();
//                 }
//             }
//         }
//     }
}

template <class key_t, class val_t>
bool BSTForwardIterator<key_t, val_t>::isPastEnd() const
{
    return this->current==sentinel;
}


template <class key_t, class val_t>
const key_t& BSTForwardIterator<key_t, val_t>::getKey() const
{
    return this->current->getKey();
}


template <class key_t, class val_t>
const val_t& BSTForwardIterator<key_t, val_t>::getValue() const
{
//    cout<<"tryna Return"<<endl;
    return this->current->getValue();
}

template <class key_t, class val_t>
void BSTForwardIterator<key_t, val_t>::setValue(const val_t& newVal)
{
    this->current->setValue(newVal);
}