#include <string>
#include <map>

using namespace std;

#ifndef BRUSH_HPP_
#define BRUSH_HPP_

namespace MapEditor
{
	class Brush
	{
		public:
			Brush(string name);
			Brush();
			string GetName();
			void SetProperty(string propname, string value);
			void SetProperty(string propname, int value);
			string GetStringProperty(string propname);
			int GetIntProperty(string propname);
		private:
			string brushName;
			map<string, string> stringproperties;
			map<string, int> intproperties;
	};
}

#endif
