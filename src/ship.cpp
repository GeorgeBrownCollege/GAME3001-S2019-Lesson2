#include "ship.h"
#include "Game.h"



ship::ship()
{
	TheTextureManager::Instance()->load("../Assets/textures/ship3.png",
		"ship", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("ship");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(500.0f, 100.0f));
	setVelocity(glm::vec2(-3.0f, 0));
	//m_reset();
	setIsColliding(false);
	setType(GameObjectType::SHIP);

	/*
	SoundManager::Instance()->load("../Assets/audio/yay.ogg",
		"yay", sound_type::SOUND_SFX);
	*/
}


ship::~ship()
{
}

void ship::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;
	TheTextureManager::Instance()->draw("ship", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), true);
}

void ship::update()
{
	m_move();
	m_checkBounds();
}

void ship::clean()
{
}

void ship::m_move()
{
	glm::vec2 newPosition = getPosition() + getVelocity();
	setPosition(newPosition);
}

void ship::m_checkBounds()
{
	if (getPosition().x <= TheGame::Instance()->getTargetPosition().x) {
		setVelocity(glm::vec2(0, 0));
	}
}

void ship::m_reset()
{
	setIsColliding(false);
	int halfWidth = getWidth() * 0.5;
	int xComponent = rand() % (640 - getWidth()) + halfWidth + 1;
	int yComponent = -getHeight();
	setPosition(glm::vec2(xComponent, yComponent));
}
