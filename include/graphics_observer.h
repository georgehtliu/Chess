/*
    graphics_observer.h
    David Gurevich
    CS 246
*/

#ifndef CHESS_INCLUDE_GRAPHICS_OBSERVER_H_
#define CHESS_INCLUDE_GRAPHICS_OBSERVER_H_

#include "observer.h"
#include "window.h"

#include <memory>
#include <unordered_map>

class Board;

class GraphicsObserver : public Observer {
    Board *subject;
    std::unique_ptr<Xwindow> w;
    std::unordered_map<std::string, XImage*> images;

   public:
    explicit GraphicsObserver(Board *board);
    void notify() override;
    void notify(Spot *s) override;
    void notify(Move *m) override;
    ~GraphicsObserver() override;

    // Graphics Constants
    const static int WIDTH = 100;
    const static int HEIGHT = 100;

    const static int BOARD_OFFSET = 30;

    const static int WHITE_COL = Xwindow::Green;
    const static int BLACK_COL = Xwindow::Brown;
};

#endif  // CHESS_INCLUDE_GRAPHICS_OBSERVER_H_