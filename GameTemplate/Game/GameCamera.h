#pragma once

class Player;

class GameCamera : public IGameObject
{
public:
	GameCamera();
	~GameCamera();
	bool Start();
	void Update();

	//ƒƒ“ƒo•Ï”
	Player* m_player = nullptr;
	Vector3 m_toCameraPos = Vector3::One;
};

