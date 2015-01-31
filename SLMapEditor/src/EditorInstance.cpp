#include "EditorInstance.hpp"
#include "tinyxml2.h"

using namespace MapEditor;
using namespace tinyxml2;

EditorInstance::EditorInstance(string workspace)
{
	strglobals["workspace"] = workspace;
	map<string, string> stringrefs;
	map<string, string> intrefs;
	XMLDocument configfile((workspace+"slme.conf").c_str());
	for(XMLElement* el; el; el = el->NextSiblingElement())
	{
		if(el->Name() == "String")
		{
			strglobals[el->FindAttribute("name")->Value()] = el->GetText();
		}
		else if(el->Name() == "Int")
		{
			intglobals[el->FindAttribute("name")->Value()] = stoi(el->GetText());
		}
		else if(el->Name() == "StringRef")
		{
			stringrefs[el->FindAttribute("name")->Value()] = el->GetText();
		}
		else if(el->Name() == "IntRef")
		{
			intrefs[el->FindAttribute("name")->Value()] = el->GetText();
		}
	}
	for(map<string, string>::iterator it = stringrefs.begin(); it != stringrefs.end(); ++it)
	{
		strglobals[it->first] = strglobals[it->second];
	}
	for(map<string, string>::iterator it = intrefs.begin(); it != intrefs.end(); ++it)
	{
		intglobals[it->first] = intglobals[it->second];
	}
}
