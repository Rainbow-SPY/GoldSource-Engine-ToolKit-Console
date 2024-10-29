#include <direct.h>
#include <errno.h>
#include <RT.config.console.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
int main(int argc, char* argv[]) /* argc (argument count): 表示命令行参数的数量，包括程序名本身。因此，argc 至少为 1 .argv (argument vector): 是一个指向字符串数组的指针，其中每个字符串是一个命令行参数。数组的第一个元素（即 argv[0]）通常是程序的名称。接下来的元素是传递给程序的命令行参数。 */
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
			echo("-background 更改主菜单背景\n");
			echo("-update 检查更新\n");
			echo("-language 切换语言\n");
			echo("-model 更改模型\n");
			echo("\n");
			return 0;
			//echo("-background 更改主菜单背景");
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
				echo("更改主菜单背景\n\n");
				echo("-background [");
				echo_Green("archive.zip");
				echo("]\n\n");
				echo("  archive.zip  指定一个含有\"");
				echo_Green("800_[");
				echo_Yellow("1/2/3");
				echo_Green("]_[");
				echo_Yellow("a/b/c/d");
				echo_Green("]_loading.tga");
				echo("\"的压缩包\n\n");
				echo("支持格式:zip 7z rar\n");
				return 0;
			}
		}
		else if (_Check_equal(argv[1], "-language"))
		{
			if (_Check_equal(argv[2], "/?"))
			{
				echo("切换界面/语音语言\n\n");
				echo("-language [");
				echo_Green("language");
				echo("]\n\n");
				echo("  language  语言代码\n\n");
				echo("     目前受支持的代码:\n");
				echo("          zh-cn 简体中文\n");
				echo("          en-us 英语(美国)\n");
				return 0;
			}
			else if (_Check_equal(argv[2], "-zh-CN"))
			{
				OPENFILENAME ofn;       // common dialog box structure
				char szFile[260];      // buffer for file name
				char selectedPath[256]; // 选择的路径

				// Initialize OPENFILENAME
				ZeroMemory(&ofn, sizeof(ofn));
				ofn.lStructSize = sizeof(ofn);
				ofn.hwndOwner = NULL;
				ofn.lpstrFile = szFile;
				ofn.lpstrFile[0] = '\0';
				ofn.nMaxFile = sizeof(szFile);
				ofn.lpstrFilter = "Half-Life 文件夹\0*.*\0"; // 文件类型过滤
				ofn.nFilterIndex = 1;
				ofn.lpstrFileTitle = NULL;
				ofn.nMaxFileTitle = 0;
				ofn.lpstrInitialDir = NULL;
				ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_ALLOWMULTISELECT;

				// Display the dialog box
				if (GetOpenFileName(&ofn))
				{
					strcpy(selectedPath, ofn.lpstrFile); // 获取选择的路径
					printf("选择的文件夹: %s\n", selectedPath);
				}
				else
				{
					printf("未选择文件夹或发生错误\n");
					return 1;
				}

				// 替换反斜杠为斜杠
				for (char* p = selectedPath; *p; ++p)
				{
					if (*p == '\\') *p = '/';
				}

				printf("正在更改语言...\n\n");

				// 执行 7za.exe 解压命令
				RunProcess(GetCurrencyDirectory() + "bin/7-zip/7za.exe x zh-CN.lang -o\"%s\" -aoa", selectedPath);

				// 复制目录（这里省略了具体的文件复制逻辑）
				// copyDirectory(...);

				return 0;
			}
			else
			{
				echo("命令语法不正确 键入");
				echo_Green("\"-language /?\"");
				echo("以查看具体用法");
				return 10001;
			}
		}
		else
		{
			echo("命令语法不正确 键入");
			echo_Green("\"-language /?\"");
			echo("以查看具体用法");
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
