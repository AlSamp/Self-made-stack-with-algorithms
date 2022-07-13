#pragma once
#include "CPrefixPostfix.h"
#include "TLinkedList.h"
class CCharStack :virtual public TLinkedList<CPrefixPostfix<char>,char> // Will take a char from the user
{

};

class CDoubleStack : virtual public TLinkedList<CPrefixPostfix<double>,double> // Will take an integer from the user
{

};

