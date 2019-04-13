#pragma once
class State
{
public:
	State();
	~State();

	virtual void update();
	virtual void draw();
};

