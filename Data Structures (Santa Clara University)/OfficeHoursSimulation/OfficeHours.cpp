// FILE: washing.cxx
// CLASSES implemented: bool_source, averager, office
//
// INVARIANT for the bool_source ADT:
//   1. The member variable probability is the appoximate probability that
//      query( ) returns true.
//
// INVARIANT for the averager ADT:
//   1. The member variable count indicates how many numbers the averager has
//      been given.
//   2. The member variable sum is the sum of all the numbers that the
//      averager has been given.
//
// INVARIANT for the office class:
//   1. The member variable seconds_for_wash is the number of seconds required
//      for one wash.
//   2. The member varible wash_time_left is 0 if the office is not busy;
//      otherwise it is the number of seconds until the office is free.


#include <cassert>   
#include <cstdlib>   
#include "OfficeHours.h" 
using namespace std;

namespace main_officehrs {
	bool_source::bool_source(double p)
	{
		assert(p >= 0);
		assert(p <= 1);
		probability = p;
	}

	bool bool_source::query() const   
	{
		return (rand() < probability * RAND_MAX);
	}

	averager::averager()
	{
		count = 0;
		sum = 0;
	}

	void averager::next_number(double value)
	{
		++count;
		sum += value;
	}

	double averager::average() const
	{
		assert(how_many_numbers() > 0);
		return sum / count;
	}

	office::office(unsigned int s) {
		seconds_for_wash = s;
		wash_time_left = 0;
	}

	void office::one_second()
	{
		if (is_busy())
			--wash_time_left;
	}

	void office::start_question()  
	{
		assert(!is_busy());
		wash_time_left = seconds_for_wash;
	}
}