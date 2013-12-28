#ifndef __H_SCREEN__
#define __H_SCREEN__

#include "point.h"

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
		xMid = pixWidth >> 1;
		yMid = pixHeight >> 1;
		xFactor = float(pixWidth) / width;
		yFactor = float(pixHeight) / height;
	}

	public:

	int PixelWidth() const { return pixWidth; }
	int PixelHeight() const { return pixHeight; }
	float Width() const { return width; }
	float Height() const { return height; }
	float Distance() const { return z; }

	void PixelWidth(int newWidth) { pixWidth = newWidth; Reset(); }
	void PixelHeight(int newHt) { pixHeight = newHt; Reset(); }
	void Width(float newWid) { width = newWid; Reset(); }
	void Height(float newHt) { height = newHt; Reset(); }
	void Distance(float newDist) { z = newDist; }

	ScreenPoint Project(Point3D point) {
		ScreenPoint result;
		float x, y;

		// Calculate the screen point in world units.
		x = z * point.x / point.z;
		y = z * point.y / point.z;

		// Convert the point to pixel units.
		result.x = xMid + int( xFactor * x + 0.5 );
		result.y = yMid + int( yFactor * y + 0.5 );

		return result;
	}
};

#endif /* __H_SCREEN__ */

