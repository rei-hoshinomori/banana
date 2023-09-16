#pragma once
class BackGround : public IGameObject
{
public:
	//�����o�֐��B
	BackGround();
	~BackGround();
	bool Start();
	void Render(RenderContext& rc);
	void SetPosition(const Vector3& position)
	{
		m_position = position;
	}
	void SetScale(const Vector3& scale)
	{
		m_scale = scale;
	}

	//�����o�ϐ��Ƃ�
	ModelRender m_modelRender; //���f�������_���[�B
	PhysicsStaticObject m_phyStaticObject; //�ÓI�����I�u�W�F�N�g�B
	Vector3 m_position;
	Vector3 m_scale = Vector3::One;
};

