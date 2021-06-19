#include <iostream>

using namespace std;

constexpr int MAXX = 301;
constexpr int MAXY = 301;

bool tab[MAXY][MAXX];
bool copy_tab[MAXY][MAXX];

int Y, X;

void copy()
{
	for(int i = 1; i < MAXY; ++i)
	{
		for(int j = 1; j < MAXX; ++j)
		{
			copy_tab[i][j] = tab[i][j];
		}
	}

}

void neg(int y1, int x1, int y2, int x2)
{
	for(int i = y1; i <= y2; ++i)
	{
		for(int j = x1; j <= x2; ++j)
		{
			if(copy_tab[i][j])
			{
				copy_tab[i][j] = 0;
			}
			else
			{
				copy_tab[i][j] = 1;
			}
		}
	}
}

void neg_org(int y1, int x1, int y2, int x2)
{
	for(int i = y1; i <= y2; ++i)
	{
		for(int j = x1; j <= x2; ++j)
		{
			if(tab[i][j])
			{
				tab[i][j] = 0;
			}
			else
			{
				tab[i][j] = 1;
			}
		}
	}
}

void print(int y, int x)
{
	for(int i = 1; i <= y; ++i)
	{
		for(int j = 1; j <= x; ++j)
		{
			if(tab[i][j])
			{
				cout << '1';
			}
			else
			{
				cout << '0';
			}
		}

		cout << '\n';
	}

}

int calc(int y1, int x1, int y2, int x2)
{
	neg_org(y1, x1, y2, x2);
	copy();

	int moves = 0;
	for(int i = Y; i > 0; --i)
	{
		for(int j = X; j > 0; --j)
		{
			if(copy_tab[i][j])
			{
				neg(1, 1, i, j);
				++moves;
			}
		}
	}

	return moves;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int Q;
	cin >> Y >> X >> Q;
	
	int y1, y2, x1, x2;
	for(int i = 0; i < Q; ++i)
	{
		cin >> y1 >> x1 >> y2 >> x2;
		cout << calc(y1, x1, y2, x2) << '\n';
	}

	return 0;
}
