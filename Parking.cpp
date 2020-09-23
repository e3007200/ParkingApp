/* ------------------------------------------------------

Name: Morris Anthony
Student ID:158091199
Date:08/05/2020
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

-----------------------------------------------------------*/


#define _CRT_SECURE_NO_WARNINGS
#include "Parking.h"
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <string>
#include "Car.h"
#include "Motorcycle.h"
#include <cstring>
#include <fstream>

namespace sdds {


    Parking::Parking() {

        parkfName = nullptr;
        numSpots = -1;
        numofPveh = -1;
        for (int i = 0; i < MAX_PARKING; i++) {

            spots[i] = nullptr;
        }



    }
    Parking::Parking(const char* src, int noOfSpots) {

        //Call  the     Load    Data    File    func;on (see    list    of      member  func7ons) and   if      it      returns true,   then    populate
        //the   Parkingand Vehicle      menus
        parkfName = nullptr;
        for (int i = 0; i < MAX_PARKING; i++) {

            spots[i] = nullptr;
        }
        numSpots = -1;
        numofPveh = -1;


        if (src != nullptr && src[0] != '\0' && noOfSpots >= 10 && noOfSpots <= MAX_PARKING) {

            parkfName = nullptr;
            parkfName = new char[strlen(src) + 1];
            strcpy(parkfName, src);
            numSpots = noOfSpots;
            numofPveh = 0;
            for (int i = 0; i < MAX_PARKING; i++) {

                spots[i] = nullptr;
            }


        }
        else {

            for (int i = 0; i < MAX_PARKING; i++) {

                spots[i] = nullptr;
            }
            parkfName = nullptr;
            numSpots = -1;
            numofPveh = -1;

        }

        if (LoadDataFile()) {

            ParkingMenu = "Parking Menu, select an action:";
            //ParkingMenu << "Park Vehicle" << "Return Vehicle" << "List Parked Vehicles" << "Close Parking (End of day)" << "Exit Program";
            ParkingMenu.add("Park Vehicle");
            ParkingMenu.add("Return Vehicle");
            ParkingMenu.add("List Parked Vehicles");
            ParkingMenu.add("Close Parking (End of day)");
            ParkingMenu.add("Exit Program");
            VehicleMenu = Menu("Select type of the vehicle:", 1);
            //VehicleMenu << "Car" << "Motorcycle" << "Cancel";
            VehicleMenu.add("Car");
            VehicleMenu.add("Motorcycle");
            VehicleMenu.add("Cancel");


        }
        else {

            cout << "Error in data file" << endl;
            parkfName = nullptr;
            spots[0] = nullptr;
            numSpots = -1;
            numofPveh = -1;

        }

    }

    Parking::~Parking() {

        SaveDataFile();
        delete[] parkfName;
        parkfName = nullptr;
        for (int i = 0; i < MAX_PARKING; i++) {

            delete spots[i];
            spots[i] = nullptr;
        }
        numSpots = -1;
        numofPveh = -1;

    }


    bool Parking::isEmpty() { //check if parking is empty

        bool empty = false;
        parkfName != nullptr && numSpots == -1 && numofPveh == -1 ? empty = true : empty = false;
        return empty;

    }
    void Parking::ParkingStatus()const { //display parking lot stats

        cout << "****** Seneca Valet Parking ******" << endl;
        cout << "*****  Available spots: ";
        cout << left << setw(4) << numSpots - numofPveh;
        cout << " *****" << endl;


    }
    void Parking::VehiclePark() { //user options to park vehicle//added graceful exit if invalid option is selected
        

        int choice;

        if (numSpots != numofPveh) {

            VehicleMenu.display();
            cin >> choice;
            if (choice == 1) {



                Vehicle* Car1 = nullptr;

                Car1 = new Car();

                Car1->setCsv(false);

                Car1->read();

                for (int i = 0; i < numSpots; i++) {

                    if ((spots[i]) == nullptr) {

                        spots[i] = nullptr;
                        spots[i] = Car1;
                        Car1->setParkingSpot(i + 1);
                        ++numofPveh;
                        cout << endl;
                        cout << "Parking Ticket" << endl;
                        spots[i]->write();
                        cout << endl;
                        break;
                    }


                }


            }
            else if (choice == 2) {

                Vehicle* Moto = nullptr;
                Moto = new Motorcycle();
                Moto->setCsv(false);
                Moto->read();
                for (int i = 0; i < numSpots; i++) {

                    if ((spots[i]) == nullptr) {

                        spots[i] = nullptr;
                        spots[i] = Moto;
                        Moto->setParkingSpot(i + 1);
                        ++numofPveh;
                        cout << endl;
                        cout << "Parking Ticket" << endl;
                        spots[i]->write();
                        cout << endl;
                        break;
                    }


                }
            }
            else if (choice == 3) {

                cout << "Parking cancelled" << endl;

            }
        }
        else {

            cout << "Parking is full" << endl;

        }

    }
    void Parking::ReturnVehicle() { //deletes vehicle from spots array setting the spot to null
        int flag = 0;
        char ntemp[8];
        ntemp[0] = '\0';

        cout << "Return Vehicle" << endl;

        cout << "Enter Licence Plate Number: ";

        cin >> ntemp;


        while (strlen(ntemp) > 8 || strlen(ntemp) < 1) {

            cout << "Invalid Licence Plate, try again: ";
        }

        for (int i = 0; i < numSpots; i++) {

            if (spots[i] != nullptr) {

                if (*spots[i] == ntemp) {



                    cout << endl << "Returning: " << endl;
                    spots[i]->write() << endl;
                    delete spots[i];
                    spots[i] = nullptr;
                    numofPveh--;
                    flag = 1;
                    break;


                }

            }

        }

        if (flag != 1) {


            cout << "Licence plate " << ntemp << " not found" << endl;

        }


    }

