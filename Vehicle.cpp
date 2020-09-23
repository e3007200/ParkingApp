/* ------------------------------------------------------

Name: Morris Anthony
Student ID:158091199
Date:08/05/2020
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stdio.h>
#include <cctype>
#include <sstream>
#include <iostream>
#include "Vehicle.h"
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;
namespace sdds {


	Vehicle::Vehicle() {

		plate[0] = '\0';
		mnm = nullptr;
		pspot = 0;

	}

	Vehicle::Vehicle(const char* lplate, const char* m) {

		plate[0] = '\0';
		mnm = nullptr;
		pspot = 0;

		if (lplate != nullptr && strlen(lplate) <= 8 && strlen(lplate) >= 1 && lplate[0] != '\0' && m != nullptr && m[0] != '\0' && strlen(m) >= 2) {


			strcpy(plate, lplate);
			mnm = nullptr;
			mnm = new char[strlen(m) + 1];
			strcpy(mnm, m);
			pspot = 0;


		}
		else {

			setEmpty();
		}


	}

	Vehicle::~Vehicle() {

		delete[] mnm;
		mnm = nullptr;
		pspot = 0;
	}

	int Vehicle::getParkingSpot() {

		return pspot;

	}

	void Vehicle::setParkingSpot(int s) {

		if (s > 0) {

			pspot = s;
		}
		else {


			plate[0] = '\0';
			delete[] mnm;
			mnm = nullptr;
			pspot = 0;
		}

	}

	bool Vehicle::operator==(const char* lplate)const { //copy plate if recieved plate is valid

		int result = 0;
		if (lplate[0] != '\0') {

			string tplate = plate;
			string nplate = lplate;
			int tlen = strlen(tplate.c_str());
			int nlen = strlen(nplate.c_str());
			

			for (int i = 0; i < nlen; i++)
			{
				nplate[i] = toupper(nplate[i]);
			}

			if (tlen == nlen) {

				result = strcmp(tplate.c_str(), nplate.c_str());
			}
			else result = 1;



			
		}

		if (result == 1 || result == -1) {

				return false;
			}
			else return true;
		

	}

	bool Vehicle:: operator==(const Vehicle& src)const { //copy vehicle if recieved vehicle is valid

		int result = 0;
		if (src.plate[0] != '\0' && src.mnm != nullptr && src.pspot != 0) {

			string nplate = plate;
			string tplate = src.plate;
			int nlen = nplate.size(); //stores size of plate from "this" car to a signed int
			int tlen = tplate.size(); //stores size of plate recieved to a signed int

			for (int i = 0; i < nlen; i++) //set to lower case for comparison
			{
				nplate[i] = tolower(nplate[i]);
			}

			for (int i = 0; i < tlen; i++)
			{
				tplate[i] = tolower(tplate[i]);
			}
			result = strcmp(nplate.c_str(), tplate.c_str()); //comparison

			if (result == 1) {

				return false;
			}
			else return true;
		}
		else {

			return false;
		}



	}

	std::istream& Vehicle::read(std::istream& in) {

		if (ReadWritable::isCsv()) { //if comma seperated is yes
			string spt;
			string plt;
			string mknmd;
		
			
			//take user input in strings if comma seprarated
			getline(in, spt, ',');
			getline(in, plt, ',');
			getline(in, mknmd, ',');

			if (spt[0] != '\0') {
				pspot = stoi(spt);
			}
			

			if (strlen(plt.c_str()) > 8) {

				plt.substr(0, 8);

			}

			//std::for_each(plt.begin(), plt.end(), [](char& d) {
			//	d = ::toupper(d);
			//	});

			int plen = plt.length();

			for (int i = 0; i < plen; i++) {

				plt[i] = toupper(plt[i]);

			}


			if (strlen(mknmd.c_str()) > 60) { //take only 60 chars from the string

				mknmd.substr(0, 60);

			}


			//copy plate converted to uppercase

			strcpy(plate, plt.c_str());
			
			delete[] mnm;
			mnm = nullptr;
			mnm = new char[strlen(mknmd.c_str()) + 1];
			strcpy(mnm, mknmd.c_str());


		}
		else { //if comma seperated is no

			cout << "Enter Licence Plate Number: ";
			cin.ignore(2000, '\n');
			string ntemp;
			getline(in, ntemp, '\n'); //get user input for plate

			while (strlen(ntemp.c_str()) > 8 || strlen(ntemp.c_str()) < 1) {

				cout << "Invalid Licence Plate, try again: ";
				getline(in, ntemp, '\n');

			}


			
			int len = ntemp.length(); //store len of plate entered by user

			for (int i = 0; i < len; i++) {

				ntemp[i] = toupper(ntemp[i]);

			}

			strcpy(plate, ntemp.c_str());
			cout << "Enter Make and Model: ";
			string temp;
			getline(in, temp, '\n'); //get user input for make n model



			while (strlen(temp.c_str()) < 2) {

				cout << "Invalid Make and model, try again: ";
				getline(in, temp, '\n');

			}

			delete[] mnm;
			mnm = nullptr;
			mnm = new char[strlen(temp.c_str()) + 1];
			strcpy(mnm, temp.c_str());

			
			return in;
		}



		return in;

	}

	std::ostream& Vehicle::write(std::ostream& os) const { //write vehicle object to console if vehicle not empty 

		if (isEmpty()) { 

			cout << "Invalid Vehicle Object" << endl;

		}
		else if (isCsv()) {

			os << pspot << "," << plate << "," << mnm << ",";
		}
		else {

			cout << "Parking Spot Number: ";

			if (pspot == 0) {

				os << "N/A" << endl;
			}
			else {

			os << pspot << endl;

			}

			os << "Licence Plate: " << plate << endl;
			os << "Make and Model: " << mnm << endl;
			
		}

		return os;
	}

	void Vehicle::setEmpty() { //set vehicle to empty

		plate[0] = '\0';
		mnm = nullptr;
		pspot = 0;
	}

	bool Vehicle::isEmpty()const { //check if vehicle is empty

		if (mnm != nullptr && plate[0] != '\0') {

			return false;
		}
		else {

			return true;
		}

	}

	 char* Vehicle::gotLicencePlate() { //return plate of vehicle


		return  plate;


	}

	char* Vehicle::getMakeModel() { //return make an model of vehicle

		return mnm;

	}

	void Vehicle::setMakeModel(const char* nn) { //set make an model of vehicle

		if (nn != nullptr) {

			delete[] mnm;
			mnm = nullptr;
			mnm = new char[strlen(nn) + 1];
			strcpy(mnm, nn);

		}
		else {

			mnm = nullptr;
		}


	}
}