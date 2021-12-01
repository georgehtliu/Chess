/*
    graphics_observer.h
    David Gurevich
    CS 246
*/

#ifndef CHESS_INCLUDE_GRAPHICS_OBSERVER_H_
#define CHESS_INCLUDE_GRAPHICS_OBSERVER_H_

#include "board.h"
#include "observer.h"
#include "window.h"

#include <memory>

class GraphicsObserver : public Observer {
    Board *subject;
    int top, bottom, left, right;

    std::unique_ptr<Xwindow> w;

   public:
    GraphicsObserver(Board *board);
    void notify() override;
    ~GraphicsObserver();

    // Graphics Constants
    const static int WIDTH = 100;
    const static int HEIGHT = 100;
};

#endif  // CHESS_INCLUDE_GRAPHICS_OBSERVER_H_