// File Name: StringList.cpp
//
// Author: Trenton Hohle
// Date: 10/16/17
// Assignment Number: 5
// CS 2308.256 Fall 2017
// Instructor: Yijuan Lu
//
// Functions that go with the StringList.h file

#include <iostream>
#include <string>
#include "StringList.h"

using namespace std;

//***********************************************************
// StringList: Initializes string class instances

// No return
//***********************************************************

StringList :: StringList()
{
   head = NULL;
}

//***********************************************************
// ~StringList: Destroys StringList classes at the end of the program

// No return
//***********************************************************

StringList :: ~StringList()
{
   StringNode *p = head;
   while(p)
   {
      head = head->next;
      delete p;
      p = head;
   }
}

//***********************************************************
// count(): counts how many links are on the linked list
//
// returns: Numbers of links
//***********************************************************

int StringList :: count()
{
   int count = 0;
   StringNode *p = head;
   while(p)
   {
      count++;
      p = p->next;
   }
   return count;
}

//***********************************************************
// add(): adds data to the end of the linked list
// adding: the data to add to the linked list
// returns: none
//***********************************************************

void StringList :: add(string adding)
{
   StringNode *p = head;
   StringNode *n = NULL;
   StringNode *newNode = new StringNode;
   newNode->data = adding;
   newNode->next = NULL;
   while(p)
   {
   	  n=p;
      p = p->next;
   }
   if(p==head)
   {
      head = newNode;
   }
   else
   {
      n->next = newNode;
   }
}

//***********************************************************
// remove(): removes a bit of data from the linked list if it exists
// removing: the bit of data that needs to be removed
// returns: boolean return if it removes something or not
//***********************************************************

bool StringList :: remove(string removing)
{
   bool worked = false;
   StringNode *p = head;
   StringNode *n = NULL;
   while((p->data!=removing) && (p!=NULL))
   {
      n=p;
      p=p->next;
   }
   if(p==head && p->next==NULL)
   {
      head = NULL;
      delete p;
      worked = true;
   }
   else if(p==head)
   {
      head=head->next;
      delete p;
      worked = true;
   }
   else if(p!= NULL)
   {
      n->next = p->next;
      delete p;
      worked = true;
   }
   return worked;
}

//***********************************************************
// display(): displays the entire lined list each on a different line
//
// returns: none
//***********************************************************

void StringList :: display()
{
   StringNode *p = head;
   while(p)
   {
      cout << p->data << endl;
      p = p->next;
   }
}

//***********************************************************
// minimum(): finds and returns the minimum value of the linked list
//
// returns: a string bit of data of the minimum value of the list
//***********************************************************

string StringList :: minimum()
{
   string min;
   if(head!=NULL)
   {
      min = head->data;
      StringNode *p = head;
      while(p)
      {
         if(min > p->data)
            min = p->data;
      
         p = p->next;
      }
   }
   else if(head==NULL)
   {
      min = "";
   }

   return min;
}

//***********************************************************
// sort(): sorts the linked list into a new list in ascending ASCII order
//
// returns: none
//***********************************************************

void StringList :: sort()
{
   StringNode *p = head;
   StringNode *newNode = new StringNode;
   StringNode *newHead = NULL;
   StringNode *n = newHead;
   
   newHead->data = minimum();
   newHead->next = NULL;
   remove(newHead->data);
   while(p)
   {
      newNode->data = minimum();
      remove(newNode->data);
      newNode -> next = NULL;

      n->next = newNode;
   }
   head = newHead;
}
