#include "Student.h"
#include <math.h>
Student::Student(unsigned int id, string name, double cgpa) :id(id), name(name), cgpa(cgpa)
{
	int t = name.size();
	
	if (id < 1 || id>pow(10, 7)) throw exception("Invalid Id");
	if (name.size() < 2 || name.size()>30) throw exception("Invalid Name");
	if (cgpa < 0 || cgpa>4) throw exception("Invalid CGPA");
}

int Student::getId()
{
	return id;
}

string Student::getName()
{
	return name;
}

double Student::getCGP()
{
	return cgpa;
}

bool Student::operator==(const Student& other)
{
	if (other.cgpa != cgpa)return false;
	if (other.name != name)return false;
	if (other.id != id)return false;
	return true;
}

bool Student::operator<(const Student& other) { return IsOtherBigger(other); }
bool Student::operator>(const Student& other) { return !IsOtherBigger(other); }

bool IsLeftFirstInAlphabet(string left, string right) {
	int comparisonSize = left.size() > right.size() ? right.size() : left.size();
	for (int i = 0; i < comparisonSize; i++)
	{
		if (left[i] < right[i])return true;
		if (left[i] > right[i])return false;
	}
	return left.size() > right.size();
}

bool Student::IsOtherBigger(Student other)
{
	if (other.cgpa > cgpa)return true;
	if (other.cgpa < cgpa)return false;
	if (other.name > name)return true;
	if (other.name < name)return false;
	if (other.id > id)return true;
	if (other.id < id)return false;
	throw exception("Elements are Equal");
}
