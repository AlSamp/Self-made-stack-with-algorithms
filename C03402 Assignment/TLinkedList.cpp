#include "TLinkedList.h"

template <class TElement, class Tdata>
TLinkedList<TElement,Tdata>::TLinkedList()
{
	mpHead = nullptr;
}

template<class TElement, class Tdata>
TLinkedList<TElement,Tdata>::~TLinkedList()
{
	while (mpHead != nullptr)
	{
		TElement* pTemp = mpHead;
		mpHead = mpHead->getNext();
		delete pTemp;
		pTemp = nullptr;
	}
}

template<class TElement, class Tdata>
TElement* TLinkedList<TElement, Tdata>::getHead()
{
	return mpHead;
}

template <class TElement, class Tdata>
void TLinkedList<TElement, Tdata>::push(Tdata data)
{

	TElement* newElement = new TElement(data);
	TElement* pCurrent = mpHead;
	bool endOfList = false;

	if (mpHead == nullptr) // if the list is empty
	{
		endOfList = true;
		mpHead = newElement;
	}

	while (pCurrent != nullptr && endOfList == false) // if the list isnt empty
	{
		if (pCurrent->getNext() == nullptr) //once at the end of the list
		{
			endOfList = true;

			pCurrent->setNext(newElement);	// add new element 
		}
		else
		{
			pCurrent = pCurrent->getNext(); // navigate through list
		}

	}
}

template <class TElement, class Tdata>
void TLinkedList< TElement, Tdata>::pop()
{
	TElement* pCurrent = mpHead;
	TElement* pPrevious = mpHead;
	bool endOfList = false;

	if (mpHead == nullptr)
	{
		cout << "Cannot pop the list is empty" << endl;
		endOfList = true;
	}
	else if (mpHead->getNext() == nullptr)
	{
		//cout << mpHead->getData() << " popped" << endl;
		delete(mpHead);
		mpHead = nullptr;
	}
	else
	{
		while (pCurrent->getNext() != nullptr && endOfList == false) // if the list is not empty
		{

			if (pPrevious == pCurrent) // desync previous and current
			{
				pCurrent = pCurrent->getNext();
			}
			else
			{
				pPrevious = pPrevious->getNext();
				pCurrent = pCurrent->getNext();
			}

			if (pCurrent->getNext() == nullptr)
			{
				/*cout << pCurrent->getData() << " popped" << endl;*/
				endOfList = true;
				delete pCurrent;
				pCurrent = nullptr;
				pPrevious->setNext(nullptr);
			}


		}
	}


}

template <class TElement, class Tdata>
void TLinkedList< TElement, Tdata>::top()
{
	TElement* pCurrent = mpHead;
	bool endOfList = false;

	if (mpHead == nullptr) // if the list is empty
	{
		cout << "Cannot view top as list is empty" << endl;
		endOfList = true;
	}
	else
	{
		while (pCurrent->getNext() != nullptr)
		{
			pCurrent = pCurrent->getNext();

			if (pCurrent->getNext() == nullptr)
			{
				/*cout << pCurrent->getData();*/
				cout << "top needs sorting out " << endl;
			}


		}
	}
}

template <class TElement, class Tdata>
void TLinkedList< TElement, Tdata>::toString()
{
	TElement* pCurrent = mpHead;
	bool endOfList = false;

	if (mpHead == nullptr)
	{
		cout << "The list is empty" << endl;
		endOfList = true;
	}
	else
	{
		while (pCurrent != nullptr && endOfList == false) // if the list is not empty
		{
			if (pCurrent == nullptr) // take note of end of list
			{
				endOfList = true;
			}
			else
			{
				pCurrent->print(); // output data

				if (endOfList == false) // 
				{
					pCurrent = pCurrent->getNext();
				}
			}


		}
	}

}

template <class TElement, class Tdata>
bool TLinkedList<TElement, Tdata>::isEmpty()
{
	if (mpHead == nullptr)
	{
		return true;
	}
}

template <class TElement, class Tdata>
int TLinkedList<TElement,  Tdata>::size()
{
	TElement* pCurrent = mpHead;
	int count = 0;

	while (pCurrent != nullptr)
	{
		pCurrent = pCurrent->getNext();
		count++;
	}
	return count;
}
