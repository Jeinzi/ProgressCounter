#include "Progresscounter.h"

/**************** Constructor ****************/

// Initializes a progresscounter for values between 0 and 100.
Progresscounter::Progresscounter()
{
	Progresscounter::Progresscounter(100, 0);
}


// Initializes a progresscounter within a custom range.
Progresscounter::Progresscounter(int maxElements, int counter)
{
	Progresscounter::maxElements = maxElements;
	Progresscounter::counter = counter;
	Progresscounter::percent = 100 * ((double)counter / (double)maxElements);
	Progresscounter::printedPercent = 0;
	Progresscounter::printed = false;
}

/**************** Functions ****************/

// Sets the counter to its initial state.
void Progresscounter::Reset()
{
	Reset(Progresscounter::maxElements, 0);
}


// Initializes the counter with new values.
void Progresscounter::Reset(int maxElements, int counter)
{
	Progresscounter::maxElements = maxElements;
	printed = false;
	SetCounter(counter);
}


// Sets the counter to the given value.
void Progresscounter::SetCounter(int counter)
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
	Progresscounter::counter = counter;

	// Calculating percantage of maximum value.
	Progresscounter::percent = 100 * ((double)counter / (double)maxElements);
}


// Increments the counter by one.
void Progresscounter::Increment()
{
	SetCounter(counter + 1);
}


// Prints the new percentage, if it has changed.
bool Progresscounter::Print()
{
	if(printedPercent != (int)percent)
	{
		if(!printed)
		{
			std::cout << "000 %";
			printed = true;
		}
		
		std::cout << "\b\b\b\b\b" << GetString();
		printedPercent = (int)percent;
		return(true);
	}
	return(false);
}


// Returns the current counter.
int Progresscounter::GetCounter()
{
	return(counter);
}


// Returns the maximum value of the counter.
int Progresscounter::GetMaxElements()
{
	return(maxElements);
}


// Returns the current progress as percentage.
double Progresscounter::GetPercent()
{
	return(percent);
}


// Returns the current percentage formatted as a string.
std::string Progresscounter::GetString()
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