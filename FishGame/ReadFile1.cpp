#include "ReadFile1.h"

ReadFile1::ReadFile1()
{
    // 파일 경로를 벡터에 추가
    aniFiles.push_back(fish1_1);
    aniFiles.push_back(fish1_2);
    aniFiles.push_back(getFish);
    aniFiles.push_back(npc);
    Save();
}

ReadFile1& ReadFile1::GetInstance()
{
    static ReadFile1 inst;
    return inst;
}

void ReadFile1::Save()
{
    // 파일 내용을 모두 미리 읽어서 aniContents에 저장
    for (int i = 0; i < aniFiles.size(); i++)
    {
        vector<string> fileContent; // 파일 내용 저장을 위한 임시 벡터
        string str;

        file.open(aniFiles[i]);
        if (file.is_open()) // 파일이 제대로 열렸는지 확인
        {
            while (getline(file, str))
            {
                fileContent.push_back(str); // 한 줄씩 벡터에 저장
            }
            aniContents.push_back(fileContent); // 파일 내용을 전체적으로 저장
        }
        file.close(); // 파일 닫기
    }
}

void ReadFile1::Show(int num)
{
    vector<string> temp = aniContents[num];
    // 파일 내용을 저장한 벡터에서 필요할 때 출력
    for (int i = 0; i < temp.size(); i++)
    {
        cout << temp[i] << endl;
    }
}
