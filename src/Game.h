#pragma once
#ifndef __Game__
#define __Game__

// Core Libraries
#include <iostream>
#include <vector>

#include <SDL.h>
#include <SDL_image.h>

// Game Managers
#include "TextureManager.h"
#include "CollisionManager.h"

// Game Objects
#include "Player.h"
#include "Island.h"
#include "Ocean.h"
#include "Cloud.h"
#include "ship.h"
#include "Target.h"

class Game
{
public:
	

	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}

		return s_pInstance;
	}

	// simply set the running variable to true
	void init() { m_bRunning = true; }

	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	// public functions
	void render();
	void update();
	void handleEvents();
	void clean();

	// a function to access the private running variable
	bool running() { return m_bRunning; }

	glm::vec2 getTargetPosition();
	

	// getters
	SDL_Renderer* getRenderer();
	glm::vec2 getMousePosition();

private:
	Game();
	~Game();

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	int m_currentFrame;

	bool m_bRunning;

	static Game* s_pInstance;

	// GameObjects
	Player* m_pPlayer;
	Island* m_pIsland;
	Ocean* m_pOcean;
	ship* m_pShip;
	Target* m_pTarget;

	// cloud game objects
	int m_cloudNum = 3;
	std::vector<Cloud*> m_pClouds;

	void createGameObjects();

	glm::vec2 m_mousePosition;
};

typedef Game TheGame;

#endif /* defined (__Game__) */

