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
void importEmp(struct emp*emps);
void exportEmp(struct emp*emps, int nf);
void payEmp(struct emp*emps);

struct emp {
  std::string firstName;
  std::string lastName;
  float hoursPerWeek;
  float wage;
  int numDependents;
  int id;
  float ytdGross;
  float ytdNet;
  int fTaxBracket;
  int sTaxBracket;
  int lTaxBracket;
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
      numFilled++;
      break;
    case 1:
      payEmp(emps);
      break;
    case 2:
      viewEmp(emps, numFilled);
    case 3:
      exportEmp(emps);
    }
  } while (choice != 4);
 
    return 0;
}

int printMenu() {
  std::cout <<
    "------------Payroll------------\n" <<
    "   0 Add employee(s)\n" <<
    "   1 Pay employees\n" <<
    "   2 View employees\n" <<
    "   3 Save\n"<<
    "   4 Exit";

    int menuChoice;
    "Enter menu choice: ";
    std::cin>>menuChoice;
    return menuChoice;
}

void addEmp(struct emp * emps, int num) {
  std::cout << "Enter employee's first name. ";
  std::cin >> emps[num].firstName;
  std::cout << std::endl;
  std::cout << "Enter employee's last name. ";
  std::cin >> emps[num].lastName;
  std::cout << std::endl;
  std::cout << "Enter employee's hours. ";
  std::cin >> emps[num].hoursPerWeek;
  std::cout << std::endl;
  std::cout << "Enter employee's wage. ";
  std::cin >> emps[num].wage;
  std::cout << std::endl;
  std::cout << "Enter employee's ID num. ";
  std::cin >> emps[num].id;
  std::cout << std::endl;
  std::cout << "Enter employee's number of dependents ";
  std::cin >> emps[num].numDependents;
  std::cout << std::endl;



}
void printEmp(struct emp*emps, int num) {
  std::cout <<std::setprecision(2)<< std::setw(20) << std::setiosflags('left') << emps[num].firstName <<
    std::setw(20) << std::setiosflags('left') << emps[num].lastName <<
    std::setw(8) << std::setiosflags('left') << emps[num].hoursPerWeek <<
    std::setw(8) << std::setiosflags('left') << emps[num].wage <<
    std::setw(8) << std::setiosflags('left') << emps[num].numDependents <<
    std::setw(20) << std::setiosflags('left') << emps[num].id <<std::endl;


}
void viewEmp(struct emp*emps, int nf) {
  std::string v;
  std::cout << "Enter employee # you'd like to view, or enter 'A' for all " << std::endl;
  std::cin.ignore(1000, '\n');
  std::getline(std::cin, v);
  std::cout << std::setprecision(2) << std::setw(20) << std::setiosflags('left') << "First Name" <<
    std::setw(20) << std::setiosflags('left') << "Last Name" <<
    std::setw(8) << std::setiosflags('left') << "Hours" <<
    std::setw(8) << std::setiosflags('left') << "Wage" <<
    std::setw(8) << std::setiosflags('left') << "#Dependents" <<
    std::setw(20) << std::setiosflags('left') << "ID $"<<std::endl;


  if (v== "A") {
    for (int i = 0; i < nf; i++) {
      printEmp(emps, 0);
    }

  }
  else {
    int numV = std::stoi(v);
    printEmp(emps, numV);
  }



}
void importEmp(struct emp*emps) {
  std::string filename;
  std::cout << "Enter name of file.";
  std::cin >> filename;

  std::ifstream employees(filename);
  if (employees.is_open()) {
    //std::getline();
  }
}

void exportEmp(struct emp*emps, int nf) {
  std::ofstream empFile("Employees.txt");
  if (empFile.is_open()) {
    for (int i = 0; i < nf; i++) {

    }
  }
}
void payEmp(struct emp *emps) {

}