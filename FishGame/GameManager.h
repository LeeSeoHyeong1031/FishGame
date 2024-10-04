#pragma once
#include "Player.h"
#include "Fish.h"
#include "UIManager.h"
#include "ReadFile1.h"
#include "Item.h"

class GameManager
{
public:
	static GameManager& GetInstance();

	GameManager(const GameManager&) = delete;
	void operator=(const GameManager&) = delete;

public:
	int money_P = 0; //플레이어 돈
	int exp = 0; //플레이어 경험치
	int level = 1; //플레이어 레벨
	int expByLevel[30] = {0}; //경험치 총 량
	int days = 1;
	int cnt = 0;
	bool gameOver = false;
	bool ending = false;
public:
	void combat(int num); //전투
	void addExp(int exp); //경험치 추가
	void LevelUp(); //플레이어 레벨업
	void Init(); //게임 초기화
	void CalcExp(); //경험치 계산
	void Bite(); //물고기 입질 여부
	void Bed(); //침대로 가기
	void GameOver(); //게임 오버
	void setGameOver(bool over); // 게임 오버 설정
	bool getGameOver(); //게임 오버인지
	void PlayerInit(); //플레이어 초기화
	bool isEnding(); //엔딩인지
	void setEnding(bool end); //엔딩 여부 설정
	void ShowStat(); //플레이어 스텟 보여주기
	void Store(); //상점 가기
	void ShowItem(); //아이템보여주기
	void ChoiceThing(int num); //고른상품
	void ShowSaleItem(); //할인된 아이템 보여주기
protected:
	GameManager() {}
	~GameManager() {}
};
