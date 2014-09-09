// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2014
// Glenn P. Downing
// ----------------------------
// --------
// includes
// --------
#include <cassert> // assert
#include <iostream> // endl, istream, ostream
#include <utility> // make_pair, pair
#include "Collatz.h"
// ------------
// collatz_read
// ------------
std::pair<int, int> collatz_read (std::istream& r) {
	int i;
	r >> i;
	if (!r)
		return std::make_pair(0, 0);
	int j;
	r >> j;
	return std::make_pair(i, j);
}
// ------------
// collatz_eval
// ------------
int collatz_eval (int i, int j) {
	if(i > j)
		return -1;
	int highest = 0;
	int tempHighest = 1;
	int calc = 0;
	while(i <= j){
		calc = i;
		while(calc > 1){
			if(calc % 2 == 0){
				calc /= 2;
				tempHighest++;
			}else{
				calc = 3*calc + 1;
				tempHighest++;
			}
		}
		
		if(tempHighest > highest)
			highest = tempHighest;

		i++;
		tempHighest = 1;
	}

	return highest;    
}
// -------------
// collatz_print
// -------------
void collatz_print (std::ostream& w, int i, int j, int v) {
	w << i << " " << j << " " << v << std::endl;
}
// -------------
// collatz_solve
// -------------
void collatz_solve (std::istream& r, std::ostream& w) {
	while (true) {
		const std::pair<int, int> p = collatz_read(r);
		if (p == std::make_pair(0, 0))
			return;
		const int i = p.first;
		const int j = p.second;
		const int v = collatz_eval(i, j);
		collatz_print(w, i, j, v);
	}
}
