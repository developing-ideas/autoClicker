#include <Windows.h>
#include <iostream>
#include "Clicker.h"

//Forward Declaration
void printMenu();
void menuSelection();

int main()
{
	SetConsoleTitleA("Auto Clicker");
	menuSelection();
}


void printMenu() {
	std::cout << "F1. Set Delay\nF2. Start Clicking\nF3. Stop Clicking\n\nF8. Exit" << std::endl;
}

extern void menuSelection() {
	system("cls");
	printMenu();
	while (!GetAsyncKeyState(VK_F8)) {
		if (GetAsyncKeyState(VK_F1) & 0x01) { Clicker::setDelay(); }
		else if (GetAsyncKeyState(VK_F2) & 0x01) { Clicker::toggleClick(Clicker::delay); }
	}
}
