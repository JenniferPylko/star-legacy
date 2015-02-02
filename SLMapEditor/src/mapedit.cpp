#include "mapedit.hpp"
#include "utils.hpp"
#include <iostream>
#include <SLMINX/Graphics/Color.hpp>
#include <SLMINX/Graphics/TextureBatch.hpp>
#include <SLMINX/Graphics/ShaderFactory.hpp>
#include <SLMINX/Graphics/Texture2D.hpp>
#include <SLMINX/Input/Mouse.hpp>

using namespace MapEditor;
using namespace MINX::Graphics;
using namespace MINX::Input;
using namespace std;

TextureBatch* texb;
Texture2D* mu1;
Texture2D* mu2;

double camX, camY;

string filename;
string filedata;

Mouse* mouse;

mapedit::mapedit(char** argv, int argc) : Game::Game()
{
	//This is the constructor. Put stuff here that should happen when the Game is created.
	if(argc < 2)
	{
		cout << "ERROR: must specify map file" << endl;
		exit(1);
	}
	filename = string(argv[1]);
	Game::SetVideoOptions(800, 600, false, "Star Legacy Map Editor");
}

void mapedit::Initialize()
{
	Game::Initialize();
	texb = new TextureBatch(ShaderFactory::GetInstance()->GetShaderAtIndex(0));
	mu1 = new Texture2D(&(Color::LightCoral),1,1);
	mu2 = new Texture2D(&(Color::LightGreen),1,1);
}

void mapedit::LoadContent()
{
	check_workspace();
	filedata = create_or_open_file(filename);
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
	Game::Draw(gameTime);
}
