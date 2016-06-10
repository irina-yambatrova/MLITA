#include "stdafx.h"
#include "../lab3_1/lab3_1.h"

BOOST_AUTO_TEST_SUITE(findWays_function)


BOOST_AUTO_TEST_CASE(return_ways_when_witn_jumpOnNumberOfSteps_is_one)
{
	BOOST_CHECK(findWays(4, 1) == 3);
}

BOOST_AUTO_TEST_CASE(return_ways_when_witn_jumpOnNumberOfSteps)
{
	BOOST_CHECK(findWays(6, 2) == 13);
}
BOOST_AUTO_TEST_CASE(return_false_when_error_input_dara)
{
	BOOST_CHECK(findWays(0, 2) == 1);
}

BOOST_AUTO_TEST_SUITE_END()
