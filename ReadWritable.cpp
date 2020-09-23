/* ------------------------------------------------------

Name: Morris Anthony
Student ID:158091199
Date:08/05/2020
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "ReadWritable.h"
using namespace std;
namespace sdds {

	ReadWritable::ReadWritable() { //set class to empty state

		flag = false;

	}

	ReadWritable::~ReadWritable() { //empty virtual destructor


	}

	bool ReadWritable::isCsv()const { //return csv value

		return flag;

	}
	void ReadWritable::setCsv(bool value) { //set csv value

		flag = value;

	}
	std::ostream& ReadWritable::write(std::ostream& os)  const { 

		return os;

	}

	std::istream& ReadWritable::read(std::istream& in) {

		return in;

	}


	std::istream& operator>>(std::istream& is, ReadWritable& s) {

		return s.read(is);

	}

	std::ostream& operator<<(std::ostream& os, const ReadWritable& s) {


		return 	s.write(os);

	}
}