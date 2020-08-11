#pragma once
#include <iostream>
#include <string>
#include <regex>
#include "Priorities.h"
#include "Student.h"
using namespace std;

class CommandLineParser
{
	Priorities prios;
public:
	void Print();
	bool TryInsert(string s);
	void TryServe();
	Student ParsInsert(string s);
	
	bool ComputeCommand(string command);
};

