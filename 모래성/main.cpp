#include <iostream>
#include <vector>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int nfiled[1001][1001];
char cfiled[1001][1001];
int x, y;

int dirx[] = { 0, 0, 1, -1, -1, 1, 1, -1 };
int diry[] = { 1, -1, 0, 0, -1, 1, -1, 1 };

typedef struct pos{
	int nx, ny;
};

vector <pos> vec;


int changeInt(char a)
{
	switch (a){
	case '.': return 0;
	case '1': return 1;
	case '2': return 2;
	case '3': return 3;
	case '4': return 4;
	case '5': return 5;
	case '6': return 6;
	case '7': return 7;
	case '8': return 8;
	case '9': return 9;
	}
	return -1;
}


int main()
{
	cin >> y >> x;
	char temp;
	int num = 0;
	for (int i = 0; i < y; i++){
		for (int j = 0; j < x; j++){
			cin >> temp;
			num = changeInt(temp);
			if (num != -1)
				nfiled[i][j] = num;
		}
	}

	bool flag = true;
	int chk = 1;
	int time = 0;
	int temp_time = 0;
	int nextx = 0;
	int nexty = 0;

	while (flag)
	{
		chk = 1;
		vec.clear();
		for (int i = 0; i < y; i++){
			for (int j = 0; j < x; j++){

				if (nfiled[i][j])
				{
					temp_time = 0;
					for (int k = 0; k < 8; k++){
						nextx = j + dirx[k];
						nexty = i + diry[k];

						if (nextx < 0 || nextx >= x || nexty < 0 || nexty >= y) continue;

						if (!nfiled[nexty][nextx])
							temp_time++;
						
					}
					if (temp_time >= nfiled[i][j]){
						vec.push_back({ j, i });
						chk = 0;
					}


				}
			}
		}
		time++;
		if (chk){
			flag = false;
		}

		for (int i = 0; i < vec.size(); i++){
			nfiled[vec[i].ny][vec[i].nx] = 0;
		}
	}

	cout << time << endl;




	return 0;
}