#ifndef PHONE_H
#define PHONE_H


#include <string>
#include <cctype>
#include "stdlib.h"


using namespace std;

class Phone

{

private:

	long long phoneNumber;
	string firstName;
	string lastName;

public:


	Phone();
	~Phone();
	void setFirstName(string);
	void setLastName(string);
	void setPhoneNumber(long long);
	string getFirstName() const;
	string getLastName() const;
	long long getPhoneNumber() const;

};



#endif // PHONE_H







