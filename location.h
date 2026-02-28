#pragma once

class Location
{
public:
	float x;
	float y;

	void increase(const Location& inc) //used for delta location, to increase it by delta.
	{
		x += inc.x;
		y += inc.y;
	}

};