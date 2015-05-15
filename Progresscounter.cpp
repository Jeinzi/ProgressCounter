#include "Progress.h"

/**************** Konstruktor ****************/

Progresscounter::Progresscounter()
{
	Progresscounter::Progresscounter(100, 0);
}

Progresscounter::Progresscounter(int MaxElements, int Counter)
{
	Progresscounter::MaxElements = MaxElements;
	Progresscounter::Counter = Counter;
	Progresscounter::Percent = 0;
	Progresscounter::PrintedPercent = 0;
	Progresscounter::Printed = false;
}

/**************** Funktionen ****************/

void Progresscounter::Reset()
{
	//Setzt die Z�hler wieder in den Anfangszustand zur�ck
	Reset(Progresscounter::MaxElements, 0);
	return;
}

void Progresscounter::Reset(int MaxElements, int Counter)
{
	//Initialisiert das Objekt mit neuen Werten
	Progresscounter::MaxElements = MaxElements;
	Printed = false;
	SetCounter(Counter);
	return;
}

void Progresscounter::SetCounter(int Counter)
{
	//Setzt den Z�hler auf den �bergebenen Wert

	//Pr�fung, ob Z�hler sich in einem validen Wertebereich befindet
	if(Counter < 0)
	{
		Counter = 0;
	}
	else if(Counter > MaxElements)
	{
		Counter = MaxElements;
	}

	//Counter wird gesetzt
	Progresscounter::Counter = Counter;

	//Prozentueller Anteil des Counters am Maximum wird berechnet
	Progresscounter::Percent = 100 * ((double)Counter / (double)MaxElements);

	return;
}

void Progresscounter::Increment()
{
	//Erh�ht den Z�hler um Eins
	SetCounter(Counter + 1);
	return;
}

bool Progresscounter::Print()
{
	//Gibt bei Bedarf die aktuelle Prozentzahl aus
	if(PrintedPercent != (int)Percent)
	{
		if(!Printed)
		{
			cout << "000 %";
			Printed = true;
		}
		else
		{
			cout << "\b\b\b\b\b" << GetString();
		}
		PrintedPercent = (int)Percent;
		return(true);
	}
	return(false);
}

int Progresscounter::GetCounter()
{
	//Gibt den aktuellen Counter zur�ck
	return(Counter);
}

int Progresscounter::GetMaxElements()
{
	//Gibt den Maximalwert des Counters zur�ck
	return(MaxElements);
}

double Progresscounter::GetPercent()
{
	//Gibt den aktuellen Fortschritt in Prozent zur�ck
	return(Percent);
}

string Progresscounter::GetString()
{
	//Gibt die aktuelle Prozentzahl formatiert als String zur�ck
	string Output = "";

	//Zahl wird formatiert
	if(Percent <= 0)
	{
		Percent = 0;
		Output += "000";
	}
	else if(Percent < 10)
	{
		Output += "00";
		Output += to_string((int)Percent);
	}
	else if(Percent < 100)
	{
		Output += "0";
		Output += to_string((int)Percent);
	}
	else
	{
		Percent = 100;
		Output += to_string((int)Percent);
	}

	//String wird weiter formatiert
	Output += " %";

	return(Output);
}