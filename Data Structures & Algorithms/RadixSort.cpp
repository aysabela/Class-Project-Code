/***************************************************************
Problem: Radix Sort
Question: what we did in class
Name: Alyssa Ysabela Flores and Wenjie Liu
ID: 1662110
Date: 10/24/18
Status: complete
****************************************************************/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	vector<int> myvec = { 987, 543, 219, 122, 4 };
	vector<vector<int>> Bucket(10);
	bool more = true;
	int level = 1;
	int pos = 0;
	const int BASE = 10;

	for (; more; ) 
	{
		more = false;
		for (int i : myvec) 
		{

			int pos = (i / level) % BASE;

			if (!more) 
			{
				more = i / level / BASE;
				
			}

			Bucket.at(pos).push_back(i);

		}
		level *= BASE;
		myvec.clear();
		for (int i = 0; i < 10; i++)
		{
			for (int q : Bucket.at(i))
			{
				myvec.push_back(q);
			}
	Bucket.at(i).clear();

	}
			}

	for (int i : myvec) {
		cout << i << endl;
	}

	system("pause");
}


	


	



