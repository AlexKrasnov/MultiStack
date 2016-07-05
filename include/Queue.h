#pragma once
#include "Stack.h"

template <class T>
class TQueue : public TStack <T>
{
protected:
	int Li; // ������ ������� �������� ���������
	virtual int GetNextIndex(int index) // �������� ��������� ������
	{ return ++index%MemSize; }
public:
	TQueue(int Size=DefMemSize) : TStack(Size), Li(0) {}
	virtual T Get () // ����� �� ������� � ��������� (#�1)
	{
		T temp;
		if (pMem == NULL) throw "No memory";
		else if (IsEmpty()) throw "Queue is empty";
		else 
		{
			temp = pMem[Li++];
			DataCount--;
		}
		return temp;
	}
};