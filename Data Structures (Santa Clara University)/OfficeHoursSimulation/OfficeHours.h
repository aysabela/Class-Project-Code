#pragma once
#ifndef MAIN_OFFICEHRS_H
#define MAIN_OFFICEHRS_H
#include <cstdlib> // Provides std::size_t

namespace main_officehrs
{
	class bool_source
	{
	public:
		// CONSTRUCTOR        
		bool_source(double p = 0.5);
		// CONSTANT function        
		bool query() const;
	private:
		double probability; // Probability of query( ) returning true    
	};

	class averager
	{
	public:
		// CONSTRUCTOR        
		averager();
		// MODIFICATION function        
		void next_number(double value);
		// CONSTANT functions        
		std::size_t how_many_numbers() const { return count; }
		double average() const;
	private:
		std::size_t count; // How many numbers have been given to the averager        
		double sum;   // Sum of all the numbers given to the averager    
	};

	class office
	{
	public:
		// CONSTRUCTOR        
		office(unsigned int s = 60);
		// MODIFICATION functions        
		void one_second();
		void start_question();
		// CONSTANT function        
		bool is_busy() const { return (wash_time_left > 0); }
	private:
		unsigned int seconds_for_wash; // Seconds for a single wash        
		unsigned int wash_time_left;   // Seconds until office no longer busy    
	};
}

#endif