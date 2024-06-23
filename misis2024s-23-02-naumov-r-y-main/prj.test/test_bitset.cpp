#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "bitSet/bitSet.hpp"
#include "doctest.h"
TEST_CASE("BitSet Constructor") {
	BitSet bs;
	CHECK(bs.Size() == 0);
	CHECK(bs.Tostring()=="");

	BitSet bs2(11);
	CHECK(bs2.Size() == 11);
	CHECK(bs2.Tostring() == "00000000000");
	bs2.Fill(true);
	CHECK(bs2.Tostring() == "11111111111");

	BitSet bs3(bs2);
	CHECK(bs3.Size() == 11);

	BitSet bs4(std::move(bs3));
	CHECK(bs3.Size() == 0);
	CHECK(bs4.Size() == 11);
	CHECK(bs3.Tostring() == "");
	bs4.Fill(false);
	CHECK(bs4.Tostring() == "00000000000");
	
	bs3 = bs2;
	CHECK(bs3.Size() == 11);
	CHECK(bs2.Size() == 11);
	CHECK(bs3.Tostring() == "11111111111");
	CHECK(bs2.Tostring() == "11111111111");

	bs3 = std::move(bs2);
	CHECK(bs3.Size() == 11);
	CHECK(bs2.Size() == 0);
	CHECK(bs3.Tostring() == "11111111111");
	CHECK(bs2.Tostring() == "");
}

TEST_CASE("BitSet operations") {
	BitSet bs;
	BitSet bs1(11);
	bs1.Set(0, true);
	bs1.Set(1, true);
	bs1.Set(2, true);
	bs1.Set(3, true);
	bs1.Set(4, true);
	bs1.Set(5, true);
	bs1.Set(6, true);
	bs1.Set(7, true);
	bs1.Set(8, false);
	bs1.Set(9, false);
	bs1.Set(10, false);
	CHECK(bs1.Tostring() == "11111111000");

	BitSet bs2(~bs1);
	CHECK(bs2.Tostring() == "00000000111");
	BitSet bs3("11100000000");
	CHECK(bs3.Tostring() == "11100000000");
}

TEST_CASE("BitSet Get/Set") {
	BitSet bs(10);
	bool b0;

	bs.Set(0, true);
	bs.Set(1, true);
	bs.Set(2, true);
	bs.Set(3, false);
	bs.Set(4, false);
	bs.Set(5, false);
	bs.Set(6, true);
	bs.Set(7, true);
	bs.Set(8, false);
	bs.Set(9, false);
	CHECK(bs.Tostring() == "1110001100");

	CHECK(bs.Get(0) == true);
	CHECK(bs[0] == 1);
	CHECK(bs.Get(1) == true);
	CHECK(bs[1] == 1);
	CHECK(bs.Get(2) == true);
	CHECK(bs[2] == 1);
	CHECK(bs.Get(3) == false);
	CHECK(bs[3] == 0);
	CHECK(bs.Get(4) == false);
	CHECK(bs[4] == 0);
	CHECK(bs.Get(5) == false);
	CHECK(bs[5] == 0);
	CHECK(bs.Get(6) == true);
	CHECK(bs[6] == 1);
	CHECK(bs.Get(7) == true);
	CHECK(bs[7] == 1);
	CHECK(bs.Get(8) == false);
	CHECK(bs[8] == 0);
	CHECK(bs.Get(9) == false);
	CHECK(bs[9] == 0);

	/*CHECK_THROWS(bs.Set(10, true));
	CHECK_THROWS(b0 = bs.Get(10));
	CHECK_THROWS(b0 = bs[10]);*/


	//CHECK_THROWS(bs.Set(-1, true));
	//CHECK_THROWS(b0 = bs.Get(-2));
	//CHECK_THROWS(b0 = bs[-25]);

}

TEST_CASE("BitSet Resize") {
	BitSet bs(10);
	bs.Resize(20);
	CHECK(bs.Size() == 20);
	CHECK(bs.Tostring() == "00000000000000000000");

	BitSet bs2("1111");
	bs2.Resize(5);
	CHECK(bs2.Size() == 5);
	CHECK(bs2.Tostring() == "11110");
	bs2.Resize(10);
	CHECK(bs2.Size() == 10);
	CHECK(bs2.Tostring() == "1111000000");
	bs2.Resize(3);
	CHECK(bs2.Size() == 3);
	CHECK(bs2.Tostring() == "111");
}