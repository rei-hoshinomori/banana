#include "stdafx.h"
#include "Gameover.h"
#include "Title.h"

Gameover::Gameover()
{
	m_spriteRender.Init("Assets/test/gameover.DDS",1920.0f,1080.0f);
}

Gameover::~Gameover()
{

}

void Gameover::Update()
{
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		NewGO<Title>(0, "title");
		DeleteGO(this);
	}
}

void Gameover::Render(RenderContext& rc)
{
	m_spriteRender.Draw(rc);
}