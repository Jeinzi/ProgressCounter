/**
 * @file
 * @brief A text-based progress counter
 *
 * This is free and unencumbered software released into the public domain.
 * For more information, please refer to http://unlicense.org
 */

#ifndef PROGRESSCOUNTER_H
#define PROGRESSCOUNTER_H

#include <string>
#include <iostream>


/** A text-based progress counter. */
class ProgressCounter
{
public:
  /** Initializes a progress counter with range 0 - 100. */
  ProgressCounter();

  /**
   * Initializes a progress counter with a custom range.
   * @param max The maximum value the counter can reach.
   * @param counter The initial value of the counter.
   */
  ProgressCounter(size_t max, size_t counter = 0);

  /** Resets the counter to zero */
  void reset();

  /**
   * Sets a new maximum value for the counter.
   * @param maxElements The maximum value the counter can reach.
   */
  void setMaximum(size_t maxElements);

  /**
   * Sets the counter to a new value.
   * @param counter The counter's new value.
   */
  void setCounter(size_t counter);

  /** Increments the counter by one. */
  void increment();

  /** Prints the new percentage, if it has changed. */
  void print() const;

  /** @return float The counter's current percentage. */
  float getPercent() const;

  /** @return size_t The counter's current value. */
  size_t getCounter() const;

  /** @return size_t The maximum value the counter can reach. */
  size_t getMaxElements() const;

  /**
   * @return std::string Returns the current percentage formatted as a string
   * as it would be printed by the class.
   */
  std::string getString() const;

private:
  float percent; ///< How much the counter is currently filled.
  size_t counter; ///< The counter's current value.
  size_t maxElements; ///< The maximum value the counter can reach.

  mutable bool printed;  ///< Whether the class has printed anything yet.
  mutable int printedPercent; ///< The percentage printed most recently.
};

#endif
