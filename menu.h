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
		if (queueFloat==0 && queueInt==0) 
		{
			cout << "all queue empty!" << endl; 
			system("pause");
			page = -1;
			menu();
		}

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
		else if (page == 1)
		{
			variable_type();
			cin >> miniPage;

			while (miniPage != 1 && miniPage != 2 && miniPage != 3 && miniPage != 4 && miniPage != 5 && miniPage != 6 && miniPage != 0)
			{
				cout << "try again!" << endl;
				cin >> miniPage;
			}
			if (miniPage != 0) 
			{
				sequence_type();
				cin >> decision;
			}
			if (miniPage == 1) 
			{
				queueInt = InputIntArray(decision);
			}
			else if (miniPage == 2)
			{
				queueFloat = InputFloatArray(decision);
			}

			cout << endl;
			system("pause");
			page = -1;
		}
		else if (page == 2)
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
			else if (miniPage2 == 3)
			{
				int choice = menuExistQueue();
				if (choice == 1)
				{
					queuePriority<int>* queueIntConcatenated;
					queueIntConcatenated = queueInt->Concatenate(InputIntArray(queueInt->GetDecision()));
					cout << '\n' << "result-------------" << endl;
					queueIntConcatenated->Print();
				}
				if (choice == 2)
				{
					queuePriority<float>* queueFloatConcatenated;
					queueFloatConcatenated = queueFloat->Concatenate(InputFloatArray(queueFloat->GetDecision()));
					cout << '\n' << "result-------------" << endl;
					queueFloatConcatenated->Print();
				}

			}
			else if (miniPage2 == 4)
			{
				int choice = menuExistQueue();
				if (choice == 1)
				{
					queuePriority<int>* queueIntExemplar = InputIntArray(queueInt->GetDecision());
					cout << '\n' << "result-------------" << endl;
					if (queueInt->FindSubSequence(queueIntExemplar)) cout << "YES" << endl;
					else cout << "NO" << endl;

				}
				if (choice == 2)
				{
					queuePriority<float>* queueFloatExemplar = InputFloatArray(queueFloat->GetDecision());
					cout << '\n' << "result-------------" << endl;
					if (queueFloat->FindSubSequence(queueFloatExemplar)) cout << "YES" << endl;
					else cout << "NO" << endl;
				}

			}
			else if (miniPage2 == 5)
			{
				int choice = menuExistQueue();

				if (choice == 1)
				{
					queuePriority<int>* SecondqueueInt = new queuePriority<int>(queueInt->GetDecision());
					int miniChoice = 0;
					int n;
					cout << "1.Divide by n" << endl;
					cout << "2.even/odd" << endl;
					cout << "3.more/less than n" << endl;
					cin >> miniChoice;
					while (miniChoice != 1 && miniChoice != 2 && miniChoice != 3)
					{
						cout << "try again" << endl;
						cin >> miniChoice;
					}
					if (miniChoice == 1)
					{
						cout << "Enter n:" << endl;
						cin >> n;
						queueInt->SplitIntoTwo(SecondqueueInt, IntFunctionsPtr[EnumIntDevidedBy], n);
					}
					else if (miniChoice == 2)
					{
						cout << "1.even" << endl;
						cout << "2.odd" << endl;
						cin >> n;
						while (n != 1 && n != 2)
						{
							cout << "try again" << endl;
							cin >> n;
						}
						if (n == 1)
						{
							queueInt->SplitIntoTwo(SecondqueueInt, IntFunctionsPtr[EnumIntDevidedBy], n);

						}
						else if (n == 2)
						{
							queueInt->SplitIntoTwo(SecondqueueInt, IntFunctionsPtr[EnumIntIsOdd], n);
						}
					}
					else if (miniChoice == 3)
					{
						cout << "1.More" << endl;
						cout << "2.Less" << endl;
						cin >> n;
						while (n != 1 && n != 2)
						{
							cout << "try again" << endl;
							cin >> n;
						}
						cout << "Enter n:" << endl;
						int number;
						cin >> number;
						if (n == 1)
						{
							queueInt->SplitIntoTwo(SecondqueueInt, IntFunctionsPtr[EnumIntMore], number);

						}
						else if (n == 2)
						{
							queueInt->SplitIntoTwo(SecondqueueInt, IntFunctionsPtr[EnumIntLess], number);
						}
					}
					cout << "First queue(False)" << endl;
					queueInt->Print();
					cout << endl;
					cout << "Second queue(True)" << endl;
					SecondqueueInt->Print();
					cout << endl;
				}
				if (choice == 2)
				{
					queuePriority<float>* SecondqueueFloat = new queuePriority<float>(queueFloat->GetDecision());
					int miniChoice = 0;
					int n;
					cout << "1.more/less than n" << endl;
					cin >> miniChoice;
					while (miniChoice != 1)
					{
						cout << "try again" << endl;
						cin >> miniChoice;
					}
					if (miniChoice == 1)
					{
						cout << "1.More" << endl;
						cout << "2.Less" << endl;
						cin >> n;
						while (n != 1 && n != 2)
						{
							cout << "try again" << endl;
							cin >> n;
						}
						cout << "Enter n:" << endl;
						float number;
						cin >> number;
						if (n == 1)
						{
							queueFloat->SplitIntoTwo(SecondqueueFloat, FloatFunctionsPtr[EnumFloatMore], number);

						}
						else if (n == 2)
						{
							queueFloat->SplitIntoTwo(SecondqueueFloat, FloatFunctionsPtr[EnumFloatLess], number);
						}
						cout << "First queue(False)" << endl;
						queueFloat->Print();
						cout << endl;
						cout << "Second queue(True)" << endl;
						SecondqueueFloat->Print();
						cout << endl;
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
			else if (page == 3)
			{
				LinkedListTests* testList = new LinkedListTests();
				DynamicArrayTests* testArray = new DynamicArrayTests();
				LinkedListSequenceTests* testListSequence = new LinkedListSequenceTests();
				ArraySequenceTests* testArraySequence = new ArraySequenceTests();
				queuePriorityTests* testQueuePriority = new queuePriorityTests();
				testQueuePriority->Test();
				testArray->Test();
				testList->Test();
				testListSequence->Test();
				testArraySequence->Test();
				cout << "SecondLaba work correctly\n";
				system("pause");
				page = -1;
			}
		}

	}
}