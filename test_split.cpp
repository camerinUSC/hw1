/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>


Node *makeNode(int val)
{

Node *newNode = new Node;
newNode->value = val;
newNode->next = NULL;
return newNode;

}


void printNodes(Node* head){
  while(head != NULL){
    std::cout << head->value << std::endl;
    head = head->next;
  }
}
int main(int argc, char* argv[])
{

  Node* head = makeNode(5);
  head->next = makeNode(4);
  head->next->next = makeNode(3);
  head->next->next->next= makeNode(2);
  head->next->next->next->next = makeNode(1);
  head->next->next->next->next->next = makeNode(0);
  head->next->next->next->next->next->next= makeNode(10);

  Node *odds = NULL;
  Node *evens = NULL;

  split(head, odds, evens);


  std::cout << "odds: " << std::endl;
  printNodes(odds);

  std::cout << "evens: " << std::endl;
  printNodes(evens);

  while(head!=NULL){
    Node* temp = head;
    head = head->next;
    delete temp;
  }
  return 0;



}
