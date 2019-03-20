#include "BSTForwardIterator.hpp"


template <class key_t, class val_t>
RBTMultimap<key_t, val_t>::RBTMultimap(): BSTMultimap<key_t, val_t>()
{
	this->sentinel=new RBTNode<key_t, val_t>(key_t(),val_t(),0);
	this->root=this->sentinel;
}

template <class key_t, class val_t>
RBTMultimap<key_t, val_t>::~RBTMultimap()
{
	this->clear();
	delete this->sentinel;
}


template <class key_t, class val_t>
BSTForwardIterator<key_t, val_t> RBTMultimap<key_t, val_t>::remove(const BSTForwardIterator<key_t, val_t>& pos)
{
	RBTNode<key_t, val_t>* y=dynamic_cast<RBTNode<key_t, val_t>*> (pos.current);
	RBTNode<key_t, val_t>* z=dynamic_cast<RBTNode<key_t, val_t>*> (pos.current);

	BSTForwardIterator<key_t, val_t> stuff(pos.current,this->sentinel);
	stuff.next();

	bool Y_Original=y->isRed();

	BSTNode<key_t, val_t>* x;
	if(z->getLeftChild()==this->sentinel)
	{
		x=z->getRightChild();
		this->transplant(z,x);
	}
	else if(z->getRightChild()==this->sentinel)
	{
		x=z->getLeftChild();
		this->transplant(z,x);
	}
	else
	{
		y=y->getRightChild();
		while(y->getLeftChild()!=this->sentinel)
		{
			y=y->getLeftChild();
		}

		Y_Original=y->isRed();

		x=y->getRightChild();

		if(y->getParent()==z)
		{
			x->setParent(y);
		}

		else
		{
			this->transplant(y,x);
		}

		this->transplant(z,y);

		y->setIsRed(z->isRed());
	}

	bool sent=0;

	if(!Y_Original)
	{
		if(x==this->sentinel)
		{
			sent=1;
		}

		this->deleteFixup(dynamic_cast<RBTNode<key_t, val_t>*>(x));
	}

	delete z;

	if(sent)
	{
		this->sentinel->setParent(nullptr);
	}

	return stuff;
}



template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::insert(const key_t& key, const val_t& value)
{
	RBTNode<key_t, val_t>* x=new RBTNode<key_t, val_t>(key,value,1);
	this->insertNode(x);
	this->insertFixup(x);
}



template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::transplant(BSTNode<key_t, val_t>* nodeToReplace, BSTNode<key_t, val_t>* replacementNode)
{
	if(nodeToReplace->getParent()==this->sentinel)
	{
		this->root=replacementNode;
	}
	else if(nodeToReplace!=this->root&&nodeToReplace==nodeToReplace->getParent()->getLeftChild())
	{
		nodeToReplace->getParent()->setLeftChild(replacementNode);		
	}

	else if(nodeToReplace!=this->root&&nodeToReplace==nodeToReplace->getParent()->getRightChild())
	{
		nodeToReplace->getParent()->setRightChild(replacementNode);
	}


	//THAT sentinal thing might give be problems later on...
	// if(replacementNode!=this->sentinel)
	// {
		replacementNode->setParent(nodeToReplace->getParent());

		if(replacementNode!=nodeToReplace->getLeftChild())
		{replacementNode->setLeftChild(nodeToReplace->getLeftChild());}
		else if(replacementNode!=this->sentinel)
		{replacementNode->setLeftChild(this->sentinel);}	
		
		if(replacementNode!=nodeToReplace->getRightChild())
		{replacementNode->setRightChild(nodeToReplace->getRightChild());}
		else if(replacementNode!=this->sentinel)
		{replacementNode->setRightChild(this->sentinel);}

//		replacementNode->setRightChild(nodeToReplace->getRightChild());

		if(replacementNode!=this->sentinel&&replacementNode->getLeftChild()!=this->sentinel)
		{
			replacementNode->getLeftChild()->setParent(replacementNode);
		}
		if(replacementNode!=this->sentinel&&replacementNode->getRightChild()!=this->sentinel)
		{
			replacementNode->getRightChild()->setParent(replacementNode);
		}
//	}
	//do we need to delete nodeToReplace??????
//	delete nodeToReplace;
}


