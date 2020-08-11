#include "Priorities.h"

list<Student> Priorities::GetStudents(list<string> events)
{
	for (list<Student>::iterator iter = order.begin(); iter != order.end();)
	{
		auto name = (*iter).getName();
		bool found = false;
		for (string toProcess : events) {
			found = name == toProcess;
			if (found) {
				iter = order.erase(iter);
				break;
			}
		}
		if (!found) iter++;
	}
	return order;
}

list<Student> Priorities::GetStudents()
{
	return order;
}

Student Priorities::Served()
{
	if (order.size() == 0) throw exception("Empty queue");
	Student s = order.front();
	order.pop_front();
	return s;
}

void Priorities::Enter(Student student)
{

	for (list<Student>::iterator iter = order.begin(); iter != order.end(); iter++)
	{
		if (student < (*iter))
		{
			order.insert(iter, student);
			return;
		}
	}
	order.push_back(student);
}
