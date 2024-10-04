#include"GameManager.h"

Unit* player = new Player("길잡이");
Player* playerPtr = dynamic_cast<Player*>(player); // player를 Player 타입으로 캐스팅
Fish fish1 = Fish("민물고기"); //약
Fish fish2 = Fish("멸치"); //약
Fish fish3 = Fish("참치"); //중
Fish shark = Fish("백상아리"); //상
vector<Fish> fishes;

vector<Item> items;
Item rod1("나뭇가지", 1000,10,1,0); //공,체 살짝
Item rod2("강화된 나뭇가지", 5000,30,2,0); //공,체 많이
Item rod3("낚시왕의 낚싯대", 10000,100,5,50); //공,체 살짝, 인내심 많이
Item rod4("삼위일체", 33333,333,33,333); //근력, 인내심, 체력 올려줌

UIManager& um = UIManager::GetInstance();
ReadFile1& rf1 = ReadFile1::GetInstance();

GameManager& GameManager::GetInstance()
{
	static GameManager inst;
	return inst;
}

void GameManager::combat(int num)
{
	Fish curFish("NULL"); // 현재 물고기
	curFish = fishes[num]; // 물고기 정보 현재 물고기에 할당. curFish 값을 바꿔도 원본 물고기 데이터 영향 안 받음(물고기 객체 복사)

	int baseTimeLimit = 10; // 기본 시간 (초 단위)
	int patience = playerPtr->getPatience(); // 플레이어의 인내심 스탯 가져오기
	int timeLimit = static_cast<int>(baseTimeLimit + (patience / 10)); // 인내심에 따른 추가 시간 (예: 인내심 10당 1초 증가)

	cout <<"스페이스바를 연타해서 물고기를 낚으세요!";

	// 시작 시간을 현재 시간으로 기록
	time_t startTime = time(NULL); // 현재 시간을 초 단위로 기록

	while (true)
	{
		// 현재 시간을 계속 갱신하면서 경과 시간을 계산
		time_t currentTime = time(NULL); // 현재 시간 갱신


		if (curFish.getDead()) // 물고기가 죽었을 때
		{
			money_P += curFish.money;
			
			break; // 물고기를 잡았으면 싸움을 종료
		}

		int remainingTime = um.ShowTime(startTime, currentTime, timeLimit);

		// 시간이 제한 시간을 넘으면 while문 탈출
		if (remainingTime <= 0)
		{
			gotoxy(0, 19);
			cout << "시간 초과! 물고기가 도망갔습니다." << endl;
			break;
		}

		// 스페이스바 입력을 받았을 때
		if (_kbhit()) // 키 입력이 있을 때만 _getch() 호출
		{
			if (_getch() == ' ') // 스페이스바 입력 시
			{
				int attackDamage = player->getAttack() + (rand() % 3); // 0~2 사이 값 생성 후 1 추가
				curFish.takeDamage(attackDamage);
				// 체력 바 업데이트 (UIManager 관련 코드 추가 필요)
			}
		}
	}
}

void GameManager::addExp(int exp)
{
	this->exp += exp;
	if (this->exp >= expByLevel[level-1])
	{
		this->exp = this->exp - expByLevel[level-1];
		level++;
		um.ShowExp();
		rf1.Show(2);
		Sleep(4000);
		LevelUp();
		return;
	}
	rf1.Show(2);
	um.ShowExp();
	Sleep(4000);
}

