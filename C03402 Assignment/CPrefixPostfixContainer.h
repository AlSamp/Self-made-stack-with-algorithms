#pragma once
#include "CPrefixPostfix.h"
#include "TLinkedList.h"
class CPrefixPostfixContainer :virtual public TLinkedList<CPrefixPostfix,char> // Will take a string from the user
{

};

