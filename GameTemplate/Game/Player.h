
class isi;

class Player : public IGameObject
{
public:
	Player();
	~Player();
	bool Start();
	void Update();
	void ManageState();
	void PlayAnimation();
	void Render(RenderContext& rc);
	/*void SetPosition(const Vector3& position)
	{
		m_position = position;
	}
	void SetRotation(const Quaternion& rotation)
	{
		m_rotation = rotation;
	}
	const Vector3& GetPosition() const
	{
		return m_position;
	}*/

	void Move();
	void Rotation();

	enum EnAnimationClip
	{
		enAnimationClip_idle,	//待機アニメーション
		enAnimationClip_run,	//走りアニメーション
		enAnimationClip_jump,	//ジャンプアニメーション
		enAnimationClip_Num,	//アニメーションクリップの数
	};

	ModelRender				m_modelRender;	
	SpriteRender spriteRender;
	Vector3					m_position;
	CharacterController		m_charaCon;
	Vector3					m_moveSpeed;
	isi*                    m_isi;
	Quaternion				m_rotation;
	AnimationClip m_animClips[enAnimationClip_Num];
	int playerState = 0;
	int starCount = 0;
	int G_overstate = 0;

};

