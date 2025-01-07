// QueueLine(Leute warten bis die Nummer auf dem Bildschirm taucht).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "clsQueueLine.h"

using namespace std;

int main()
{

	clsQueueLine Auslanderbehorde("A", 10);

	clsQueueLine Fuehrerscheinstelle("F", 5);

	Auslanderbehorde.IssueTicket();
	Auslanderbehorde.IssueTicket();
	Auslanderbehorde.IssueTicket();

	Auslanderbehorde.IssueTicket();

	Auslanderbehorde.PrintAllTicktes();

	Auslanderbehorde.PrintInfo();

	Auslanderbehorde.PrintTicktsLine();

	Auslanderbehorde.ServeNextClient();

	Auslanderbehorde.PrintTicktsLine();

	Auslanderbehorde.ServeNextClient();

	Auslanderbehorde.PrintInfo();



	

}