template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::rotateRight(BSTNode<key_t, val_t>* node)
{


	BSTNode<key_t, val_t>* y=node->getLeftChild();

	//what if the node is a sentinal

	node->setLeftChild(y->getRightChild());
	if(y->getRightChild()!=this->sentinel)
	{
		y->getRightChild()->setParent(node);
	}

	y->setParent(node->getParent());

	if(node->getParent()==this->sentinel)
	{
		this->root=y;
	}

	else if(node==node->getParent()->getRightChild())
	{
		node->getParent()->setRightChild(y);
	}

	else
	{
		node->getParent()->setLeftChild(y);
	}

	y->setRightChild(node);

	node->setParent(y);
}


template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::rotateLeft(BSTNode<key_t, val_t>* node)
{
		BSTNode<key_t, val_t>* y=node->getRightChild();
		node->setRightChild(y->getLeftChild());

		if(y->getLeftChild()!=this->sentinel)
		{
			y->getLeftChild()->setParent(node);
		}

		y->setParent(node->getParent());

		if(node->getParent()==this->sentinel)
		{
			this->root=y;
		}

		else if(node==node->getParent()->getLeftChild())
		{
			node->getParent()->setLeftChild(y);
		}

		else
		{
			node->getParent()->setRightChild(y);
		}

		y->setLeftChild(node);

		node->setParent(y);
}



template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::insertFixup(RBTNode<key_t, val_t>* insertedNode)
{
	while(insertedNode->getParent()->isRed())
	{
		if(insertedNode->getParent()==insertedNode->getParent()->getParent()->getLeftChild())
		{
			RBTNode<key_t, val_t>* y=insertedNode->getParent()->getParent()->getRightChild();

			if(y->isRed())
			{
				insertedNode->getParent()->setIsRed(0);
				y->setIsRed(0);
				insertedNode->getParent()->getParent()->setIsRed(1);
				insertedNode=insertedNode->getParent()->getParent();
			}

			else if(insertedNode==insertedNode->getParent()->getRightChild())
			{
				insertedNode=insertedNode->getParent();
				this->rotateLeft(insertedNode);
			}

			else if(insertedNode!=this->root)
			{
				insertedNode->getParent()->setIsRed(0);
				if(insertedNode->getParent()!=this->root)
				{
					insertedNode->getParent()->getParent()->setIsRed(1);
					this->rotateRight(insertedNode->getParent()->getParent());
				}
			}
		}

		else
		{
			RBTNode<key_t, val_t>* y=insertedNode->getParent()->getParent()->getLeftChild();

			if(y->isRed())
			{
				insertedNode->getParent()->setIsRed(0);
				y->setIsRed(0);
				insertedNode->getParent()->getParent()->setIsRed(1);
				insertedNode=insertedNode->getParent()->getParent();
			}

			else if(insertedNode==insertedNode->getParent()->getLeftChild())
			{
				insertedNode=insertedNode->getParent();
				this->rotateRight(insertedNode);
			}

			else if(insertedNode!=this->root)
			{
				insertedNode->getParent()->setIsRed(0);

				if(insertedNode->getParent()!=this->root)
				{
					insertedNode->getParent()->getParent()->setIsRed(1);
					this->rotateLeft(insertedNode->getParent()->getParent());
				}
			}
		}
	}

	RBTNode<key_t, val_t>* x=dynamic_cast<RBTNode<key_t, val_t>* >(this->root);
	x->setIsRed(0);
	this->root=x;
}