    void Parking::ListVehicle() { //couts statement


        cout << "*** List of parked vehicles ***" << endl;

        for (int i = 0; i < numSpots; i++) {

            if (spots[i] != nullptr) {

                spots[i]->write();
                cout << "-------------------------------" << endl;

            }


        }

    }
    bool Parking::CloseVehicle() { //returns bool

        string option;
        if (isEmpty()) {

            cout << "Closing Parking" << endl;
            return true;
        }
        else {

            cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
            cout << "Are you sure? (Y)es/(N)o: ";
            cin >> option;

            while (strlen(option.c_str()) >= 2 || (option[0] != 'Y' && option[0] != 'y' && option[0] != 'n' && option[0] != 'N')) {

                cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                cin >> option;

            }


            if (option[0] == 'Y' || option[0] == 'y') {

                cout << "Closing Parking" << endl;

                for (int i = 0; i < numSpots; i++) {

                    if (spots[i] != nullptr) {

                        cout << endl;
                        cout << "Towing request" << endl;
                        cout << "*********************" << endl;
                        spots[i]->write();
                        delete spots[i];
                        spots[i] = nullptr;
                    }

                }

                return true;
            }
            else {

                cout << "Aborted!" << endl;
                return false;
            }

        }


    }

    bool Parking::Exit()const { //exit choice
        bool option = false;
        char choice[10];

        cout << "This will terminate the program!" << endl;
        cout << "Are you sure? (Y)es/(N)o: ";


        cin >> choice;



        while ((choice[0] != 'Y' && choice[0] != 'y' && choice[0] != 'N' && choice[0] != 'n') || (choice[1] != '\0')) { //yes or no checker

            cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
            cin >> choice;


        }

        if (choice[0] == 'Y' || choice[0] == 'y') {
            option = true;
        }
        else if (choice[0] == 'N' || choice[0] == 'n') {
            option = false;
        }

        return option;

    }

    bool Parking::LoadDataFile() {

        char a = '\0'; //char to store first char (m or c)
        bool gstate = true; //store func state

        if (!isEmpty()) {


            ifstream fin; //connect and open file
            fin.open(parkfName);
          


            if (!fin.is_open()) {

                 gstate = false;
               
            }


            while (fin.good() && gstate && (numofPveh < numSpots)) { //loop through file and store each line in a vehicle object (car or moto)

                Vehicle* temp = nullptr;  //temp vehicle pointer to store data temporarily
                fin.get(a);
                fin.ignore(1);
               
                if (a == 'M') {

                    temp = new Motorcycle();
                    temp->setCsv(true);

                    if (fin >> *temp) {

                        spots[temp->getParkingSpot() - 1] = nullptr;
                        spots[temp->getParkingSpot() - 1] = temp;
                        numofPveh++;

                        temp->setCsv(false);
                     

                    }
                    else {

                    
                        delete temp;
                        temp = nullptr;

                    }
                }
                else if (a == 'C') {
                   
                    temp = new Car();
                    temp->setCsv(true);
                    if (fin >> *temp) {

                        spots[temp->getParkingSpot() - 1] = nullptr;
                        spots[temp->getParkingSpot() - 1] = temp;
                        numofPveh++;
                        temp->setCsv(false);
                      
                    }
                    else {

                        delete temp;
                        temp = nullptr;

                    }
                } 
                            
            }
          
            fin.close();

        }

        return gstate;

    }

    void Parking::SaveDataFile()const { //save all data in program to file 


        ofstream fout(parkfName);

        if (!fout.good()) {

            cout << "Error in File" << endl;

        }
        else {

            for (int i = 0; i < numSpots; i++) {

                if (spots[i] != nullptr) {


                    spots[i]->setCsv(true);

                    spots[i]->write(fout);


                }

            }

            cin.ignore();
            fout.close();

        }

    }

    int Parking::run() { //run display and wait for user input // added graceful exit if invalid option is selected
        int choice;
        if (parkfName != nullptr) {

            //switch case for options
            do {

                ParkingStatus();
                ParkingMenu.display();
                cin >> choice;
                switch (choice) {

                case 1:
                    VehiclePark();
                    break;
                case 2:
                    ReturnVehicle();
                    break;
                case 3:
                    ListVehicle();
                    break;
                case 4:

                    if (CloseVehicle()) {
                        choice = 6;

                    }
                    break;

                case 5:

                    if (Exit()) {
                        cout << "Exiting program!" << endl;
                        choice = 6;

                    }
                    break;

                }



            } while (choice > 0 && choice <= 5);

            return choice;

        }
        else {

            return 0;

        }

    }

}