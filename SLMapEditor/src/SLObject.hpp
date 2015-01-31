#include <string>
#include <map>

using namespace std;

#ifndef SLOBJECT_HPP_
#define SLOBJECT_HPP_

namespace MapEditor
{
	class SLObject
	{
		public:
			SLObject(string name);
			void SetParam(string paramname, string value);
			void SetParam(string paramname, int value);
			string GetStringParam(string paramname);
			int GetIntParam(string paramname);
		private:
			string objectName;
			map<string, string> stringparams;
			map<string, int> intparams;
	};
}

#endif
