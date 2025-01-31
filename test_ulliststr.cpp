#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{

  ULListStr test;

  test.push_back("C");
  test.push_back("A");
  test.push_back("M");

  test.push_front("1");
  test.push_front("2");
  test.push_front("3");

  std::cout << "Front: " << test.front() << std::endl;
  std::cout << "Back: " << test.back() << std::endl;
  std::cout << "Size: " << test.size() << std::endl;

  std::cout << "Popping front:" << std::endl;
  test.pop_front();
  std::cout << "New front:" << test.front() << std::endl;

  std::cout << "Popping back:" << std::endl;
  test.pop_back();
  std::cout << "New back:" << test.back() << std::endl;


}
