#include "Brush.hpp"
#include "utils.hpp"

#include <vector>
#include <iostream>

using namespace MapEditor;

Brush::Brush(string name)
{
	if(name.size() > 0)
	{
		brushName = name;
	}
	else
	{
		cerr << "ERROR: Blank brush name, this will cause problems" << endl;
	}
}

Brush::Brush() : Brush("")
{
}

string Brush::GetName()
{
	return brushName;
}

void Brush::SetProperty(string name, string value)
{
	stringproperties[name] = value;
}

void Brush::SetProperty(string name, int value)
{
	intproperties[name] = value;
}

string Brush::GetStringProperty(string name)
{
	return stringproperties[name];
}

int Brush::GetIntProperty(string name)
{
	return intproperties[name];
}
