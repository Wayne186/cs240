#include "ArrayList.h"

/**
 * @brief      Default Constructor.
 *
 * @tparam     T     Typename
 */
template<class T>
ArrayList<T>::ArrayList() :
	m_size(0),
	m_capacity(10)
{
	pElements = new T[m_capacity];
}

/**
 * @brief      Clear the ArrayList
 *
 * @tparam     T     Typename
 */
template<class T>
void ArrayList<T>::clear()
{
	//! TODO
	delete[] pElements;
	m_size = 0;
}

/**
 * @brief      Adds a thing to the ArrayList
 *
 * @param[in]  toPush  The to be added.
 *
 * @tparam     T       Typename
 */
template<class T>
void ArrayList<T>::add(const T& toPush)
{
	//! TODO
	if (m_size > m_capacity) {
		T * tem = new T[m_capacity *= SIZE_INCREMENT];
		for (int i = 0; i < m_size; i++)
			tem[i] = pElements[i];
	}
	
	pElements[m_size] = toPush;
	m_size++;

}

/**
 * @brief      Adds a thing in a specific index.
 *
 * @param[in]  toPush  Thing to add
 * @param[in]  index   Where it is to be added.
 *
 * @tparam     T       Type of thing
 */
template<class T>
void ArrayList<T>::add(const T& toPush, int index)
{
	//! TODO
	if(m_size+1 > m_capacity) {
		T * temp = new T[m_capacity * SIZE_INCREMENT];
		for(int i = 0; i < m_size; i++)
			temp[i] = pElements[i];
		pElements = temp;
		m_capacity *= 2;
	}
	T push = toPush;
	while (index <= m_size) {
		T temp = pElements[index];
		pElements[index++] = push;
		push = temp;
	}

	m_size++;
}

/**
 * @brief      Pushes to the back of the list.
 *
 * @param[in]  toPush  Thing to push back.
 *
 * @tparam     T       Typename
 */
template<class T>
void ArrayList<T>::push_back(const T& toPush)
{
	//! TODO
	add(toPush);
}

/**
 * @brief      Push a thing to the front of the list.
 *
 * @param[in]  toPush  Thing to be pushed.
 *
 * @tparam     T       Typename
 */
template<class T>
void ArrayList<T>::push_front(const T& toPush)
{
	//! TODO
	add(toPush, 0);
}

/**
 * @brief      Remove the item at a specific index.
 *
 * @param[in]  index  Index of the thing to be removed.
 *
 * @tparam     T      Typename
 *
 * @return     Shallow copy of the item we removed.
 */
template<class T>
const T ArrayList<T>::remove(int index)
{
	//! TODO
	const T t = T();
	if(index >= m_size-1)
		return t;
	else {
		T t2 = pElements[index];
		while(index < m_size-1) {
			pElements[index] = pElements[index+1];
			index++;
		}
		m_size--;
		return t2;
	}

}

/**
 * @brief      Removes a particular item from the list.
 *
 * @param[in]  toRemove  Thing to remove.
 * @param      ok        True upon successful removal.
 *
 * @tparam     T         Typename
 */
template<class T>
void ArrayList<T>::remove(const T & toRemove, bool * ok) {
	//! TODO
	for(int i = 0; i < m_size; i++) {
		if (toRemove == pElements[i]) {
			remove(i);
			*ok = true;
			return;
		}
	}
	*ok = false;
	return;
}

/**
 * @brief      Check if an item is in the ArrayList.
 *
 * @param[in]  object The thing we want to know about.
 *
 * @tparam     T       Typename
 *
 * @return     Returns true if it's there.
 */
template<class T>
bool ArrayList<T>::contains(const T& object)
{
	//! TODO
	for(int i = 0; i < m_size; i++){
		if(pElements[i] == object) 
			return true;
	}
	return false;
}

/**
 * @brief      Returns the first index of T.
 *
 * @param[in]  object  Thing.
 *
 * @tparam     T       Typename
 *
 * @return     The first index of thing.
 */
template<class T>
int ArrayList<T>::indexOf(const T& object)
{
	//! TODO
	for(int i = 0; i < m_size; i++){
		if(pElements[i] == object)
			return i;
	}
	return -1;
}

/**
 * @brief      Return the ith occurance of T.
 *
 * @param[in]  object     Thing.
 * @param[in]  occurance  Occurance of thing to find.
 *
 * @tparam     T          Type of thing.
 *
 * @return     Location of thing.
 */
template<class T>
int ArrayList<T>::indexOf(const T& object, int occurance)
{
	//! TODO
	int num = 0;
	for(int i = 0; i < m_size; i++){
		if(pElements[i] == object) 
			num++;
		if(pElements[i] == object && num == occurance) 
			return i;
	}
	return -1;
}

/**
 * @brief      Check for the last index of an object.
 *
 * @param[in]  object  Thing to check
 *
 * @tparam     T       Typename
 *
 * @return     Integer location of the last location, or -1.
 */
template<class T>
int ArrayList<T>::lastIndexOf(const T& object)
{
	//! TODO
	int num = 0;
	for(int i = 0; i < m_size; i++){
		if(pElements[i] == object) 
			num = i;
	}
	return -1;
}

/**
 * @brief      Sorts the given list in ascending order.
 * 
 * This sorts the list in ascending order. It is assumed
 * that the < operator has been overloaded.
 *
 * @tparam     T   type.  
 */
template<class T>
void ArrayList<T>::sort()
{
	//! TODO
	for(int i = 0; i < m_size-1; i++){
		for(int j = 0; j < m_size-i-1; j++){
			if(pElements[j] > pElements[j+1]){
				T temp = pElements[j];
				pElements[j] = pElements[j+1];
				pElements[j+1] = temp;
			}
		}
	}
}
