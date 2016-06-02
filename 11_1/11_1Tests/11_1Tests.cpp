#include "stdafx.h"
#include "../11_1/11_1.h"

BOOST_AUTO_TEST_SUITE(square_function)

BOOST_AUTO_TEST_CASE(return_true_when_point_in_triangle)
{
	int ax = -2, ay = -2, bx = 3, by = 2, cx = 1, cy = 4, px = 0, py = 0;
	BOOST_CHECK(CheckPoint(ax, ay, bx, by, cx, cy, px, py) == 1);
}

BOOST_AUTO_TEST_CASE(return_false_when_point_not_in_triangle)
{
	int ax = 0, ay = 0, bx = 100, by = 0, cx = 100, cy = 0, px = 110, py = 110;
	BOOST_CHECK(CheckPoint(ax, ay, bx, by, cx, cy, px, py) == 0);
}  

BOOST_AUTO_TEST_CASE(return_true_when_point_in_big_triangle)
{
	int ax = 0, ay = 0, bx = 19000, by = 1110, cx = 800000, cy = 0, px = 1000, py = 10;
	BOOST_CHECK(CheckPoint(ax, ay, bx, by, cx, cy, px, py) == 1);
}

BOOST_AUTO_TEST_CASE(return_true_when_zero_point_in_triangle)
{
	int ax = 0, ay = 0, bx = 0, by = 0, cx = 0, cy = 0, px = 0, py = 0;
	BOOST_CHECK(CheckPoint(ax, ay, bx, by, cx, cy, px, py) == 1);
}

BOOST_AUTO_TEST_SUITE_END()
