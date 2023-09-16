#include "stdafx.h"
#include "Test.h"

Test::Test()
{
	modelRender.Init("Assets/test/misaka.tkm");
}

Test::~Test()
{

}

void Test::Update()
{
	Move();

	modelRender.Update();
}

void Test::Move()
{
	modelRender.SetPosition(position);
}

void Test::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}
