// Spray does not work properly, sorry Professor

#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <random>
#include <math.h>

using namespace std;

const int SIZE = 99;

class Shape {
protected:
	char shapeType;
	int serialNumber;

public:

	Shape(char sType, int sNumber) {
		shapeType = sType;
		serialNumber = sNumber;
	}
	
	virtual void draw() {
	}

	~Shape() {
	}
};

class Circle : public Shape {
protected:
	double radius;
public:
	Circle(int sType, int sNumber, double r) : Shape(sType, sNumber) {
		radius = r;
	}

	virtual void draw() {
		int m1_2 = radius * 1.5;
		for (int col = radius ; col >= -radius; col -= 2) {
			for (int row = -m1_2; row <= m1_2; row++) {
				if (static_cast<int>(sqrt(pow(row, 2) + pow(col, 2))) == radius) {
					cout << "*";
				}
				else { cout << " "; }
			}
			cout << "\n";
		}
		cout << endl << endl;
	}

	~Circle() {
	}

};

class Spray : public Circle {
protected:
	double density;
public:
	Spray(int sType, int sNumber, double r, double d) : Circle(sType, sNumber, r) {
		density = d;
	}

	void draw() {
		random_device rd;
		default_random_engine generator(rd());
		uniform_int_distribution<int> distribution(0, 99);
		int dice_roll1 = distribution(generator);

		int row, col;
		double z = 0;
		for (row = 0; row <= (radius*2); row++) {
			for (col = 0; col <= (radius*2); col++) {
				z = sqrt((pow((row-radius), 2) + pow((col-radius), 2)));
				if ((-0.5 < (radius - z)) && ((radius - z) < 0.5)) {
					cout << "*";
					//
					if ((density < radius) && (dice_roll1 < density)) {
						uniform_int_distribution<int> distribution(0, density);
						int dice_roll1 = distribution(generator);
						cout << "*";
					}
					else
						cout << " "; //
				}
				else {
					cout << " ";
				}
			}
			cout << endl;
		}
		cout << endl << endl;
	}

	~Spray() {
	}
};

class Square : public Shape {
protected:
	double width;
public:
	Square(int sType, int sNumber, int w) : Shape(sType, sNumber) {
		width = w;
	}
	
	virtual void draw() {
		int row, col;
		for (row = 1; row <= width; row++) {
			for (col = 1; col <= width; col++) {
				cout << "* ";
			}
			cout << endl;
		}
		cout << endl << endl;
	}

	~Square() {
	}
};

class Rectangle : public Square {
protected:
	double length;
public:
	Rectangle(int sType, int sNumber, int w, int l) : Square(sType, sNumber, w) {
		length = l;
	}

	void draw() {
		int row, col;
		for (row = 0; row < width; row++) {
			cout << "*";
			for (col = 1; col < length; col++) {
				cout << "*";
			}
			cout << endl;
		}
		cout << endl << endl;
	}

	~Rectangle() {
	}
};

class Manager {
private:

	Shape * arrShape[SIZE] = { nullptr }; // Manager owns the main data structure

public:

	Manager()
	{
		populateShapeData();
	}

	void populateShapeData() {
		char shapeType;
		int serialNumber;
		double measure1, measure2;

		ifstream inputFile;
		string fileName = "shaperecords.txt";
		inputFile.open(fileName);

		stringstream s1;
		string temp;
		int i = 0;

		if (inputFile) {
			while (getline(inputFile, temp)) {
				s1 << temp;
				s1 >> shapeType >> serialNumber >> measure1 >> measure2;
				if (shapeType == 'C') {
					arrShape[i] = new Circle(shapeType, serialNumber, measure1);
				}
				else if (shapeType == 'S') {
					arrShape[i] = new Spray(shapeType, serialNumber, measure1, measure2);
				}
				else if (shapeType == 'Q') {
					arrShape[i] = new Square(shapeType, serialNumber, measure1);
				}
				else if (shapeType == 'R') {
					arrShape[i] = new Rectangle(shapeType, serialNumber, measure1, measure2);
				}
				i++;
				s1.clear();
			}

		}
		else {
			cout << "Error opening file.";
		}

		inputFile.close();
	}

	void displayAll()
	{
		for (int i = 0; i < SIZE; i++) {
			arrShape[i]->draw();
		}
	}

	~Manager() {

		for (int i = 0; i < SIZE; i++) {
			if (arrShape[i] != nullptr) {
				delete arrShape[i];
			}
		}
	}
};

int main()
{

	Manager ms;
	ms.displayAll();

	system("pause");
	return 0;
}
