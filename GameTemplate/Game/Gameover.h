#pragma once
class Gameover : public IGameObject
{
public:
	Gameover();
	~Gameover();

	void Update();
	void Render(RenderContext& rc);

	SpriteRender m_spriteRender;
};



