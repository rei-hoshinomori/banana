#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "BackGround.h"
#include "GameCamera.h"
#include "Title.h"
#include "isi.h"
#include "star.h"
#include "Clear.h"
#include "Gameover.h"
//#include "sound/SoundEngine.h"

Game::Game()
{

}

Game::~Game()
{
	DeleteGO(m_player);
	DeleteGO(m_gameCamera);
	DeleteGO(bgm);
	DeleteGO(m_backGround);
	DeleteGO(m_isi);
	DeleteGO(m_star);
}


bool Game::Start()
{
	m_gameCamera = NewGO<GameCamera>(0);
	m_player = NewGO<Player>(0, "player");
	m_isi = NewGO<isi>(0,"isi");
	m_isi -> position = { 0.0f,250.0f,-1500.0f };

	m_star = NewGO<star>(0,"star");
	//m_star -> position = { 0.0f,50.0f,500.0f };
	m_star->position.Set(0.0f, 60.0f, 6500.0f);
	//m_star->position.Set(0.0f, 60.0f, 500.0f);

	m_backGround = NewGO<BackGround>(0, "backGround");
	g_soundEngine->ResistWaveFileBank(0, "Assets/sound/Murder.wav");

	m_skyCube = NewGO<SkyCube>(0, "skycube");
	g_renderingEngine->SetAmbientByIBLTexture(m_skyCube->GetTextureFilePath(), 0.1f);
	g_renderingEngine->SetCascadeNearAreaRates(0.01f, 0.1f, 0.5f);

	
	bgm = NewGO<SoundSource>(0);
	bgm->Init(0);
	bgm->Play(true);

	m_player->starCount;

	return true;

	
}

void Game::Update()
{
	if (m_player->starCount == 1)
	{
		NewGO<Clear>(0, "gameClear");
		DeleteGO(this);
	}
	
	// g_renderingEngine->DisableRaytracing();
	m_modelRender.Update();

	if (m_player->m_position.y < -500.0f)
	{
		NewGO<Gameover>(0, "gameOver");
		//spriteRender.Init("Assets/dds/misaka02.dds", 1920.0f, 1080.0f);
		DeleteGO(this);

	}
	if (m_player->G_overstate == 1)
	{
		NewGO<Gameover>(0, "gameOver");
		//spriteRender.Init("Assets/dds/misaka02.dds", 1920.0f, 1080.0f);
		DeleteGO(this);

	}

	

	//ÉÇÉfÉãçXêV
	m_modelRender.Update();
}

void Game::Render(RenderContext& rc)
{
	//m_modelRender.Draw(rc);
}

