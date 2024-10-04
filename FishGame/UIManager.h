#pragma once
#include "GameManager.h"
class UIManager
{
public:
	static UIManager& GetInstance();

	UIManager(const UIManager&) = delete;
	void operator=(const UIManager&) = delete;
protected:
	UIManager() {}
	~UIManager() {}

public:
	void ShowExp();
	void ShowHealth(Unit* player);
	int ShowTime(time_t startTime, time_t currentTime, int timeLimit);
	void ShowTextGameOver(int num);
	void ShowDay();
	void ShowEnding();
	void ShowStat(Player* player);
	int ShowLevelUpStat(Player* player);
	int npcTalk();
	void npc0();
	void npc1();
};

