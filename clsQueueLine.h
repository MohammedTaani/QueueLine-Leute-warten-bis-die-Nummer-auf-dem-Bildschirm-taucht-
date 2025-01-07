#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <queue>

using namespace std;


class clsQueueLine
{

	queue <string> _Line;

	int _Zahl = 0;

	int _Served = 0;

	int _Wating = 0;

	string _Prifix;

	int _Zeit;

public:

	clsQueueLine(string Prifix, int Zeit = 0) {

		_Prifix = Prifix;

		_Zeit = Zeit;

	}

	string Datum() {

		time_t t = time(nullptr);

		tm* m = localtime(&t);

		int Jahr = m->tm_year + 1900;
		int Monat = m->tm_mon + 1;
		int Tag = m->tm_mday;

		int Stunde = m->tm_hour;
		int Minute = m->tm_min;
		int Sekunde = m->tm_sec;

		string Date = to_string(Tag) + "/" + to_string(Monat) + "/" + to_string(Jahr) + " - " +
			to_string(Stunde) + ":" + to_string(Minute) + ":" + to_string(Sekunde);

		return Date;

	}

	void IssueTicket() {

		string Temp = "#//#";

		int TempZeit = _Zeit * _Zahl;

		_Zahl++;
		

		string S1 = _Prifix + to_string(_Zahl) + Temp + to_string(TempZeit) + Temp + Datum() + Temp + to_string(_Wating);
		
		_Wating++;

		_Line.push(S1);

	}

	static vector <string> SplitString(string S1, string Dilimiter = " ") {

		vector <string> JedesWortIstAllein;


		string Word = "";
		short pos = 0;

		while ((pos = S1.find(Dilimiter)) != std::string::npos) {

			Word = S1.substr(0, pos);

			if (Word != "") {

				JedesWortIstAllein.push_back(Word);

			}

			S1.erase(0, pos + Dilimiter.length());

		}

		if (S1 != "") {


			JedesWortIstAllein.push_back(S1);

		}

		return JedesWortIstAllein;

	}

	void PrintInfo() {

	
		cout << "\n\n";

		cout << "\t\t\t--------------Queue Info---------------" << endl;

		cout << "\t\t\tPrifix         : " << _Prifix << endl;
		cout << "\t\t\tTotal Ticktes  : " << _Zahl << endl;
		cout << "\t\t\tServed Clients : " << _Served << endl;
		cout << "\t\t\tWating         : " << _Wating << endl;

		cout << "\t\t\t---------------------------------------" << endl;

		cout << endl << endl;

	}

	void PrintTicktsLine() {



		string S = "";

		cout << "Tickts : ";

		int i = _Served + 1;

		for (i; i <= _Zahl; i++) {

			S = S + _Prifix + to_string(i) + " --> ";

		}

		S = S.substr(0, S.length() - 5);

		cout << S << endl;

	}

	void PrintAllTicktes() {

		if (_Line.empty())
			return;

		queue <string> Temp = _Line;

		cout << endl << "\t\t\t\t-------Tickts------" << endl;

		for (int i = 1; i <= _Zahl - _Served; i++) {

			vector <string> S1 = SplitString(Temp.front(), "#//#");

			cout << "\t\t\t=========================================" << endl;

				cout << "\t\t\t\t\t" << S1[0] << endl;

				cout << "\t\t\t\t" << S1[2] << endl;
				cout << "\t\t\t\tWating Client - " << S1[3] << endl;
				cout << "\t\t\t\tServed time in - " << S1[1] << " Minuten" << endl;

				cout << "\t\t\t=========================================" << endl;


			Temp.pop();

		}

		cout << "\n\n";

	}

	void ServeNextClient() {

		if (_Line.empty())
			return;

		_Wating--;

		_Served++;

		_Line.pop();

	}

};

