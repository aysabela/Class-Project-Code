#include "Phone.h"
#include <cstdlib>

using namespace std;


Phone::Phone()

{


}

Phone::~Phone()

{



}



void Phone::setFirstName(string f)

{

	firstName = f;

}



void Phone::setLastName(string l)

{

	lastName = l;

}



string Phone::getFirstName() const

{

	return firstName;

}



string Phone::getLastName() const

{

	return lastName;

}



void Phone::setPhoneNumber(long long s)

{

	phoneNumber = s;

}

long long Phone::getPhoneNumber() const

{

	return phoneNumber;

}

