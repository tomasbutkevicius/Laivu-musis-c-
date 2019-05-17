#include	<iostream>
#include "classbendras.h"

using namespace std;
class kompiuteris : public bendra
{
private:
	char m[10][10];
public:
	kompiuteris() {
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
				l[i][j] = '.';
		laivai = 10;
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
				m[i][j] = '.';
	}
	void saudymas()
	{
		int x, y, pataike(0);
		char koordy;
		do {
			cout << "Enter line number and collumn letter" << endl;
			cin >> x >> koordy;
			while (!cin)
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Wrong input" << endl;
				cin >> x >> koordy;
			}
			koordy = toupper(koordy);
			x--;
			y = koordy - '0' - 17;
			//////////////////////
			if (l[x][y] == '.' || l[x][y] == 'X' || l[x][y] == '*') //return 0 atitinka nepataikyma
			{
				pataike = 0;
				if (l[x][y] == '.' || l[x][y] == '*')
					m[x][y] = '*';
				else
					m[x][y] = 'X';
			}
			else
				if (l[x][y] == 'O') //return 1 atitinka pataikyma
				{
					pataike = 1;

					l[x][y] = 'X';
					m[x][y] = 'X';
					tikrina(x, y);
					matoma();
					cout << "BOT SHIPS LEFT:" << " " << laivai << endl;
				}
			if (get_laivai() == 0)
				break;
		} while (pataike == 1);
		//return 2 atitiks laivo sunaikinima
		system("cls");
	}
	void tikrina(int x, int y) //!!! Crashina prie sito, kai saudau, gal reikia prideti isimti, kai prieina krasta ????
	{
		int laivas(0);
		int a, b;
		for (a = x - 1; a <= x + 1; a++)
		{
			for (b = y - 1; b <= y + 1; b++)
			{
				if (l[a][b] == 'O' && ((a <= 9 && a >= 0) && (b <= 9 && b >= 0)))
				{
					laivas = 1;
					a = 100;
					b = 100;
				}
				else
					if (l[a][b] == 'X' && ((a <= 9 && a >= 0) && (b <= 9 && b >= 0)))
					{
						int end(0), q(0), w(0);
						q = a;
						w = b;
						if (x == a && y < b)
						{
							//q++;
							b++;
							while (end == 0)
							{
								if (a > 9 || a < 0 || b>9 || b < 0)
								{

									end = 1;
								}
								if (l[a][b] == 'O' && ((a <= 9 && a >= 0) && (b <= 9 && b >= 0)))
								{
									end = 1;
									laivas = 1;
									a = 100;
									b = 100;
								}
								else
									if (l[a][b] == '.' && ((a <= 9 && a >= 0) && (b <= 9 && b >= 0)))
									{
										end = 1;
									}
								b++;
							}
							a = q;
							b = w;
						}
						else
							if (x == a && y > b)
							{
								//q++;
								b--;
								while (end == 0)
								{
									if (a > 9 || a < 0 || b>9 || b < 0)
									{
										end = 1;
									}
									if (l[a][b] == 'O' && ((a <= 9 && a >= 0) && (b <= 9 && b >= 0)))
									{
										end = 1;
										laivas = 1;
										a = 100;
										b = 100;
									}
									else
										if (l[a][b] == '.' && ((a <= 9 && a >= 0) && (b <= 9 && b >= 0)))
										{
											end = 1;
										}
									b--;
								}
								a = q;
								b = w;
							}
							else
								if (x > a && y == b)
								{
									//w++;
									a--;
									while (end == 0)
									{
										if (a > 9 || a < 0 || b>9 || b < 0)
										{
											end = 1;
										}
										if (l[a][b] == 'O' && ((a <= 9 && a >= 0) && (b <= 9 && b >= 0)))
										{
											end = 1;
											laivas = 1;
											a = 100;
											b = 100;
										}
										else
											if (l[a][b] == '.' && ((a <= 9 && a >= 0) && (b <= 9 && b >= 0)))
											{
												end = 1;
											}
										a--;
									}
									a = q;
									b = w;
								}
								else
									if (x < a && y == b)
									{
										//w++;
										a++;
										while (end == 0)
										{
											if (a > 9 || a < 0 || b>9 || b < 0)
											{
												end = 1;
											}
											if (l[a][b] == 'O' && ((a <= 9 && a >= 0) && (b <= 9 && b >= 0)))
											{
												end = 1;
												laivas = 1;
												a = 100;
												b = 100;
											}
											else
												if (l[a][b] == '.' && ((a <= 9 && a >= 0) && (b <= 9 && b >= 0)))
												{
													end = 1;
												}
											a++;
										}
										a = q;
										b = w;
									}
					}
			}
		}
		//Kai laivas numustas:
		if (laivas == 0)
		{
			sprogdina();
			Beep(200, 444);
			Beep(200, 444);
			Beep(200, 444);
		}
	}
	void matoma() {
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
				cout << m[i][j] << " ";
			}
			cout << endl;
		}
	}
	~kompiuteris() {}
};