//ALYSSA'S CODE

/*
Goals:

1. Learn how to implement copy constructor.
2. Learn how to implement overloading operator

Step 1
Implement a copy constructor for the class StudentTestScores.

Step 2
Implement an overloading operator ">" so that

		 (obj1 > obj2) is true

when the average score of sts1 is greater than that of sts2.

*/
#include <iostream>
#include <string>

using namespace std;

const double DEFAULT_SCORE = 0.0;

class StudentTestScores
{
private:
	string studentName;
	double * testScores; /// points to array of test scores
	int numTestScore;
public:
	StudentTestScores(string name, int numScores)
	{
		studentName = name;
		numTestScore = numScores;
		testScores = new double[numTestScore];
		for (int i = 0; i < numTestScore; i++)
		{
			testScores[i] = DEFAULT_SCORE;
		}
	}
	~StudentTestScores()
	{
		delete[] testScores;
	}
	void setName(string name)
	{
		studentName = name;
		return;
	}

	string getName()
	{
		return studentName;
	}

	void setTestScore(double score, int index)
	{
		testScores[index] = score;
		return;
	}
	double getTestScore(int index)
	{
		return testScores[index];
	}

	void displayNameNAllScores()
	{
		cout << getName() << endl;
		for (int i = 0; i < numTestScore; i++)
		{
			cout << getTestScore(i) << "  ";
		}
	}

	
	/// Copy constructor
	StudentTestScores(const StudentTestScores &sts) {
		studentName = sts.studentName;
		numTestScore = sts.numTestScore;
		testScores = new double[numTestScore];
		for (int i = 0; i < sts.numTestScore; i++)
		{
			testScores[i] = sts.testScores[i];
		}

	}


	/// Overloading operator ">"
	friend bool operator >(StudentTestScores &sts1, StudentTestScores &sts2) {
		double avg1 = 0;
		double avg2 = 0;
		double avgResult1 = 0;
		double avgResult2 = 0;
		for (int i = 0; i < sts1.numTestScore; i++) {
			avg1 += sts1.testScores[i];
		}

		avgResult1 = (avg1 / sts1.numTestScore);
		
		for (int i = 0; i < sts2.numTestScore; i++) {
			avg2 += sts2.testScores[i];
		}

		avgResult2 = (avg2 / sts2.numTestScore);

		return (avgResult1 > avgResult2);
	}	
	
};

int main()
{
	StudentTestScores sts1("John", 3);
	sts1.setTestScore(70, 0);
	sts1.setTestScore(80, 1);
	sts1.setTestScore(90, 2);

	cout << endl << "Display 1st student -- 1st run" << endl;
	sts1.displayNameNAllScores();

	StudentTestScores sts2 = sts1;

	cout << endl << endl << "Display 2nd student -- 1st run" << endl;
	sts2.displayNameNAllScores();

	sts2.setName("Mary");
	sts2.setTestScore(100, 2);
	cout << endl << endl << "The name of 2nd student has been changed to Mary and the 3rd score has been changed to 100.";

	cout << endl << endl << "Display 1st student -- 2nd run" << endl;
	sts1.displayNameNAllScores();
	cout << endl << endl << "Display 2nd student -- 2nd run" << endl;
	sts2.displayNameNAllScores();
	cout << endl << endl;



	/// Copy constructor test -- Copy all data in sts1 to sts3
	StudentTestScores sts3(sts1);
	/// Now, let us test again.
	/// Change the third score of sts3 to 99. This should NOT impact the data of sts1
	sts3.setTestScore(99, 2);
	cout << endl << "Display 1st student -- 3rd run" << endl;
	sts1.displayNameNAllScores();
	cout << endl << "Display 3rd student -- 3rd run" << endl;
	sts3.displayNameNAllScores();
	cout << endl;

	/// Overloading operator > test
	if (sts2 > sts1)
		cout << "The average score of sts2 is higher than that of sts1" << endl;
	else
		cout << "The average score of sts2 is lower than or equal to that of sts1" << endl;

		system("pause");
	return 0;
}
