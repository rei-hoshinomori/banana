#pragma once
class Player;
class isi : public IGameObject
{
public:
	isi();
	~isi();
	void Update();
	void Render(RenderContext& renderContext);
	void Move();

	ModelRender m_modelRender;
	Vector3 position;
	//Vector3 m_moveSpeed;
	Quaternion rot;
	//CharacterController		m_charaCon;
	//int moveCount = 0;
	Player* m_player;

};