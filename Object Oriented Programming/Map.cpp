#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;


int main()
{
	string word;
	ifstream inputFile;
	inputFile.open("NotesBetweenTwoSisters.txt");
	map<string, int> myMap;
	map<string, int>::iterator it = myMap.begin();
	map<string, int>::iterator it1;

	
	if (inputFile) {
		while (inputFile >> word) {
			for (int i = 0; i < word.length(); ++i) {
				if (ispunct(word[i])) {
					word.erase(i);
				}
				else {
					it1 = myMap.find("");
					if (it1 != myMap.end())
						myMap.erase(it1);
				}
			}
			transform(word.begin(), word.end(), word.begin(), ::tolower);
			++myMap[word]; 
		}
	}
	else {
		cout << "Error opening file.";
	}

	inputFile.close();
	
	cout << "Alyssa's Map Code contains: " << endl;
	for (it = myMap.begin(); it != myMap.end(); it++) {
		cout << setw(10) << it->first << setw(5) << it->second << endl;
	}

	system("pause");
	return 0;

}
