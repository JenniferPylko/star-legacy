#include <string>
#include <vector>
#include <fstream>
#include <SLMINX/Graphics/Texture2D.hpp>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <iostream>
#include "tinyxml2.h"

using namespace std;
using namespace tinyxml2;

namespace MapEditor
{

string system = "System/";
string brushes = "Brushes/";
string textures = "Textures/";
string entities = "Entities/";
string objects = "SLObjects/";
string workspace;


string sl_str_t = "String";
string sl_int_t = "Int";
string sl_str_ref_t = "StringRef";
string sl_int_ref_t = "IntRef";
string sl_brush_t = "Brush";
string sl_entity_t = "Entity";
string sl_object_t = "SLObject";

unsigned long getsum(string data)
{
	unsigned long ret;
	for(int i = 0; i < data.size(); ++i)
	{
		ret += static_cast<unsigned long>(data[i]);
	}
	return ret;
}

vector<string> getdir(string dir)
{
	vector<string> files;
	DIR *dp;
	struct dirent *dirp;
	struct stat s;
	if((dp  = opendir(dir.c_str())) == NULL) {
		cerr << "Error(" << errno << ") opening " << dir << endl;
		return files;
	}

	while ((dirp = readdir(dp)) != NULL) {
		stat(dirp->d_name, &s);
		if(s.st_mode & S_IFREG)
		{
			files.push_back(string(dirp->d_name));
		}
	}
	closedir(dp);
	return files;
}

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

bool check_if_file_exists(string file)
{
	struct stat buf;
	return stat(file.c_str(), &buf) != -1;
}

string create_or_open_file(string file, string defaultData)
{
	fstream f;
	f.open(file);
	struct stat buf;
	if(stat(file.c_str(), &buf) == -1)
	{
		f << defaultData;
		f.close();
		return defaultData;
	}
	else
	{
		string returnVal;
		f >> returnVal;
		return returnVal;
	}
}

string check_workspace()
{
	#ifdef __GLIBC__
		string homedir = string(getenv("HOME"));
		workspace = homedir+"/.slmapedit/";
	#else
		string homedir = "C:\\Users\\Public\\"; //no detection because I don't know how
		workspace = homedir+"\\SLMapEditor\\";
	#endif
	mkdir(workspace.c_str(), 0777);
	mkdir((workspace+system).c_str(), 0777);
	mkdir((workspace+brushes).c_str(), 0777);
	mkdir((workspace+textures).c_str(), 0777);
	mkdir((workspace+entities).c_str(), 0777);
	mkdir((workspace+objects).c_str(), 0777);
	
	XMLPrinter p;
	ofstream of;
	if(!check_if_file_exists(workspace+"slme.conf"))
	{
		p.OpenElement("StringRef");
			p.PushAttribute("name","savedir");
			p.PushText("workspace");
		p.CloseElement();
		p.OpenElement("String");
			p.PushAttribute("name","gamedir");
			p.PushText("PATH_TO_INSTALLATION/");
		p.CloseElement();
		of.open(workspace+"slme.conf");
		of << p.CStr();
		of.close();
		p.ClearBuffer();
	}
	if(!check_if_file_exists(workspace+entities+"player.slet"))
	{
		p.OpenElement("Entity");
			p.PushAttribute("name","playerspawn");
			p.OpenElement("String");
				p.PushAttribute("name","spawn");
				p.PushText("spawnfunc_player");
			p.CloseElement();
			p.OpenElement("Int");
				p.PushAttribute("name","x");
				p.PushText("0");
			p.CloseElement();
			p.OpenElement("Int");
				p.PushAttribute("name","y");
				p.PushText("0");
			p.CloseElement();
		p.CloseElement();
		of.open(workspace+entities+"player.slet");
		of << p.CStr();
		of.close();
		p.ClearBuffer();
	}
	
	if(!check_if_file_exists(workspace+brushes+"default.slbt"))
	{
		p.OpenElement("Brush");
			p.PushAttribute("name","default");
			p.OpenElement("String");
				p.PushAttribute("name","tx_color");
				p.PushText("default.png");
			p.CloseElement();
			p.OpenElement("String");
				p.PushAttribute("name","tx_norm");
				p.PushText("default_normalmap.png");
			p.CloseElement();
			p.OpenElement("String");
				p.PushAttribute("name","tx_bloom");
				p.PushText("default_bloommap.png");
			p.CloseElement();
			p.OpenElement("Int");
				p.PushAttribute("name","tx_offset_x");
				p.PushText("0");
			p.CloseElement();
			p.OpenElement("Int");
				p.PushAttribute("name","tx_offset_y");
				p.PushText("0");
			p.CloseElement();
			p.OpenElement("Int");
				p.PushAttribute("name","tx_rotate");
				p.PushText("0");
			p.CloseElement();
			p.OpenElement("Int");
				p.PushAttribute("name","tx_scale");
				p.PushText("1");
			p.CloseElement();
			p.OpenElement("Int");
				p.PushAttribute("name","shadow_enable");
				p.PushText("1");
			p.CloseElement();
			p.OpenElement("Int");
				p.PushAttribute("name","shadow_layers");
				p.PushText("7");
			p.CloseElement();
		p.CloseElement();
		of.open(workspace+brushes+"default.slbt");
		of << p.CStr();
		of.close();
		p.ClearBuffer();
	}
	struct stat buf;
	string data;
	if(stat((workspace+textures+"default.png").c_str(), &buf) == -1)
	{
		of.open(workspace+textures+"default.png");
		data = base64_decode("iVBORw0KGgoAAAANSUhEUgAAAAIAAAACCAIAAAD91JpzAAAACXBIWXMAAAsTAAALEwEAmpwYAAAAB3RJTUUH3wEcAyowQ+eHEAAAABl0RVh0Q29tbWVudABDcmVhdGVkIHdpdGggR0lNUFeBDhcAAAAQSURBVAjXY2BgYPgPhQwMABvyA/0KFqxtAAAAAElFTkSuQmCC");
		of.write(data.c_str(),data.length());
		of.close();
	}
	if(stat((workspace+system+"save.png").c_str(), &buf) == -1)
	{
		of.open(workspace+system+"save.png");
		data = base64_decode("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");
		of.write(data.c_str(),data.length());
		of.close();
	}
	if(stat((workspace+system+"export.png").c_str(), &buf) == -1)
	{
		of.open(workspace+system+"export.png");
		data = base64_decode("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");
		of.write(data.c_str(),data.length());
		of.close();
	}
		
	return workspace;
}

}
