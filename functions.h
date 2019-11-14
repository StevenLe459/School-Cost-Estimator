#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "Student.h"
#include "input_validation.h"
#include "color.h"
#include <iostream>
#include <string>
#include <vector>

void showMenu();
void showCostMenu(std::vector<Student*> &);
void showStudentMenu(std::vector<Student*> &);
void handleOption(std::string, std::vector<Student*> &);
void handleCost(std::string, std::vector<Student*> &);
void handleStudent(std::string, std::vector<Student*> &);
void showResult(std::vector<Student*>);

void showMenu() {
  set_color(99);
  std::cout << "----------Menu----------" << std::endl;
  std::cout << "Option A: Edit Cost Information" << std::endl;
  std::cout << "Option B: Edit Student Information" << std::endl;
  std::cout << "Option E: Exit" << std::endl;
  reset_color();
}

void handleOption(std::string userOption, std::vector<Student*> & vect) {
  if (userOption == "A" || userOption == "a") {
    showCostMenu(vect);
  }
  else if (userOption == "B" || userOption == "b") {
    showStudentMenu(vect);
  }
  else if (userOption == "E" || userOption == "e") {
    std::cout << "Goodbye!" << std::endl;
  }
  else {
    std::cout << "Invalid option. Please try again." << std::endl;
  }
}

void showCostMenu(std::vector<Student*> & vect) {
  std::string option;
  set_color(177);
  std::cout << "----------Cost Menu----------" << std::endl;
  std::cout << "Option A: Edit cost per credit hour" << std::endl;
  std::cout << "Option B: Edit book cost per class" << std::endl;
  std::cout << "Option C: Edit room and board cost per month" << std::endl;
  std::cout << "Option D: Edit food cost per month" << std::endl;
  std::cout << "Option E: Edit travel cost per month" << std::endl;
  std::cout << "Option R: Return" << std::endl;
  reset_color();
  std::cout << "Please enter your option: ";
  std::cin >> option;
  handleCost(option, vect);
}

void handleCost(std::string userOption, std::vector<Student*> & vect) {
  double d;
  if (userOption == "A" || userOption == "a") {
    std::cout << "Please enter a cost." << std::endl;
    d = validateDouble(d);
    for (Student *s : vect) {
      s->semester.setCostCredit(d);
    }
  }
  else if (userOption == "B" || userOption == "b") {
    std::cout << "Please enter the book cost." << std::endl;
    d = validateDouble(d);
    for (Student *s : vect) {
      s->semester.setBook(d);   
    }
  }
  else if (userOption == "C" || userOption == "c") {
    std::cout << "Please enter the room and board cost." << std::endl;
    d = validateDouble(d);
    for (Student *s : vect) {
      s->semester.setRoomBoard(d);
    }
  }
  else if (userOption == "D" || userOption == "d") {
    std::cout << "Please enter the food cost." << std::endl;
    d = validateDouble(d);
    for (Student *s : vect) {
      s->semester.setFood(d);
    }
  }
  else if (userOption == "E" || userOption == "e") {
    std::cout << "Please enter the travel cost." << std::endl;
    d = validateDouble(d);
    for (Student *s : vect) {
      s->semester.setTravel(d);
    }
  }
  else if (userOption == "R" || userOption == "r") {
    ;
  }
  else {
    std::cout << "Invalid option." << std::endl;
  }
}

void showStudentMenu(std::vector<Student*> & vect) {
  std::string option;
  set_color(148);
  std::cout << "----------Student Menu----------" << std::endl;
  std::cout << "Option A: Edit hours per class" << std::endl;
  std::cout << "Option B: Edit months in a semester" << std::endl;
  std::cout << "Option C: Edit hours a full time student takes" << std::endl;
  std::cout << "Option D: Edit hours a part time student takes" << std::endl;
  std::cout << "Option E: Edit hours a half time student takes" << std::endl;
  std::cout << "Option F: Edit hours in a degree" << std::endl;
  std::cout << "Option G: Edit semesters in a year" << std::endl;
  std::cout << "Option H: Edit school name" << std::endl;
  std::cout << "Option R: Return" << std::endl;
  reset_color();
  std::cout << "Please enter your option: ";
  std::cin >> option;
  handleStudent(option, vect);
}

