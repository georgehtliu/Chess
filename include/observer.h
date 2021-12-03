/*
    observer.h
    David Gurevich
    CS 246
*/

#ifndef CHESS_INCLUDE_OBSERVER_H_
#define CHESS_INCLUDE_OBSERVER_H_

class Spot;

class Observer {
   public:
    virtual void notify() = 0;
    virtual void notify(Spot *s) = 0;
    virtual ~Observer() = default;
};

#endif  // CHESS_INCLUDE_OBSERVER_H_