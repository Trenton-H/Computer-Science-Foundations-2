// File Name: Question.h
//
// Author: Trenton Hohle
// Date: 11/4/2017
// Assignment Number:4
// CS 2308 Fall 2017
// Instructor: Yijuan Lu
//
// Header file for the Question Class.

#include <string>
using namespace std;


class Question
{
   private:
      string stem, answers[4];
      char key;
   public:
   	   Question();
   	   Question(string, string[], char);
   	   void setStem(string);
   	   string getStem();
   	   void setAnswers(string []);
   	   string getAnswer(int);
   	   void setKey(char);
	   char getKey();	   	   
   	   void display(int);
};
