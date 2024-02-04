#pragma once
#include "Player.h"
#include "Enemy.h"
#include "GameScene.h"

class Scene
{
private:
	Player* player;
	Enemy* enemy;
	Gamescene currentScene;

	int titleHandle;
	int clearHandle;

public:
	Scene();
	~Scene();

	void Gameplay(char* keys, char* preKeys);

	void Gamestage(char* keys);

	void DrawTitle();
	void DrawGamestage();
	void DrawClear();

	void Draw();
};