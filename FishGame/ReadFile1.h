#pragma once
#include"util.h"

class ReadFile1
{
public:
    static ReadFile1& GetInstance();

    ReadFile1(const ReadFile1&) = delete;
    void operator=(const ReadFile1&) = delete;
public:
        fstream file;
        vector<vector<string>> aniContents; // ���� ������ ������ ����
        vector<string> aniFiles;            // ���� ��θ� ������ ����

        // ���� ��θ� ���ڿ��� ����
        string fish1_1 = "./textsource/fish1_ani(1).txt";
        string fish1_2 = "./textsource/fish1_ani(2).txt";
        string getFish = "./textsource/getFish.txt";
        string npc = "./textsource/npc.txt";

        void Save();
        void Show(int num);
protected:
    ReadFile1();
};

