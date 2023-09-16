#pragma once
class Test:public IGameObject
{
public:
	Test();
	~Test();
	void Update();
	void Render(RenderContext& rc);
	void Move();
	
	ModelRender modelRender;
	Vector3 position;
};

