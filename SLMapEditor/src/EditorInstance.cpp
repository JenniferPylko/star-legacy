#include "EditorInstance.hpp"
#include "tinyxml2.h"
#include "utils.hpp"

using namespace MapEditor;
using namespace tinyxml2;

EditorInstance::EditorInstance(string workspace)
{
	strglobals["workspace"] = workspace;
	map<string, string> stringrefs;
	map<string, string> intrefs;
	XMLDocument configfile((workspace + "slme.conf").c_str());
	for(XMLElement* el = configfile.FirstChildElement(); el; el = el->NextSiblingElement())
	{
		if(el->Name() == sl_str_t)
		{
			strglobals[el->Attribute("name")] = el->GetText();
		}
		else if(el->Name() == sl_int_t)
		{
			intglobals[el->Attribute("name")] = stoi(el->GetText());
		}
		else if(el->Name() == sl_str_ref_t)
		{
			stringrefs[el->Attribute("name")] = el->GetText();
		}
		else if(el->Name() == sl_int_ref_t)
		{
			intrefs[el->Attribute("name")] = el->GetText();
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
	vector<vector<string>> editorfiles;
	editorfiles.push_back(getdir(workspace+brushes));
	editorfiles.push_back(getdir(workspace+entities));
	editorfiles.push_back(getdir(workspace+objects));
	editorfiles.push_back(getdir(strglobals["gamedir"]+brushes));
	editorfiles.push_back(getdir(strglobals["gamedir"]+entities));
	editorfiles.push_back(getdir(strglobals["gamedir"]+objects));
	string editordata;
	for(int i = 0; i < editorfiles.size(); ++i)
	{
		for(int j = 0; j < editorfiles[i].size(); ++j)
		{
			editordata += editorfiles[i][j];
		}
	}
	XMLDocument editorxml(true, COLLAPSE_WHITESPACE);
	editorxml.Parse(editordata.c_str());
	for(XMLElement* el = editorxml.FirstChildElement(); el; el = el->NextSiblingElement())
	{
		if(el->Name() == sl_str_t)
		{
			strglobals[el->Attribute("name")] = el->GetText();
		}
		else if(el->Name() == sl_int_t)
		{
			intglobals[el->Attribute("name")] = stoi(el->GetText());
		}
		else if(el->Name() == sl_str_ref_t)
		{
			stringrefs[el->Attribute("name")] = el->GetText();
		}
		else if(el->Name() == sl_int_ref_t)
		{
			intrefs[el->Attribute("name")] = el->GetText();
		}
		else if(el->Name() == sl_brush_t)
		{
			loadedbrushes[el->Attribute("name")] = Brush(el->Attribute("name"));
			for(XMLElement* el2 = el->FirstChildElement(); el2; el2 = el2->NextSiblingElement())
			{
				if(el2->Name() == sl_str_t)
				{
					loadedbrushes[el->Attribute("name")].SetProperty(el2->Attribute("name"), el->GetText());
				}
				else if(el2->Name() == sl_int_t)
				{
					loadedbrushes[el->Attribute("name")].SetProperty(el2->Attribute("name"), stoi(el->GetText()));
				}
			}
		}
		else if(el->Name() == sl_entity_t)
		{
			loadedentities[el->Attribute("name")] = Entity(el->Attribute("name"));
			for(XMLElement* el2 = el->FirstChildElement(); el2; el2 = el2->NextSiblingElement())
			{
				if(el2->Name() == sl_str_t)
				{
					loadedentities[el->Attribute("name")].SetField(el2->Attribute("name"), el->GetText());
				}
				else if(el2->Name() == sl_int_t)
				{
					loadedentities[el->Attribute("name")].SetField(el2->Attribute("name"), stoi(el->GetText()));
				}
			}
		}
		else if(el->Name() == sl_object_t)
		{
			loadedobjects[el->Attribute("name")] = SLObject(el->Attribute("name"));
			for(XMLElement* el2 = el->FirstChildElement(); el2; el2 = el2->NextSiblingElement())
			{
				if(el2->Name() == sl_str_t)
				{
					loadedobjects[el->Attribute("name")].SetParam(el2->Attribute("name"), el->GetText());
				}
				else if(el2->Name() == sl_int_t)
				{
					loadedobjects[el->Attribute("name")].SetParam(el2->Attribute("name"), stoi(el->GetText()));
				}
			}
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
