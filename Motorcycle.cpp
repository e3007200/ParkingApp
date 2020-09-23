/* ------------------------------------------------------
Name: Morris Anthony
Student ID: 158091199
Date:07/28/2020
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stdio.h>
#include <cctype>
#include <sstream>
#include <iostream>
#include "Motorcycle.h"
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;
namespace sdds {


	Motorcycle::Motorcycle() { //sets base to default automatically

		sideCar = false;
		

	}

	Motorcycle::Motorcycle(const char* lplate, const char* m) :Vehicle(lplate, m) { // lplate and m passed to custom constructor for base class



	}

	std::istream& Motorcycle::read(std::istream& in) { //read user input for motorcycle information

		string option;


		if (isCsv()) {

			Vehicle::read(in);
			in >> sideCar;
			in.ignore(256, '\n');


		}
		else {

			cout << endl;
			cout << "Motorcycle information entry" << endl;
			Vehicle::read(in);




			cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";// check for user response
			cin >> option;

			while (strlen(option.c_str()) > 1 || (option[0] != 'Y' && option[0] != 'y' && option[0] != 'N' && option[0] != 'n')) { //yes or no validator for 

				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
				cin >> option;

			}

			if (option[0] == 'Y' || option[0] == 'y') {

				sideCar = true;
			}
			else {


				sideCar = false;
			}


		}

		
		return in;

	}


	std::ostream& Motorcycle::write(std::ostream& os)const { //write motorcycle info to console



		if (isEmpty()) {


			os << "Invalid Motorcycle Object" << endl;


		}
		else {


			if (isCsv()) {

				os << "M,";
				Vehicle::write(os) << sideCar << endl;


			}
			else {

				
				os << "Vehicle type: Motorcycle" << endl;
				if (sideCar) {

					Vehicle::write(os);
					os << "With Sidecar" << endl;

				}
				else {

					Vehicle::write(os);


				}


			}

		}

		return os;


	}


}

