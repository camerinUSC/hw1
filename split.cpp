/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>


/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE

// if in is NULL
  if(in == NULL){
    return;
  }

  // saving next value in the input array

  Node *newNode = in->next;

  // discarding original saved value since list DOES NOT
  // have to be preserved

  in->next = NULL;

  //even case

  if(in->value % 2 == 0){
    if(evens == NULL){
    evens = in;
    }

    else{
      evens->next = in;


    }
    split(newNode, odds, evens->next);

  }

  // odd case


  else{
    
    if(odds == NULL){
    odds = in;
    }

    else{
            odds->next = in;
    }

    split(newNode, odds->next, evens);


  }






// setting in to NULL after finishing
  in = NULL;


}

/* If you needed a helper function, write it here */