void handleStudent(std::string userOption, std::vector<Student*> & vect) {
  int i;
  std::string str;
  if (userOption == "A" || userOption == "a") {
    std::cout << "Please enter the hours per class." << std::endl;
    i = validateInt(i);
    for (Student *s : vect) {
      s->setHoursPerClass(i);
    }
  }
  else if (userOption == "B" || userOption == "b") {
    std::cout << "Please enter the months in a semester." << std::endl;
    i = validateInt(i);
    for (Student *s : vect) {
      s->setMonthsInSemester(i);
    }
  }
  else if (userOption == "C" || userOption == "c") {
    std::cout << "Please enter the hours a full time student takes." << std::endl;
    i = validateInt(i);
    vect[0]->setHoursTaken(i);
  }
  else if (userOption == "D" || userOption == "d") {
    std::cout << "Please enter the hours a part time student takes." << std::endl;
    i = validateInt(i);
    vect[1]->setHoursTaken(i);
  }
  else if (userOption == "E" || userOption == "e") {
    std::cout << "Please enter the hours a part time student takes." << std::endl;
    i = validateInt(i);
    vect[2]->setHoursTaken(i);
  }
  else if (userOption == "F" || userOption == "f") {
    std::cout << "Please enter the hours in a degree." << std::endl;
    i = validateInt(i);
    for (Student *s : vect) {
      s->setHoursInDegree(i);
    }
  }
  else if (userOption == "G" || userOption == "g") {
    std::cout << "Please enter the semesters in a year." << std::endl;
    i = validateInt(i);
    for (Student *s : vect) {
      s->setSemestersInYear(i);
    }
  }
  else if (userOption == "H" || userOption == "h") {
    std::cout << "Please enter the name of the school: ";
    std::cin.ignore();
    std::getline(std::cin, str);
    for (Student *s : vect) {
      s->setSchoolName(str);
    }
  }
  else if (userOption == "R" || userOption == "r") {
    ;
  }
  else {
    std::cout << "Invalid option." << std::endl;
  }
}

void showResult(std::vector<Student*> vect) {
  set_color(209);
  std::cout << "----------Data----------" << std::endl;
  std::cout << "School name: " << vect[0]->getSchoolName() << std::endl;
  std::cout << "Cost per credit hour: $" << vect[0]->semester.getCostCredit() << std::endl;
  std::cout << "Book cost per class: $" << vect[0]->semester.getBook() << std::endl;
  std::cout << "Room and board cost per month: $" << vect[0]->semester.getRoomBoard() << std::endl;
  std::cout << "Food cost per month: $" << vect[0]->semester.getFood() << std::endl;
  std::cout << "Travel cost per month: $" << vect[0]->semester.getTravel() << std::endl;
  std::cout << "Hours per class: " << vect[0]->getHoursPerClass() << std::endl;
  std::cout << "Months in semester: " << vect[0]->getMonthsInSemester() << std::endl;
  for (Student *s: vect) {
    std::cout << "Hours a " << s->getType() << " student takes: " << s->getHoursTaken() << std::endl; 
  }
  std::cout << "Hours in a Degree: " << vect[0]->getHoursInDegree() << std::endl;
  std::cout << "Semesters in a year: " << vect[0]->getSemestersInYear() << std::endl;
  int x = 50;
  for (Student *s : vect) {
    set_color(x);
    std::cout << "----------" << s->getType() << "----------" << std::endl;
    std::cout << "*****Cost per Semester*****" << std::endl;
    std::cout << "Tuition: $" << s->tuition() << std::endl;
    std::cout << "Room and Board: $" << s->roomAndBoard() << std::endl;
    std::cout << "Travel: $" << s->travel() << std::endl;
    std::cout << "Food: $" << s->food() << std::endl;
    std::cout << "Book: $" << s->book() << std::endl;
    std::cout << "Total for Semester: $" << s->semesterCost() << std::endl;
    std::cout << "Total cost for degree: $" << s->totalTuition() << std::endl;
    std::cout << "*****Time*****" << std::endl;
    std::cout << "Number of semesters to complete degree: " << s->numSemesters() << std::endl;
    std::cout << "Number of years to complete degree: " << s->numYears() << std::endl;
    x += 10;
  }
  set_color(134);
  std::cout << "----------Bar Graph of Tution----------" << std::endl;
  for (Student *s : vect) {
    std::cout << s->getType() << " ";
    for (int i = 1; i <= s->totalTuition() / 1000; i++) {
      std::cout << "*";
    }
    std::cout << std::endl;
  }
  reset_color();
}
#endif