void GameManager::LevelUp()
{
	int select = um.ShowLevelUpStat(playerPtr);
	if (select == HEALTH)
	{
		playerPtr->setMaxHealth(playerPtr->getMaxHealth() + 10); //기존 최대 체력 + 10
		player->setHealth(player->getHealth() + 10); //현재 남은 체력 + 10
	}
	else if (select == STRENGTH) player->setAttack(player->getAttack() + 1); //기존 공격력 + 1
	else if (select == PATIENCE) playerPtr->setPatience(playerPtr->getPatience() + 10); //기존 인내심 + 10
}
void GameManager::Init()
{
	CalcExp(); //경험치 초기화
	//물고기 데이터 초기화
	fishes.push_back(fish1);
	fishes.push_back(fish2);
	fishes.push_back(fish3);
	fishes.push_back(shark);
	//낚싯대 아이템에 넣기
	items.push_back(rod1);
	items.push_back(rod2);
	items.push_back(rod3);
	items.push_back(rod4);
	
	for (int i = 0; i < fishes.size(); i++)
	{
		if (fishes[i].getName() == "민물고기")
		{
		fishes[i].SetUP(1,30,5, 20,500);
		}
		else if (fishes[i].getName() == "멸치")
		{
			fishes[i].SetUP(1, 10, 2, 5,100);
		}
		else if (fishes[i].getName() == "참치")
		{
			fishes[i].SetUP(10, 150, 10, 70,2000);
		}
		else if (fishes[i].getName() == "백상아리")
		{
			fishes[i].SetUP(50, 500, 80, 150,10000);
		}
	}
}

void GameManager::CalcExp()
{
		const int levels = 30;
		int total[levels];

		// 첫 번째 값이 10, 마지막 값이 1000이 되도록 점진적으로 증가시키는 방법
		int startExp = 10;  // 0번째 인덱스의 경험치
		int endExp = 1000;  // 29번째 인덱스의 경험치

		// 총 레벨 수에서 1을 뺀 만큼의 증가 단계를 나눠줌
		for (int i = 0; i < levels; i++)
		{
			total[i] = startExp + i * (endExp - startExp) / (levels - 1);
			expByLevel[i] = total[i];
		}
}

// 별점 1점드립니다.
// 체력 채웠는데 왜 낚시터 못나가요..?
// 빨리 고쳐주세요 :(
// 별점 5점 드립니다
// 너무 제 취향입니다!!! :)
//ㄴ 플레이 해주셔서 감사합니다. 더욱 더 발전하는 fishing company가 되겠습니다.
void GameManager::Bite()
{
	//낚시대 가기를 했는데 만약 체력이 10이하라면 죽으니까 자라고 문구 출력하기
	if (player->getHealth() <= 10)
	{
		cout << "가서 잠이나 자세요" << endl;
		anyPressKey();
		return;
	}

	cout << "낚시대 던지는 중..." << endl;
	Sleep(3000);

	//현재 입질 할 확률 70퍼 줄꺼임.
	srand((unsigned int)time(NULL));
	int biteRate = (rand() % 100) + 1; //1~100
	int fish;
	if (level >= 5) fish = rand() % 4; //0,1,2,3  5레벨 이상
	else if (level >= 3) fish = rand() % 3; //0,1,2 3레벨 이상
	else fish = rand() % 2; //0,1

	if (biteRate >= 30)
	{
		//물었음-밀당하기
		cout << "물고기 힛또!" << endl;
		Sleep(1000);
		combat(fish);
		gotoxy(0, 20);
		player->takeDamage(fishes[fish].getAttack() + 10); //물고기 공격력 + 10 만큼 체력 깎기
		gotoxy(0,30);
		um.ShowHealth(player);
		Sleep(1000);
	}
	else
	{
		gotoxy(0, 20);
		//도망감
		player->takeDamage(10); //아무 수확 없을 때
		cout << endl;
		cout << "아무 일도 없었다..." << endl;
		gotoxy(0, 30);
		um.ShowHealth(player);
	}
	if (player->getDead() == true) GameOver(); //플레이어가 죽었는지 확인하여 true면 GameOver호출
	anyPressKey(); //아무키나 입력해서 나가기
}

void GameManager::Bed()
{
	cout << "자는중..." << endl;
	player->setHealth(playerPtr->getMaxHealth()); //체력을 최대체력 만큼 채워주기
	++days; //하루 증가
	Sleep(2000);
	cout << "체력 충전 완료!" << endl;
	if (days >= 4) setEnding(true); //days가 30일 이상이면 EndDay호출
	Sleep(2000);
	
}

