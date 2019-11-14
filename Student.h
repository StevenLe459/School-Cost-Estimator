#ifndef STUDENT_H
#define STUDENT_H
#include "Cost.h"
#include <string>
#include <cmath>

class Student {
  private:
    int hoursPerClass;
    int monthsInSemester;
    int hoursTaken;
    int hoursInDegree;
    int semestersInYear;
    std::string type;
    std::string schoolName;
  public:  
    Cost semester;
    Student(int hpc, int mis, int ht, int hid, int siy, std::string ty, std::string sn, double c, double b, double rb, double f, double t) : hoursPerClass(hpc), monthsInSemester(mis), hoursTaken(ht), hoursInDegree(hid), semestersInYear(siy), type(ty), schoolName(sn), semester(c, b, rb, f, t) {}
    int getHoursPerClass() const {
      return hoursPerClass;
    }
    int getMonthsInSemester() const {
      return monthsInSemester;
    }
    int getHoursTaken() const {
      return hoursTaken;
    }
    int getHoursInDegree() const {
      return hoursInDegree;
    }
    int getSemestersInYear() const {
      return semestersInYear;
    }
    std::string getType() const {
      return type;
    }
    std::string getSchoolName() const {
      return schoolName;
    }
    void setHoursPerClass(int i) {
      hoursPerClass = i;
    }
    void setMonthsInSemester(int i) {
      monthsInSemester = i;
    }
    void setHoursTaken(int i) {
      hoursTaken = i;
    }
    void setHoursInDegree(int i) {
      hoursInDegree = i;
    }
    void setSemestersInYear(int i) {
      semestersInYear = i;
    }
    void setSchoolName(std::string sn) {
      schoolName = sn;
    }
    double tuition() {
     return hoursTaken * semester.getCostCredit();
    }
    double roomAndBoard() {
      return monthsInSemester * semester.getRoomBoard();
    }
    double travel() {
      return monthsInSemester * semester.getTravel();
    }
    double food() {
      return monthsInSemester * semester.getFood();
    }
    double book() {
      return hoursTaken / hoursPerClass * semester.getBook();
    }
    int numSemesters() {
      return std::round((double)hoursInDegree / (double)hoursTaken);
    }
    double semesterCost() {
      return tuition() + roomAndBoard() + travel() + food() + book();
    }
    double totalTuition() {
      return semesterCost() * numSemesters();
    }
    double numYears() {
      return (double)numSemesters() / (double)semestersInYear;
    }
};
#endif