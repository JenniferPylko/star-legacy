#include "mapedit.hpp"
#include "utils.hpp"
#include <MINX/Graphics/Color.hpp>
#include <MINX/Graphics/TextureBatch.hpp>
#include <MINX/Graphics/ShaderFactory.hpp>

using namespace MapEditor;
using namespace MINX::Graphics;

TextureBatch* texb;


mapedit::mapedit() : Game::Game()
{
	//This is the constructor. Put stuff here that should happen when the Game is created.

	Game::SetVideoOptions(800, 600, false, "Star Legacy Map Editor");
}

void mapedit::Initialize()
{
	Game::Initialize();
	texb = new TextureBatch(ShaderFactory::GetInstance()->GetShaderAtIndex(0));
}

void mapedit::LoadContent()
{
	check_workspace();
	Game::LoadContent();
}

void mapedit::UnloadContent()
{
	//Put stuff here that unloads content from your game.
	Game::UnloadContent();
}

void mapedit::Update(GameTime * gameTime)
{
	//Put stuff here to update the logic in your game each tick.
	Game::Update(gameTime);
}

void mapedit::Draw(GameTime * gameTime)
{
	SetRenderTarget(NULL, Graphics::Color::CornflowerBlue);

	//Put stuff here to draw your game each frame.
	Game::Draw(gameTime);
}
