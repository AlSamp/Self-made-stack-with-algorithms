#include "TLinkedList.h"

TLinkedList::TLinkedList()
{
	mpHead = nullptr;
}

TLinkedList::~TLinkedList()
{
	while (mpHead != nullptr)
	{
		CElement* pTemp = mpHead;
		mpHead = mpHead->getNext();
		delete pTemp;
	}
}

void TLinkedList::push(int data)
{

	CElement* newElement = new CElement(data);
	CElement* pCurrent = mpHead;
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

void TLinkedList::pop()
{
	CElement* pCurrent = mpHead;
	CElement* pPrevious = mpHead;
	bool endOfList = false;

	if (mpHead == nullptr)
	{
		cout << "Cannot pop the list is empty" << endl;
		endOfList = true;
	}
	else if (mpHead->getNext() == nullptr)
	{
		cout << mpHead->getData() << " popped" << endl;
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
				cout << pCurrent->getData() << " popped" << endl;
				endOfList = true;
				delete pCurrent;
				pPrevious->setNext(nullptr);
			}


		}
	}


}

void TLinkedList::top()
{
	CElement* pCurrent = mpHead;
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
				cout << pCurrent->getData();
			}


		}
	}



}

void TLinkedList::toString()
{
	CElement* pCurrent = mpHead;
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
				cout << pCurrent->getData() << endl; // output data

				if (endOfList == false) // 
				{
					pCurrent = pCurrent->getNext();
				}
			}


		}
	}

}

bool TLinkedList::isEmpty()
{
	if (mpHead == nullptr)
	{
		return true;
	}
}

int TLinkedList::size()
{
	CElement* pCurrent = mpHead;
	int count = 0;

	while (pCurrent != nullptr)
	{
		pCurrent = pCurrent->getNext();
		count++;
	}
	return count;
}
