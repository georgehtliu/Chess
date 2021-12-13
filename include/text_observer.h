#ifndef CHESS_INCLUDE_TEXT_OBSERVER_H_
#define CHESS_INCLUDE_TEXT_OBSERVER_H_

#include "board.h"
#include "observer.h"
#include "window.h"

#include <memory>

class TextObserver : public Observer {
    Board *subject;
    std::unique_ptr<Xwindow> w;

   public:
    TextObserver(Board *board);
    void notify() override;
    void notify(Spot *s) override;
    void notify(Move *m) override;
    ~TextObserver();
};

#endif  // CHESS_INCLUDE_TEXT_OBSERVER_H_