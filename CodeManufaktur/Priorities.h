#pragma once
#include <list>
#include "Student.h"
using namespace std;
class Priorities
{
	list <Student> order;

public :
	list <Student> GetStudents(list<string > events);
	list <Student> GetStudents();
	Student Served();
	void Enter(Student student);



};

