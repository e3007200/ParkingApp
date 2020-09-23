/* ------------------------------------------------------

Name: Morris Anthony
Student ID:158091199
Date:08/05/2020
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

-----------------------------------------------------------*/
#ifndef READWRITABLE_H
#define READWRITABLE_H
#include <iostream>
namespace sdds {

	class ReadWritable {

		bool flag; //comma seperated yes no flag

	public:
		ReadWritable();
		virtual ~ReadWritable(); //virtual destructor to be able to delete all of the latest versions of derived classes
		bool isCsv()const;
		void setCsv(bool value);
		virtual std::ostream& write(std::ostream& os = std::cout)const = 0; //pure virtual write, always calls the latest version of write
		virtual std::istream& read(std::istream& in = std::cin) = 0; //pure virtual write, always calls the latest version of read

	};

	std::istream& operator>>(std::istream& is, ReadWritable& s);
	std::ostream& operator<<(std::ostream& os, const ReadWritable& s);

}
#endif //READWRITABEL
