#include "stdafx.h"
#include "Player.h"
#include "isi.h"
#include "Gameover.h"

Player::Player()
{
	
}

Player::~Player()
{

}


void Player::Move()
{
	m_moveSpeed.x = 0.0f;
	m_moveSpeed.z = 0.0f;

	Vector3 stickL;
	stickL.x = g_pad[0]->GetLStickXF();
	stickL.y = g_pad[0]->GetLStickYF();

	Vector3 forward = g_camera3D->GetForward();
	Vector3 right = g_camera3D->GetRight();
	forward.y = 0.0f;
	right.y = 0.0f;

	right *= stickL.x * 60.0f;
	forward *= stickL.y * 60.0f;

	m_moveSpeed += right + forward;

	m_moveSpeed.x += stickL.x * 60.0f;
	m_moveSpeed.z += stickL.y * 60.0f;

	if (m_charaCon.IsOnGround())
	{
		m_moveSpeed.y = 0.0f;
	}
		if (g_pad[0]->IsTrigger(enButtonA) && m_charaCon.IsOnGround())
		{
			m_moveSpeed.y = 175.0f;
		}
		else
		{
			m_moveSpeed.y -= 10.0f;
		}


		

		m_position = m_charaCon.Execute(m_moveSpeed, g_gameTime->GetFrameDeltaTime());


	

		//���W
		m_modelRender.SetPosition(m_position);
	
}

void Player::Rotation()
{
	if (fabsf(m_moveSpeed.x) >= 0.001f || fabsf(m_moveSpeed.z) >= 0.001f)
	{
		m_rotation.SetRotationYFromDirectionXZ(m_moveSpeed);
		m_modelRender.SetRotation(m_rotation);
	}
}

bool Player::Start()
{
	//�L�����R���̏�����
	m_charaCon.Init(12.5f, 37.5f, m_position);
	//�A�j���[�V����
	m_animClips[enAnimationClip_idle].Load("Assets/animData/run.tka");
	m_animClips[enAnimationClip_jump].Load("Assets/animData/jump.tka");
		
	m_animClips[enAnimationClip_idle].SetLoopFlag(true);
	//m_animClips[enAnimationClip_jump].SetLoopFlag(true);

	m_isi = FindGO<isi>("isi");

	//���f��������
	m_modelRender.Init("Assets/modelData/unityChan.tkm",m_animClips,enAnimationClip_Num,enModelUpAxisY);
	m_modelRender.SetScale(0.5f, 0.5f, 0.5f);

	

	return true;
}

void Player::Update()
{

	/*m_moveSpeed.x = g_pad[0]->GetLStickXF() * 200.0f;
	//m_moveSpeed.z += 1.0f;
	{
		if (g_pad[0]->IsTrigger(enButtonA) && m_charaCon.IsOnGround())
		{
			m_moveSpeed.y = 100.0f;

		}
		else
		{
			m_moveSpeed.y -= 20.0f;
		}
	}

	if (m_position.y < -100.0f)
	{
		DeleteGO(this);
	}*/
	

	

	m_position = m_charaCon.Execute(m_moveSpeed, g_gameTime->GetFrameDeltaTime());
	//�ړ�����
	Move();
	//��]����
	//Rotation();
	//�X�e�[�g�Ǘ�
	ManageState();
	//���[�V�����Đ�
	PlayAnimation();
	//���f���X�V
	m_modelRender.Update();
	//����
	Vector3 diff = m_position - m_isi->position;
	if (diff.Length() <= 500.0f)
	{
		//NewGO<Gameover>(0, "gameOver");
		//DeleteGO(this);
		G_overstate = 1;
	}
}

//�X�e�[�g�Ǘ�
void Player::ManageState()
{
	if (m_charaCon.IsOnGround() == true)
	{
		playerState = 1;
		//return;
	}
	else
	{
		playerState = 0;
	}
}



void Player::PlayAnimation()
{
	if (playerState == 0)
	{
		m_modelRender.PlayAnimation(enAnimationClip_jump, 0.2f);
	}
	else
	{
		m_modelRender.PlayAnimation(enAnimationClip_idle);
	}
}

void Player::Render(RenderContext& renderContext)
{
	//���f���\��
	m_modelRender.Draw(renderContext);
}



