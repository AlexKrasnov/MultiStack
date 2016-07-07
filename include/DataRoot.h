#pragma once
#include <iostream>

using namespace std;

#define DefMemSize 100
enum TMemType { MEM_HOLDER, MEM_RENTER };

template <class T>
class TDataRoot
{
protected: // поля
	T* pMem; // память для СД
	int MemSize; // размер памяти для СД
	int DataCount; // к-во элементов в СД
	TMemType MemType; // режим управления памятью
protected: // методы
	void SetMem ( void *pMem, int Size ) // задание памяти
	{
		if ( MemType == MEM_HOLDER ) delete pMem; // ! информация не сохраняется
		pMem = (T*) pMem;
		MemType = MEM_RENTER;
		MemSize = Size;
	}
public:
	TDataRoot (int Size=DefMemSize) : DataCount(0), MemSize(Size)
	{
		if ( Size == 0 ) 
		{ // память будет установлена методом SetMem
			pMem = NULL; MemType = MEM_RENTER;
		}
		else 
		{ // память выделяется объектом
			pMem = new T[MemSize];
			MemType = MEM_HOLDER;
		}
	}
	~TDataRoot ()
	{
		if (MemType == MEM_HOLDER) delete pMem;
		pMem = NULL;
	}
	virtual int IsEmpty() const // контроль пустоты СД
	{
		return DataCount==0;
	}
	virtual int IsFull() const // контроль переполнения СД
	{
		return DataCount>=MemSize;
	}
	virtual void Put(const T &Val) =0; // добавить значение
	virtual T Get() =0;            // извлечь значение
	// служебные методы
	virtual void Print() = 0;  // печать значений
	virtual int IsValid() = 0; // тестирование структуры
	// дружественные классы
	friend class TMultiStack;
	friend class TSuperMultiStack;
	friend class TComplexMultiStack;
};