#include "ReadFile1.h"

ReadFile1::ReadFile1()
{
    // ���� ��θ� ���Ϳ� �߰�
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
    // ���� ������ ��� �̸� �о aniContents�� ����
    for (int i = 0; i < aniFiles.size(); i++)
    {
        vector<string> fileContent; // ���� ���� ������ ���� �ӽ� ����
        string str;

        file.open(aniFiles[i]);
        if (file.is_open()) // ������ ����� ���ȴ��� Ȯ��
        {
            while (getline(file, str))
            {
                fileContent.push_back(str); // �� �پ� ���Ϳ� ����
            }
            aniContents.push_back(fileContent); // ���� ������ ��ü������ ����
        }
        file.close(); // ���� �ݱ�
    }
}

void ReadFile1::Show(int num)
{
    vector<string> temp = aniContents[num];
    // ���� ������ ������ ���Ϳ��� �ʿ��� �� ���
    for (int i = 0; i < temp.size(); i++)
    {
        cout << temp[i] << endl;
    }
}
