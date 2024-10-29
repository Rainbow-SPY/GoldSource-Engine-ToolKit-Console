#include <direct.h>
#include <errno.h>
#include <RT.config.console.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
int main(int argc, char* argv[]) /* argc (argument count): ��ʾ�����в���������������������������ˣ�argc ����Ϊ 1 .argv (argument vector): ��һ��ָ���ַ��������ָ�룬����ÿ���ַ�����һ�������в���������ĵ�һ��Ԫ�أ��� argv[0]��ͨ���ǳ�������ơ���������Ԫ���Ǵ��ݸ�����������в����� */
{
	if (argc == 1)
	{
		echo("Nothing in here...");
		return 0;
	}
	if (argc > 1) 
	{
		if (_Check_equal(argv[1],"-help"))
		{
			echo("-background �������˵�����\n");
			echo("-update ������\n");
			echo("-language �л�����\n");
			echo("-model ����ģ��\n");
			echo("\n");
			return 0;
			//echo("-background �������˵�����");
		}
		else if (_Check_equal(argv[1],"-version"))
		{
			char* ver = "0.1.24128";
			echo("=================================================================\n");
			echo("== Gold Source Engine ToolKit Console ver %s            ==\n", ver);
			echo("==                                                             ==\n");
			echo("== Type \"-help\" for more help.                                 ==\n");
			echo("== Write & repack by Rainbow-SPY                               ==\n");
			echo("== Copyright (C) Rainbow-SPY 2019-2024 , All rights reserved   ==\n");
			echo("=================================================================\n");
			echo("\n");
			return 0;
		}
		else if (_Check_equal(argv[1],"-background"))
		{
			if (_Check_equal(argv[2],"/?"))
			{
				echo("�������˵�����\n\n");
				echo("-background [");
				echo_Green("archive.zip");
				echo("]\n\n");
				echo("  archive.zip  ָ��һ������\"");
				echo_Green("800_[");
				echo_Yellow("1/2/3");
				echo_Green("]_[");
				echo_Yellow("a/b/c/d");
				echo_Green("]_loading.tga");
				echo("\"��ѹ����\n\n");
				echo("֧�ָ�ʽ:zip 7z rar\n");
				return 0;
			}
		}
		else if (_Check_equal(argv[1], "-language"))
		{
			if (_Check_equal(argv[2], "/?"))
			{
				echo("�л�����/��������\n\n");
				echo("-language [");
				echo_Green("language");
				echo("]\n\n");
				echo("  language  ���Դ���\n\n");
				echo("     Ŀǰ��֧�ֵĴ���:\n");
				echo("          zh-cn ��������\n");
				echo("          en-us Ӣ��(����)\n");
				return 0;
			}
			else if (_Check_equal(argv[2], "-zh-CN"))
			{
				OPENFILENAME ofn;       // common dialog box structure
				char szFile[260];      // buffer for file name
				char selectedPath[256]; // ѡ���·��

				// Initialize OPENFILENAME
				ZeroMemory(&ofn, sizeof(ofn));
				ofn.lStructSize = sizeof(ofn);
				ofn.hwndOwner = NULL;
				ofn.lpstrFile = szFile;
				ofn.lpstrFile[0] = '\0';
				ofn.nMaxFile = sizeof(szFile);
				ofn.lpstrFilter = "Half-Life �ļ���\0*.*\0"; // �ļ����͹���
				ofn.nFilterIndex = 1;
				ofn.lpstrFileTitle = NULL;
				ofn.nMaxFileTitle = 0;
				ofn.lpstrInitialDir = NULL;
				ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_ALLOWMULTISELECT;

				// Display the dialog box
				if (GetOpenFileName(&ofn))
				{
					strcpy(selectedPath, ofn.lpstrFile); // ��ȡѡ���·��
					printf("ѡ����ļ���: %s\n", selectedPath);
				}
				else
				{
					printf("δѡ���ļ��л�������\n");
					return 1;
				}

				// �滻��б��Ϊб��
				for (char* p = selectedPath; *p; ++p)
				{
					if (*p == '\\') *p = '/';
				}

				printf("���ڸ�������...\n\n");

				// ִ�� 7za.exe ��ѹ����
				RunProcess(GetCurrencyDirectory() + "bin/7-zip/7za.exe x zh-CN.lang -o\"%s\" -aoa", selectedPath);

				// ����Ŀ¼������ʡ���˾�����ļ������߼���
				// copyDirectory(...);

				return 0;
			}
			else
			{
				echo("�����﷨����ȷ ����");
				echo_Green("\"-language /?\"");
				echo("�Բ鿴�����÷�");
				return 10001;
			}
		}
		else
		{
			echo("�����﷨����ȷ ����");
			echo_Green("\"-language /?\"");
			echo("�Բ鿴�����÷�");
			return 10001;
		}
	}
	//else if (_Check_equal(argv[1], ""))
	//else if (_Check_equal(argv[1], ""))
	//else if (_Check_equal(argv[1], ""))
	//else if (_Check_equal(argv[1], ""))
	//else if (_Check_equal(argv[1], ""))
	//else if (_Check_equal(argv[1], "")
	//FILE* fp;
	//fp = OpenFile(".\\1.txt", "r");
	//CloseFile(fp);
	return 0;
}
