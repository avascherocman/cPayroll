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
void importEmp(struct emp*emps, int & numFilled);
void exportEmp(struct emp*emps, int nf);
void payEmp(struct emp*emps, int nf);
void printEmpHeader();

struct emp {
  std::string firstName;
  std::string lastName;
  float hoursPerWeek;
  float wage;
  int numDependents;
  int id;
  float weeklyGross;              //
  float weeklyNet;               // calculated values by program - imported and exported, but not
  float ytdGross;               // outputted into stream
  float ytdNet;                //
  float fTaxBracket;            //
  float sTaxBracket;           //
  float lTaxBracket;          //      
};

int main()
{
  int numFilled;
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
      payEmp(emps, numFilled);
      break;
    case 2:
      viewEmp(emps, numFilled);
      break;
    case 3:
      exportEmp(emps, numFilled);
      break;
    case 4:
      importEmp(emps, numFilled);
      break;
    }
  } while (choice != 5);
 
    return 0;
}

int printMenu() {
  std::cout <<
    "------------Payroll------------\n" <<
    "   0 Add employee(s)\n" <<
    "   1 Pay employees\n" <<
    "   2 View employees\n" <<
    "   3 Save\n" <<
    "   4 Import\n" <<
    "   5 Exit" << std::endl;

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
  emps[num].weeklyGross = 0;
  emps[num].weeklyNet = 0;
  emps[num].ytdGross = 0;
  emps[num].ytdNet = 0;
  emps[num].fTaxBracket = 0;
  emps[num].sTaxBracket = 0;
  emps[num].lTaxBracket = 0;


}
void printEmp(struct emp*emps, int num) {
  std::cout << std::setprecision(2) << std::setw(20) << std::setiosflags('left') << emps[num].firstName <<
    std::setw(20) << std::setiosflags('left') << emps[num].lastName <<
    std::setw(8) << std::setiosflags('left') << emps[num].hoursPerWeek <<
    std::setw(8) << std::setiosflags('left') << emps[num].wage <<
    std::setw(16) << std::setiosflags('left') << emps[num].numDependents <<
    std::setw(8) << std::setiosflags('left') << emps[num].id << std::setprecision(0)<<
    std::setw(4) << std::setiosflags('left') << emps[num].fTaxBracket <<
    std::setw(4) << std::setiosflags('left') << emps[num].sTaxBracket <<
    std::setw(4) << std::setiosflags('left') << emps[num].lTaxBracket << std::endl;

}
void viewEmp(struct emp*emps, int nf) {
  std::string v;
  std::cout << "Enter employee # you'd like to view, or enter 'A' for all " << std::endl;
  std::cin.ignore(1000, '\n');
  std::getline(std::cin, v);
  printEmpHeader();


  if (v== "A") {
    for (int i = 0; i < nf; i++) {
      printEmp(emps, i);
    }

  }
  else {
    int numV = std::stoi(v);
    printEmp(emps, numV);
  }

}
void importEmp(struct emp*emps, int & numFilled) {
  printEmpHeader();
  int ln = 0;
  std::ifstream empFile("Employees.txt");
  if (empFile.is_open()) {
    std::string line;
    int i = 0;
   do {
      for (int j = 0; j < 13; j++) {
        std::getline(empFile, line);
        ln++;
        switch (j) {
        case 0:
          emps[i].firstName = line;
          break;
        case 1:
          emps[i].lastName = line;
          break;
        case 2:
          emps[i].hoursPerWeek = std::stoi(line);
          break;
        case 3:
          emps[i].wage = std::stof(line);
          break;
        case 4:
          emps[i].numDependents = std::stoi(line);
          break;
        case 5:
          emps[i].id = std::stoi(line);
          break;
        case 6:
          emps[i].weeklyGross = std::stof(line);
          break;
        case 7:
          emps[i].weeklyNet = std::stof(line);
          break;
        case 8:
          emps[i].ytdGross = std::stof(line);
          break;
        case 9:
          emps[i].ytdNet = std::stof(line);
          break;
        case 10:
          emps[i].fTaxBracket = std::stof(line);
          break;
        case 11:
          emps[i].sTaxBracket = std::stof(line);
          break;
        case 12:
          emps[i].lTaxBracket = std::stof(line);
          break;
        }
      }printEmp(emps, i);
      i++;
   } while (!empFile.eof());
   numFilled = i;
   empFile.close();
  }
}
void exportEmp(struct emp*emps, int nf) {
  std::ofstream empFile("Employees.txt");
  if (empFile.is_open()) {
    for (int i = 0; i < nf; i++) { 
      if (i == nf - 1) {
        empFile << emps[i].firstName << "\n";
        empFile << emps[i].lastName << "\n";
        empFile << emps[i].hoursPerWeek << "\n";
        empFile << emps[i].wage << "\n";
        empFile << emps[i].numDependents << "\n";         //13 pieces of data total
        empFile << emps[i].id << "\n";
        empFile << emps[i].weeklyGross << "\n";
        empFile << emps[i].weeklyNet << "\n";
        empFile << emps[i].ytdGross << "\n";
        empFile << emps[i].ytdNet << "\n";
        empFile << emps[i].fTaxBracket << "\n";
        empFile << emps[i].sTaxBracket << "\n";
        empFile << emps[i].lTaxBracket;
      }
      else {
        empFile << emps[i].firstName << "\n";
        empFile << emps[i].lastName << "\n";
        empFile << emps[i].hoursPerWeek << "\n";
        empFile << emps[i].wage << "\n";
        empFile << emps[i].numDependents << "\n";         //13 pieces of data total
        empFile << emps[i].id << "\n";
        empFile << emps[i].weeklyGross << "\n";
        empFile << emps[i].weeklyNet << "\n";
        empFile << emps[i].ytdGross << "\n";
        empFile << emps[i].ytdNet << "\n";
        empFile << emps[i].fTaxBracket << "\n";
        empFile << emps[i].sTaxBracket << "\n";
        empFile << emps[i].lTaxBracket << "\n";
      }
      
    }
  }
  empFile.close();
}
void payEmp(struct emp *emps, int nf) {
  //headers
  std::cout << std::setprecision(2) << std::setw(20) << std::setiosflags('left') << "First Name" <<
    std::setw(20) << std::setiosflags('left') << "Last Name" <<
    std::setw(8) << std::setiosflags('left') << "Hours" <<
    std::setw(8) << std::setiosflags('left') << "Wage" <<
    std::setw(12) << std::setiosflags('left') << "W Gross" <<
    std::setw(12) << std::setiosflags('left') << "W Net" <<
    std::setw(12) << std::setiosflags('left') << "YTD Gross" <<
    std::setw(12) << std::setiosflags('left') << "YTD Net" << std::endl;
 
  for (int i = 0; i < nf; i++) {
    emps[i].weeklyGross = emps[i].hoursPerWeek * emps[i].wage;
    emps[i].ytdGross += emps[i].weeklyGross;

    

    //set federal, state, and local tax brackets
    if (emps[i].weeklyGross * 52 <= 20000) {
      emps[i].fTaxBracket = 0;
      emps[i].sTaxBracket = 0;
      emps[i].lTaxBracket = 0;
    }
    else  if (emps[i].weeklyGross * 52 >= 20000 && emps[i].weeklyGross * 52 <= 50000) {
      emps[i].fTaxBracket = 1;
      emps[i].sTaxBracket = 1;
      emps[i].lTaxBracket = 1;
    }
    else {
      emps[i].fTaxBracket = 2;
      emps[i].sTaxBracket = 2;
      emps[i].lTaxBracket = 2;
    }
    std::cout << std::setprecision(2) << std::setw(20) << std::setiosflags('left') << emps[i].firstName <<
    std::setw(20) << std::setiosflags('left') << emps[i].lastName <<
      std::setw(8) << std::setiosflags('left') << emps[i].hoursPerWeek <<
      std::setw(8) << std::setiosflags('left') << emps[i].wage <<
      std::setw(12) << std::setiosflags('left') << emps[i].weeklyGross <<
      std::setw(12) << std::setiosflags('left') << emps[i].weeklyNet<<
      std::setw(12) << std::setiosflags('left') << emps[i].ytdGross <<
      std::setw(12) << std::setiosflags('left') << emps[i].ytdNet << std::endl;

  } 

}
void printEmpHeader() {
  std::cout << std::setprecision(2) << std::setw(20) << std::setiosflags('left') << "First Name" <<
    std::setw(20) << std::setiosflags('left') << "Last Name" <<
    std::setw(8) << std::setiosflags('left') << "Hours" <<
    std::setw(8) << std::setiosflags('left') << "Wage" <<
    std::setw(16) << std::setiosflags('left') << "#Dependents" <<
    std::setw(8) << std::setiosflags('left') << "ID #" <<
    std::setw(4) << std::setiosflags('left') << "F" <<
    std::setw(4) << std::setiosflags('left') << "S" <<
    std::setw(4) << std::setiosflags('left') << "L" << std::endl;

}
