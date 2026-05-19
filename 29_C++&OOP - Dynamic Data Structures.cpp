// 29_C++&OOP - Dynamic Data Structures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "FwList.h"
using namespace std;



int main()
{
    FwList<int> list;
 //   list.print();
 //   for (size_t i = 0; i < 3; i++)
 //   {
 //       list.addHead((i + 1)*10);
	//	list.print();
 //   }
	//cout << "\n -------- Removing head -------- \n\n";
	//while (!list.isEmpty()) {

	//	list.removeHead();



    FwList<int> a;
    a.addTail(1);
    a.addTail(2);
    a.addTail(3);

    FwList<int> b;
    b.addTail(3);
    b.addTail(4);
    b.addTail(5);

    cout << "List A:" << endl;
    a.print();

    cout << "List B:" << endl;
    b.print();

    // Клон
    FwList<int> copy = a.clone();

    cout << "Clone A:" << endl;
    copy.print();

    // +
    FwList<int> sum = a + b;

    cout << "A + B:" << endl;
    sum.print();

    // *
    FwList<int> inter = a * b;

    cout << "A * B:" << endl;
    inter.print();
}



/*В існуючий клас однозв'язного списку додати: 
------------------------------------------------
операцію клонування списку (функція повинна повертати адресу голови клонованого списку), 
------------------------------------------------
перевантажити оператор + (оператор повинен повертати адресу голови нового списку, який містить елементи обох списків,
для яких викликався оператор), 
------------------------------------------------
перевантажити оператор * (оператор повинен повертати адресу голови нового списку, який містить
тільки загальні елементи обох списків, для яких викликався оператор). */