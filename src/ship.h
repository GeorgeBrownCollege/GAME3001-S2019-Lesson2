#pragma once
#ifndef __Ship__
#define __Ship__

#include "GameObject.h"
#include "TextureManager.h"
#include "SoundManager.h"

class ship :
	public GameObject
{
public:
	ship();
	~ship();

	// Inherited via GameObject
	void draw() override;

	void update() override;

	void clean() override;

private:
	void m_move();

	void m_checkBounds();

	void m_reset();
};


#endif /* defined (__Ship__) */

