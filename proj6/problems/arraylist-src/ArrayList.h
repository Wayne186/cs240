#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>
#include <algorithm>
#include <type_traits>
#include <stdlib.h>
#include <string.h>

/**
 * ArrayList class
 *
 * This class implements an ArrayList in a fashion
 * that is similar to that of Java, but also adds
 * a lot of useful C++ features.
 *
 * @author Hunter Allen <allen286@purdue.edu>
 * @author Brian Hays <hays1@purdue.edu>
 */
template<class T>
class ArrayList
{
public:
	ArrayList();

	int indexOf(const T& other);
	int indexOf(const T& object, int occurance);
	int lastIndexOf(const T& other);
	const int & size(){ return m_size; }
	const T & get(int index){ return pElements[index]; }
	const T remove(int index);
	void remove(const T & toRemove, bool * ok);
	inline T & operator [](int index){ return pElements[index]; }

	void add(const T& toPush);
	void add(const T& toPush, int index);
	void push_back(const T& toPush);
	void push_front(const T& toPush);

	void clear();

	bool isEmpty(){ return m_size == 0; }
	bool contains(const T& object);

	void sort();
	
	/**
	 * @brief      Gets operator.
	 * 
	 * Deep copies the other ArrayList.
	 * 
	 * @param[in]  other  ArrayList to copy
	 *
	 * @return     return *this
	 */
	ArrayList<T> & operator = (const ArrayList<T> & other)
	{
		//! TODO
		for(int i = 0; i < this->size(); i++)
			memcpy(&this[i], &other[i], sizeof(this[i]));
	
		return *this;
	}

	/**
	 * @brief      Equals operator.
	 *
	 * @param      other  Array with which we are checking equality.
	 *
	 * @return     True, if they are equal. :P
	 */
	bool operator == (ArrayList<T> & other)
	{
		//! TODO
		int num = memcmp(this, &other, sizeof(this));
		if(num)
			return false;
		return true;
	}

	/**
	 * @brief      Overloads the input operator.
	 *
	 * The input element shall be added to the back of the array.
	 * 
	 * @param[in]  toAdd  Adds an element to the array.
	 *
	 * @return     *this
	 */
	ArrayList<T> & operator << (const T & toAdd) {
		//! TODO
		this->add(toAdd);
		return *this;
	}

	/**
	 * @brief      Overloads the input operator.
	 * 
	 * The list shall be appended to this one.
	 *
	 * @param      other  List to adjoin.
	 *
	 * @return     *this
	 */
	ArrayList<T> & operator << (ArrayList<T> & other) {
		//! TODO
		for (int i = 0; i < other.m_size; i++)
			this->add(other[i]);
		return *this;
	}

	/**
	 * @brief      Overloads += operator.
	 *
	 * This adds another element to the list, just like <<.
	 * 
	 * @param[in]  toAdd  Adds an element to the end.
	 *
	 * @return     *this
	 */
	ArrayList<T> & operator += (const T & toAdd) {
		this->push_back(toAdd);
		return *this;
	}

	/**
	 * @brief      Overloads += operator.
	 *
	 * Another one of 'dem add to back things.
	 * 
	 * @param      other  The list you are to adjoin.
	 *
	 * @return     *this
	 */
	ArrayList<T> & operator += (ArrayList<T> & other) {
		//! TODO
		for(int i = 0; i< other.m_size; i++)
			this->add(other[i]);
		return *this;
	}

private:
	T * pElements;
	int m_size;
	int m_capacity;
	const static int SIZE_INCREMENT = 2;
};
#endif
