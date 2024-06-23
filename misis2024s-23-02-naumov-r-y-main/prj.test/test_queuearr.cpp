#include <queuearr/queuearr.hpp>
#include <complex/complex.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

	

TEST_CASE("all in one cuz 'm lazy") {
	QueueArr q;
	CHECK_EQ(q.IsEmpty(), 1);
	QueueArr q1(q);
	CHECK_EQ(q1.IsEmpty(), 1);
	CHECK_THROWS(void(q.Top()));
	q.Push(Complex(1, 2));
	CHECK_EQ(q.IsEmpty(), 0);
	CHECK_EQ(q.Top(), Complex(1, 2));
	q.Pop();
	q.Push(Complex(1));
	q.Clear();
	CHECK_EQ(q.IsEmpty(), 1);
}