#include "ProgressCounter.hpp"

/**************** Constructor ****************/

// Initializes a ProgressCounter for values between 0 and 100.
ProgressCounter::ProgressCounter()
	: ProgressCounter::ProgressCounter(100 ,0) {}


// Initializes a ProgressCounter within a custom range.
ProgressCounter::ProgressCounter(int maxElements, int counter)
{
	ProgressCounter::maxElements = maxElements;
	ProgressCounter::counter = counter;
	ProgressCounter::percent = 100 * ((double)counter / (double)maxElements);
	ProgressCounter::printedPercent = -1;
	ProgressCounter::printed = false;
}

/**************** Functions ****************/

// Sets the counter to its initial state.
void ProgressCounter::Reset()
{
	Reset(ProgressCounter::maxElements, 0);
}


// Initializes the counter with new values.
void ProgressCounter::Reset(int maxElements, int counter)
{
	ProgressCounter::maxElements = maxElements;
	printed = false;
	SetCounter(counter);
}


// Sets the counter to the given value.
void ProgressCounter::SetCounter(int counter)
{
	// Checks if the counter is in a valid range.
	if(counter < 0)
	{
		counter = 0;
	}
	else if(counter > maxElements)
	{
		counter = maxElements;
	}

	// Setting counter.
	ProgressCounter::counter = counter;

	// Calculating percantage of maximum value.
	ProgressCounter::percent = 100 * ((double)counter / (double)maxElements);
}


// Increments the counter by one.
void ProgressCounter::Increment()
{
	SetCounter(counter + 1);
}


// Prints the new percentage, if it has changed.
bool ProgressCounter::Print()
{
	if(printedPercent != (int)percent)
	{
		if(!printed)
		{
			std::cout << "000 %";
			printed = true;
		}

		std::cout << "\b\b\b\b\b" << GetString();
		fflush(stdout);
		printedPercent = (int)percent;
		return(true);
	}
	return(false);
}


// Returns the current counter.
int ProgressCounter::GetCounter()
{
	return(counter);
}


// Returns the maximum value of the counter.
int ProgressCounter::GetMaxElements()
{
	return(maxElements);
}


// Returns the current progress as percentage.
double ProgressCounter::GetPercent()
{
	return(percent);
}


// Returns the current percentage formatted as a string.
std::string ProgressCounter::GetString()
{
	std::string output = "";

	// Formatting number.
	if(percent <= 0)
	{
		percent = 0;
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
		percent = 100;
		output += std::to_string((int)percent);
	}
	output += " %";

	return(output);
}
