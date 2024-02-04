#include "Scene.h"

Scene::Scene()
{
	player = new Player(300, 300, 5, 5, true);
	enemy = new Enemy(500, 100, 5, true);

	titleHandle = Novice::LoadTexture("./images/title.png");
	clearHandle = Novice::LoadTexture("./images/clear.png");

	currentScene = Title_;
}
Scene::~Scene()
{
	delete player;
	delete enemy;
}

void Scene::Gameplay(char* keys, char* preKeys)
{
	switch (currentScene) {
	case Title_:
		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
			currentScene = Gamestage_;
		}
		break;

	case Gamestage_:
		Gamestage(keys);

		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
			currentScene = Clear_;
		}
		break;

	case Clear_:
		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
			currentScene = Title_;
		}
		break;
	}

	float distX = float(player->bullet_->GetPosX() - enemy->GetPosX());
	float distY = float(player->bullet_->GetPosY() - enemy->GetPosY());
	float dist = (distX * distX) + (distY * distY);
	int radius = player->bullet_->GetRadius() + enemy->GetRadius();

	if (dist <= radius * radius) {
		enemy->SetIsAlive(false);
	}

	float distanceX = float(player->GetPosX() - enemy->GetPosX());
	float distanceY = float(player->GetPosY() - enemy->GetPosY());
	float distance = (distanceX * distanceX) + (distanceY * distanceY);
	int rad= player->GetRadius() + enemy->GetRadius();

	if (distance <= rad * rad) {
		player->SetIsAlive(false);

	}

	if (player->GetIsAive() == false) {
		if (keys[DIK_R] && !preKeys[DIK_R]) {
			player->SetIsAlive(true);
		}
	}
}

void Scene::Gamestage(char* keys)
{
	player->Update(keys);
	enemy->Update();
}

void Scene::DrawTitle()
{
	Novice::DrawSprite(0, 0, titleHandle, 1.0f, 1.0f, 0, WHITE);
	player->SetIsAlive(true);
}

void Scene::DrawGamestage()
{
	player->Draw();
	enemy->Draw();
}

void Scene::DrawClear()
{
	Novice::DrawSprite(0, 0, clearHandle, 1.0f, 1.0f, 0, WHITE);
}

void Scene::Draw()
{
	switch (currentScene) {
	case Title_:
		DrawTitle();
		break;

	case Gamestage_:
		DrawGamestage();
		break;

	case Clear_:
		DrawClear();
		break;
	}
}