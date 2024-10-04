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
        vector<vector<string>> aniContents; // 파일 내용을 저장할 벡터
        vector<string> aniFiles;            // 파일 경로를 저장할 벡터

        // 파일 경로를 문자열로 설정
        string fish1_1 = "./textsource/fish1_ani(1).txt";
        string fish1_2 = "./textsource/fish1_ani(2).txt";
        string getFish = "./textsource/getFish.txt";
        string npc = "./textsource/npc.txt";

        void Save();
        void Show(int num);
protected:
    ReadFile1();
};

