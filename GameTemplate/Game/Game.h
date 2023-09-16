#pragma once

#include "sound/SoundSource.h"

class Player;
class BackGround;
class GameCamera;
class isi;
class star;

class Game : public IGameObject
{
public:
	Game();
	~Game();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	

	ModelRender m_modelRender;
	SpriteRender spriteRender;
	Vector3 m_pos;
	Player* m_player = nullptr;
	isi* m_isi = nullptr;
	star* m_star = nullptr;
	BackGround* m_backGround = nullptr;
	GameCamera* m_gameCamera = nullptr;
	Quaternion m_rotation;
	Vector3 m_position;
	SoundSource* bgm;
	SkyCube* m_skyCube = nullptr;
	


};

