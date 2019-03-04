#ifndef PROGRESSCOUNTER_H
#define PROGRESSCOUNTER_H

#include <string>
#include <iostream>

// A class representing a text based progress counter.
class ProgressCounter
{
public:
  ProgressCounter();
  ProgressCounter(size_t maxElements, size_t counter = 0);

  void reset();
  void reset(size_t maxElements, size_t counter = 0);
  void setCounter(size_t counter);
  void increment();
  bool print() const;
  float getPercent() const;
  size_t getCounter() const;
  size_t getMaxElements() const;
  std::string getString() const;

private:
  float percent;
  size_t counter;
  size_t maxElements;

  mutable bool printed;
  mutable int printedPercent;
};

#endif
