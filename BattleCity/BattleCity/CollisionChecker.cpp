#include "CollisionChecker.h"



CollisionChecker::CollisionChecker()
{
} 


CollisionChecker::~CollisionChecker()
{
}

bool CollisionChecker::ColBetweenTwoObjs(int x1, int y1, int x2, int y2)
{
	if (x1 == x2 || y1 == y2)
		return true;
	else
		return false;
}
