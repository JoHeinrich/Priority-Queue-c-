#pragma once
#include<string >
using namespace std;
class Student
{
	unsigned int id;
	string name; 
	double cgpa;
public :
	Student(unsigned int id, string name, double cgpa);
	int getId();
	string getName();
	double getCGP();
	bool IsOtherBigger(Student other);
	bool operator==(const Student& other);
	bool operator<(const Student& other);
	bool operator>(const Student& other);
	std::wstring ToString() { return L"()"; }

};

