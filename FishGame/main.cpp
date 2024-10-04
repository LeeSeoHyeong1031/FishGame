#include"Player.h"
#include"Fish.h"
#include"UIManager.h"
int main()
{
	GameManager& gm = GameManager::GetInstance();
	UIManager& um = UIManager::GetInstance();
	ReadFile1& rf1 = ReadFile1::GetInstance();
	
	cursorView();
	while(1)
	{
		gm.Init();
		gm.setGameOver(false);
		gm.setEnding(false);
		gm.PlayerInit();
		titleDraw();
		int select = menuDraw();
		if (select == 0)
		{
			while (1)
			{
				if (gm.getGameOver())
				{
					system("cls");
					um.ShowTextGameOver(6);
					Sleep(5000);
					break;
				}
				if (gm.isEnding())
				{
					system("cls");
					um.ShowEnding();
					Sleep(4000);
					break;
				}
				system("cls");
				um.ShowDay();
				//���� ����
				int actS = PlaceDraw();
				system("cls");
				//������ ����
				if (actS == FISHING)
				{
					gm.Bite();
				}
				//����â ����
				else if (actS == STAT)
				{
					gm.ShowStat();
				}
				//ħ��� ����
				else if (actS == BED)
				{
					gm.Bed();
				}
				//���� ����
				else if (actS == STORE)
				{
					gm.Store();
				}
				//�������� ������
				else if (actS == EXIT)
				{
					break;
				}
			}
		}
		if (select == 1)
		{
			//���丮 ���
		}
		if (select == 2)
		{
			return 0; //���� ����
		}
	}
}