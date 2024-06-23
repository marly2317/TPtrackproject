#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "queuelstpr/queuelstpr.hpp"

TEST_CASE("QueueLstPr constructors") {
	QueueLstPr queue;
	CHECK(queue.IsEmpty());
	QueueLstPr queue1;
	queue1.Push(1);
	QueueLstPr queue2(queue1);
	QueueLstPr queue3;
	queue3 = queue2;
	CHECK_FALSE(queue2.IsEmpty());
	CHECK_FALSE(queue3.IsEmpty());

	QueueLstPr queue4(std::move(queue3));
	
	CHECK(queue4.Top() == 1);
	CHECK(queue3.IsEmpty());
}

TEST_CASE("QueueLstPr - IsEmpty") {
	QueueLstPr queue;
	CHECK(queue.IsEmpty());
	queue.Push(1);
	CHECK(!queue.IsEmpty());
	queue.Pop();
	CHECK(queue.IsEmpty());
}

TEST_CASE("QueueLstPr - right order") {
	QueueLstPr queue;
	queue.Push(1);
	queue.Push(3);
	queue.Push(2);
	
	CHECK(queue.Top() == 1);
	queue.Pop();
	CHECK(queue.Top() == 2);
	queue.Pop();
	CHECK(queue.Top() == 3);
	queue.Pop();
	CHECK(queue.IsEmpty());
}
