// File Name: QuizDriver.cpp
//
// Author: Trenton Hohle
// Date: 11/04/2017
// Assignment Number:4
// CS 2308 Fall 2017
// Instructor: Yijuan Lu
//
// Driver to test the Question class.

#include <iostream>
#include "Question.h"

using namespace std;

//***********************************************************
// Main: Driver for the Question Class
//
// returns 0
//***********************************************************

int main()
{
    Question test1[5];

    test1[0].setStem("What name is given to half of a byte (4 bytes)?");
    string test1Answers[] = {"Nibble", "Ort", "Scrap", "Snippet"};
    test1[0].setAnswers(test1Answers);
    test1[0].setKey('A');
    
    test1[1].setStem("Which Country is home to the Kangaroo?");
    test1Answers[0] = "China";
    test1Answers[1] = "India";
    test1Answers[2] = "Mexico";
    test1Answers[3] = "Australia";
    test1[1].setAnswers(test1Answers);
    test1[1].setKey('D');
    
    test1[2].setStem("What do you use to measure an angle?");
    test1Answers[0] = "Compass";
    test1Answers[1] = "Protractor";
    test1Answers[2] = "Ruler";
    test1Answers[3] = "T-Square";
    test1[2].setAnswers(test1Answers);
    test1[2].setKey('B');
    
    test1[3].setStem("The Great Sphinx has the head of a human and the body of a what?");
    test1Answers[0] = "Camel";
    test1Answers[1] = "Eagle";
    test1Answers[2] = "Lion";
    test1Answers[3] = "Alligator";
    test1[3].setAnswers(test1Answers);
    test1[3].setKey('C');
    
    test1[4].setStem("What is the flat rubber disc used in a game of ice hockey?");
    test1Answers[0] = "Birdie";
    test1Answers[1] = "Puck";
    test1Answers[2] = "Dart";
    test1Answers[3] = "Tile";
    test1[4].setAnswers(test1Answers);
    test1[4].setKey('B');

    for(int i =0; i<5; i++)
       test1[i].display(i);

	
	cout << "Answers:" << endl;
	for(int i = 0; i<5; i++)
	   cout << test1[i].getKey() << " ";
}
