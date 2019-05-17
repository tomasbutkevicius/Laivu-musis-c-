#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "classbendras.h"
#include "kompiuteris.h"
#include <windows.h>
#include <MMsystem.h>
#pragma comment(lib, "Winmm.lib")
using namespace std;
/*
O- laivas
X- nuskendes laivas
laivai turi tarpusavyje nesiliesti!!!!
*/
//koma, help me
//AI 1.0411 build'e, nuo 19-04-11 pradedu daryti saudyma kompiuterio, AI
	//bandysiu su vienu masyvu zaidejui, nes kompiuteris matys juk tik tai, kas parasyta
		//reik padaryt, kad kompiuteris tik i sonus saudytu, o ne kvadratu aplink, pataikes
		//Reik padaryt pabaiga
	//bandau pridet garsa nuo 05=03
class zaidejas : public bendra
{
private:
	int ax, ay, pataike, keicia_saudyma;
public:
	zaidejas() {
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
				l[i][j] = '.';
		laivai = 10;
		pataike = 0;
		ax = 0;
		ay = 0;
		keicia_saudyma = 0;
	}
	void uzpildo()
	{
		for (int i = 4; i > 0; i--) {
			for (int j = 0; j < (5 - i); j++) {
				cout << "Enter " << i << " size ship coordinates:" << endl;
				int L, x;
				//
				int koordx, y, tinka;
				char koordy;
				char kryptis;//do while atlieka, kol galima atlikti
				tinka = 1;
				cout << "Enter line number and collumn letter:" << endl;
				cin >> koordx >> koordy;
				while (!cin)
				{
					cin.clear();
					cin.ignore(100, '\n');
					cout << "Wrong input" << endl;
					cin >> koordx >> koordy;
				}
				koordy = toupper(koordy);
				koordx--;
				y = koordy - '0' - 17;
				if (koordx < 0 || koordx>9 || y < 0 || y>9)
				{
					cout << "Bad position" << endl;
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
									cout << "Bad position" << endl;
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
					cout << "Direction ? (A- down, D- right)" << endl;
						cin >> kryptis;
					system("cls");
					if (kryptis == 'a' || kryptis == 'A')
					{
						int naujasx = koordx + (i - 1);
						if (naujasx >= 10)
						{
							cout << "Bad position" << endl;
							tinka = 0;
							//cout << koordx + i;
							j--;
						}
						else {
							//kai i apacia, tai x+3
							for (int a = naujasx - 1; a <= naujasx + 1; a++)
								for (int b = y - 1; b <= y + 1; b++)
								{
									if (a >= 0 && b >= 0 && a <= 9 && b <= 9) {
										if (l[a][b] == 'O')
										{
											cout << "Bad position" << endl;
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
						if (kryptis == 'D' || kryptis == 'd')
						{
							int naujasy = y + (i - 1);
							if (naujasy >= 10)
							{
								cout << "Bad position" << endl;
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
												cout << "Bad position" << endl;
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
						{
							cout << "Wrong input";
							j--;
							tinka = 0;
						}
					if (tinka == 1) {
						
						l[koordx][y] = 'O';
						if (kryptis == 'A' || kryptis == 'a')
						{
							for (int f = 1; f < i; f++)
							{
								koordx++;
								l[koordx][y] = 'O';
							}
						}
						if (kryptis == 'D' || kryptis == 'd')
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
					system("cls");
					l[koordx][y] = 'O';
				}
				lentele();
			}
			cout << endl << endl << endl << endl << endl << endl;
		}
	}
	void saudymas()
	{
		int kiek_prieso_laivu = get_laivai();
		int x, y;
		int galima(0);
		int saudo(0);			
		if (pataike == 1)
		{
			smart(ax, ay);
		}
		else do{
			galima = 0;
			kiek_prieso_laivu = get_laivai();

			if (get_laivai() == 0)
				break;
			while (galima == 0)
			{
				x = rand() % 10;
				y = rand() % 10;
				if (l[x][y] != 'X' && l[x][y] != '*')
					galima = 1;
			}
			if (l[x][y] == '.')
			{
				saudo = 0;
				l[x][y] = '*';
				keicia_saudyma = 0;
			}
			if (l[x][y] == 'O')
			{
				pataike = 1;
				l[x][y] = 'X';
				tikrina(x, y);
				if (kiek_prieso_laivu > get_laivai())
				{
					pataike = 0;
					saudo = 1;
				}
				else
				{
					ax = x;
					ay = y;
					smart(x, y);
					break;
				}
				cout << "Ship damage" << endl;
			}

		} while (saudo == 1);
	}
	void smart(int a, int b)
	{
		int kiek_prieso_laivu = get_laivai();
		keicia_saudyma = 0;
		int pataikyma = 1;
		int tinka(0);
		for (int i = a - 1; i <= a + 1; i++)
		{
			for (int j = b - 1; j <= b + 1; j++)
			{
				if((i <= 9 && i >= 0) && (j <= 9 && j >= 0))
				if (l[i][j] == '.' || l[i][j] == 'O')
				{
					tinka = 1;
				}
			}
		}
		if (tinka == 0)
		{
			pataike = 0;
			saudymas();
			return;
		}
		while (keicia_saudyma==0&&pataikyma==1)
		{
			tinka = 1;
			cout << "RIP" << endl;
			if (pataikyma == 1 && keicia_saudyma == 0)
			{
				if ((l[a][b - 1] != 'X' && l[a][b - 1] != '*') && ((a <= 9 && a >= 0) && (b - 1 <= 9 && b - 1 >= 0)))
				{
					tinka = 0;
					if (l[a][b - 1] == '.')
					{
						pataikyma = 0;
						l[a][b - 1] = '*';
						break;
					}
					else
						if (l[a][b - 1] == 'O')
						{
							pataikyma = 1;
							l[a][b - 1] = 'X';
							ax = a;
							ay = b - 1;
							tikrina(a, b - 1);
							if (get_laivai() < kiek_prieso_laivu)
							{
								pataike = 0;
								saudymas();
								
								return;
							}
							b = b - 2;
							a = a;
							while (pataikyma == 1 && (a <= 9 && a >= 0) && (b <= 9 && b >= 0))
							{
								if (l[a][b] == 'O')
								{
									l[a][b] = 'X';
									tikrina(a, b);
									if (get_laivai() < kiek_prieso_laivu)
									{
										pataike = 0;
										saudymas();
										return;
									}
									pataikyma = 1;
									ax = a;
									ay = b;
								}
								else
									if ((l[a][b] == '*' || l[a][b] == 'X') && (a <= 9 && a >= 0) && (b <= 9 && b >= 0))
									{
										keicia_saudyma = 1;
										break;
									}
									else
										if (l[a][b] == '.' && (a <= 9 && a >= 0) && (b <= 9 && b >= 0))
										{
											pataikyma = 0;
											l[a][b] = '*';
										}
								b = b - 1;
								a = a;
							}
						}
				}
			}
			if (pataikyma == 1 && keicia_saudyma == 0)
			{
				if ((l[a - 1][b] != 'X' && l[a - 1][b] != '*') && ((a - 1 <= 9 && a - 1 >= 0) && (b <= 9 && b >= 0)))
				{
					tinka = 0;
					if (l[a - 1][b] == '.')
					{
						pataikyma = 0;
						l[a - 1][b] = '*';
						break;
					}
					else
						if (l[a - 1][b] == 'O')
						{
							l[a - 1][b] = 'X';
							tikrina(a - 1, b);
							if (get_laivai() < kiek_prieso_laivu)
							{
								pataike = 0;
								saudymas();
								
								return;
							}
							pataikyma = 1;
							ax = a - 1;
							ay = b;
							b = b;
							a = a - 2;
							while (pataikyma == 1 && (a <= 9 && a >= 0) && (b <= 9 && b >= 0))
							{
								if (l[a][b] == 'O')
								{
									l[a][b] = 'X';
									tikrina(a, b);
									if (get_laivai() < kiek_prieso_laivu)
									{
										pataike = 0;
										saudymas();
										
										return;
									}
									ax = a;
									ay = b;
									pataike = 1;
								}
								else
									if ((l[a][b] == '*' || l[a][b] == 'X') && (a <= 9 && a >= 0) && (b <= 9 && b >= 0))
									{
										keicia_saudyma = 1;
										break;
									}
									else
										if (l[a][b] == '.' && (a <= 9 && a >= 0) && (b <= 9 && b >= 0))
										{
											pataikyma = 0;
											l[a][b] = '*';
										}
								b = b;
								a = a - 2;
							}
						}
				}
			}
			if (pataikyma == 1 && keicia_saudyma == 0)
			{
				if ((l[a][b + 1] != 'X' && l[a][b + 1] != '*') && ((a <= 9 && a >= 0) && (b + 1 <= 9 && b + 1 >= 0)))
				{
					tinka = 0;
					if (l[a][b + 1] == '.')
					{
						pataikyma = 0;
						l[a][b + 1] = '*';
						break;
					}
					else
						if (l[a][b + 1] == 'O')
						{
							l[a][b + 1] = 'X';
							ax = a;
							ay = b + 1;
							tikrina(a, b + 1);
							if (get_laivai() < kiek_prieso_laivu)
							{
								pataike = 0;
								saudymas();
								
								return;
							}
							pataikyma = 1;
							b = b + 2;
							a = a;
							while (pataikyma == 1 && (a <= 9 && a >= 0) && (b <= 9 && b >= 0))
							{
								if (l[a][b] == 'O')
								{
									l[a][b] = 'X';
									ax = a;
									ay = b;
									tikrina(a, b);
									if (get_laivai() < kiek_prieso_laivu)
									{
										pataike = 0;
										saudymas();
										
										return;
									}
									pataikyma = 1;
								}
								else
									if ((l[a][b] == '*' || l[a][b] == 'X') && (a <= 9 && a >= 0) && (b <= 9 && b >= 0))
									{
										keicia_saudyma = 1;
										break;
									}
									else
										if (l[a][b] == '.' && (a <= 9 && a >= 0) && (b <= 9 && b >= 0))
										{
											pataikyma = 0;
											l[a][b] = '*';
										}
								b = b + 1;
								a = a;
							}
						}
				}
			}
			if (pataikyma == 1 && keicia_saudyma == 0)
			{
				if ((l[a + 1][b] != 'X' && l[a + 1][b] != '*') && ((a + 1 <= 9 && a + 1 >= 0) && (b <= 9 && b >= 0)))
				{
					tinka = 0;
					if (l[a + 1][b] == '.')
					{
						pataikyma = 0;
						l[a + 1][b] = '*';
						break;
					}
					else
						if (l[a + 1][b] == 'O')
						{
							l[a + 1][b] = 'X';
							ax = a + 1;
							ay = b;
							tikrina(a + 1, b);
							if (get_laivai() < kiek_prieso_laivu)
							{
								saudymas();
								pataike = 0;
								return;
							}
							pataikyma = 1;
							b = b;
							a = a + 2;
							while (pataikyma == 1 && (a <= 9 && a >= 0) && (b <= 9 && b >= 0))
							{
								if (l[a][b] == 'O')
								{
									l[a][b] = 'X';
									ax = a;
									ay = b;
									tikrina(a, b);
									if (get_laivai() < kiek_prieso_laivu)
									{
										saudymas();
										pataike = 0;
										return;
									}
									pataike = 1;
								}
								else
									if ((l[a][b] == '*' || l[a][b] == 'X') && (a <= 9 && a >= 0) && (b <= 9 && b >= 0))
									{
										keicia_saudyma = 1;
										break;
									}
									else
										if (l[a][b] == '.' && (a <= 9 && a >= 0) && (b <= 9 && b >= 0))
										{
											pataikyma = 0;
											l[a][b] = '*';
										}
								b = b;
								a = a + 1;
							}
						}
				}
				if (tinka == 1)
				{
					pataike = 0;
					break;
				}
			}
		}
		if (keicia_saudyma)
		{
			pataike = 0;
				saudymas();
		}
}
	void tikrina(int x, int y)
		//radau klaida, cia reikejo prideti if ((l[a][b] == '.' || l[a][b] == '*') && ((a <= 9 && a >= 0) && (b <= 9 && b >= 0))) 
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
									if ((l[a][b] == '.' || l[a][b] == '*') && ((a <= 9 && a >= 0) && (b <= 9 && b >= 0)))
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
										if ((l[a][b] == '.' || l[a][b] == '*') && ((a <= 9 && a >= 0) && (b <= 9 && b >= 0)))
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
											if ((l[a][b] == '.' || l[a][b] == '*') && ((a <= 9 && a >= 0) && (b <= 9 && b >= 0)))
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
												if ((l[a][b] == '.' || l[a][b] == '*') && ((a <= 9 && a >= 0) && (b <= 9 && b >= 0)))
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
			int vienvietis(1);
			sprogdina();
			Beep(200, 444);
			Beep(200, 444);
			Beep(200, 444);
			a = x;
			b = y;
			for (int i = x - 1; i <= x + 1; i++)
			{
				for (int j = y - 1; j <= y + 1; j++)
				{
					if (l[i][j] == 'X' && (i >= 0 && i <= 9 && j >= 0 && j <= 9) && i != x && j != y)
						vienvietis = 0;
					if (l[i][j] != 'X' && (i >= 0 && i <= 9 && j >= 0 && j <= 9) && i != x && j != y)
						l[i][j] == '*';
				}
			}
			if (vienvietis == 0)
			{
				for (a = x - 1; a <= x + 1; a++)
				{
					if (a != x)
						if (a >= 0 && a <= 9 && b >= 0 && b <= 9)
							if (l[a][b] == 'X')
							{
								int a2 = a;
								if (a > x)
								{
									while (l[a2][b] != '.' && l[a2][b] != '*' && (a >= 0 && a <= 9 && b >= 0 && b <= 9))
									{
										a2 = a2 + 1;
									}
									a2 = a2 - 1;
									for (int i = a2 - 1; i <= a2 + 1; i++)
									{
										for (int j = b - 1; j <= b + 1; j++)
										{
											if (l[i][j] != 'X' && (i >= 0 && i <= 9 && j >= 0 && j <= 9) && l[i][j] != 'O')
												l[i][j] = '*';
										}
									}
								}
								else if (a < x) {
									while (l[a2][b] != '.' && l[a2][b] != '*')
									{
										a2 = a2 - 1;
									}
									a2 = a2 + 1;
									for (int i = a2 - 1; i <= a2 + 1; i++)
									{
										for (int j = b - 1; j <= b + 1; j++)
										{
											if (l[i][j] != 'X' && (i >= 0 && i <= 9 && j >= 0 && j <= 9) && l[i][j] != 'O')
												l[i][j] = '*';
										}
									}
								}
							}

				}
				for (a = y - 1; a <= y + 1; a++)
				{
					if (a != y)
						if (a >= 0 && a <= 9 && b >= 0 && b <= 9)
							if (l[a][b] == 'X')
							{
								int a2 = a;
								if (a > y)
								{
									while (l[a][a2] != '.' && l[a][a2] != '*' && (a >= 0 && a <= 9 && b >= 0 && b <= 9))
									{
										a2 = a2 + 1;
									}
									a2 = a2 - 1;
									for (int i = a - 1; i <= a + 1; i++)
									{
										for (int j = a2 - 1; j <= a2 + 1; j++)
										{
											if (l[i][j] != 'X' && (i >= 0 && i <= 9 && j >= 0 && j <= 9) && l[i][j] != 'O')
												l[i][j] = '*';
										}
									}
								}
								else if (a < y) {
									while (l[a][a2] != '.' && l[a][a2] != '*')
									{
										a2 = a2 - 1;
									}
									a2 = a2 + 1;
									for (int i = a - 1; i <= a + 1; i++)
									{
										for (int j = a2 - 1; j <= a2 + 1; j++)
										{
											if (l[i][j] != 'X' && (i >= 0 && i <= 9 && j >= 0 && j <= 9) && l[i][j] != 'O')
												l[i][j] = '*';
										}
									}
								}
							}

				}
			}
			else
			{
				for (int i = x - 1; i <= x + 1; i++)
				{
					for (int j = y - 1; j <= y + 1; j++)
					{
						if (l[i][j] != 'X' && (i >= 0 && i <= 9 && j >= 0 && j <= 9) && l[i][j] != 'O')
							l[i][j] = '*';
					}
				}
			}
			}
	}
	~zaidejas() {}

};

int main()
{
	setlocale(LC_ALL, "lithuanian");
	char koordy;
	int kl1, x, y;
	srand(time(NULL));  //sita sake, kad uztenka panaudoti viena karta programoje
	zaidejas A;
	kompiuteris B;
	A.lentele();
	cout << endl;
	B.random();
	for (int i = 200; i < 1000; i+=150)
		Beep(i, 500);
	cout << endl;
	cout << "Press 1 for random generation of your ships" << endl;
	cout << "Other numbers for manual selection" << endl;
	cin >> kl1;
	while (!cin)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Wrong input" << endl;
		cin >> kl1;
	}

	if (kl1 == 1)
	{
		A.random();
	}
	else
		A.uzpildo();

	for (int i = 0; i < 10; i++)
		cout << endl;
	cout << "Player ships:" << endl;
	A.lentele();
	cout << endl << "BOT:" << endl;
	B.matoma();

	while (B.get_laivai() > 0 && A.get_laivai() > 0)
	{
			cout << endl;
		cout << "FIRE AT WILL:" << endl;
		if(B.get_laivai() > 0 && A.get_laivai() > 0)
		B.saudymas();
		if(B.get_laivai() > 0 && A.get_laivai() > 0)
		A.saudymas();
		cout << "BOT_LENTELE:" << endl;
		B.lentele();
		cout<<"Player ships:" << endl;
		A.lentele();
		cout << "BOT:" << endl;
		B.matoma();
		
		cout << "ENEMY SHIPS LEFT: ";
		cout << B.get_laivai() << endl;
		cout << "YOUR SHIPS LEFT: ";
		cout << A.get_laivai() << endl;
		
		if (B.get_laivai() == 0)
		{
			system("cls");
			system("color 0A");			
			cout << "Victory!" << endl;
			for (int i = 200; i < 1000; i += 150)
				Beep(i, 500);
			for (int i = 1000; i > 500; i -= 170)
				Beep(i, 500);
			Beep(700, 800);
		}
		if (A.get_laivai() == 0)
		{
			system("cls");
			system("color c0");
			cout << "Defeat." << endl;
			for (int i = 200; i < 1000; i += 150)
				Beep(i, 500);
			for (int i = 1000; i > 500; i -= 170)
				Beep(i, 500);
			Beep(700, 800);
		}
	}
	cout <<"Bot Ships left: "<< B.get_laivai() << endl;
	cout <<"Your Ships left: "<< A.get_laivai();
	return 0;
}
//keturvietis-1, trivieciai-2, dvivieciai-3,vienvietis -4