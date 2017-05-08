#include "DLList.h"

/**
 * @brief      Constructor for the DLList.
 */

int nElement;
DLList::DLList()
{
	/** @todo Write a constructor for a dllist. Check slides! **/
	head = new DLNode();
	head->next = head;
	head->prev = head;
	nElement = 0;
}

/**
 * @brief      Destructor for the DLList.
 */
DLList::~DLList()
{
	/** @todo Clean up your mess! **/
	DLNode * e = head->next;
	DLNode * temp;
	while (e->next != head->next) {
		temp = e;
		head->next->next = e->next;
		e->next->prev = head->next;
		e = e->next;
		delete temp;
	} 
	delete e;
}

/**
 * @brief      Print the DLList line by line.
 */
void DLList::print()
{
	/** @todo Print this list line by line **/
	DLNode * e = head->next;
	while (e->next != head->next) {
		std::cout<<e->data<<std::endl;
		nElement++;
		e = e->next;
	}
}

/**
 * @brief      Sort and print the list.
 * 
 * This function should sort and print the list.
 * Note: the actual list is NOT to be modified.
 * In other words, it should only *print* in a
 * sorted order, not actually sort the list.
 */
void DLList::printSorted()
{
	/** @todo Print a sorted copy of this list **/
	DLNode * e = head->next;
	int * list = new int[nElement];
	int i = 0;
	while (e->next != head->next) {
		list[i++] = e->data;
		e = e->next;
	}
	list[i] = e->data;
	int temp;
	for(i = 0; i < nElement - 1; i++) {
		for(int j = 0; j < nElement - i - 1; j++) {
			if(list[j] > list[j + 1]) {
				temp = list[j + 1];
				list[j + 1] = list[j];
				list[j] = temp;
			}
		}
	}
	i = 0;
	while(i < nElement) 
		std::cout<<list[i++]<<std::endl;
}

/**
 * @brief      Add to the front of the list.
 *
 * @param[in]  data  Item to add to front.
 */
void DLList::insertFront(int data)
{
	/** @todo Insert to the front of the list **/
	DLNode * e = new DLNode();
	e->data = data;
	e->next = head->next;
	e->prev = head;
	head->next = e;
	e->next->prev = e;
}

void DLList::insertLast(int data) {
	DLNode * e = new DLNode();
	e->data = data;
	e->next = head;
	e->prev = head->prev;
	e->prev->next = e;
	head->prev = e;
}

/**
 * @brief      Removes & stores the last element.
 *
 * The last element is removed and stored in the
 * referenced variable data.
 * 
 * @param      data  Thing in which we are storing the data.
 *
 * @return     True upon successful removal.
 */
bool DLList::removeLast(int & data)
{
	/** @todo Remove the last thing **/
	DLNode * e = head->next;
	while (e->next != head->next) {
		data = e->data;
		e = e->next;
	}
	head->prev->next = head->next;
	head->prev = head->prev;
	delete e;
	return true;
}

/**
 * @brief      Difference of two lists.
 *
 * @param      list  Subtrahend.
 *
 * @return     Returns a pointer to the difference.
 */
DLList * DLList::difference(DLList & list)
{
	DLList * diff = new DLList();
	/** @todo Implement this function **/
	DLNode * e = head->prev;
	DLNode * e2;
	int flag;
	while (e->prev != head->prev) {
		flag = 1;
		e2 = list.head->prev;
		while(e2->prev != list.head->prev) {
			if(e->data == e2->data) flag = 0;
			e2 = e2->prev;
		}
		if(flag == 1) diff -> insertLast(e->data);
		e = e->prev;
	}
		
	return diff;
}

/**
 * @brief      Returns a sublist of items in a range.
 *
 * @param[in]  start  First index.
 * @param[in]  end    Second index.
 *
 * @return     Elements between first and second index.
 */
DLList * DLList::getRange(int start, int end)
{
	DLList * range = new DLList();
	/** @todo getRange **/
	DLNode * e = head->next;
	while(e->next != head->next) {
		if( e->data <= end && e->data >= start)
			e = e->next;
		//e = e->next;
	}
	return range;
}

/**
 * @brief      Intersection of this list and another list.
 *
 * @param      list  The other list.
 *
 * @return     Elements list shares with this one.
 */
DLList * DLList::intersection(DLList & list)
{
	DLList * inter = new DLList();
	DLNode * e = head->next;
	DLNode * e2;
	while(e->next != head->next) {
		e2 = list.head->next;
		while(e2->next != list.head->next) {
			if(e->data == e2->data)
				inter -> insertLast(e->data);
			e2 = e2->next;
		}
		e = e->next;
	}
	/** @todo intersection **/
	return  inter;
}

/**
 * @brief      Removes nodes in the start-end range.
 *
 * @param[in]  start  First node.
 * @param[in]  end    Second node.
 */
void DLList::removeRange(int start, int end)
{
	/** @todo Remove a range of elements **/
}
