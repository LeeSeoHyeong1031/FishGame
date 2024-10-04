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
				//게임 시작
				int actS = PlaceDraw();
				system("cls");
				//낚시터 가기
				if (actS == FISHING)
				{
					gm.Bite();
				}
				//스텟창 가기
				else if (actS == STAT)
				{
					gm.ShowStat();
				}
				//침대로 가기
				else if (actS == BED)
				{
					gm.Bed();
				}
				//상점 가기
				else if (actS == STORE)
				{
					gm.Store();
				}
				//메인으로 나가기
				else if (actS == EXIT)
				{
					break;
				}
			}
		}
		if (select == 1)
		{
			//스토리 출력
		}
		if (select == 2)
		{
			return 0; //게임 종료
		}
	}
}