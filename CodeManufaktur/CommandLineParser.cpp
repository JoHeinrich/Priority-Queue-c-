#include "CommandLineParser.h"
#include<vector>
#include <sstream>

bool  CommandLineParser::ComputeCommand(string command) {

	if (command == "PRINT") Print();
	else if (command == "SERVED") TryServe();
	else if (command.substr(0, string("ENTER").size()) == "ENTER") TryInsert(command.substr(string("ENTER").size(), command.size()));
	else if (command == "QUIT") return false;
	else
	{
		cout << "Unknown command";
	}
	
	return true;
}

void CommandLineParser::TryServe()
{
	try
	{
		Student student = prios.Served();
		cout << "Served " << student.getName();
	}
	catch (exception e)
	{
		cout << e.what();
	}
}

bool CommandLineParser::TryInsert(string s) {

	try
	{ 
		Student student = ParsInsert(s);
		prios.Enter(student);
		cout << "Inserted " << student.getName();
	}
	catch (exception e)
	{
		cout << e.what();
		return false;
	}
	
	return true;
}

Student CommandLineParser::ParsInsert(string s)
{
	string enter;

	unsigned int id;
	string name;
	double cgpa;

	stringstream ss;
	ss << s;

	ss >> name;
	ss >> cgpa;
	ss >> id;

	return Student(id, name, cgpa);

}

void CommandLineParser::Print()
{
	if (prios.GetStudents().size() == 0)
	{
		cout << "LEER";
		return;
	}
	for (Student s: prios.GetStudents())
	{
		cout << s.getName()<<"\n";
	}
}
