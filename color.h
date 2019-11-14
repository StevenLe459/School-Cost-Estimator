#ifndef COLOR_H
#define COLOR_H
#include <iostream>

void set_color(int);
void reset_color(int);

void set_color(int i) {
  std::cout << "\u001b[38;5;" << i << "m";
}
void reset_color() {
  std::cout << "\u001b[0m";
}
#endif