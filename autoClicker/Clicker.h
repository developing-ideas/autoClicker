#pragma once

static class Clicker {
private:
	static bool isClicking;

public:
	static int delay;

	static void toggleClick(int delay);
	static void setDelay();
};