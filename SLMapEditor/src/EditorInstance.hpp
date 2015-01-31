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
			string GetStringGlobal(string globalame);
			int GetIntGlobal(string globalname);
		private:
			map<string, Brush> brushes;
			map<string, Entity> entities;
			map<string, SLObject> objects;
			map<string, string> strglobals;
			map<string, int> intglobals;
	};
}

#endif
