/* ------------------------------------------------------

Name: Morris Anthony
Student ID:158091199
Date:08/05/2020
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

-----------------------------------------------------------*/
#include <iostream>
#include "Vehicle.h"
namespace sdds {


	class Car : public Vehicle {

		bool carWash;

	public:

		Car();
		Car(const char* lplate, const char* m);
		Car(const Car& src) = delete; //copy construction not allowed
		Car* operator=(const Car& src) = delete; //copy assignment not allowed
		std::istream& read(std::istream& in = std::cin);
		std::ostream& write(std::ostream& os = std::cout)const;

	};


}
