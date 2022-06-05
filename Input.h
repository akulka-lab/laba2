#pragma once
#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>
#include "Header.h"

auto InputIntArray = [&](int decision) {
	int typeInput;
	int* items;
	int count;

	float_int_menu();
	cin >> typeInput;

	cout << "Enter count:" << endl;
	cin >> count;

	items = new int[count];
	while (typeInput != 1 && typeInput != 2)
	{
		cout << "try again!" << endl;
		cin >> typeInput;
	}
	if (typeInput == 1)
	{
		for (int i = 0; i < count; i++)
		{
			cout << "data[" << i << "]=" << endl;
			cin >> items[i];
		}
		cout << '[';
		for (int i = 0; i < count; i++)
		{
			cout << ' ' << items[i];
		}
		cout << " ]";
	}
	else if (typeInput == 2)
	{
		int min, max;
		cout << "Enter min:" << endl;
		cin >> min;
		cout << "Enter max:" << endl;
		cin >> max;
		cout << '[';
		for (int i = 0; i < count; i++)
		{
			items[i] = rand() % (max - min) + min;
			cout << ' ' << items[i];
		}
		cout << " ]";
	}
	return new queuePriority<int>(decision, items, count);
};
auto InputFloatArray = [&](int decision)
{
	int typeInput;
	float* items;
	int count;

	float_int_menu();
	cin >> typeInput;

	cout << "Enter count:" << endl;
	cin >> count;

	items = new float[count];
	while (typeInput != 1 && typeInput != 2)
	{
		cout << "try again!" << endl;
		cin >> typeInput;
	}
	if (typeInput == 1)
	{
		for (int i = 0; i < count; i++)
		{
			cout << "data[" << i << "]=" << endl;
			cin >> items[i];
		}
		cout << '[';
		for (int i = 0; i < count; i++)
		{
			cout << ' ' << items[i];
		}
		cout << " ]";
	}
	else if (typeInput == 2)
	{
		float min, max;
		cout << "Enter min:" << endl;
		cin >> min;
		cout << "Enter max:" << endl;
		cin >> max;
		cout << '[';
		for (int i = 0; i < count; i++)
		{
			items[i] = ((float)rand() / (float)RAND_MAX) * (max - min) + min;
			cout << ' ' << items[i];
		}
		cout << " ]";
	}
	return new queuePriority<float>(decision, items, count);
};