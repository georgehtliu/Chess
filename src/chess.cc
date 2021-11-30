/*
    chess.cc
    November 29, 2021

    Authors:
    David Gurevich
*/

#include <iostream>

#include "window.h"

int main() {
    Xwindow w;

    w.fillRectangle(100, 200, 50, 250, Xwindow::Blue);

    w.drawString(50, 50, "Hello!");

    char c;
    std::cin >> c;
}
