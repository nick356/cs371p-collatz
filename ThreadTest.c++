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
#include <thread>


void cycle_length(int i, int* blar){
	int cycleLength = 1;
	while( i > 1){
		if(i % 2 == 0){
			i = i>>1;
		}else{
			i = i+(i>>1)+1;
			cycleLength++;
		}
		cycleLength++;
	}
	*blar = cycleLength;
}

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
	assert(i>0 && j>0);
	int temp;
	int tempI;
	int x = 5;
	int y = 6;
	int* globalA;
	int* globalB;
	if(i>j){
		j = i^j;
		i = i^j;
		j = i^j;	
	}

	tempI = i;
	int highest = 0;
	temp = 0;
	globalA = &x;
	globalB = &y;
	while(i <= tempI+((j-tempI)/2)){
		cycle_length(i,globalA);
		cycle_length(j-temp,globalB);
		if(x > y && x > highest)
			highest = x;
		else if(y > x && y > highest)
			highest = y;
		else if(y == x && y > highest)
			highest = y;
		i++;
		temp++;
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

int main () {
	using namespace std;	
	collatz_solve(cin, cout);
	return 0;
}
