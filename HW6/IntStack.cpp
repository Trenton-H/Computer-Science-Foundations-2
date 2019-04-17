// File Name: assign6_tah138.cpp
//
// Author: Trenton Hohle
// Date: 12/5/17
// Assignment Number: 6
// CS 2308.256 Fall 2017
// Instructor: Yijuan Lu

#include <iostream>
#include "IntStack.h"
#include <cassert>

using namespace std;

//***********************************************************
// IntStack: Constructor, initializes the stack
// 
// No return
//***********************************************************

IntStack :: IntStack()
{
	head = NULL;
	
}

//***********************************************************
// push: adds a bracket to the stack
// num: variable to store the bracket to be added to the stack
// No return
//***********************************************************

void IntStack :: push(int num)
{
	assert(!isFull());
	Node *n = new Node;
	n-> data = num;
	n->next = head;
	head = n;
}

//***********************************************************
// pop: returns the top bracket from the stack
// 
// returns the top bracket
//***********************************************************

int IntStack :: pop()
{
	if(isEmpty())
		return 0;
	else
	{
		Node *p = head;
		head = head->next;
		int num = p->data;
		delete p;
		return num;
	}
}

//***********************************************************
// isFull: tells if the stack is full
// 
// returns true if full or false otherwise
//***********************************************************

bool IntStack :: isFull()
{
	return false;
}

//***********************************************************
// isEmpty: tells if the stack is empty
// 
// returns true if empty or false otherwise
//***********************************************************

bool IntStack :: isEmpty()
{
	return head == NULL;
}

//***********************************************************
// ~IntStack: Destructor, deletes the whole stack
// 
// No return
//***********************************************************

IntStack :: ~IntStack()
{
	while(head)
		int temp = pop();
}
