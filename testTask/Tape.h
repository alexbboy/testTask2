#include <list>
#include <iostream>
#include <fstream>
#include <array>
#pragma once

using namespace std;
class Tapeinterface
{
protected:
	int length;
	list<int> *head=new list<int>(length);
	list<int>::iterator iter = head->begin();
public:
	virtual void generate(string path,string path2) { length = 0; };
	~Tapeinterface() {
		delete head;
	}
	void move_forward() {
		iter++;
	};
	void move_back() {
		iter--;
	};
	bool checkSorted(list<int>* head) {
		int f = INT_MIN;
		for (auto iter = head->begin(); iter != head->end(); iter++) {
			if (*iter >= f) {
				f = *iter;
			}
			else
				return false;
		}
		return true;
	}
	
	
	list<int> sort(list<int> *head, int n) {
		ofstream output;
		output.open("output.txt");
		const int size = head->size() - 1;
		int* arraypart=new int(size);
		int j = 0;
		for (auto iter = head->begin(); iter != head->end(); iter++) {
			arraypart[j] = *iter;
			j++;

		}
		
		for (int i = 1; i < j; i++) {
			int key = arraypart[i];
			int j = i - 1;
			while (j > -1 && arraypart[j] > key) {
				arraypart[j + 1] = arraypart[j];
				j--;
			}
			arraypart[j + 1] = key;
		}
		list<int> part;
		
		for (int i = 0; i < j; i++) {
			part.push_back(arraypart[i]);
		}
		return part;

	};
};

//C:\Users\Алексей\source\repos\testTask\testTask\Tape.h

