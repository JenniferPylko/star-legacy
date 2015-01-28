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

/* THIS IS AN ALTERED SOURCE VERSION
   base64

   Copyright (C) 2004-2008 René Nyffenegger

   This source code is provided 'as-is', without any express or implied
   warranty. In no event will the author be held liable for any damages
   arising from the use of this software.

   Permission is granted to anyone to use this software for any purpose,
   including commercial applications, and to alter it and redistribute it
   freely, subject to the following restrictions:

   1. The origin of this source code must not be misrepresented; you must not
      claim that you wrote the original source code. If you use this source code
      in a product, an acknowledgment in the product documentation would be
      appreciated but is not required.

   2. Altered source versions must be plainly marked as such, and must not be
      misrepresented as being the original source code.

   3. This notice may not be removed or altered from any source distribution.

   René Nyffenegger rene.nyffenegger@adp-gmbh.ch

*/
const std::string base64_chars = 
             "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
             "abcdefghijklmnopqrstuvwxyz"
             "0123456789+/";
bool is_base64(unsigned char c) {
  return (isalnum(c) || (c == '+') || (c == '/'));
}
std::string base64_decode(std::string const& encoded_string) {
  int in_len = encoded_string.size();
  int i = 0;
  int j = 0;
  int in_ = 0;
  unsigned char char_array_4[4], char_array_3[3];
  std::string ret;

  while (in_len-- && ( encoded_string[in_] != '=') && is_base64(encoded_string[in_])) {
    char_array_4[i++] = encoded_string[in_]; in_++;
    if (i ==4) {
      for (i = 0; i <4; i++)
        char_array_4[i] = base64_chars.find(char_array_4[i]);

      char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
      char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
      char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

      for (i = 0; (i < 3); i++)
        ret += char_array_3[i];
      i = 0;
    }
  }

  if (i) {
    for (j = i; j <4; j++)
      char_array_4[j] = 0;

    for (j = 0; j <4; j++)
      char_array_4[j] = base64_chars.find(char_array_4[j]);

    char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
    char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
    char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

    for (j = 0; (j < i - 1); j++) ret += char_array_3[j];
  }

  return ret;
}

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
	if(stat((workspace+textures+"/default.png").c_str(), &buf) == -1)
	{
		of.open(workspace+textures+"/default.png");
		string data = "iVBORw0KGgoAAAANSUhEUgAAAAIAAAACCAIAAAD91JpzAAAACXBIWXMAAAsTAAALEwEAmpwYAAAAB3RJTUUH3wEcAyowQ+eHEAAAABl0RVh0Q29tbWVudABDcmVhdGVkIHdpdGggR0lNUFeBDhcAAAAQSURBVAjXY2BgYPgPhQwMABvyA/0KFqxtAAAAAElFTkSuQmCC";
		of.write(base64_decode(data).c_str(),data.length());
		of.close();
	}
		
	return workspace;
}

}
