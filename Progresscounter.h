#ifndef PROGRESSCOUNTER_H
#define PROGRESSCOUNTER_H

#include <string>
#include <iostream>

class Progresscounter
{
public:
	Progresscounter();
	Progresscounter(int maxElements, int counter = 0);

	void	Reset();
	void	Reset(int maxElements, int counter = 0);
	void	SetCounter(int counter);
	void	Increment();
	bool	Print();
	int		GetCounter();
	int		GetMaxElements();
	double	GetPercent();
	std::string	GetString();

private:
	bool	printed;
	int		maxElements;
	int		counter;
	int		printedPercent;
	double	percent;
};

#endif