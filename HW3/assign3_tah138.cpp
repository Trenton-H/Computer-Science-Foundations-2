// File Name: assign3_tah138.cpp
//
// Author: Trenton Hohle
// Date: 10/18/2017
// Assignment Number: 3
// CS 2308.002 Fall 2017
// Instructor: Yijuan Lu
//
// Takes 3 arrays and determines if they are in ascending order or not.
// Then it uses points with a function to get back the feet and inches
// from the initial amount of total inches. Then it takes a signle array
// and doubles that array. Lastly, it takes an array and returns only 
// part of the whole array

#include <iostream>

using namespace std;

bool isSorted(int *, int);
double chain(int, int*, int*);
int *grow(int*, int);
int *subArray(int *, int, int);
int *duplicateArray(int *, int, int);
void displayArray(int*, int);

//***********************************************************
// main: Calls all the other functions and does all the outputting
// returns 0
//***********************************************************

int main()
{
	bool sortedResult = false;
	string resultAnswers = "";
	int size = 8;
	int array1[] = {1,2,3,4,5,6,7,8};
	int array2[] = {8,7,6,5,4,3,2,1};
	int array3[] = {1,2,3,5,4,6,7,8};
	int inchesTotal = 53;
	int inches = -1;
	int feet = -1;
	double inchFeet = -1.00;
	int *tempArray = NULL;
	int start = 4;
	int length = 4;
	
//Instruction say to only output in the main except to display the 
//arrays so... its a mess...
	
	cout << "testing isSorted: " << endl;
	cout << "test data array 1: ";
	displayArray(array1, size);
	cout << endl;
	cout << "Expected Result: true" << endl;
	sortedResult = isSorted(array1, size);
	if(sortedResult)
	   resultAnswers = "true";
	else
	   resultAnswers = "false";
	cout << "Actual Result: " << resultAnswers << endl;
	
	cout << "test data array 2: ";
	displayArray(array2, size);
	cout << endl;
	cout << "Expected Result: false" << endl;
	sortedResult = isSorted(array2, size);
	if(sortedResult)
	   resultAnswers = "true";
	else
	   resultAnswers = "false";
	cout << "Actual Result: " << resultAnswers << endl;
	
	cout << "test data array 3: ";
	displayArray(array3, size);
	cout << endl;
	cout << "Expected Result: false" << endl;
	sortedResult = isSorted(array3, size);
	if(sortedResult)
	   resultAnswers = "true";
	else
	   resultAnswers = "false";
	cout << "Actual Result: " << resultAnswers << endl;
	cout << endl;
	
	cout << "Testing chain for " << inchesTotal << " inches:" << endl;
	cout << "Expected result: 15.46 feet: 4 inches: 5" << endl;
	cout << "Actual results: " << chain(inchesTotal, &feet, &inches);
	cout << " feet: " << feet << " inches: " << inches << endl;
	cout << endl << endl;
	
	cout << "testing grow:" << endl;
	cout << "test data: ";
	displayArray(array1, size);
	cout << "\nExpected Result: 1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8" << endl;
	tempArray = grow(array1, size);
	cout << "Actual result: ";
	displayArray(tempArray, size*2);
	cout << endl << endl;

	cout << "testing subArray: " << endl;
	cout << "test data: ";
	displayArray(array1, size);
	cout << "\nstart: " << start << " length: " << length << endl;
	cout << "Expected result: 5 6 7 8" << endl;
	cout << "Actual Result: ";
	tempArray = subArray(array1, start, length);
	displayArray(tempArray, length);
	cout << endl;
	
	delete[] tempArray;
	tempArray = NULL;
	
	return 0;
}

//***********************************************************
// isSorted: determines if the passed array is in ascending order or not.
// array: array of the integer numbers to test
// size: the size of the array
// returns true for ascending order or false for not
//***********************************************************

bool isSorted(int *array, int size)
{
	bool test = true;
	for(int i = 1; i<size; i++)
	{
	   if(*(array + (i-1))> *(array+i))
	      test = false;
	}
	return test;
}

//***********************************************************
// chain: breaks the total inches down into feet and inches
// totalInches: total amount of inches initially passed to the function
// feet: pointer to return the total whole number of feet
// inches: pointer to return the remainder of inches
// returns returns feet * 3.49 + inches * .3
//***********************************************************

double chain( int totalInches, int *feet, int *inches)
{
	*feet = totalInches / 12;
	*inches = totalInches%12;
	return *feet*3.49 + *inches*.30;
}

//***********************************************************
// grow: takes the passed array and doubles it
// integerArray: the array that is passed to the function
// size: size of the array passed
// returns the location of the doubled array
//***********************************************************

int *grow(int *integerArray, int size)
{
	int *newArray = new int [size*2];
	int counter = 0;
	
	for(int i = 0; i<size; i++)
	{
	   *(newArray + counter) = *(integerArray + i);
	   counter++;
	   *(newArray + counter) = *(integerArray + i);
	   counter++;
	}
	return newArray;
}

//***********************************************************
// subArray: take an initial array and break it into a smaller subsection
//           of the array 
// array: initial array passed to be broken down
// start: starting point in the initial array for the broken down one
// length: end point of the broken down array to be taken from the 
//         initial array
// returns the location of the broken down array
//***********************************************************

int *subArray(int *array, int start, int length)
{
   int *result = duplicateArray(array,start, length);
   return result;
}

//***********************************************************
// duplicateArray: function that actually copies items from the initial 
//                 array into a new array
// arr: initial array
// start: starting point in the array
// size: end point of initial array / length of new array
// returns location of the smaller subarray
//***********************************************************

int *duplicateArray(int *arr,int start, int size)
{
	int *newArray = new int [size];
	if(size <= 0)
	   return NULL;
	
	for(int index=0; index<size; index++)
	{
	   *(newArray + index) = *(arr+start);
	   start++;
	}
	return newArray;
}

//***********************************************************
// displayArray: displays arrays that are passed to it 
// array: location of the array to display
// size: size of the array
// no return
//***********************************************************

void displayArray(int *array, int size)
{
	for(int i = 0; i<size; i++)
	   cout << *(array + i) << " ";
}
