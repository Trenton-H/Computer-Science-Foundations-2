// File Name: Question.cpp
//
// Author: Trenton Hohle
// Date: 11/04/2017
// Assignment Number:4
// CS 2308 Fall 2017
// Instructor: Yijuan Lu
//
// Function Definitions for the Question class.

#include <iostream>
#include <string>
using namespace std;
#include "Question.h"

//***********************************************************
// Question: Default Constructor
// 
// no return
//***********************************************************

Question :: Question ()
{
	stem = "";
	answers[0] = "";
	answers[1] = "";
	answers[2] = "";
	answers[3] = "";
	key = 'X';
}

//***********************************************************
// Question: Constructor with 3 elements passed to it
// question: variable to store the question for the quiz
// tempAnswers[]: array to hold question answer choices
// tempKey: variable to hold the correct question answer
// 
// no return
//***********************************************************

Question :: Question (string question, string tempAnswers[], char tempKey)
{
   stem = question;
   for(int i =0; i< 5; i++)
   {
      answers[i] = tempAnswers[i];
   }
   key = tempKey;
}

//***********************************************************
// setStem: setter for the stem variable
// s: temp variable to hold the question string
// 
// no return
//***********************************************************

void Question :: setStem(string s)
{
   stem = s;
}

//***********************************************************
// getStem: getter for the stem variable
// 
// returns stem variable string
//***********************************************************

string Question :: getStem()
{
   return stem;
}

//***********************************************************
// setAnswers: setter for the answer choices array
// a[]: array to hold the question options
//
// no return 
//***********************************************************

void Question :: setAnswers(string a[])
{
   answers[0] = a[0];
   answers[1] = a[1];
   answers[2] = a[2];
   answers[3] = a[3];
}

//***********************************************************
// getAnswer: determines which player scored the most points
// i: variable index to return the location of the spot
// 
// returns location of spot in answers array
//***********************************************************

string Question :: getAnswer(int i)
{
   return answers[i];
}

//***********************************************************
// setKey: setter for the variable key
// k: temp variable to hold the correct answer
//
// no return
//***********************************************************

void Question :: setKey(char k)
{
   key = k;
}

//***********************************************************
// getKey: getter for the variable key
// 
// returns the variable key
//***********************************************************

char Question :: getKey()
{
   return key;
} 

//***********************************************************
// display: displays the contents of the question instance
// i: the location of the question the user wants
//
// no return
//***********************************************************
	   
void Question :: display(int i)
{
      cout << i+1 << ". " << stem << "?" << endl;
      for(int j =0; j<4; j++)
      {
         cout << char('A'+j) << ". " << answers[j] << endl;
      }
   cout << endl;
}
