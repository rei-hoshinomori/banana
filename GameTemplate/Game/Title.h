#pragma once
class Title : public IGameObject
{
public:
	Title();
	~Title();

	void Render(RenderContext& rc);
	void Update();
	SpriteRender spriteRender;
	SoundSource* bgm;
	//Player* m_player;
	//BackGround* m_backGround;
	//GameCamera* m_gameCamera;

};

