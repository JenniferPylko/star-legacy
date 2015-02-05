
#include "SLMain.hpp"
#include <SLMINX/Graphics/Color.hpp>
#include <SLMINX/Graphics/TextureBatch.hpp>
#include <SLMINX/Graphics/Texture2D.hpp>
#include <SLMINX/Graphics/ShaderFactory.hpp>

using namespace StarLegacy;
using namespace MINX;
using namespace MINX::Graphics;


TextureBatch* texb;
Texture2D* tex;
Texture2D* tex2;


SLMain::SLMain() : Game::Game()
{
	//This is the constructor. Put stuff here that should happen when the Game is created.

	Game::SetVideoOptions(640, 480, false, "SLMain");
}

void SLMain::Initialize()
{
	Game::Initialize();
}

void SLMain::LoadContent()
{
	texb = new TextureBatch(ShaderFactory::GetInstance()->GetShaderAtIndex(0));
	tex = new Texture2D("test.png");
	tex2 = new Texture2D("test2.png");
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
	texb->Draw(tex, Vector2(20, 20), Vector2(sin(gameTime->GetElapsedMillis()/1000.0)+1,cos(gameTime->GetElapsedMillis()/1000.0)+1)*540);
	texb->Draw(tex2, Vector2(80, 20), Vector2(540,540));
	texb->DrawLoadedTextures();
	Game::Draw(gameTime);
}
