#pragma once
#include <windows.h>
#include <MMsystem.h>
using namespace std;
class bendra {
protected:
	char l[10][10];
	int laivai;
public:
	int get_laivai()
	{
		return laivai;
	}
	void sprogdina()
	{
		laivai--;
	}
	void lentele()
	{
		int i, j, z(1);
		cout << "   A B C D E F G H I J" << endl;
		for (i = 0; i < 10; i++)
		{
			if (z == 10) cout << z << " ";
			else
				cout << z << "  ";
			z++;
			for (j = 0; j < 10; j++)
			{
				cout << l[i][j] << " ";
			}
			cout << endl;
		}
	}
	void random()
	{

		for (int i = 4; i > 0; i--) {
			for (int j = 0; j < (5 - i); j++) 
			{
				int L, x;
				int koordx, y, tinka(1);
				int kryptis;

				koordx = rand() % 10;
				y = rand() % 10;
				if (koordx < 0 || koordx>9 || y < 0 || y>9)
				{
					tinka = 0;
					j--;
				}
				else {
					for (int a = koordx - 1; a <= koordx + 1; a++)
						for (int b = y - 1; b <= y + 1; b++)
						{
							if (a >= 0 && b >= 0 && a <= 9 && b <= 9) {
								if (l[a][b] == 'O')
								{
									tinka = 0;
									j--;
									a = 100;
									b = 100;
								}
							}
						}
				}
				if (tinka == 1 && i > 1)
				{
					kryptis = rand() % 2;
					if (kryptis == 0)
					{
						int naujasx = koordx + (i - 1);
						if (naujasx  >= 10)
						{
							tinka = 0;
							j--;
						}
						else {
							for (int a = naujasx - 1; a <= naujasx + 1; a++)
								for (int b = y - 1; b <= y + 1; b++)
								{
									if (a >= 0 && b >= 0 && a <= 9 && b <= 9) {
										if (l[a][b] == 'O')
										{
											tinka = 0;
											j--;
											a = 100;
											b = 100;
										}
									}
								}
						}
					}
					else
						if (kryptis == 1)
						{
							int naujasy = y + (i - 1);
							if (naujasy >= 10)
							{
								tinka = 0;
								j--;
							}
							else {
								for (int a = koordx - 1; a <= koordx + 1; a++)
									for (int b = naujasy - 1; b <= naujasy + 1; b++)
									{
										if (a >= 0 && b >= 0 && a <= 9 && b <= 9) {
											if (l[a][b] == 'O')
											{
												tinka = 0;
												j--;
												a = 100;
												b = 100;
											}
										}
									}
							}
						}
					if (tinka == 1) {
						l[koordx][y] = 'O';
						if (kryptis == 0)
						{
							for (int f = 1; f < i; f++)
							{
								koordx++;
								l[koordx][y] = 'O';
							}
						}
						if (kryptis == 1)
						{
							for (int f = 1; f < i; f++)
							{
								y++;
								l[koordx][y] = 'O';
							}
						}

					}
				}
				else if (tinka == 1)
				{
					l[koordx][y] = 'O';
				}
			}
		}
	}
};