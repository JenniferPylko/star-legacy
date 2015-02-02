#include <string>
#include <vector>
#include <SLMINX/Graphics/Texture2D.hpp>

#ifndef UTILS_HPP_
#define UTILS_HPP_

namespace MapEditor
{

	
	extern std::string system;
	extern std::string brushes;
	extern std::string textures;
	extern std::string entities;
	extern std::string objects;
	extern std::string workspace;

	extern std::string sl_str_t;
	extern std::string sl_int_t;
	extern std::string sl_str_ref_t;
	extern std::string sl_int_ref_t;
	extern std::string sl_brush_t;
	extern std::string sl_entity_t;
	extern std::string sl_object_t;

	extern std::string system, brushes, textures, entities;
	extern std::vector<std::string> getdir(std::string name);
	extern std::string check_workspace();
	extern bool check_if_file_exists(std::string file);
	extern std::string create_or_open_file(std::string file, std::string defaultData  = "");
}

#endif
