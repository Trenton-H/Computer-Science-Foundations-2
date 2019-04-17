/* 
File Name : Assign1_tah138.cpp

Author: Trenton Hohle
Date: 9/20/17
Assignment Number: 1
CS 2308..002
Instructor: Yijuan Lu

Initializes with the names, weights and speed it took the rats to do the maze.
It then computes the average weight for the rats, as well as who the fastest
and slowest rats are.
Outputs all the information of the rats, as well as the average weight,
the fastest and slowest rats.
*/
#include <iostream>
#include <iomanip>
using namespace std;

struct Rat
{
   string name;
   double weight;
   int time;
};

double averageWeight(Rat[]);
void ratSpeed(Rat[], string &, string &);

//***************************************************************************
//main: Initializes data, calls other functions, and makes statements.
//
//Returns 0.
//***************************************************************************


int main()
{
   Rat rat[9];
   
   rat[0].name = "Ben";
   rat[0].weight = 6.5;
   rat[0].time = 29;
   rat[1].name = "Fred";
   rat[1].weight = 5.8;
   rat[1].time = 31;
   rat[2].name = "Splinter";
   rat[2].weight = 7.7;
   rat[2].time = 33;
   rat[3].name = "Lima Bean";
   rat[3].weight = 6.5;
   rat[3].time = 27;
   rat[4].name = "Black Bean";
   rat[4].weight = 5.8;
   rat[4].time = 31;
   rat[5].name = "Pinto Bean";
   rat[5].weight = 7.7;
   rat[5].time = 33;
   rat[6].name = "Skat";
   rat[6].weight = 6.5;
   rat[6].time = 29;
   rat[7].name = "Big Pook";
   rat[7].weight = 9.8;
   rat[7].time = 34;
   rat[8].name = "Tiger";
   rat[8].weight = 7.7;
   rat[8].time = 33;
   
   string fastest = rat[0].name;
   string slowest = rat[0].name;
   
   for(int i=0; i<9; i++)
   {
   	   cout << rat[i].name << " - " << rat[i].weight << " - " << rat[i].time << endl;
   }
   
   cout << "\nAverage Weight: "<< fixed << setprecision(1) << averageWeight(rat) << endl;
   ratSpeed(rat, fastest, slowest);
   cout << "Fastest Rat: " << fastest << endl;
   cout << "Slowest Rat: " << slowest << endl;
   cout << endl;

   return 0;
}

//***************************************************************************
//averageWeight: calculates that average weight of the rats
//
//rat: the array of the rats and there accompanying information
//returns the average weight of the rats
//***************************************************************************

double averageWeight(Rat rat[])
{
   double average;
   for(int i=0; i<9; i++)
   {
   	   average += rat[i].weight;
   }
   return average/9;
}

//***************************************************************************
//ratSpeed: calculates who the fastest and slowest rats are
//
//rat: the array of the rats and there accompanying information
//fastest: reference variable of a default fastest rat
//slowest: reference variable of a default slowest rat
//no return
//***************************************************************************


void ratSpeed(Rat rat[], string& fastest, string &slowest)
{
   int slow = rat[0].time;
   int fast = rat[0].time;
   for(int i = 0; i<9; i++)
   {
   	   if(slow < rat[i].time)
   	   {
   	   	   slow = rat[i].time;
   	   	   slowest = rat[i].name;
	   }
	   if(fast > rat[i].time)
   	   {
   	   	   fast = rat[i].time;
   	   	   fastest = rat[i].name;
   	   }
   }
}
