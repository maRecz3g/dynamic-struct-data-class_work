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



	list.addHead(10);
	list.addHead(20);
	list.addTail(30);

	list.print();

	list.removeAt(20);

	list.print();

	FwList<int> copy = list;

	copy.print();
}
