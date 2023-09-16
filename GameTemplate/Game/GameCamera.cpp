#include "stdafx.h"
#include "GameCamera.h"
#include "Player.h"

GameCamera::GameCamera()
{

}

GameCamera::~GameCamera()
{

}

bool GameCamera::Start()
{
	g_camera3D->SetNear(1.0f);
	g_camera3D->SetFar(40000.0f);


	m_player = FindGO<Player>("player");
	return true;


};


void GameCamera::Update()
{
	//カメラ更新
	//注視点を計算
	Vector3 target = m_player->m_position;

	target.y += 25.0f;
	
	
	Vector3 toPos = { 0.0f,35.0f,-75.0f };
	Vector3 pos = target + toPos;

	g_camera3D->SetTarget(target);
	g_camera3D->SetPosition(pos);

	g_camera3D->Update();

}
