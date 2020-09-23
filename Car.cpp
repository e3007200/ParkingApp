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
#include "Car.h"
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;
namespace sdds {

	Car::Car() { //sets base to default automatically

		carWash = false;
		
	}

	Car::Car(const char* lplate, const char* m) :Vehicle(lplate, m) { // calls custom constructor for base class



	}

	std::istream& Car::read(std::istream& in) {

		string option;


		if (isCsv()) {

			Vehicle::read(in);
			in >> carWash;
			in.ignore(256, '\n');


		}
		else {

			cout << endl;
			cout << "Car information entry" << endl;
			Vehicle::read(in);


			cout << "Carwash while parked? (Y)es/(N)o: "; // check for user response
			cin >> option;

			while (strlen(option.c_str()) > 1 || (option[0] != 'Y' && option[0] != 'y' && option[0] != 'n' && option[0] != 'N')) { //yes or no validator for response

				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
				cin >> option;

			}


			if (option[0] == 'Y' || option[0] == 'y') {

				carWash = true;
			}
			else {


				carWash = false;
			}


		}
		
		return in;

	}


	std::ostream& Car::write(std::ostream& os)const {


		if (isEmpty()) {


			os << "Invalid Car Object" << endl;


		}
		else {


			if (isCsv()) {

				os << "C,";
				Vehicle::write(os) << carWash << endl;


			}
			else {


				os << "Vehicle type: Car" << endl;
				if (carWash) {

					Vehicle::write(os);
					os << "With Carwash" << endl;

				}
				else {

					Vehicle::write(os);
					os << "Without Carwash" << endl;

				}



			}


		}

		return os;



	}


}