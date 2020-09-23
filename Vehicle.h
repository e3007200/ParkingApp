/* ------------------------------------------------------

Name: Morris Anthony
Student ID:158091199
Date:08/05/2020
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

-----------------------------------------------------------*/
#ifndef VEHICLE_H
#define VEHICLE_H
#include "ReadWritable.h"
#include <iostream>
namespace sdds {

	//derived class vehicle
	class Vehicle : public ReadWritable { //derived class vehicle

		char plate[8 + 1];
		char* mnm;
		int pspot;

	public:

		Vehicle();
		Vehicle(const char* lplate, const char* m);
		~Vehicle();
		int getParkingSpot();
		void setParkingSpot(int s);
		bool operator==(const char* lpate)const;
		bool operator==(const Vehicle& src)const;
		std::istream& read(std::istream& in = std::cin);
		std::ostream& write(std::ostream& os = std::cout)const;

	protected:

		void setEmpty();
		bool isEmpty()const;
		char* gotLicencePlate();
		char* getMakeModel();
		void setMakeModel(const char* nn);


	};


}

#endif //VEHICL_H

