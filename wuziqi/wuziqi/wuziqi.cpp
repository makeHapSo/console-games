#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 15;
const string myde = " #  ";
const string botde = " *  ";
const string starde = "___ ";

class wuziqi
{
public:
	wuziqi()
	{
		
	}
public:
	int show();
	int panduan();
	void botplay();
	void play();
	void starqipan();
	void showqipan();
	void myplay();
private:
	 string qipan[N][N];
};

int main()
{
	wuziqi a;
	a.play();

	return 0;
}

int wuziqi::show()
{
	int a;
	cout <<"请选择！"<<endl;
	cout << "1.开始游戏" << endl;
	cout << "2.退出" << endl;
	cin >> a;
	switch (a)
	{
	case 1:
		showqipan();
		return 1;
		break;
	case 2:
		return 2;
		break;
	default:
		break;
	}
	return 3;
}

void wuziqi::showqipan()
{
	system("cls");
	cout << "    " << "1   " << "2   " << "3   " << "4   " << "5   " << "6   " << "7   " << "8   "
		<< "9   " << "10   " << "11   " << "12   " << "13   " << "14   " << "15   " << endl;
	for (int i = 0; i < N; i++)
	{
		if (i + 1 < 10)
			cout << i + 1 << "   ";
		else
			cout << i + 1 << "  ";
		for (int j = 0; j < N; j++)
		{
			cout << qipan[i][j];
		}
		cout << endl;
	}
	
}

void wuziqi::starqipan()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			qipan[i][j] = starde;
		}
	}
}

void wuziqi::play()
{
	int a = 0;
	int b = 0;
	starqipan();
	//show();
	b = show();
	if (b != 2)
	{
		while (1)
		{
			myplay();
			botplay();
			showqipan();
			//panduan();
			a = panduan();
			if (a == 1 && a == 2)
			{
				break;
			}
		}
	
	}
	return;
}

void wuziqi::myplay()
{
	cout <<"请输入想下的坐标"<< endl;
	int a;
	int b;
	cin >> a >> b;
	qipan[a-1][b-1] = myde;
}

void wuziqi::botplay()
{
	srand((int)time(0));
	int tempa = rand() % 15;
	int tempb = rand() % 15;
	if (qipan[tempa][tempb] != myde)
	{
		qipan[tempa][tempb] = botde;
	}

	/*for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			while (qipan[i][j] == myde)
			{
				for (int n = 0; n<15; n++)
				{
					if(i-n >= 0 && i+n <15 && j-n>= 0 && j+n<15)
					{
						if (qipan[i-n][j] == starde)
						{
							qipan[i-n][j] = botde;
						}
						else if (qipan[i + n][j] == starde)
						{
							qipan[i + n][j] = botde;
						}
						else if (qipan[i][j + n] == starde)
						{
							qipan[i][j + n] = botde;
						}
						else if (qipan[i][j - n] == starde)
						{
							qipan[i][j - n] = botde;
						}
					}
					
				}
			}
		}
	}*/
}

int wuziqi::panduan()
{
	int conten = 0;
	
	if(conten != 5)
	{
		for (int j = 0; j < N; j++) //判断列是否有五子相连
		{
			for (int i = 0; i < N; i++)
			{
				if (conten == 5)
				{
					cout << "你赢了！" << endl;
					return 1;
					break;
				}
				if (qipan[i][j] == myde)
				{
					conten += 1;
				}
				else
				{
					conten = 0;
				}
			}
			if (conten == 5)
			{
				break;
			}
		}
		for (int i = 0; i < N; i++) //判断行是否有五子相连
		{
			for (int j = 0; j < N; j++)
			{
				if (conten == 5)
				{
					cout << "你赢了！" << endl;
					return 1;
					break;
				}
				if (qipan[i][j] == myde)
				{
					conten += 1;
				}
				else
				{
					conten = 0;
				}
			}
			if (conten == 5)
			{
				break;
			}
		}

		for (int i = 0; i < N; i++) //判断对角是否五子想连
		{
			if (conten == 5)
			{
				cout << "你赢了！" << endl;
				return 1;
				break;
			}
			if (qipan[i][i] == myde)
			{
				conten += 1;
			}
			else
			{
				conten = 0;
			}
		}
	}

	if (conten != 5)
	{
		for (int j = 0; j < N; j++) //判断列是否有五子相连
		{
			for (int i = 0; i < N; i++)
			{
				if (conten == 5)
				{
					cout << "电脑赢了，你个菜鸡！" << endl;
					return 1;
					break;
				}
				if (qipan[i][j] == myde)
				{
					conten += 1;
				}
				else
				{
					conten = 0;
				}
			}
			if (conten == 5)
			{
				break;
			}
		}
		for (int j = 0; j < N; j++) //判断行是否有五子相连
		{
			for (int i = 0; i < N; i++)
			{
				if (conten == 5)
				{
					cout << "电脑赢了，你个菜鸡！" << endl;
					return 1;
					break;
				}
				if (qipan[i][j] == myde)
				{
					conten += 1;
				}
				else
				{
					conten = 0;
				}
			}
			if (conten == 5)
			{
				break;
			}
		}

		for (int i = 0; i < N; i++)
		{
			if (conten == 5)
			{
				cout << "电脑赢了，你个菜鸡！" << endl;
				return 1;
				break;
			}
			if (qipan[i][i] == myde)
			{
				conten += 1;
			}
			else
			{
				conten = 0;
			}
		}
	}
}