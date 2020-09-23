#include <iostream>
#include <cstdio>
#include "Utils.h"

#define _CRT_SECURE_NO_WARNINGS
using namespace std;
namespace mrks {


	void clear() { // clear function to clear buffer
		while (getchar() != '\n')
			;  // empty statement intentional 
	}

	int getInt(int min, int max) { //getint function to accept user input as per criteria

		int value, keeptrying = 1, rc;
		char after;
		printf("Please enter the number of marks: ");
		do {

			rc = scanf("%d%c", &value, &after);
			if (rc == 0) {
				printf("Invalid Number, try again: ");
				clear();
			}
			else if (after != '\n') {
				printf("Invalid trailing characters, try again: ");
				clear();
			}
			else if (value < min ||
				value > max) {
				printf("Invalid value (5<=value<=50), try again: ");
			}
			else
				keeptrying = 0;
		} while (keeptrying == 1);

		return value;
	}

	void sort(int nm, int marks[], int size) { //sort function to sort the entered marks
		for (int i = 0; i < size; i++) {
			for (int j = i + 1; j < size; j++) {
				if (marks[j] > marks[i]) {
					nm = marks[i];
					marks[i] = marks[j];
					marks[j] = nm;

				}
			}
		}
		for (int i = 0; i < size; i++) {
			if (i != size - 1) {
				cout << marks[i] << ", ";
			}
			else {
				cout << marks[i] << endl;
			}
		}
	}

	void averagemarks(double& sum, int marks[], int numofmarks, double& average) { //average function to calculate average
		
		
		for (int i = 0; i < numofmarks; i++) {
			sum += marks[i];
		}
		average = sum / numofmarks;
		

	}

	void prgtitle() { //title function
		cout << "Mark Stats Program." << endl;
	}


}