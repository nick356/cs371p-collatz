// --------------------------------
// projects/collatz/TestCollatz.c++
// Copyright (C) 2014
// Glenn P. Downing
// --------------------------------
// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions
// --------
// includes
// --------
#include <iostream> // cout, endl
#include <sstream> // istringtstream, ostringstream
#include <string> // ==
#include <utility> // pair
#include "gtest/gtest.h"
#include "Collatz.h"
// -----------
// TestCollatz
// -----------

// ----
// read
// ----
TEST(Collatz, read_1) {
	std::istringstream r("1 10\n");
	const std::pair<int, int> p = collatz_read(r);
	ASSERT_EQ( 1, p.first);
	ASSERT_EQ(10, p.second);
}

TEST(Collatz, read_2){
	std::istringstream r("110 200\n");
	const std::pair<int, int> p = collatz_read(r);
	ASSERT_EQ(110, p.first);
	ASSERT_EQ(200, p.second);
}

TEST(Collatz, read_3){
	std::istringstream r("1 1000000\n");
	const std::pair<int, int> p = collatz_read(r);
	ASSERT_EQ(1, p.first);
	ASSERT_EQ(1000000, p.second);
}
// ----
// eval
// ----
TEST(Collatz, eval_1) {
	const int v = collatz_eval(1, 10);
	ASSERT_EQ(20, v);
}

TEST(Collatz, eval_2) {
	const int v = collatz_eval(100, 200);
	ASSERT_EQ(125, v);
}

TEST(Collatz, eval_3) {
	const int v = collatz_eval(201, 210);
	ASSERT_EQ(89, v);
}

TEST(Collatz, eval_4) {
	const int v = collatz_eval(900, 1000);
	ASSERT_EQ(174, v);
}

TEST(Collatz, eval_5) {
	const int v = collatz_eval(5, 10);
	ASSERT_EQ(20, v);
}

TEST(Collatz, eval_6) {
	const int v = collatz_eval(1, 1);
	ASSERT_EQ(1, v);
}

TEST(Collatz, eval_7) {
	const int v = collatz_eval(10, 20);
	ASSERT_EQ(21, v);
}

TEST(Collatz, eval_8) {
	const int v = collatz_eval(10, 20);
	ASSERT_EQ(21, v);
}


// -----
// print
// -----
TEST(Collatz, print_1) {
	std::ostringstream w;
	collatz_print(w, 1, 10, 20);
	ASSERT_EQ("1 10 20\n", w.str());
}

TEST(Collatz, print_2) {
	std::ostringstream w;
	collatz_print(w, 1, 1000000, 20);
	ASSERT_EQ("1 1000000 20\n", w.str());
}

TEST(Collatz, print_3) {
	std::ostringstream w;
	collatz_print(w, 100, 200, 125);
	ASSERT_EQ("100 200 125\n", w.str());
}

// -----
// cycle_length
// -----

TEST(Collatz, cycle_length1){
	int v = cycle_length(22);
	ASSERT_EQ(16,v);
}

TEST(Collatz, cycle_length2){
	int v = cycle_length(9);
	ASSERT_EQ(20,v);
}


TEST(Collatz, cycle_length3){
	int v = cycle_length(51);
	ASSERT_EQ(25,v);
}

TEST(Collatz, cycle_length4){
	int v = cycle_length(5);
	ASSERT_EQ(6,v);
}

TEST(Collatz, cycle_length5){
	int v = cycle_length(10);
	ASSERT_EQ(7,v);
}

TEST(Collatz, cycle_length6){
	int v = cycle_length(1);
	ASSERT_EQ(1,v);
}

TEST(Collatz, cycle_length7){
	int v = cycle_length(2);
	ASSERT_EQ(2,v);
}

TEST(Collatz, cycle_length8){
	int v = cycle_length(3);
	ASSERT_EQ(8,v);
}


TEST(Collatz, cycle_length9){
	int v = cycle_length(100);
	ASSERT_EQ(26,v);
}

TEST(Collatz, cycle_length10){
	int v = cycle_length(4);
	ASSERT_EQ(3,v);
}

TEST(Collatz, cycle_length11){
	int v = cycle_length(8);
	ASSERT_EQ(4,v);
}

