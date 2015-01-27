
#include "SLMain.hpp"
#include <MINX/Graphics/Color.hpp>

using namespace StarLegacy;


SLMain::SLMain() : Game::Game()
{
	//This is the constructor. Put stuff here that should happen when the Game is created.

	Game::SetVideoOptions(640, 480, false, "SLMain");
}

void SLMain::Initialize()
{
	//Put stuff here that should happen when the Game is initialized.
	Game::Initialize();
}

void SLMain::LoadContent()
{
	//Put stuff here that loads content for your game.
	Game::LoadContent();
}

void SLMain::UnloadContent()
{
	//Put stuff here that unloads content from your game.
	Game::UnloadContent();
}

void SLMain::Update(GameTime * gameTime)
{
	//Put stuff here to update the logic in your game each tick.
	Game::Update(gameTime);
}

void SLMain::Draw(GameTime * gameTime)
{
	SetRenderTarget(NULL, Graphics::Color::CornflowerBlue);

	//Put stuff here to draw your game each frame.
	Game::Draw(gameTime);
}
