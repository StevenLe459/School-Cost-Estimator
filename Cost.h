#ifndef COST_H
#define COST_H

class Cost {
  private:
    double costCredit;
    double book;
    double roomBoard;
    double food;
    double travel;
  public:
    Cost(double c, double b, double rb, double f, double t) : costCredit(c), book(b), roomBoard(rb), food(f), travel(t) {}
    double getCostCredit() const {
      return costCredit;
    }
    double getBook() const {
      return book;
    }
    double getRoomBoard() const {
      return roomBoard;
    }
    double getFood() const {
      return food;
    }
    double getTravel() const {
      return travel;
    }
    void setCostCredit(double d) {
      costCredit = d;
    }
    void setBook(double d) {
      book = d;
    }
    void setRoomBoard(double d) {
      roomBoard = d;
    }
    void setFood(double d) {
      food = d;
    }
    void setTravel(double d) {
      travel = d;
    }
};
#endif