#include <iostream>
#include <string>
#include <random>

using namespace std; 

const int SIZE = 10;
int ** getRandomInt()
{

	random_device rd;
	default_random_engine generator(rd());
	uniform_int_distribution<int> distribution(1, 100);
	int dice_roll = distribution(generator);	int *pp[SIZE]; 		for (int i = 0; i < SIZE; i++) {
		uniform_int_distribution<int> distribution(1, 100);
		int dice_roll = distribution(generator);
			 pp[i] = new int;
			*pp[i] = dice_roll;
		}		return pp;
}
void displayInt(int ** pp)
{
	for (int i = 0; i < SIZE; i++) {
			cout << *pp[i] << " ";
	}
}
void deleteInt(int ** pp)
{
	for (int i = 0; i < SIZE; i++) {
		if (pp[i] != nullptr) {
			delete pp[i];
		}
	}
}
int main()
{
	int ** pp = getRandomInt();
	displayInt(pp);
	deleteInt(pp);
	system("pause");
	return 0;
}

