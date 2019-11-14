#include "functions.h"

int main() {
  Student full(3, 4, 12, 60, 3, "Full time", "TCC", 59, 100, 400, 150, 90);
  Student part(3, 4, 9, 60, 3, "Part time", "TCC", 59, 100, 400, 150, 90);
  Student half(3, 4, 6, 60, 3, "Half time", "TCC", 59, 100, 400, 150, 90);
  Student *f = &full;
  Student *p = &part;
  Student *h = &half;
  std::string option;
  std::vector<Student*> vect;
  vect.push_back(f);
  vect.push_back(p);
  vect.push_back(h);
  do {
    std::cout << "\x1b[2J\x1b[1;1H";
    showResult(vect);
    std::cout << "\n---------------------------------------------\n" << std::endl;
    showMenu();
    std::cout << "Please enter an option: ";
    std::cin >> option;
    handleOption(option, vect);
  } while(option != "E" && option != "e");
  return 0;
}