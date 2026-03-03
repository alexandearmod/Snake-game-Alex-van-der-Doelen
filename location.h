#pragma once

class Location
{
public:
	int x;
	int y;

	void increase(const Location& inc) //used for delta location.
	{
		x += inc.x;
		y += inc.y;
	}

};