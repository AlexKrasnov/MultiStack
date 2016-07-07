#include "Queue.h"
#include <conio.h>
#include <clocale>

int main()
{
	try
	{
	setlocale(LC_ALL,"Rus");
	TQueue<int> q;
	int temp;
	cout << "Тестирование программ поддержки структуры типа очереди" << endl;
	for ( int i=0; i<5; i++ )
	{
		q.Put(i);
		cout << "Положили значение " << i << endl;
	}
	while (!q.IsEmpty())
	{
		temp = q.Get();
		cout << "Взяли значение " << temp << endl;
	}
	cout << "Нажмите любую клавишу" << endl;
	return 0;
	}
	catch (const char* error)
	{
		cout << error << endl;
	}
}
