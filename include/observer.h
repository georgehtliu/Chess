/*
    observer.h
    David Gurevich
    CS 246
*/

#ifndef CHESS_INCLUDE_OBSERVER_H_
#define CHESS_INCLUDE_OBSERVER_H_

class Observer {
   public:
    virtual void notify() = 0;
    virtual ~Observer() = default;
};

#endif  // CHESS_INCLUDE_OBSERVER_H_