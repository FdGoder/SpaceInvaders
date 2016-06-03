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

	system("color 0a");//цвет поля
	while (endgame == false) {
		srand(time(0));//генерация рандом(slu4ainoe) числа
		system("cls");
		for (int y = 0; y < 20; y++) {

			cout << Map[y] << endl;
		}
		cout << "Score: " << score << endl;
		cout << "Health: " << yourHealth << "/" << maxHealth << endl;//интерфейс

		for (int y = 0; y < 20; y++) {
			for (int x = 0; x < 20; x++) {

				switch (Map[y][x]) {

				case'W'://Кейс управления танчиком

					if (GetAsyncKeyState(VK_LEFT) != 0) {//движение <=

						int newX = x - 1;

						switch (Map[y][newX]) {

						case ' ':
							Map[y][x] = ' ';
							x--;
							Map[y][newX] = 'W';

							break;

						}

					}

					if (GetAsyncKeyState(VK_RIGHT) != 0) {//движение =>
						int newX = x + 1;

						switch (Map[y][newX]) {

						case ' ':
							Map[y][x] = ' ';
							x++;
							Map[y][newX] = 'W';

							break;

						}
					}

					if (GetAsyncKeyState(VK_SPACE) != 0) {//управление выстрелом(пробел)

						y--;
						Map[y][x] = '^';
					}
					
					break;

				case '^'://сама "анимация" выстрела, а также условия запрета: вылета снаряда ^ за пределы поля,
						 //убийство более одного врага
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

				case '@'://случайно генерируемые выстрелы инопланетян(@)

					randomNum = rand() % 10 + 1;//изменение частоты стрельбы

					if (randomNum == 1) {

						y++;
						Map[y][x] = '*';
					}
					break;

				case '*'://сама "анимация" выстрела, а также условие запрета: вылета снаряда * за пределы поля
					Map[y][x] = ' ';
					y++;

					if ((Map[y][x] != '#') && (Map[y][x] != 'W')) {
						Map[y][x] = '*';
					}
					else if (Map[y][x] == 'W') {//Взаимодействие выстрелов инопланетян с танчиком
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

