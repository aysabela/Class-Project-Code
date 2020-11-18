#ifndef PHONRMGR_H
#define PHONRMGR_H

#include "Phone.h"

const int SIZE = 999;


class PhoneMgr
{

private:

	Phone * arrPhone[SIZE] = { nullptr }; // Manager owns the main data structure
	int recordCount = 0; 

public:

	PhoneMgr();
	~PhoneMgr();

	int getRecordCount() const;

	void Display();
	void Random();
	void Dial(int);

};



#endif // PhoneMgr_H



