/* ------------------------------------------------------

Name: Morris Anthony
Student ID:158091199
Date:08/05/2020
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

-----------------------------------------------------------*/
#include <iostream>

#ifndef UNTITLED_MENU_H
#define UNTITLED_MENU_H
using namespace std;
namespace sdds {
    const int MAX_NO_OF_ITEMS = 10;

    class Menu; //forward declaration of menu
    class MenuItem {
        friend Menu; //friend menu to be able to access Menu class  elements 
        char* menu;
        MenuItem();
        MenuItem(const char* m);
        void display(std::ostream& os) const;
        MenuItem(const MenuItem& m);
        ~MenuItem();
        MenuItem& operator=(const MenuItem& source) = delete;
        friend std::ostream& operator<<(std::ostream& os, const MenuItem& s);


    };


    class Menu {

        char* menu_title;  //holds menu title
        MenuItem* item[MAX_NO_OF_ITEMS]; //an array of menutem pointers set to a max of items const
        int itemcounter; //no of items counter
        int userselection; //stores user choice
        int indent; //stores indent 

    public:
        Menu();
        ~Menu();
        Menu(const Menu& src);
        Menu(const char* mm, int nm = 0); //set int to a default 0
        void init(const Menu& source);
        Menu& operator=(const Menu&);
        Menu& operator=(const char* newTitle);
        operator bool()const;
        bool isEmpty() const;
        void display() const;
        void add(const char*);
        int run() const;
        operator int() const;
        Menu& operator<<(const char* s);
        bool isnum(const string& s)const;
    };


}


#endif //UNTITLED_MENU_H
