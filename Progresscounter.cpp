#include "Progresscounter.h"

/**************** Konstruktor ****************/

Progresscounter::Progresscounter()
{
	Progresscounter::Progresscounter(100, 0);
}

Progresscounter::Progresscounter(int maxElements, int counter)
{
	Progresscounter::maxElements = maxElements;
	Progresscounter::counter = counter;
	Progresscounter::percent = 0;
	Progresscounter::printedPercent = 0;
	Progresscounter::printed = false;
}

/**************** Funktionen ****************/

void Progresscounter::Reset()
{
	//Setzt die Z�hler wieder in den Anfangszustand zur�ck
	Reset(Progresscounter::maxElements, 0);
	return;
}

void Progresscounter::Reset(int maxElements, int counter)
{
	//Initialisiert das Objekt mit neuen Werten
	Progresscounter::maxElements = maxElements;
	printed = false;
	SetCounter(counter);
	return;
}

void Progresscounter::SetCounter(int counter)
{
	//Setzt den Z�hler auf den �bergebenen Wert

	//Pr�fung, ob Z�hler sich in einem validen Wertebereich befindet
	if(counter < 0)
	{
		counter = 0;
	}
	else if(counter > maxElements)
	{
		counter = maxElements;
	}

	//Counter wird gesetzt
	Progresscounter::counter = counter;

	//Prozentueller Anteil des Counters am Maximum wird berechnet
	Progresscounter::percent = 100 * ((double)counter / (double)maxElements);

	return;
}

void Progresscounter::Increment()
{
	//Erh�ht den Z�hler um Eins
	SetCounter(counter + 1);
	return;
}

bool Progresscounter::Print()
{
	//Gibt bei Bedarf die aktuelle Prozentzahl aus
	if(printedPercent != (int)percent)
	{
		if(!printed)
		{
			cout << "000 %";
			printed = true;
		}
		else
		{
			cout << "\b\b\b\b\b" << GetString();
		}
		printedPercent = (int)percent;
		return(true);
	}
	return(false);
}

int Progresscounter::GetCounter()
{
	//Gibt den aktuellen Counter zur�ck
	return(counter);
}

int Progresscounter::GetMaxElements()
{
	//Gibt den Maximalwert des Counters zur�ck
	return(maxElements);
}

double Progresscounter::GetPercent()
{
	//Gibt den aktuellen Fortschritt in Prozent zur�ck
	return(percent);
}

string Progresscounter::GetString()
{
	//Gibt die aktuelle Prozentzahl formatiert als String zur�ck
	string output = "";

	//Zahl wird formatiert
	if(percent <= 0)
	{
		percent = 0;
		output += "000";
	}
	else if(percent < 10)
	{
		output += "00";
		output += to_string((int)percent);
	}
	else if(percent < 100)
	{
		output += "0";
		output += to_string((int)percent);
	}
	else
	{
		percent = 100;
		output += to_string((int)percent);
	}

	//String wird weiter formatiert
	output += " %";

	return(output);
}