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

	void	reset();
	void	reset(size_t maxElements, size_t counter = 0);
	void	setCounter(size_t counter);
	void	increment();
	bool	print() const;
	size_t	getCounter() const;
	size_t	getMaxElements() const;
	float		getPercent() const;
	std::string	getString() const;

private:
	mutable bool	printed;
	size_t	maxElements;
	size_t	counter;
	mutable int	printedPercent;
	float		percent;
};

#endif
