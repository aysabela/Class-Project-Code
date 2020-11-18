/* Part 4 Questions
1. We put the entire template class in the .h file because class templates need both the declaration and definition for the compiler to compile the template

2. When you divide two doubles, you will properly get the divided answer. However, taking the division of two integers will give you the remainder as opposed to the actual
value you would want out of the quotient.


*/
#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <sstream>

using namespace std;

template <class T>
T randomPick(T x, T y, T z) {
	T result;
	random_device rd;
	default_random_engine generator(rd());
	uniform_int_distribution<int> distribution(1, 3);
	int dice_roll = distribution(generator);
	if (dice_roll == 1) {
		result = x;
	}
	else if (dice_roll == 2) {
		result = y;
	}
	else {
		result = z;
	}
	return result;
}

template <class T>
T getChoice(string a, string b, T x, T y) {
	string s1 = " ";
	do {
		cout << a << " or " << b << "? ";
		getline(cin, s1);

	} while ((s1 != a) && (s1 != b));
	return (s1.compare(a) == 0 ? x : y);
}

template <class T>
class UniqueList {
private:
	vector<T> vec;

public:
	void insert(T x) {
		if (find(vec.begin(), vec.end(), x) == vec.end()) {
			vec.push_back(x);
		}
		else cout << "Error. Item entered: " << x << " already exists. No changes made." << endl << endl;
	}

	void display() {
		for (int i = 0; i < vec.size(); i++) {
			cout << vec.at(i) << endl;
		}
	}

	int Size() {
		return vec.size();
	}

	T getFirst() {
		return vec.front();
	}

	T getLast() {
		return vec.back();
	}

	T getMin() {
		T min = vec.at(0);
		for (int i = 0; i < vec.size(); i++) {
			if (vec.at(i) < min || vec.at(i).size() < min.size()) {
				min = vec.at(i);
			}
		}
		return min;
	}


	T getMax() {
		T max = vec.at(0);
		for (int i = 0; i < vec.size(); i++) {
			if (vec.at(i) > max || vec.at(i).size() < max.size()) {
				max = vec.at(i);
			}
		}
		return max;
	}
};

int main()

{

	cout << "Part 1" << endl;
	cout << randomPick('1', '2', '3') << endl;
	cout << randomPick(11, 22, 33) << endl;
	cout << randomPick("Mac", "PC", "Others") << endl << endl;


	cout << "Part 2" << endl;
	cout << getChoice("x", "y", 1, 2) << endl << endl;

	/// User enters z -> system fails to get a choice

	/// User enters y -> system returns 2


	cout << "Part 3" << endl;
	UniqueList <string> u;
	u.insert("11");
	u.insert("12");
	u.insert("23");
	u.insert("40");
	u.insert("9");
	u.insert("12");
	u.display();
	cout << endl;

	cout << "The size of UniqueList is " << u.Size() << endl;
	cout << "The first element of UniqueList is " << u.getFirst() << endl;
	cout << "The last element of UniqueList is " << u.getLast() << endl;
	cout << "The min element of UniqueList is " << u.getMin() << endl;


	system("pause");
	return 0;

}