template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::deleteFixup(RBTNode<key_t, val_t>* replacementNode)
{
	while(replacementNode!=this->root && !replacementNode->isRed())
	{
		if(replacementNode==replacementNode->getParent()->getLeftChild())
		{
			RBTNode<key_t, val_t>* w=replacementNode->getParent()->getRightChild();
			if(w->isRed())
			{
				//cout<<"1"<<endl;
				w->setIsRed(0);
				replacementNode->getParent()->setIsRed(1);
				this->rotateLeft(replacementNode->getParent());
				w=replacementNode->getParent()->getRightChild();
			}

			if(!w->getLeftChild()->isRed() && !w->getRightChild()->isRed())
			{
				//cout<<"2"<<endl;
				w->setIsRed(1);
				replacementNode=replacementNode->getParent();
			}

			else
			{
				if(!w->getRightChild()->isRed())
				{
					//cout<<"3"<<endl;
					w->getLeftChild()->setIsRed(0);
					w->setIsRed(1);
					RBTNode<key_t, val_t>* x=w->getParent();
					this->rotateRight(w);
					w=x->getRightChild();
				}
				//cout<<"4"<<endl;
				w->setIsRed(replacementNode->getParent()->isRed());
				replacementNode->getParent()->setIsRed(0);
				w->getRightChild()->setIsRed(0);
				this->rotateLeft(replacementNode->getParent());
				replacementNode=dynamic_cast<RBTNode<key_t, val_t>*>(this->root);
			}
		}
		else
		{
			RBTNode<key_t, val_t>* w=replacementNode->getParent()->getLeftChild();
			if(w->isRed())
			{
				//out<<"5"<<endl;
				w->setIsRed(0);
				replacementNode->getParent()->setIsRed(1);
				this->rotateRight(replacementNode->getParent());
				w=replacementNode->getParent()->getLeftChild();
			}

			if(!w->getRightChild()->isRed() && !w->getLeftChild()->isRed())
			{
				//cout<<"6"<<endl;
				w->setIsRed(1);
				replacementNode=replacementNode->getParent();
			}

			else
			{
				if(!w->getLeftChild()->isRed())
				{
					//cout<<"7"<<endl;
					w->getRightChild()->setIsRed(0);
					w->setIsRed(1);
					RBTNode<key_t, val_t>* x=w->getParent();
					this->rotateLeft(w);
					w=x->getLeftChild();
				}

				//cout<<"8"<<endl;
				w->setIsRed(replacementNode->getParent()->isRed());
				replacementNode->getParent()->setIsRed(0);
				w->getLeftChild()->setIsRed(0);
				this->rotateRight(replacementNode->getParent());
				replacementNode=dynamic_cast<RBTNode<key_t, val_t>*>(this->root);
			}
		}
	}
	replacementNode->setIsRed(0);
}



template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::insertNode(RBTNode<key_t, val_t>* z)
{
    RBTNode<key_t, val_t>* x=dynamic_cast<RBTNode<key_t, val_t>*> (this->root);
    
    RBTNode<key_t, val_t>* y=dynamic_cast<RBTNode<key_t, val_t>*> (this->sentinel);

    while(x!=dynamic_cast<RBTNode<key_t, val_t>* >(this->sentinel))
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

	z->setLeftChild(this->sentinel);
	z->setRightChild(this->sentinel);	

	z->setIsRed(1);

    this->numItems++;
}




