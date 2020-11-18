//ALYSSA'S CODE
#include <iostream>

using namespace std;

template<typename T1, typename T2>
class Pair {
public:
	Pair *next;
	T1 key;
	T2 value;

	Pair<T1, T2>() = default;

	Pair<T1, T2>(T1 k, T2 v) {
		key = k;
		value = v;
	}

	void setKey(T1 k) {
		key = k;
	}

	void setVal(T2 v) {
		value = v;
	}
};

template<typename T1, typename T2>
class myMap {
public:

	Pair<T1, T2> *head;

	myMap() {
		head = nullptr;
	}

	Pair<T1, T2> *begin() {
		return head;
	}

	Pair<T1, T2> *end() {
		return nullptr;
	}

	void display() {
		cout << "Alyssa's Map Code contains: " << endl;
		Pair<T1, T2> *nodePtr = head;
		Pair<T1, T2> *previousNode = nullptr;
		while (nodePtr) {
			cout << nodePtr->key << " -> " << nodePtr->value << endl;
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
	}

	bool insert(Pair<T1, T2> pa) {
		bool b = false;
		Pair<T1, T2> *newNode;
		Pair<T1, T2> *nodePtr;
		Pair<T1, T2> *previousNode = nullptr;


		newNode = new Pair<T1, T2>;
		newNode->setKey(pa.key);
		newNode->setVal(pa.value);
		b = false;

		if (!head || (head->key > pa.key)) {
			newNode->next = head;
			head = newNode;
			b = true;
		}
		else
		{

			nodePtr = head;
			previousNode = nullptr;

			if (find(pa.key) == end()) {
				while (nodePtr != nullptr && nodePtr->key < pa.key) {
					previousNode = nodePtr;
					nodePtr = nodePtr->next;
				}

				previousNode->next = newNode;
				newNode->next = nodePtr;
				b = true;
			}
			else {
				b = false;
			}


		}

		return b;
	}

	
	Pair<T1, T2> *find(T1 key) /// Return a pointer
	{
		Pair<T1, T2> *nodePtr = head;
		while (nodePtr) {
			if (nodePtr->key == key) {
				cout << nodePtr->key << " with value " << nodePtr->value << " has been found." << endl;
				return nodePtr;
			}
			nodePtr = nodePtr->next;
			if (!nodePtr) {
				return nullptr;
			}
		}
	}

};

//Professor's test code for main
int main() {

	myMap<char, int> myMap;

	myMap.insert(Pair<char, int>('z', 900));
	myMap.insert(Pair<char, int>('a', 100));
	myMap.insert(Pair<char, int>('c', 300));

	 bool ret = myMap.insert(Pair<char, int>('z', 500));  /// This insertion should fail since the key exists
	 if (ret == false) {
		 cout << "element 'z' already existed" << endl;
	 } else  /// True
		 cout << "It is inserted.";

	 myMap.find('c'); // Return a pointer which points to the 'c' element
	 myMap.find('x'); // Return a nullptr to indicate that the element cannot be found.
		 
	 myMap.display();

	system("pause");
	return 0;
}