TEST(Collatz, cycle_length12){
	int v = cycle_length(16);
	ASSERT_EQ(5,v);
}

TEST(Collatz, cycle_length13){
	int v = cycle_length(987027);
	ASSERT_EQ(122,v);
}
// -----
// solve
// -----
TEST(Collatz, solve1) {
	std::istringstream r("1 10\n100 200\n201 210\n900 1000\n");
	std::ostringstream w;
	collatz_solve(r, w);
	ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());
}

TEST(Collatz, solve2){
	std::istringstream r("57531 88198\n25786 89434\n111448 80015\n29418 66943\n19209 47970\n");
	std::ostringstream w;
	collatz_solve(r,w);
	ASSERT_EQ("57531 88198 351\n25786 89434 351\n111448 80015 354\n29418 66943 340\n19209 47970 324\n",w.str());
}

TEST(Collatz, solve3){
	std::istringstream r("70302 102195\n25114 4015\n70120 24426\n8887 44993\n62215 3902\n17177 49652\n30321 51476\n85443 74628\n60022 49611\n21868 51512\n67112 7699\n");
	std::ostringstream w;
	collatz_solve(r,w);
	ASSERT_EQ("70302 102195 351\n25114 4015 282\n70120 24426 340\n8887 44993 324\n62215 3902 340\n17177 49652 324\n30321 51476 324\n85443 74628 351\n60022 49611 340\n21868 51512 324\n67112 7699 340\n",w.str());
}



/*
% ls -al /usr/include/gtest/
...
gtest.h
...
% locate libgtest.a
/usr/lib/libgtest.a
...
% locate libpthread.a
...
/usr/lib32/libpthread.a
% locate libgtest_main.a
/usr/lib/libgtest_main.a
...
% g++-4.7 -fprofile-arcs -ftest-coverage -pedantic -std=c++11 -Wall Collatz.c++ TestCollatz.c++ -o TestCollatz -lgtest -lgtest_main -lpthread
% valgrind TestCollatz > TestCollatz.out 2>&1
% gcov-4.7 -b Collatz.c++ >> TestCollatz.out
% gcov-4.7 -b TestCollatz.c++ >> TestCollatz.out
% cat TestCollatz.out
==14225== Memcheck, a memory error detector
==14225== Copyright (C) 2002-2011, and GNU GPL'd, by Julian Seward et al.
==14225== Using Valgrind-3.7.0 and LibVEX; rerun with -h for copyright info
==14225== Command: TestCollatz
==14225==
Running main() from gtest_main.cc
[==========] Running 7 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 7 tests from Collatz
[ RUN ] Collatz.read
[ OK ] Collatz.read (31 ms)
[ RUN ] Collatz.eval_1
[ OK ] Collatz.eval_1 (5 ms)
[ RUN ] Collatz.eval_2
[ OK ] Collatz.eval_2 (3 ms)
[ RUN ] Collatz.eval_3
[ OK ] Collatz.eval_3 (3 ms)
[ RUN ] Collatz.eval_4
[ OK ] Collatz.eval_4 (3 ms)
[ RUN ] Collatz.print
[ OK ] Collatz.print (17 ms)
[ RUN ] Collatz.solve
[ OK ] Collatz.solve (10 ms)
[----------] 7 tests from Collatz (88 ms total)
[----------] Global test environment tear-down
[==========] 7 tests from 1 test case ran. (132 ms total)
[ PASSED ] 7 tests.
==14225==
==14225== HEAP SUMMARY:
==14225== in use at exit: 0 bytes in 0 blocks
==14225== total heap usage: 495 allocs, 495 frees, 70,302 bytes allocated
==14225==
==14225== All heap blocks were freed -- no leaks are possible
==14225==
==14225== For counts of detected and suppressed errors, rerun with: -v
==14225== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 2 from 2)
File 'Collatz.c++'
Lines executed:100.00% of 17
Branches executed:100.00% of 18
Taken at least once:61.11% of 18
Calls executed:89.47% of 19
Creating 'Collatz.c++.gcov'
...
File 'TestCollatz.c++'
Lines executed:100.00% of 26
Branches executed:57.14% of 224
Taken at least once:28.57% of 224
Calls executed:54.07% of 209
Creating 'TestCollatz.c++.gcov'
...
*/
