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
	//���f����ǂݍ��ށB
	m_modelRender.Init("Assets/test/stage_kari01.tkm");
	//�傫���ύX�B
	m_modelRender.SetScale({ 0.35f,0.35f,0.35f });
	//�傫���̕ύX�𔽉f�����邽�߂ɁA���f�����X�V�B
	m_modelRender.Update();
	//�ʒu���
	m_modelRender.SetPosition(m_position);

	//�ÓI�����I�u�W�F�N�g���쐬�B
	m_phyStaticObject.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetModel().GetWorldMatrix());

	//�����蔻��`���L���B
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();

	return true;
}

void BackGround::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}
