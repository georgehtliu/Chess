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
    std::unique_ptr<Xwindow> w;

   public:
    explicit GraphicsObserver(Board *board);
    void notify() override;
    void notify(Spot *s) override;
    void notify(Move *m) override;
    ~GraphicsObserver() override;

    // Graphics Constants
    const static int WIDTH = 100;
    const static int HEIGHT = 100;

    const static int WHITE_COL = Xwindow::Green;
    const static int BLACK_COL = Xwindow::Brown;
};

#endif  // CHESS_INCLUDE_GRAPHICS_OBSERVER_H_