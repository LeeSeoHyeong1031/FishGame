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
	int money_P = 0; //�÷��̾� ��
	int exp = 0; //�÷��̾� ����ġ
	int level = 1; //�÷��̾� ����
	int expByLevel[30] = {0}; //����ġ �� ��
	int days = 1;
	int cnt = 0;
	bool gameOver = false;
	bool ending = false;
public:
	void combat(int num); //����
	void addExp(int exp); //����ġ �߰�
	void LevelUp(); //�÷��̾� ������
	void Init(); //���� �ʱ�ȭ
	void CalcExp(); //����ġ ���
	void Bite(); //����� ���� ����
	void Bed(); //ħ��� ����
	void GameOver(); //���� ����
	void setGameOver(bool over); // ���� ���� ����
	bool getGameOver(); //���� ��������
	void PlayerInit(); //�÷��̾� �ʱ�ȭ
	bool isEnding(); //��������
	void setEnding(bool end); //���� ���� ����
	void ShowStat(); //�÷��̾� ���� �����ֱ�
	void Store(); //���� ����
	void ShowItem(); //�����ۺ����ֱ�
	void ChoiceThing(int num); //����ǰ
	void ShowSaleItem(); //���ε� ������ �����ֱ�
protected:
	GameManager() {}
	~GameManager() {}
};
