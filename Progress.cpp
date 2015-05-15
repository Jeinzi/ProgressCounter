#include "Progress.h"

/**************** Konstruktor ****************/

Progress::Progress()
{
	Progress::Progress(100, 0);
}

Progress::Progress(int MaxElements, int Counter)
{
	Progress::MaxElements		= MaxElements;
	Progress::Counter			= Counter;
	Progress::Percent			= 0;
	Progress::PrintedPercent	= 0;
	Progress::Printed			= false;
}

/**************** Funktionen ****************/

void Progress::Reset()
{
	//Setzt die Zähler wieder in den Anfangszustand zurück
	Reset(Progress::MaxElements, 0);
	return;
}

void Progress::Reset(int MaxElements, int Counter)
{
	//Initialisiert das Objekt mit neuen Werten
	Progress::MaxElements = MaxElements;
	Printed = false;
	SetCounter(Counter);
	return;
}

void Progress::SetCounter(int Counter)
{
	//Setzt den Zähler auf den übergebenen Wert

	//Prüfung, ob Zähler sich in einem validen Wertebereich befindet
	if(Counter < 0)
	{
		Counter = 0;
	}
	else if(Counter > MaxElements)
	{
		Counter = MaxElements;
	}

	//Counter wird gesetzt
	Progress::Counter = Counter;

	//Prozentueller Anteil des Counters am Maximum wird berechnet
	Progress::Percent			= 100 * ((double)Counter / (double)MaxElements);

	return;
}

void Progress::Increment()
{
	//Erhöht den Zähler um Eins
	SetCounter(Counter + 1);
	return;
}

bool Progress::Print()
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

int Progress::GetCounter()
{
	//Gibt den aktuellen Counter zurück
	return(Counter);
}

int Progress::GetMaxElements()
{
	//Gibt den Maximalwert des Counters zurück
	return(MaxElements);
}

double Progress::GetPercent()
{
	//Gibt den aktuellen Fortschritt in Prozent zurück
	return(Percent);
}

string Progress::GetString()
{
	//Gibt die aktuelle Prozentzahl formatiert als String zurück
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
		Output += IntToString((int)Percent);
	}
	else if(Percent < 100)
	{
		Output += "0";
		Output += IntToString((int)Percent);
	}
	else
	{
		Percent = 100;
		Output += IntToString((int)Percent);
	}

	//String wird weiter formatiert
	Output += " %";

	return(Output);
}