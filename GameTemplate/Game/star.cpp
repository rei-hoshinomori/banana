#include "stdafx.h"
#include "star.h"
#include "Player.h"
#include "isi.h"

star::star()
{

}
star::~star()
{

}

bool star::Start()
{
	m_modelRender.Init("Assets/modelData/star.tkm");
	m_player = FindGO<Player>("player");

	return true;
}

void star::Update()
{
	/*rot.AddRotationDegY(2.0f);

	if (moveCount == 0)
	{
		position.y += 1.0f;
	}
	else if (moveCount == 1)
	{
		position.y -= 1.0f;
	}
	if (position.y >= 100.0f)
	{
		moveCount = 1;
	}
	else if (position.y <= -100.0f)
	{
		moveCount = 0;
	}*/

	m_modelRender.SetPosition(position);

	m_modelRender.Update();

	Vector3 diff = position - m_player->m_position;
	if (diff.Length() <= 100.0f)
	{
		m_player->starCount += 1;

		DeleteGO(this);
	}
}

void star::Render(RenderContext& renderContext)
{
	m_modelRender.Draw(renderContext);
}