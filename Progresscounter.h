#ifndef PROGRESS_H
#define PROGRESS_H

#include <string>
#include <iostream>

using namespace std;

class Progresscounter
{
public:
	Progresscounter();
	Progresscounter(int MaxElements, int Counter = 0);

	void	Reset();
	void	Reset(int MaxElements, int Counter = 0);
	void	SetCounter(int Counter);
	void	Increment();
	bool	Print();
	int		GetCounter();
	int		GetMaxElements();
	double	GetPercent();
	string	GetString();

private:
	bool	Printed;
	int		MaxElements;
	int		Counter;
	int		PrintedPercent;
	double	Percent;
};

#endif