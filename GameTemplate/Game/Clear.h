#pragma once
class Clear : public IGameObject
{
public:
	Clear();
	~Clear();

	void Update();
	void Render(RenderContext& rc);

	SpriteRender m_spriteRender;
};

