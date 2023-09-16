#include "stdafx.h"
#include "isi.h"
#include "Player.h"

isi::isi()
{
	m_modelRender.Init("Assets/test/isi.tkm");
	m_player = FindGO<Player>("Player");

	
}

isi::~isi()
{

}

void isi::Update()
{
	rot.AddRotationDegX(10.0f);
	//position.x = 0.0f;
	//.SetPosition(position);
	Move();
	m_modelRender.Update();

}

void isi::Move()
{
	position.z += 2.5f;
	m_modelRender.SetPosition(position);
}

void isi::Render(RenderContext& renderContext)
{
	m_modelRender.Draw(renderContext);
}