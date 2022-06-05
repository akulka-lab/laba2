#pragma once
#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>
#include "ArraySequenceTests.h"
#include "DynamicArrayTests.h"
#include "LinkedListTests.h"
#include "LinkedListSequenceTests.h"
#include "queuePriorityTests.h"
#include "queuePriority.h"
#include "Errors.h"
#include "Input.h"
#include "functions.h"
#include "Header.h"

using namespace std;

int read_data() {
    int read_mode = 0;
    printf(
           " _______________________________________________________________________  \n"
            "|                                                                       | \n"
            "|                   How do you want to write data?                      | \n"
            "|                                                                       | \n"
            "|   1  -> Read data from std                                            | \n"
            "|   2  -> Read data from input file                                     | \n"
            "|   3  -> Random data generation                                        | \n"
            "|   4  -> Exit                                                          | \n"
            "|____  _________________________________________________________________| \n"
            "     |/                                                                   \n");

    scanf("%d", &read_mode);
    return read_mode;
}

int show_data() {
    int show_mode = 0;
    printf(
            " _______________________________________________________________________  \n"
            "|                                                                       | \n"
            "|                   How do you want to see data?                        | \n"
            "|                                                                       | \n"
            "|   1  -> See data from std                                             | \n"
            "|   2  -> See data in output file                                       | \n"
            "|   3  -> Exit                                                          | \n"
            "|____  _________________________________________________________________| \n"
            "     |/                                                                   \n");

    scanf("%d", &show_mode);
    return show_mode;
}


int need_print_data() {
    int need_print = 0;
    printf(
            " _________________________________________  \n"
            "|                                         | \n"
            "|          See data right now?            | \n"
            "|                                         | \n"
            "|   1  -> Yes                             | \n"
            "|   2  -> No                              | \n"
            "|____  ___________________________________| \n"
            "     |/                                     \n");

    scanf("%d", &need_print);
    return need_print;
}

void gnome_sort(void *base, int len, int size, int (*comp)(const void *,const void *))
{
    int i = 1;
    char *p = (char *) base;
    while (i < len) {
        if (i == 0)
            i = 1;
        if (comp((p + (i - 1) * size), p + i * size)) {
            i++;
        } else {
            swap(p + (i - 1) * size, p + i * size, size);
            i--;
        }
    }
}

void menu()
{
	queuePriority<int>* queueInt = 0;
	queuePriority<float>* queueFloat = 0;

	int* data = new int[2];
	int j = 0, i = 1;
	int choice;
	int miniPage;
	int decision;
	int page = -1;

	auto menuExistQueue = [&]()
	{
		Queue_type();
		cin >> choice;

		return (int)data[choice-1];
	};
	
	while (page != 0)
	{
		if (page == -1)
		{
			Select_type();
			cin >> page;

			while (page != 1 && page != 2 && page != 3 && page!=0 )
			{
				cout << "try again!" << endl;
				cin >> page;
			}
		}
		if (page == 2)
		{
			int miniPage2;
			mini_menu();

			
			cin >> miniPage2;
			while (miniPage2 != 1 && miniPage2 != 2 && miniPage2 != 3 && miniPage2 != 4 && miniPage2 != 5 && miniPage2 != 6 && miniPage2 != 7 && miniPage2 != 0)
			{
				cout << "try again!" << endl;
				cin >> miniPage2;
			}
			if (miniPage2 == 1)
			{

				int choice = menuExistQueue();
				if (choice == 1)
				{
					int intPass;
					cout << "Enter int:" << endl;
					cin >> intPass;
					queueInt->Add(intPass);
				}
				else if (choice == 2)
				{
					float floatPass;
					cout << "Enter float:" << endl;
					cin >> floatPass;
					queueFloat->Add(floatPass);
				}

			}
			else if (miniPage2 == 2)
			{
				int startIndex, endIndex;
				cout << "start Index:" << endl;
				cin >> startIndex;
				cout << "end Index:" << endl;
				cin >> endIndex;
				int choice = menuExistQueue();
				if (choice == 1)
				{
					queueInt->GetSubsequence(startIndex, endIndex);
					queueInt->Print();
				}
				else if (choice == 2)
				{
					queueFloat->GetSubsequence(startIndex, endIndex);
					queueFloat->Print();
				}

			}
			}

				else if (miniPage2 == 6)
				{
					int choice = menuExistQueue();
					if (choice == 1) queueInt->Print();
					if (choice == 2) queueFloat->Print();
				}
				cout << endl;
				system("pause");

				page = -1;
			}
		}

	}
}

void double_selection_sort(void *base, int len, int size, int (*comp)(const void *,const void *))
{
    int min = 0;
    int max = 0;
    char *p = (char *) base;
    for (int i = 0; i < len/2 + len % 2; i++) {
        min = i;
        min = len - i - 1;
        for (int j = i + 1; j < len - i - 1; j++) {
            if (comp(p + j * size, p + min * size) < 0)
                min = j;
            if (comp(p + j * size, p + min * size) > 0)
                max = j;
        }
        swap(p + i * size, p + min * size);
        swap(p + (len - i - 1) * size, p + max * size);
    }
}
