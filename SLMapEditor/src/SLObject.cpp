#include "SLObject.hpp"
#include "utils.hpp"

#include <vector>
#include <iostream>

using namespace MapEditor;

SLObject::SLObject(string name)
{
	if(name.size() > 0)
	{
		objectName = name;
	}
	else
	{
		cerr << "ERROR: Blank object name, this will cause problems" << endl;
	}
}

SLObject::SLObject() : SLObject("")
{
}

string SLObject::GetName()
{
	return objectName;
}

void SLObject::SetParam(string name, string value)
{
	stringparams[name] = value;
}

void SLObject::SetParam(string name, int value)
{
	intparams[name] = value;
}

string SLObject::GetStringParam(string name)
{
	return stringparams[name];
}

int SLObject::GetIntParam(string name)
{
	return intparams[name];
}
