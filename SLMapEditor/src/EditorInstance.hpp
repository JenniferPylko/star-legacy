#include <map>
#include <string>
#include "Entity.hpp"
#include "Brush.hpp"
#include "SLObject.hpp"

#ifndef EDITOR_INSTANCE_H_
#define EDITOR_INSTANCE_H_

using namespace std;

namespace MapEditor
{
	class EditorInstance
	{
		public:
			EditorInstance(string workspace);
			Brush GetBrushTemplate(string brushname);
			Entity GetEntityTemplate(string entityname);
			SLObject GetSLObjectTemplate(string templatename);
			map<string, Brush> GetLoadedBrushes();
			map<string, Entity> GetLoadedEntities();
			map<string, SLObject> GetLoadedObjects();
			string GetStringGlobal(string globalame);
			int GetIntGlobal(string globalname);
		private:
			map<string, Brush> loadedbrushes;
			map<string, Entity> loadedentities;
			map<string, SLObject> loadedobjects;
			map<string, string> strglobals;
			map<string, int> intglobals;
	};
}

#endif
