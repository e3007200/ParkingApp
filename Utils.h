#pragma once
#ifndef NAMESPACE_UTILS_H
#define NAMESPACE_UTILS_H
#include <iostream>
using namespace std;
namespace mrks {

	int getInt(int min, int max);
	void clear();
	void sort(int, int[], int);
	void prgtitle();
	void averagemarks(double& sum, int marks[], int numofmarks, double& average);
}





#endif

