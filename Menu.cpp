/* ------------------------------------------------------

Name: Morris Anthony
Student ID:158091199
Date:08/05/2020
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <string>

namespace sdds {

    //MenuItem Stuff

    MenuItem::MenuItem() {

        menu = nullptr;

    }

    MenuItem::MenuItem(const char* m) {

        if (m != nullptr && m[0] != '\0') {

            //copying char recieved to MenuItem
            menu = new char[strlen(m) + 1];
            strcpy(menu, m);

        }
        else {


            menu = nullptr;

        }

    }

    void MenuItem::display(std::ostream& os) const {

        os << menu << endl;

    }

    std::ostream& operator<<(std::ostream& os, const MenuItem& s) {

        if (s.menu != nullptr && s.menu[0] != '\0') {

            s.display(os);//pass ostream object os to display
            return os;

        }
        else return os;

    }

    MenuItem :: ~MenuItem() {

        delete[] menu;
        menu = nullptr;

    }



    Menu& Menu::operator=(const char* newTitle) {

        if (newTitle != nullptr) {


            delete[] menu_title; //deleting menu_title before assigning to avoid leaks
            menu_title = nullptr;
            menu_title = new char[strlen(newTitle) + 1]; //assigning dynamic memory for menu_title
            strcpy(menu_title, newTitle);//copying title


        }
        else {

            menu_title = nullptr;
        }

        return *this;

    }

    Menu::Menu() {
        //setting objects to nullptr as default
        menu_title = nullptr;
        item[0] = nullptr;
        itemcounter = 0;
        userselection = 0;
        indent = 0;

    }

    Menu::~Menu() {
        //deleting objects for clearing dynamic memory
        delete[] menu_title;
        menu_title = nullptr;
        for (int i = 0; i < itemcounter; i++) {


            delete item[i];
            item[i] = nullptr;

        }
    }

    Menu::Menu(const char* mm, int nm) {
        //copies char recived to menu title and setsindentation
        menu_title = nullptr;
        item[0] = nullptr;
        itemcounter = 0;
        userselection = 0;
        indent = 0;

        if (mm != nullptr) {

            menu_title = new char[strlen(mm) + 1];
            strcpy(menu_title, mm);
            indent = nm;


        }
        else {


            menu_title = nullptr;
            item[0] = nullptr;
            itemcounter = 0;
            userselection = 0;
            indent = 0;
        }


    }

    void Menu::init(const Menu& source) {
        //init function that copies class object passed 
        itemcounter = source.itemcounter; //shallow copies
        indent = source.indent; //shallow copies

        if (!source.isEmpty()) { //checking  if object title is not null

            menu_title = new char[strlen(source.menu_title) + 1]; //deep copying elements
            strcpy(menu_title, source.menu_title);

            for (int i = 0; i < source.itemcounter; i++) {

                item[i] = new MenuItem(source.item[i]->menu);

            }

            indent = source.indent;

        }
        else {

            delete[] menu_title;
            menu_title = nullptr;

        }



    }



    Menu::Menu(const Menu& src) {

        init(src); //calling init to copy reference of class object recieved

    }

    Menu& Menu::operator=(const Menu& src) {


        //deleting objects before assigning
        delete[] menu_title;
        menu_title = nullptr;

        for (int i = 0; i < itemcounter; i++) {


            delete item[i];
            item[i] = nullptr;

        }
        //calling init function to copy objects
        init(src);


        return *this;

    }

    Menu :: operator bool()const {

        //checks if object is valid
        bool isValid = false;

        if (menu_title != nullptr) {

            isValid = true;

        }

        return isValid;
    }

    bool Menu::isEmpty() const {
        //checks if object is empty
        if (menu_title == nullptr) {

            return true;

        }
        else {

            return false;

        }


    }
    void Menu::display() const {
        int nwidth = 0; //nwidth to store indentation

        if (isEmpty()) { //checking if object is in safe empty state

            cout << "Invalid Menu!" << endl;

        }
        else if (!isEmpty() && itemcounter == 0) { //if not display objects with indent;
            
            if (indent > 0) {
                nwidth = indent * 4; //setting indent value
                cout << right << setw(int(nwidth + (strlen(menu_title)))) << menu_title << endl; //use setw for indentation and right justification
                cout << "No Items to display!" << endl;
            }
            else {
                cout << menu_title << endl;
                cout << "No Items to display!" << endl;
            }

        }
        else {


            if (indent > 0) { //displaying objects when there is no indent
                nwidth = indent * 4;
                cout << right << setw(int(nwidth + (strlen(menu_title)))) << menu_title << endl;
                
                for (int i = 0; i < itemcounter; i++) {



                    cout << setw(nwidth + 1) << i + 1 << "- " << item[i]->menu << endl;

                }

                cout << setw(int(nwidth + 2)) << "> ";
            }
            else {

                cout << menu_title << endl;
                for (int i = 0; i < itemcounter; i++) {

                    cout << i + 1 << "- " << item[i]->menu << endl;

                }

                cout << "> ";

            }

        }

    }

    void Menu::add(const char* ad) {

        if (ad != nullptr && itemcounter < MAX_NO_OF_ITEMS) { //if object recieved is not nullptr and number of items in object is less than MAX


            item[itemcounter] = nullptr; //set item[itemcounter] (empty element) to nullptr;
            item[itemcounter] = new MenuItem(ad); //pass it to the menuitem array for assignment
            itemcounter++; //increment the count

        }
        else {

            *this = Menu();

        }

    }

    int Menu::run() const {

        char num[4]; //char to store user input
        bool isdigit = false;
        int newnum = 0;

        if (itemcounter == 0) {

            newnum = 0; //if no items return -

        }

        display();


        if (!isEmpty() && itemcounter != 0) {

            while (!isdigit) {

                cin >> num;
                cin.ignore();
                //isdigit = is_number(num); //call to is_number func which returns true if char string is a number
                isdigit = isnum(num);
                if (!isdigit) {
                    cout << "Invalid Integer, try again: ";
                }
                else {

                    newnum = stoi(num); // if it is number , covert to string
                    while (newnum > itemcounter || newnum <= 0)
                    {

                        cout << "Invalid selection, try again: ";
                        cin >> newnum;
                        cin.ignore(); //clear buffer

                    }
                }


            }
        }


        return newnum;

    }

    Menu :: operator int() const {
        //checks if object is valid and executes run 
        if (!isEmpty()) {

            return run();
        }
        else return 0;
    }



    Menu& Menu::operator<<(const char* s) {
        //allows cascaded values for Menu object
        add(s);
        return *this;

    }


     
    bool Menu:: isnum(const string& s)const {

        bool a = false;
        int count = 0;
        int len = s.length();
        for (int i = 0; i < len; i++) {

            if (isdigit(s[i])) {

                count++;

            }
        }

        if (count == len) {

            a = true;
        }

        return a;

    }



}