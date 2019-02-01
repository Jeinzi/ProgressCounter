#include "ProgressCounter.hpp"

/**************** Constructor ****************/

// Initializes a ProgressCounter for values between 0 and 100.
ProgressCounter::ProgressCounter()
	: ProgressCounter::ProgressCounter(100 ,0) {}


// Initializes a ProgressCounter within a custom range.
ProgressCounter::ProgressCounter(size_t maxElements, size_t counter)
{
	ProgressCounter::maxElements = maxElements;
	ProgressCounter::counter = counter;
	ProgressCounter::percent = 100 * ((float)counter / (float)maxElements);
	ProgressCounter::printedPercent = -1;
	ProgressCounter::printed = false;
}

/**************** Functions ****************/

// Sets the counter to its initial state.
void ProgressCounter::reset()
{
	reset(ProgressCounter::maxElements, 0);
}


// Initializes the counter with new values.
void ProgressCounter::reset(size_t maxElements, size_t counter)
{
	ProgressCounter::maxElements = maxElements;
	printed = false;
	setCounter(counter);
}


// Sets the counter to the given value.
void ProgressCounter::setCounter(size_t counter)
{
	// Checks if the counter is in a valid range.
	if(counter > maxElements)
	{
		counter = maxElements;
	}

	// Setting counter.
	ProgressCounter::counter = counter;

	// Calculating percantage of maximum value.
	ProgressCounter::percent = 100 * ((float)counter / (float)maxElements);
}


// Increments the counter by one.
void ProgressCounter::increment()
{
	setCounter(counter + 1);
}


// Prints the new percentage, if it has changed.
bool ProgressCounter::print() const
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
		return(true);
	}
	return(false);
}


// Returns the current counter.
size_t ProgressCounter::getCounter() const
{
	return(counter);
}


// Returns the maximum value of the counter.
size_t ProgressCounter::getMaxElements() const
{
	return(maxElements);
}


// Returns the current progress as percentage.
float ProgressCounter::getPercent() const
{
	return(percent);
}


// Returns the current percentage formatted as a string.
std::string ProgressCounter::getString() const
{
	std::string output = "";

	// Formatting number.
	if(percent <= 0)
	{
		output += "000";
	}
	else if(percent < 10)
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
		output += std::to_string((int)percent);
	}
	output += " %";

	return(output);
}
