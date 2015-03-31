#include "DLLProjectList.h"

DLLProjectList::DLLProjectList()
{
	size = 0;
	head = tail = NULL;
}

DLLProjectList::~DLLProjectList()
{
	//iterator that deletes all nodes
}

/**
 * Returns the Position after Position p (error if p is the last position)
 *
 * @param a Position ADT pos representing the current node
 * @return the Position ADT representing the node after the current node, assuming the input is valid
 */
Position* DLLProjectList::After(const Position* pos)
{
	DLLNode* node = dynamic_cast<DLLNode*>(pos);
	
	if(node == tail)
	{
		throw Exception("DLLProjectList-After: cannot call After on tail of list");
	}
	
	return node.GetNext();
}

/**
 * Returns the Position before Position p (error if p is first position)
 *
 * @param a Position ADT pos representing the current node
 * @return the Position ADT representing the node before the current node, assuming the input is valid
 */
Position* DLLProjectList::Before(const Position* pos)
{
	DLLNode* node = dynamic_cast<DLLNode*>(pos);
	
	if(node == head)
	{
		throw Exception("DLLProjectList-Before: cannot call Before on head of list");
	}
	
	return node.GetPrev();
}

/**
 * Returns first Position of the list
 *
 * @return the Position ADT that represents the beginning of the list
 */
Position* DLLProjectList::First()
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
	DLLNode* node = DLLNode(val, head, NULL);
	if(head == NULL)
	{
		head = tail = node;
	}
	else
	{
		head.setPrev(node);
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
	DLLNode* node = DLLNode(val, NULL, tail);
	if(tail == NULL)
	{
		head = tail = node;
	}
	else
	{
		tail.setNext(node);
		tail = node;
	}
	
	++size;
}

/**
 * Returns Boolean value indicating if the list has no nodes
 *
 * @return false if there are no nodes in the linked list, true otherwise
 */
bool DLLProjectList::IsEmpty()
{
	return head == NULL;
}

/**
 * Determines if Position pos is the first position of the list
 *
 * @param a Position ADT pos
 * @return boolean indicating whether or not Position pos is the head of the linked list
 */
bool DLLProjectList::IsFirst(const Position* pos)
{
	DLLNode* node = dynamic_cast<DLLNode*>(pos);
	
	return node == head;
}

/**
 * Determines if Position p is the last position of the list
 *
 * @param a Position ADT p
 * @return boolean indicating whether or not Position pos is the tail of the linked list
 */
bool DLLProjectList::IsLast(const Position* pos)
{
	DLLNode* node = dynamic_cast<DLLNode*>(pos);
	
	return node == tail;
}

/**
 * Returns last Position of the list
 *
 * @return the Position ADT that represents the end of the list
 */
Position* DLLProjectList::Last()
{
	return tail;
}

/**
 * Returns the number of positions in the list as an integer
 *
 * @return the number of nodes in the linked list 
 */
std::size_t DLLProjectList::Size()
{
	return size;
}