#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int nfiled[1001][1001];
int nfiled_copy[1001][1001];

int x, y;

int dirx[] = { 0, 0, 1, -1, -1, 1, 1, -1 };
int diry[] = { 1, -1, 0, 0, -1, 1, -1, 1 };

typedef struct pos{
	int nx, ny;
};

vector <pos> vec;
queue <pos> que[2];

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

	int que_num = 0;
	pos cur = { 0, 0 };
	int nextx = 0;
	int nexty = 0;
	int time = 0;

	for (int i = 0; i < y; i++){
		for (int j = 0; j < x; j++){
			if (nfiled[i][j]){
				for (int k = 0; k < 8; k++){

					nextx = j + dirx[k];
					nexty = i + diry[k];

					if (nextx < 0 || nextx >= x || nexty < 0 || nexty >= y) continue;

					if (!nfiled[nexty][nextx])
						nfiled_copy[i][j]++;
				}

				if (nfiled_copy[i][j] >= nfiled[i][j]){
					que[que_num].push({ j, i });
					vec.push_back({ j, i });
				}
			}
		}
	}
	for (int i = 0; i < vec.size(); i++){
		nfiled[vec[i].ny][vec[i].nx] = 0;
	}
	
	while (!que[que_num].empty())
	{
		while (!que[que_num].empty())
		{
			cur = que[que_num].front();
			que[que_num].pop();

			for (int i = 0; i < 8; i++){
				nextx = cur.nx + dirx[i];
				nexty = cur.ny + diry[i];

				if (nextx < 0 || nextx >= x || nexty < 0 || nexty >= y || !nfiled[nexty][nextx]) continue;

				nfiled_copy[nexty][nextx]++;

				if (nfiled_copy[nexty][nextx] >= nfiled[nexty][nextx]){
					que[!que_num].push({ nextx, nexty });
					nfiled[nexty][nextx] = 0;
				}
			}
		}
		que_num = !que_num;
		time++;
	}



	cout << time << endl;
	return 0;
}