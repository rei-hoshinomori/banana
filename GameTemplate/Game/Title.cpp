#include "stdafx.h"
#include "Title.h"

#include "Game.h"

Title::Title()
{
	spriteRender.Init("Assets/test/title1.dds",1920.0f,1080.0f);
}

Title::~Title()
{
	
}


void Title::Update()
{
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		NewGO<Game>(0);
		DeleteGO(this);
	}
}

void Title::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}