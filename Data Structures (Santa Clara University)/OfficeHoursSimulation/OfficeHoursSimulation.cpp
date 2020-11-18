/* 
*
* Name: Alyssa Ysabela Flores
* 
* Description: This is my office hours simulation which utilizes most of the code in the original carwash code we were provided
* in the files. The only big difference is that the main simulation code has been duplicated and returns separate values it normally
* output to the console in the original carwash code.
*
* Last Modified: October 9th 2020 
*
*
*/

#include <iostream>    
#include <cstdlib>    
#include <queue>      
#include <ctime>
#include "OfficeHours.h"   
using namespace std;
using namespace main_officehrs;

double avgStudHelp
(unsigned int office_time, double arrival_prob, unsigned int total_time);
double avgWaitInLine
(unsigned int office_time, double arrival_prob, unsigned int total_time);

int main() {
	double avgTimeStudentInOffice1 = 0;
	double avgTimeStudentInOffice2 = 0;
	double avgWaitTime = 0.0;
	double avgWaitTime2 = 0.0;
	double avgStudentHelped = 0.0;
	double avgStudentHelped2 = 0.0;
	double avgPastHr = 0.0; 
	

	srand(time(NULL));

	for (int i = 1; i < 1001; i++) {
		int j = rand() % (1119) + 1;
		int k = rand() % (3999) + 1;
		avgStudentHelped += avgStudHelp(j, 1.0 / k, 18000); 
		avgStudentHelped2 = avgStudentHelped / i;
		
		avgWaitTime += avgWaitInLine(j, 1.0 / k, 18000);
		avgWaitTime2 = avgWaitTime / i;

		avgTimeStudentInOffice1 += j;
		avgTimeStudentInOffice2 = avgTimeStudentInOffice1 / i;
		
	}

	avgWaitTime2 = avgWaitTime2 / 60;
	avgTimeStudentInOffice2 = avgTimeStudentInOffice2 / 60;

	avgPastHr = (avgStudentHelped2 * avgWaitTime2 + avgStudentHelped2 * avgTimeStudentInOffice2)-60;

	cout << "Total average time a student spends waiting during an office hour visit: " << avgWaitTime2 << " min" << endl;
	cout << "Total average time student spends with the professor during office hours: " << avgTimeStudentInOffice2 << " min" << endl;
	cout << "Total average time professor stays past office hours: " << avgPastHr << " min" << endl;

	return EXIT_SUCCESS;
}


double avgStudHelp
(unsigned int office_time, double arrival_prob, unsigned int total_time)
{
	queue<unsigned int> arrival_times; // Waiting students time stamps    
	unsigned int next;                 // A value taken from the queue    
	bool_source arrival(arrival_prob);
	office machine(office_time);
	averager wait_times;
	unsigned int current_second;

	for (current_second = 1; current_second <= total_time; ++current_second)
	{   // Simulate the passage of one second of time.        

		// Check whether a new student has arrived & if it's still under the hour.        
		if (arrival.query() && current_second <= 3600)
			arrival_times.push(current_second);

		// Check whether we can start helping another student.        
		if ((!machine.is_busy()) && (!arrival_times.empty()))
		{
			next = arrival_times.front();
			arrival_times.pop();
			wait_times.next_number(current_second - next);
			machine.start_question();
		}

		// Tell the office to simulate the passage of one second.        
		machine.one_second();
	}

	return wait_times.how_many_numbers();
}

double avgWaitInLine
(unsigned int office_time, double arrival_prob, unsigned int total_time)
{
	queue<unsigned int> arrival_times; // Waiting students time stamps    
	unsigned int next;                 // A value taken from the queue    
	bool_source arrival(arrival_prob);
	office machine(office_time);
	averager wait_times;
	unsigned int current_second;

	double wait_times_var = 0.0;

	for (current_second = 1; current_second <= total_time; ++current_second)
	{   // Simulate the passage of one second of time.        

		// Check whether a new student has arrived & if it's still under the hour.        
		if (arrival.query() && current_second <= 3600)
			arrival_times.push(current_second);

		// Check whether we can start helping another student.        
		if ((!machine.is_busy()) && (!arrival_times.empty()))
		{
			next = arrival_times.front();
			arrival_times.pop();
			wait_times.next_number(current_second - next);
			machine.start_question();
		}

		// Tell the office to simulate the passage of one second.        
		machine.one_second();
	}

	if (wait_times.how_many_numbers() > 0)
		wait_times_var = wait_times.average();
		return wait_times_var;
}