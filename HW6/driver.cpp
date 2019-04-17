// File Name: assign6_tah138.cpp
//
// Author: Trenton Hohle
// Date: 12/5/17
// Assignment Number: 6
// CS 2308.256 Fall 2017
// Instructor: Yijuan Lu

#include <iostream>
#include "IntStack.h"
#include <fstream>
#include <string>

using namespace std;

//***********************************************************
// main: imports the file, checks that the file is open, scans the files
//       contents to find all the brackets, adds all the brackets to the stack
//       figures out if any brackets are missing or wrongly matched
// 
// returns 0
//***********************************************************

int main()
{
	string textfile;
	cout << "Enter the text file you would like to check:";
	getline(cin, textfile);
	
	ifstream fin (textfile.c_str());
	if(!fin)
	{
		cout << "error opening file!" << endl;
		return 0;
	}
	
	IntStack braces;
	
	getline(fin, textfile);
	fin.close();
	char brace;
	for(int i =0; i<textfile.length(); i++)
	{
		if(textfile[i] == '{' || textfile[i] == '(' || textfile[i] == '[')
			braces.push(textfile[i]);
		if(textfile[i] == '}' || textfile[i] == ')' || textfile[i] == ']')
		{
			if(braces.isEmpty())
			{
				cout << "There is no opening bracket only a closing one" << endl;
				return 0;
			}
			brace = braces.pop();
			
			if(brace == '[' && textfile[i] != ']' || brace == '{' && 
			   textfile[i] != '}' || brace == '(' && textfile[i] != ')')
			{
				if(brace == '[')
					cout << "Expected ]" << " found " << textfile[i] << endl;
				if(brace == '{')
					cout << "Expected }" << " found " << textfile[i] << endl;
				if(brace == '(')
					cout << "Expected )" << " found " << textfile[i] << endl;
				return 0;
			}
		}
	}
	
	if(braces.pop())
	{
		cout << "You are missing a closing bracket!" << endl;
		return 0;
	}
	else
		cout << "There was no error" << endl;
	return 0;
}
