#include "stdafx.h"
#include "Clear.h"
#include "Title.h"

Clear::Clear()
{
	m_spriteRender.Init("Assets/test/clear1.DDS",1920.0f,1080.0f);
}

Clear::~Clear()
{

}

void Clear::Update()
{
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		NewGO<Title>(0, "title");
		DeleteGO(this);
	}
}

void Clear::Render(RenderContext& rc)
{
	m_spriteRender.Draw(rc);
}

