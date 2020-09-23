/* ------------------------------------------------------

Name: Morris Anthony
Student ID:158091199
Date:08/05/2020
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

-----------------------------------------------------------*/

#include <iostream>
#include "Vehicle.h"
using namespace std;
namespace sdds {

	class Motorcycle : public Vehicle {

		bool sideCar;

	public:
		Motorcycle();
		Motorcycle(const char* lplate, const char* m);
		Motorcycle(const Motorcycle& src) = delete; //copy construction not allowed
		Motorcycle* operator=(const Motorcycle& src) = delete; //copy assignment not allowed
		std::istream& read(std::istream& in);
		std::ostream& write(std::ostream& os = std::cout)const;


	};


}