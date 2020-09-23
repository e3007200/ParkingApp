/* ------------------------------------------------------

Name: Morris Anthony
Student ID:158091199
Date:08/05/2020
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

-----------------------------------------------------------*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include "Menu.h"
#include "Vehicle.h"
namespace sdds {
		
	const int MAX_PARKING = 100;
	class Parking  {

		//Parking	holds	a	C-style	string	with	unknown	size	to	hold	the	data	file	name	of	the	applica;on.
		char* parkfName;

		Menu ParkingMenu;
		Menu VehicleMenu;

		int numSpots;
		int numofPveh;
		Vehicle* spots[MAX_PARKING];
		

		Parking& operator=(const Parking& source) = delete; //copy assignment not allowed
		Parking(const Parking& m) = delete; //copy construction not allowed

		bool isEmpty();
		void ParkingStatus() const;
		void VehiclePark();
		void ReturnVehicle();
		void ListVehicle();
		bool CloseVehicle();
		bool Exit()const;
		bool LoadDataFile();
		void SaveDataFile()const;

	public:
		int run();
		Parking();
		Parking(const char*, int);
		~Parking();




	};


}
