#include "Entity.hpp"
#include "utils.hpp"

#include <vector>
#include <iostream>

using namespace MapEditor;

Entity::Entity(string name)
{
	if(name.size() > 0)
	{
		entityName = name;
	}
	else
	{
		cerr << "ERROR: Blank entity name, this will cause problems" << endl;
	}
}

Entity::Entity() : Entity("")
{
}

string Entity::GetName()
{
	return entityName;
}

void Entity::SetField(string name, string value)
{
	stringfields[name] = value;
}

void Entity::SetField(string name, int value)
{
	intfields[name] = value;
}

string Entity::GetStringField(string name)
{
	return stringfields[name];
}

int Entity::GetIntField(string name)
{
	return intfields[name];
}
