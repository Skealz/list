#include "stdafx.h"
#include "dirent.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;
vector<string> listDirInDir(string path);
vector<string> listFileInDir(string path);

vector<string> listDirInDir(string path)
{
	DIR *dir;
	struct dirent *ent;
	vector<string> fileList;

	dir = opendir(path.c_str());
	if (dir != NULL)
	{
		while ((ent = readdir(dir)) != NULL)
		{
			if (ent->d_type == DT_DIR)
			{
				fileList.push_back(ent->d_name);
			}
		}
		closedir(dir);
	}
	else
	{
		cout << "Cannot open directory" << path << endl;
		exit(EXIT_FAILURE);
	}
	return fileList;
}

vector<string> listFileInDir(string path)
{
	DIR *dir;
	struct dirent *ent;
	vector<string> fileList;

	dir = opendir(path.c_str());
	if (dir != NULL)
	{
		while ((ent = readdir(dir)) != NULL)
		{
			if (ent->d_type == DT_REG)
			{
				fileList.push_back(ent->d_name);
			}
		}
		closedir(dir);
	}
	else
	{
		cout << "Cannot open directory" << path << endl;
		exit(EXIT_FAILURE);
	}
	return fileList;
}