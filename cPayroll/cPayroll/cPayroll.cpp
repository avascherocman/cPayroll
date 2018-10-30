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

int printMenu();
void addEmp(struct emp * emps, int num);
void viewEmp(struct emp*emps, int nf);
void printEmp(struct emp*emps, int num);

struct emp {
  std::string fname;
  std::string lname;
  float hours;
  float wage;
  int numDep;
  float id;
  float paid;
  float yearly;
};

int main()
{
  int numFilled = 0;
  emp emps[100];
  int choice = 0;
  do{
    choice = printMenu();
    switch (choice) {
    case 0:
      addEmp(emps, numFilled);
      break;
    case 1:
      break;
    case 2:
      viewEmp(emps, numFilled);
      break;
    }
  } while (choice != 3);
 
    return 0;
}

int printMenu() {
  std::cout <<
    "------------Payroll------------\n" <<
    "   0 Add employee(s)\n" <<
    "   1 Pay employees\n" <<
    "   2 View employees\n" <<
    "   3 Exit\n";

    int menuChoice;
    "Enter menu choice: ";
    std::cin>>menuChoice;
    return menuChoice;
}

void addEmp(struct emp * emps, int num) {
  std::cout << "Enter employee's first name. ";
  std::cin >> emps[num].fname;
  std::cout << std::endl;
  std::cout << "Enter employee's last name. ";
  std::cin >> emps[num].lname;
  std::cout << std::endl;
  std::cout << "Enter employee's hours. ";
  std::cin >> emps[num].hours;
  std::cout << std::endl;
  std::cout << "Enter employee's wage. ";
  std::cin >> emps[num].wage;
  std::cout << std::endl;
  std::cout << "Enter employee's ID num. ";
  std::cin >> emps[num].id;
  std::cout << std::endl;
  std::cout << "Enter employee's number of dependents ";
  std::cin >> emps[num].numDep;
  std::cout << std::endl;



}
void printEmp(struct emp*emps, int num) {
  std::cout << emps[num].fname << " " << emps[num].lname;
  std::cout << emps[num].wage << " " << emps[num].hours;

}
void viewEmp(struct emp*emps, int nf) {
  int num;
  std::cout << "Enter employee # you'd like to view ";
  std::cin >> num;
  if (num <= nf) {
    printEmp(emps, num);
  }
  else {
    std::cout << "Invalid input";
  }


}

