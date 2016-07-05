#pragma once
#include <iostream>

using namespace std;

#define DefMemSize 100
enum TMemType { MEM_HOLDER, MEM_RENTER };

template <class T>
class TDataRoot
{
protected: // ����
	T* pMem; // ������ ��� ��
	int MemSize; // ������ ������ ��� ��
	int DataCount; // �-�� ��������� � ��
	TMemType MemType; // ����� ���������� �������
protected: // ������
	void SetMem ( void *pMem, int Size ) // ������� ������
	{
		if ( MemType == MEM_HOLDER ) delete pMem; // ! ���������� �� �����������
		pMem = (T*) pMem;
		MemType = MEM_RENTER;
		MemSize = Size;
	}
public:
	TDataRoot (int Size=DefMemSize) : DataCount(0), MemSize(Size)
	{
		if ( Size == 0 ) 
		{ // ������ ����� ����������� ������� SetMem
			pMem = NULL; MemType = MEM_RENTER;
		}
		else 
		{ // ������ ���������� ��������
			pMem = new T[MemSize];
			MemType = MEM_HOLDER;
		}
	}
	~TDataRoot ()
	{
		if (MemType == MEM_HOLDER) delete pMem;
		pMem = NULL;
	}
	virtual int IsEmpty() const // �������� ������� ��
	{
		return DataCount==0;
	}
	virtual int IsFull() const // �������� ������������ ��
	{
		return DataCount>=MemSize;
	}
	virtual void Put(const T &Val) =0; // �������� ��������
	virtual T Get() =0;            // ������� ��������
	// ��������� ������
	virtual void Print() = 0;  // ������ ��������
	virtual int IsValid() = 0; // ������������ ���������
	// ������������� ������
	friend class TMultiStack;
	friend class TSuperMultiStack;
	friend class TComplexMultiStack;
};