#include <cstdio>
#include <stdexcept>
#include "DLLProjectList.h"

DLLProjectList::DLLProjectList()
{
	size = 0;
	head = tail = NULL;
}

DLLProjectList::DLLProjectList(const DLLProjectList* const ref)
{
	printf("DLL Working\n");

	size = ref->size;
	/*printf("%i\n",size);
	printf("DLL Working\n");
	int x = ref->head->GetValue();
	printf("%i\n",x);
	printf("DLL Working\n");
	DLLNode* n = ref->head->GetNext();
	printf("%x\n",n);
	printf("DLL Working\n");
	DLLNode* p = ref->head->GetPrev();
	printf("%x\n",p);
	printf("DLL Working\n");*/
	
	head = new DLLNode(ref->head);
	tail = new DLLNode(ref->tail);
	
	printf("DLL Working\n");
	
	if(ref->tail != NULL) //hard-coded because we cannot use other member's inline functions
	{
		DLLNode* iter = ref->tail;
	
		printf("DLL Working\n");
	
		while(iter != ref->head)
		{
			printf("DLL Working\n");
			InsertFirst(iter->GetValue());
			printf("DLL Working\n");
			iter = iter->GetPrev();
		}
		
		printf("DLL Working\n");
		
		InsertFirst(iter->GetValue());
	}
}

DLLProjectList::~DLLProjectList()
{
	//iterator that deletes all nodes
	while(!IsEmpty())
		RemoveFirst();
}

/**
 * Returns the Position after Position p (error if p is the last position)
 *
 * @param a Position ADT pos representing the current node
 * @return the Position ADT representing the node after the current node, assuming the input is valid
 */
Position* DLLProjectList::After(Position* pos) const
{
	DLLNode* node = static_cast<DLLNode*>(pos);
	
	if(node == tail)
		throw std::invalid_argument("DLLProjectList-After: cannot call After on tail of list");
	
	return node->GetNext();
}

/**
 * Returns the Position before Position p (error if p is first position)
 *
 * @param a Position ADT pos representing the current node
 * @return the Position ADT representing the node before the current node, assuming the input is valid
 */
Position* DLLProjectList::Before(Position* pos) const
{
	DLLNode* node = static_cast<DLLNode*>(pos);
	
	if(node == head)
		throw std::invalid_argument("DLLProjectList-Before: cannot call Before on head of list");
	
	return node->GetPrev();
}

/**
 * Returns first Position of the list
 *
 * @return the Position ADT that represents the beginning of the list
 */
Position* DLLProjectList::First() const
{
	return head;
}

/**
 * Adds a new node with value val at the front of the list
 *
 * @param the 8 digit base10 number that should be stored in the starting node 
 */
void DLLProjectList::InsertFirst(int val)
{
	DLLNode* node = new DLLNode(val, head, NULL);
	if(head == NULL)
	{
		head = tail = node;
	}
	else
	{
		head->SetPrev(node);
		head = node;
	}
	
	++size;
}

/**
 * Adds a new node with value val at the end of the list
 *
 * @param the 8 digit base10 number that should be stored in the final node 
 */
void DLLProjectList::InsertLast(int val)
{
	DLLNode* node = new DLLNode(val, NULL, tail);
	if(tail == NULL)
	{
		head = tail = node;
	}
	else
	{
		tail->SetNext(node);
		tail = node;
	}
	
	++size;
}

/**
 * Returns Boolean value indicating if the list has no nodes
 *
 * @return false if there are no nodes in the linked list, true otherwise
 */
bool DLLProjectList::IsEmpty() const
{
	return head == NULL;
}

/**
 * Determines if Position pos is the first position of the list
 *
 * @param a Position ADT pos
 * @return boolean indicating whether or not Position pos is the head of the linked list
 */
bool DLLProjectList::IsFirst(Position* pos) const
{
	DLLNode* node = static_cast<DLLNode*>(pos);
	
	return node == head;
}

/**
 * Determines if Position p is the last position of the list
 *
 * @param a Position ADT p
 * @return boolean indicating whether or not Position pos is the tail of the linked list
 */
bool DLLProjectList::IsLast(Position* pos) const
{
	DLLNode* node = static_cast<DLLNode*>(pos);
	
	return node == tail;
}

/**
 * Returns last Position of the list
 *
 * @return the Position ADT that represents the end of the list
 */
Position* DLLProjectList::Last() const
{
	return tail;
}

/**
 * Remove the first node in the list 
 */
void DLLProjectList::RemoveFirst()
{
	if(head == NULL)
	{
		throw std::invalid_argument("DLLProjectList-RemoveFirst: cannot remove the head of a null list");
	}
	else
	{
		DLLNode* first = head;
		
		if(!IsLast(first))
		{
			head = static_cast<DLLNode*>(this->After(first));
			head->SetPrev(NULL);
		}
		else
		{
			head = tail = NULL;
		}
		
		delete first;
		--size;
	}
}

/**
 * Returns the number of positions in the list as an integer
 *
 * @return the number of nodes in the linked list 
 */
size_t DLLProjectList::Size() const
{
	return size;
}