#include <string>
#include <vector>
#include <MINX/Graphics/Texture2D.hpp>
#include <sys/stat.h>
#include <sys/types.h>

using namespace std;

namespace MapEditor
{

string system = "/System";
string brushes = "/Brushes";
string textures = "/Textures";
string entities = "/Entities";

string check_workspace()
{
	#ifdef __GLIBC__
		string homedir = string(getenv("HOME"));
		string workspace = homedir+"/.slmapedit";
	#else
		string homedir = "C:\\Users\\Public\\"; //no detection because I don't know how
		string workspace = homedir+"\\SLMapEditor";
	#endif
	mkdir(workspace.c_str(), 0777);
	mkdir((workspace+system).c_str(), 0777);
	mkdir((workspace+brushes).c_str(), 0777);
	mkdir((workspace+textures).c_str(), 0777);
	mkdir((workspace+entities).c_str(), 0777);
	
	ofstream of;
	struct stat buf;
	if(stat((workspace+entities+"player.slet").c_str(), &buf) == -1)
	{
		of.open(workspace+entities+"player.slet");
		of << "player\
		{\
		\t!spawn spawnfunc_player\
		\tx\
		\ty\
		}";
		of.close();
	}
		
	return workspace;
}

}
