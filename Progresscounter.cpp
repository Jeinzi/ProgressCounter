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
	//Setzt die Zähler wieder in den Anfangszustand zurück
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
	//Setzt den Zähler auf den übergebenen Wert

	//Prüfung, ob Zähler sich in einem validen Wertebereich befindet
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
	//Erhöht den Zähler um Eins
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
	//Gibt den aktuellen Counter zurück
	return(counter);
}

int Progresscounter::GetMaxElements()
{
	//Gibt den Maximalwert des Counters zurück
	return(maxElements);
}

double Progresscounter::GetPercent()
{
	//Gibt den aktuellen Fortschritt in Prozent zurück
	return(percent);
}

string Progresscounter::GetString()
{
	//Gibt die aktuelle Prozentzahl formatiert als String zurück
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