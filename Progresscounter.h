#ifndef PROGRESS_H
#define PROGRESS_H

#include <string>
#include <iostream>

using namespace std;

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
	string	GetString();

private:
	bool	printed;
	int		maxElements;
	int		counter;
	int		printedPercent;
	double	percent;
};

#endif