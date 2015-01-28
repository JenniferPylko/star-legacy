#include <string>
#include <vector>
#include <fstream>
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
string workspace;

string check_workspace()
{
	#ifdef __GLIBC__
		string homedir = string(getenv("HOME"));
		workspace = homedir+"/.slmapedit";
	#else
		string homedir = "C:\\Users\\Public\\"; //no detection because I don't know how
		workspace = homedir+"\\SLMapEditor";
	#endif
	mkdir(workspace.c_str(), 0777);
	mkdir((workspace+system).c_str(), 0777);
	mkdir((workspace+brushes).c_str(), 0777);
	mkdir((workspace+textures).c_str(), 0777);
	mkdir((workspace+entities).c_str(), 0777);
	
	ofstream of;
	struct stat buf;
	if(stat((workspace+"/slme.conf").c_str(), &buf) == -1)
	{
		of.open(workspace+"/slme.conf");
		of << "game ref sl\
		savedir   str@ workspace\
		exportdir str@ game.dir";
		of.close();
	}
	if(stat((workspace+system+"/sl.slg").c_str(), &buf) == -1)
	{
		of.open(workspace+system+"/sl.slg");
		of << "sl\
		{\
		\tdir str PATH_TO_INSTALLATION/\
		}";
		of.close();
	}
	if(stat((workspace+entities+"/player.slet").c_str(), &buf) == -1)
	{
		of.open(workspace+entities+"/player.slet");
		of << "player\
		{\
		\tspawn str spawnfunc_player\
		\tx      int\
		\ty      int\
		}";
		of.close();
	}
	if(stat((workspace+brushes+"/default.slbt").c_str(), &buf) == -1)
	{
		of.open(workspace+brushes+"/default.slbt");
		of << "default\
		{\
		\ttx_color      str Textures/default.png\
		\ttx_norm       str Textures/default_normalmap.png\
		\ttx_bloom      str Textures/default_bloommap.png\
		\ttx_offset_x   int 0\
		\ttx_offset_y   int 0\
		\ttx_rotate     int 0\
		\ttx_scale      int 1\
		\tdisp_mode     int 0\
		\tshadow_enable int 1\
		\tshadow_pt1_x  int 1\
		\tshadow_pt1_y  int 0\
		\tshadow_pt2_x  int 1\
		\tshadow_pt2_y  int 2\
		\tshadow_a_min  int 0\
		\tshadow_a_max  int 180\
		\tshadow_layers int 7\
		}";
		of.close();
	}
		
	return workspace;
}

}
