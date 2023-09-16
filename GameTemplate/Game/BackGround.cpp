#include "stdafx.h"
#include "BackGround.h"

BackGround::BackGround()
{

}

BackGround::~BackGround()
{

}

bool BackGround::Start()
{
	//モデルを読み込む。
	m_modelRender.Init("Assets/test/stage_kari01.tkm");
	//大きさ変更。
	m_modelRender.SetScale({ 0.35f,0.35f,0.35f });
	//大きさの変更を反映させるために、モデルを更新。
	m_modelRender.Update();
	//位置情報
	m_modelRender.SetPosition(m_position);

	//静的物理オブジェクトを作成。
	m_phyStaticObject.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetModel().GetWorldMatrix());

	//当たり判定描画を有効。
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();

	return true;
}

void BackGround::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}
