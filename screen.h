#ifndef __H_SCREEN__
#define __H_SCREEN__

struct ScreenPoint {
	int x, y;
};

class Screen {
	int pixWidth, pixHeight; // width/height in pixels
	int xMid, yMid; // offset from top-left screen pos to the center
	float width, height; // width/height in world units
	float xFactor, yFactor; // Multiplication factors
	float z; // distance from the origin in world units

	void Reset() {
		
	}
};

#endif /* __H_SCREEN__ */

