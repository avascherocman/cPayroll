// cPayroll.cpp : Defines the entry point for the console application.
/* Ava Scherocman 
   Payroll Project
   10 / 22 / 18
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

int main()
{
  int printMenu();
  

  int choice = printMenu();
  switch (choice) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    break;

  }
    return 0;
}

int printMenu() {
  std::cout <<
    "------------Payroll------------\n" <<
    "   0 Add employee(s)\n" <<
    "   1 Pay employees\n" <<
    "   2 View employees\n" <<
    "   3 ";

    int menuChoice;
    "Enter menu choice: ";
    std::cin>>menuChoice;
    return menuChoice;
}