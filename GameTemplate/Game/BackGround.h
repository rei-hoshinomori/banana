#pragma once
class BackGround : public IGameObject
{
public:
	//メンバ関数。
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

	//メンバ変数とか
	ModelRender m_modelRender; //モデルレンダラー。
	PhysicsStaticObject m_phyStaticObject; //静的物理オブジェクト。
	Vector3 m_position;
	Vector3 m_scale = Vector3::One;
};

