#include <string>
#include <map>

using namespace std;

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

namespace MapEditor
{
	class Entity
	{
		public:
			Entity(string name);
			string GetEntityData();
			void SetField(string fieldname, string value);
			void SetField(string fieldname, int value);
			string GetStringField(string fieldname);
			int GetIntField(string fieldname);
		private:
			string entityName;
			map<string, string> stringfields;
			map<string, int> intfields;
	};
}

#endif
