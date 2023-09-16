#pragma once
class Player;
class star : public IGameObject
{
public:
	star();
	~star();
	void Update();
	void Render(RenderContext& renderContext);
	bool Start();
	ModelRender m_modelRender;
	Vector3 position;
	Quaternion rot;
	int moveCount = 0;
	Player* m_player;

};

