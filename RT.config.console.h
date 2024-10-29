#pragma once
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <direct.h>
#define echo printf
#define _OpenFile fopen
#define _CloseFil fclose
#define _WriteFile fputc
#define _ReadFile fgetc
#define _InputString getchar
#define _Check_equal(a, b) (strcmp(a, b) == 0)
void set_color(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
void echo_Blue(const char* s)
{
    set_color(1); // ��ɫ
    echo("%s", s);
    set_color(7); // ����ΪĬ����ɫ
}
void echo_Green(const char* s)
{
    set_color(2); // ��ɫ
    echo("%s", s);
    set_color(7); // ����ΪĬ����ɫ
}
void echo_Cyan(const char* s)
{
    set_color(3); // ��ɫ
    echo("%s", s);
    set_color(7); // ����ΪĬ����ɫ
}
void echo_Red(const char* s)
{
    set_color(4); // ��ɫ
    echo("%s", s);
    set_color(7);  // ����ΪĬ����ɫ
}
void echo_Purple(const char* s)
{
    set_color(5); // ��ɫ
    echo("%s", s);
    set_color(7); // ����ΪĬ����ɫ
}
void echo_Yellow(const char* s)
{
    set_color(6); // ��ɫ
    echo("%s", s);
    set_color(7); // ����ΪĬ����ɫ
}
void echo_light_red(const char* s)
{
    set_color(12); // ǳ��ɫ
    echo("%s", s);
    set_color(7); // ����ΪĬ����ɫ
}