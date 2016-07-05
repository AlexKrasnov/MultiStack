#pragma once
#include "DataRoot.h"

#define StackID 101

template <class T>
class TStack : public TDataRoot <T>
{
protected:
	int Hi; // ������ ���������� �������� ���������
	virtual int GetNextIndex(int index) // �������� ��������� ������
	{ return ++index;}
public:
	TStack ( int Size=DefMemSize ): TDataRoot(Size) { Hi=-1; }
	virtual void Put(const T &val) // �������� � ���� (#�1)
	{
		if (pMem == NULL) throw "No memory";
		else if (IsFull()) throw "Stack is full";
		else 
		{
			pMem[++Hi] = val;
			DataCount++;
		}
	}
	virtual T Get() // ����� �� ����� � ���������
	{
		T temp;
		if (pMem == NULL) throw "No memory";
		else if (IsEmpty()) throw "Stack is empty";
		else 
		{
			temp = pMem[Hi--];
			DataCount--;
		}
		return temp;
	}
protected:
	// ��������� ������
	virtual int IsValid() // ������������ ���������
	{
		int res = 0;
		if ( pMem == NULL ) res = 1;
		if ( MemSize < DataCount ) res += 2;
		return res;
	}
	virtual void Print() // ������ ��������
	{
		for (int i=0; i<DataCount; i++)
			cout << pMem[i];
		cout << endl;
	}
	virtual void CopyToVector(T v[]) // ���������� � �������
	{
		for ( int i=0; i<DataCount; i++)
			v[i] = pMem[i];
	}
};