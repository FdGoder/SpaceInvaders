// Semess.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
#include <iostream>
#include "time.h"

using namespace std;

char Map[20][20] = {
	"###################",
	"#                 #",
	"#  @ @ @ @ @ @ @  #",
	"#   @ @ @ @ @ @   #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#        W        #",
	"###################",

};

bool endgame = false;
int gamespeed = 200;
int randomNum;
int maxHealth = 100;
int yourHealth = maxHealth;
int score;

int main()
{

	system("color 0a");//���� ����
	while (endgame == false) {
		srand(time(0));//��������� ������(slu4ainoe) �����
		system("cls");
		for (int y = 0; y < 20; y++) {

			cout << Map[y] << endl;
		}
		cout << "Score: " << score << endl;
		cout << "Health: " << yourHealth << "/" << maxHealth << endl;//���������

		for (int y = 0; y < 20; y++) {
			for (int x = 0; x < 20; x++) {

				switch (Map[y][x]) {

				case'W'://���� ���������� ��������

					if (GetAsyncKeyState(VK_LEFT) != 0) {//�������� <=

						int newX = x - 1;

						switch (Map[y][newX]) {

						case ' ':
							Map[y][x] = ' ';
							x--;
							Map[y][newX] = 'W';

							break;

						}

					}

					if (GetAsyncKeyState(VK_RIGHT) != 0) {//�������� =>
						int newX = x + 1;

						switch (Map[y][newX]) {

						case ' ':
							Map[y][x] = ' ';
							x++;
							Map[y][newX] = 'W';

							break;

						}
					}

					if (GetAsyncKeyState(VK_SPACE) != 0) {//���������� ���������(������)

						y--;
						Map[y][x] = '^';
					}
					
					break;

				case '^'://���� "��������" ��������, � ����� ������� �������: ������ ������� ^ �� ������� ����,
						 //�������� ����� ������ �����
					Map[y][x] = ' ';
					y--;
					if ((Map[y][x] != '#') && (Map[y][x] != '@')) {
						Map[y][x] = '^';
					}
					else if (Map[y][x] == '@') {
						Map[y][x] = ' ';
						score += 1;
					}

					break;

				case '@'://�������� ������������ �������� �����������(@)

					randomNum = rand() % 10 + 1;//��������� ������� ��������

					if (randomNum == 1) {

						y++;
						Map[y][x] = '*';
					}
					break;

				case '*'://���� "��������" ��������, � ����� ������� �������: ������ ������� * �� ������� ����
					Map[y][x] = ' ';
					y++;

					if ((Map[y][x] != '#') && (Map[y][x] != 'W')) {
						Map[y][x] = '*';
					}
					else if (Map[y][x] == 'W') {//�������������� ��������� ����������� � ��������
							yourHealth -= 25;
					}
					break;
				}

			}

		}
		if ((yourHealth <= 0) || (score > 12)) {
			endgame = true;
		}
		Sleep(gamespeed);
	}

	system("cls");
	if (score>12)
		cout << "\n\n\n\n\n Victory! You best player in the World! \n\n\n\n\n" << endl;
	else
		cout << "\n\n\n\n\nYou lost this game *___*\n\n\n\n\n" << endl;
	system("PAUSE");

	return 0;
}