template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::printDOT(std::string filename)
{
   using namespace std;
   ofstream fout(filename.c_str());

   long long counter = 1;
   map<RBTNode<key_t, val_t>*, long long> nodeToCounter;
   nodeToCounter[dynamic_cast<RBTNode<key_t, val_t>* >(this->sentinel)] = counter;
   counter++;

   fout << "digraph RBTMultimap {" << endl;

   fout << "\t node" << nodeToCounter[dynamic_cast<RBTNode<key_t, val_t>* >(this->sentinel)] << " [label=\"nil\", style=filled, color=grey, fontcolor=white];" << endl;

   if(this->root != this->sentinel)
   {
      RBTNode<key_t, val_t>* rt = dynamic_cast<RBTNode<key_t, val_t>* >(this->root);
      if(!nodeToCounter[rt])
      {
	 nodeToCounter[rt] = counter;
	 counter++;
      }
      if(!nodeToCounter[rt->getParent()])
      {
	 nodeToCounter[rt->getParent()] = counter;
	 counter++;
      }
      fout << "\t node" << nodeToCounter[rt] << " -> node" << nodeToCounter[rt->getParent()] << " [constraint=false, tailport=n, headport=s";
      if(rt->getParent() == this->sentinel)
      {
	 fout << ", color=grey];" << endl;
      }
      else
      {
	 //The root's parent is something weird!! Make the arrow orange so it sticks out
	 fout << ", color=orange];" << endl;
      }

      map<RBTNode<key_t, val_t>*, bool> printed;
   
      queue<RBTNode<key_t, val_t>* > q;
      q.push(rt);
      while(!q.empty())
      {
	 RBTNode<key_t, val_t>* node = q.front();
	 q.pop();

	 printed[node] = true;
      
	 //Set up node's appearance
	 if(!nodeToCounter[node])
	 {
	    nodeToCounter[node] = counter;
	    counter++;
	 }
	 fout << "\t node" << nodeToCounter[node] << " [label=\"k: " << node->getKey() << "\", style=filled, color=";
	 if(node->isRed())
	 {
	    fout << "red";
	 }
	 else
	 {
	    fout << "black, fontcolor=white";
	 }
	 fout << "];" << endl;

	 //Set up child links
	 //First the left node
	 if(!nodeToCounter[node->getLeftChild()])
	 {
	    nodeToCounter[node->getLeftChild()] = counter;
	    counter++;
	 }
	 fout << "\t node" << nodeToCounter[node] << " -> node" << nodeToCounter[node->getLeftChild()] << " [tailport=sw";    
	 if(node->getLeftChild() == this->sentinel)
	 {
	    fout << ", color=grey";
	 }
	 else if(printed[node->getLeftChild()])
	 {
	    fout << ", color=orange";
	 }
	 else
	 {
	    q.push(node->getLeftChild());
	 }

	 if(node->getLeftChild() != this->sentinel)
	 {
	    if(node->getLeftChild()->getParent() == node)
	    {
	       //The child's parent pointer points right back,
	       //so draw the second arrow
	       fout << ", dir=both];" << endl;
	    }
	    else
	    {
	       //The child node's parent pointer is not correct!
	       //Draw it in orange so it sticks out
	       fout << "];" << endl;
	       if(!nodeToCounter[node->getLeftChild()->getParent()])
	       {
		  nodeToCounter[node->getLeftChild()->getParent()] = counter;
		  counter++;
	       }
	       fout << "\t node" << nodeToCounter[node->getLeftChild()] << " -> node" << nodeToCounter[node->getLeftChild()->getParent()] << " [tailport=n, color=orange];" << endl;
	    }
	 }
	 else
	 {
	    fout << "];" << endl;
	 }

	 //Now the right node
	 if(!nodeToCounter[node->getRightChild()])
	 {
	    nodeToCounter[node->getRightChild()] = counter;
	    counter++;
	 }
	 fout << "\t node" << nodeToCounter[node] << " -> node" << nodeToCounter[node->getRightChild()] << " [tailport=se";    
	 if(node->getRightChild() == this->sentinel)
	 {
	    fout << ", color=grey";
	 }
	 else if(printed[node->getRightChild()])
	 {
	    fout << ", color=orange";
	 }
	 else
	 {
	    q.push(node->getRightChild());
	 }

	 if(node->getRightChild() != this->sentinel)
	 {
	    if(node->getRightChild()->getParent() == node)
	    {
	       //The child's parent pointer points right back,
	       //so draw the second arrow
	       fout << ", dir=both];" << endl;
	    }
	    else
	    {
	       //The child node's parent pointer is not correct!
	       //Draw it in orange so it sticks out
	       fout << "];" << endl;
	       if(!nodeToCounter[node->getRightChild()->getParent()])
	       {
		  nodeToCounter[node->getRightChild()->getParent()] = counter;
		  counter++;
	       }
	       fout << "\t node" << nodeToCounter[node->getRightChild()] << " -> node" << nodeToCounter[node->getRightChild()->getParent()] << " [tailport=n, color=orange];" << endl;
	    }
	 }
	 else
	 {
	    fout << "];" << endl;
	 }
      }
   }
   fout << "}" << endl;
}