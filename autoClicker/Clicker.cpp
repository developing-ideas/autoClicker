#include <Windows.h>
#include <iostream>
#include "Clicker.h"

bool Clicker::isClicking = false;
int Clicker::delay = 1000; //default delay
void menuSelection();



void Clicker::toggleClick(int delay) {
	try {
		isClicking = true;
		POINT currentMousePos;
		GetCursorPos(&currentMousePos);

		while (Clicker::isClicking) {
			mouse_event(MOUSEEVENTF_LEFTDOWN, currentMousePos.x, currentMousePos.y, 0, 0);
			Sleep(delay);
			mouse_event(MOUSEEVENTF_LEFTUP, currentMousePos.x, currentMousePos.y, 0, 0);
			if (GetAsyncKeyState(VK_F3) & 0x01) { Clicker::isClicking = false; }
		}
	}
	catch (std::exception e) { std::cout << e.what() << std::endl; menuSelection(); }
}


void Clicker::setDelay() {
	try {
		bool delaySet = false;
		int newDelay = 0;
		std::cout << "\nPlease enter the delay in milliseconds" << std::endl;
		std::cin >> newDelay;
		std::cin.clear();		//clear cin buffer
		std::cin.ignore(100, '\n');

		while (newDelay >= 1 && newDelay <= 600000) {
			Clicker::delay = newDelay;
			newDelay = 0;
			std::cout << "Delay Set to " << Clicker::delay << " ms" << std::endl;
			Sleep(1000);
			delaySet = true;
			break;
		}

		if (delaySet) {
			delaySet = false;
			menuSelection();
		}

		else {
			std::cout << "Invalid delay, please choose between 1-600000ms" << std::endl;
			setDelay();
		}
	}
	catch (std::exception e) { std::cout << e.what() << std::endl; menuSelection(); }
}