void GameManager::GameOver()
{
	gameOver = true;
}

void GameManager::setGameOver(bool over)
{
	gameOver = over;
}

bool GameManager::getGameOver()
{
	return gameOver;
}

void GameManager::PlayerInit()
{
	playerPtr->Init();
	days = 1;
	exp = 0;
	level = 1;
}

bool GameManager::isEnding()
{
	return ending;
}

void GameManager::setEnding(bool end)
{
	ending = end;
}

void GameManager::ShowStat()
{
	um.ShowStat(playerPtr);
}

void GameManager::Store()
{
	system("cls");
	rf1.Show(3);
	gotoxy(50,0);
	cout << "소지한 돈 : " << money_P<<"원";
	cnt == 0 ? ShowItem() : ShowSaleItem(); //상품할인된 적이 없다면 기존 아이템가격, 있다면 할인된 가격 표시
	int select = 1;
	//상품할인 된 적이 없다면 대화 진행
	if (cnt == 0)
	{
		select = um.npcTalk(); //0,1
		if (select == 0)
		{
			um.npc0();
		}
		if (select == 1)
		{
			um.npc1();
		}
	}

	//0번 대화시도를 골랐다면 상품 할인 && 할인된 적이 없다면
	if (select == 0 && cnt == 0)
	{
		for (int i = 0; i < items.size(); i++)
		{
			int sale = static_cast<int>(items[i].getPrice() * 0.7); //원래 가격에 70퍼센트가격으로 받음
			items[i].setPrice(sale);
			ShowSaleItem();
		}
		cnt++;
	}
	gotoxy(1, 23);
	cout << "상품을 골라주세요 : ";
	int temp;
	cin >> temp;
	ChoiceThing(temp);
	anyPressKey();
}

void GameManager::ShowItem()
{
	int x = 30;
	int y = 10;
	int cnt = 1;
	for (int i = 0; i < items.size(); i++)
	{
		gotoxy(x + 4, y - 1);
		cout << cnt << "번";
		gotoxy(x, y);
		cout << "이름 : " << items[i].getName();
		gotoxy(x, y + 1);
		cout << "가격 : " << items[i].getPrice() << "원 ";
		gotoxy(x-2, y + 2);
		cout << "체력+" << items[i].getHealth() << " 근력+" << items[i].getDamage() << " 인내심+" << items[i].getPatience();
		x += 15;
		cnt++;
		if (cnt == 3)
		{
			x = 30;
			y = 15;
		}
	}
}
//1~4번
void GameManager::ChoiceThing(int num)
{
	int temp = num - 1;
	//플레이어가 가진 돈이 선택한 아이템 가격보다 많다면 && 선택한 아이템 수량이 있는경우
	if (money_P >= items[temp].getPrice() && items[temp].getCount() == 1)
	{
		//가능하다면 돈빼는거랑 스텟 적용하기, 수량 0으로 바꾸기
		money_P -= items[temp].getPrice();
		items[temp].setCount(); //아이템 수량 0
		int h = player->getHealth() + items[temp].getHealth(); //체력, 최대체력 건들어야 함. 현재체력 + 아이템체력
		int mx = playerPtr->getMaxHealth() + items[temp].getHealth(); //최대채력 + 아이템체력
		playerPtr->setMaxHealth(mx); //최대체력 설정
		player->setHealth(h); //체력설정
		int damage = player->getAttack() + items[temp].getDamage();//플레이어 공격력 + 아이템 공격력
		player->setAttack(damage); //공격력 설정
		int patience = playerPtr->getPatience()+ items[temp].getPatience(); //플레이어 인내심+ 아이템 인내심
		playerPtr->setPatience(patience); //인내심 설정
		cout << "구 매  성 공!  ";
	}
	else
	{
		cout << "구매할 수 없습니다!  ";
	}
}

void GameManager::ShowSaleItem()
{
	textcolor(YELLOW, BLACK);
	ShowItem();
	textcolor(WHITE, BLACK);
}

