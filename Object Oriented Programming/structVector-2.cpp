// This program stores, in two vectors, the hours worked by 5
// employees, and their hourly pay rates.
/*

1. What is the function push_back() for? Why the function is named as "push_back"? 

2. If the function push_back() is for adding a new element to the end of the vector,
what is the name of the function which deletes an element at the end?

3. Can we add a new element to the front of the vector? Could we delete an element
at the front?

4. Use this program as the base and implement a function which returns the biggest value in the int vector.

5. We are using 2 vectors to handle hours and payRate. If we need to handle employee information,
which consists of 20 fields, can we use 20 vectors to do this? If not, what is the better
design?

*/
#include <iostream>
#include <iomanip>
#include <vector>   
#include <sstream>
using namespace std;


struct Employee {
	string name;
	int hours;
	double payRate;

};


int main()
{

	string holder;
	int hours;
	int numEmployees;
	vector <Employee> work;
	Employee Emp;
	string name;
	double payRate;

	cout << "How many employees do you have? ";
	getline(cin, holder);
	stringstream(holder) >> numEmployees;

	cout << "What's the employees name? : ";
	getline(cin, name);

	cout << "Enter the hours worked by " << Emp.name << " employees and their hourly rates.\n";
	getline(cin, holder);
	stringstream(holder) >> hours >> payRate;

	for (int i = 0; i < numEmployees; i++)
	{
		int tempHours;    // To hold the number of hours entered
		double tempRate;  // To hold the payrate entered

		cout << "Hours worked by employee #" << (i + 1);
		cout << ": ";
		cin >> tempHours;
		Emp.hours = tempHours;      // Add an element to hours
		cout << "Hourly pay rate for employee #";
		cout << (index + 1) << ": ";
		cin >> tempRate;
		Emp.payRate = tempRate;  // Add an element to payRate
		work.push_back(Emp);
	}

	// Display each employee's gross pay.
	cout << "Here is the gross pay for each employee:\n";
	cout << fixed << showpoint << setprecision(2);
	for (i = 0; index < numEmployees; i++)
	{
		double grossPay = hours[i] * payRate[i];
		cout << "Employee #" << (i + 1);
		cout << ": $" << grossPay << endl;
	}
	
	system("pause");
	
	return 0;
}

/*



// Input the payroll data.
cout << "Enter the hours worked by " << numEmployees;
cout << " employees and their hourly rates.\n";
for (index = 0; index < numEmployees; index++)
{
	int tempHours;    // To hold the number of hours entered
	double tempRate;  // To hold the payrate entered

	cout << "Hours worked by employee #" << (index + 1);
	cout << ": ";
	cin >> tempHours;
	hours.push_back(tempHours);      // Add an element to hours
	cout << "Hourly pay rate for employee #";
	cout << (index + 1) << ": ";
	cin >> tempRate;
	payRate.push_back(tempRate);  // Add an element to payRate
}

// Display each employee's gross pay.
cout << "Here is the gross pay for each employee:\n";
cout << fixed << showpoint << setprecision(2);
for (index = 0; index < numEmployees; index++)
{
	double grossPay = hours[index] * payRate[index];
	cout << "Employee #" << (index + 1);
	cout << ": $" << grossPay << endl;
}
return 0;
} */