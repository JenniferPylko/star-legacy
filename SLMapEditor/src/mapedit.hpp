
//AUTOGENERATED FILE: DO NOT EDIT
#include <MINX/Game.hpp>
#include <MINX/GameTime.hpp>
#ifndef MINX_MAPEDIT_HPP_
#define MINX_MAPEDIT_HPP_

using namespace MINX;

namespace MapEditor
{
	class mapedit : public Game
	{
		public:
			mapedit(char** argv, int argc);
			void Initialize();
			void LoadContent();
			void UnloadContent();
			void Update(GameTime* gameTime);
			void Draw(GameTime* gameTime);
	};
}

#endif
