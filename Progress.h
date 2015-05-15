#ifndef CPROGRESS_H
#define CPROGRESS_H

#include <string>
#include <General.h>

using namespace std;

class Progress
{
public:
	Progress();
	Progress(int MaxElements, int Counter = 0);

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