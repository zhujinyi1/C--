#include <iostream>
#define Size 12
using namespace std;
/*测试数据： 
4 2 N 4 3
1 1 NR WL #
1 2 ERF NLR WF #
1 3 ERF NL WLF #
1 4 ER NL #
2 1 NRF SLF WL #
2 2 EL NLF WLRF SLRF #
2 3 ELRF NF WLRF SF #
2 4 ELR NF SR #
3 1 SL WR #
3 2 ELF NF WR SLR #
3 3 ELF WL SLR #
3 4 EL SR #
*/
/*    (N)
       a
 (W)d     b(E)  路口的四个方向（上北，下南，左西，右东） 
       c
      (S)
*/
/*   L  R  F
   S ab ad ac
   W bc ba bd
   N cd cb ca
   E da dc db
*/
struct Node
{
	int direction[2][2];
} Dir[Size][Size];
int node[4 * Size][4 * Size] = {0};
void csh();
int compareESWN(char ch);
int compareLRF(char ch1, char ch2);
void fy(char fx[][25]);
void CreateDG();
void DFS(int i, int visit[]);
int main()
{
	char fx[Size][25]; //输入数据
	int a1, b1, a2, b2;
	int visit[4 * Size]; //辅助数组
	char direct;
	cin >> a1 >> b1 >> direct >> a2 >> b2;
	fflush(stdin);
	for (int i = 0; i < Size; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			fx[i][j] = getchar();
			if (fx[i][j] == '#')
				break;
		}
		fflush(stdin);
	}
	for (int i = 0; i < 4 * Size; i++)
		visit[i] = 0;
	csh();
	fy(fx);
	CreateDG();

	for (int i = 0; i < 48; i++)
	{
		for (int j = 0; j < 48; j++)
			cout << node[i][j] << " ";
		cout << endl;
	}

	DFS(38, visit);

	return 0;
}
void csh()
{
	int i1, i2, j1, j2;
	for (i1 = 0; i1 < 3; i1++)
		for (j1 = 0; j1 < 4; j1++)
		{
			for (i2 = 0; i2 < 2; i2++)
				for (j2 = 0; j2 < 2; j2++)
					Dir[i1][j1].direction[i2][j2] = 0;
		}
}
void fy(char fx[][25])
{
	int i, k, t;
	for (i = 0; i < Size; i++)
	{
		k = t = 4;
		do
		{
			k = t;
			t = t + 1;
			while (fx[i][t] != ' ')
			{
				Dir[(fx[i][0] - '0') - 1][(fx[i][2] - '0') - 1].direction[compareESWN(fx[i][k])][compareLRF(fx[i][k], fx[i][t])] = 1;
				t = t + 1;
			}
			t = t + 1;
		} while (fx[i][t] != '#');
	}

	for (int i1 = 0; i1 < 3; i1++)
	{
		for (int j1 = 0; j1 < 4; j1++)
		{
			for (int i2 = 0; i2 < 4; i2++)
			{
				for (int j2 = 0; j2 < 4; j2++)
					cout << Dir[i1][j1].direction[i2][j2] << " ";
				cout << endl;
				cout << endl;
			}
			cout << endl;
		}
	}
}
int compareESWN(char ch)
{
	switch (ch)
	{
	case 'S':
		return 0;
	case 'W':
		return 1;
	case 'N':
		return 2;
	case 'E':
		return 3;
	}
}
int compareLRF(char ch1, char ch2)
{
	switch (ch1)
	{
	case 'S':
		switch (ch2)
		{
		case 'L':
			return 1;
		case 'R':
			return 3;
		case 'F':
			return 2;
		}
	case 'W':
		switch (ch2)
		{
		case 'L':
			return 2;
		case 'R':
			return 0;
		case 'F':
			return 3;
		}
	case 'N':
		switch (ch2)
		{
		case 'L':
			return 3;
		case 'R':
			return 1;
		case 'F':
			return 0;
		}
	case 'E':
		switch (ch2)
		{
		case 'L':
			return 0;
		case 'R':
			return 2;
		case 'F':
			return 1;
		}
	}
}
void CreateDG()
{
	for (int i1 = 0; i1 < 3; i1++)
		for (int j1 = 0; j1 < 4; j1++)
		{
			for (int i2 = 0; i2 < 2; i2++)
				for (int j2 = 0; j2 < 2; j2++)
					node[i1 * 16 + j1 * 4 + i2][i1 * 16 + j1 * 4 + j2] = Dir[i1][j1].direction[i2][j2];
		}
	for (int i = 1; i < Size * 4 - 6; i += 4)
		node[i][i + 6] = 1;
	for (int i = 2; i < Size * 4 - 17; i += 4)
		node[i][i + 14] = 1;
}
void DFS(int i, int visit[])
{
	visit[i] = 1;
	cout << i << " ";
	for (int j = 0; j < Size * 4; j++)
		if (!visit[j] && node[i][j] == 1)
			DFS(j, visit);
}