/**
 * @file
 * @brief Implementation of methods in ProgressCounter.hpp
 *
 * This is free and unencumbered software released into the public domain.
 * For more information, please refer to http://unlicense.org
 */

#include "ProgressCounter.hpp"


/**************** Constructors ****************/

ProgressCounter::ProgressCounter()
  : ProgressCounter::ProgressCounter(100 ,0) {}




ProgressCounter::ProgressCounter(size_t maxElements, size_t counter)
{
  this->maxElements = maxElements;
  this->counter = counter;
  this->percent = 100 * ((float)counter / (float)maxElements);
  this->printedPercent = -1;
  this->printed = false;
}




/**************** Methods ****************/

void ProgressCounter::reset()
{
  setCounter(0);
}




void ProgressCounter::setMaximum(size_t maxElements)
{
  this->maxElements = maxElements;
  printed = false;
  setCounter(counter);
}




void ProgressCounter::setCounter(size_t counter)
{
  // Checks if the counter is in a valid range.
  if(counter > maxElements)
  {
    counter = maxElements;
  }

  // Setting counter.
  this->counter = counter;

  // Calculating percantage of maximum value.
  this->percent = 100 * ((float)counter / (float)maxElements);
}




void ProgressCounter::increment()
{
  setCounter(counter + 1);
}




void ProgressCounter::print() const
{
  if(printedPercent != (int)percent)
  {
    if(!printed)
    {
      std::cout << "000 %";
      printed = true;
    }

    std::cout << "\b\b\b\b\b" << getString();
    fflush(stdout);
    printedPercent = (int)percent;
  }
}




size_t ProgressCounter::getCounter() const
{
  return counter;
}

size_t ProgressCounter::getMaxElements() const
{
  return maxElements;
}

float ProgressCounter::getPercent() const
{
  return percent;
}




std::string ProgressCounter::getString() const
{
  std::string output("0", 1);

  // Formatting number.
  if(percent < 10)
  {
    output += "00";
    output += std::to_string((int)percent);
  }
  else if(percent < 100)
  {
    output += "0";
    output += std::to_string((int)percent);
  }
  else
  {
    output = "100";
  }
  output += " %";

  return output;
}
