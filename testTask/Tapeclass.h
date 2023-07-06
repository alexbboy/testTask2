#include "Tape.h"
#include <iostream>
#include <fstream>

#pragma once
using namespace std;
class Tapeclass :public Tapeinterface
{
public: 
	void generate(string inputname,string outputname) {
		ifstream file;
		string filepath = "C:\\Users\\Алексей\\source\\repos\\testTask\\" + inputname;
		string fileoutput = "C:\\Users\\Алексей\\source\\repos\\testTask\\" + outputname;
		file.open(filepath);

		list<int> part;
		int iter = 0;
		int first = 0;
		while (!file.eof()) {
			int j = 0;
			file >> j;
			
			if (iter == 0) {
				first = j;
				iter++;
				}
			else
				if(j<first)
				part.push_back(j);
			

		}
		part = sort(&part, part.size());
		file.close();
		ofstream outputfile;
		outputfile.open(outputname);
		iter = 0;
		first = 0;
		int count = 0;
	
		for (auto iter = part.begin(); iter != part.end();iter++) {
			
			outputfile << *iter<<endl;
			count++;
			
		}
		for (int i = 0; i < count; i++) {
			part.pop_back();
		}
		ifstream file2;
		count = 0;
		iter = 0;

		file2.open(filepath);

		while (!file2.eof()) {
			int j = 0;
			file2 >> j;

			if (iter == 0) {
				first = j;
				iter++;
			}
			
				if (j >= first)
					part.push_back(j);


		}
		part = sort(&part, part.size());
		for (auto iter = part.begin(); iter != part.end(); iter++) {

			outputfile << *iter<<endl;
			count++;
			int size = part.size();
		}
		for (int i = 0; i < count; i++) {
			part.pop_back();
		}

	}

};

