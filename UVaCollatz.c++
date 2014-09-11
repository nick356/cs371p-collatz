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

int cache[100000];
bool cacheStat[100000]={false};
// ------------
// collatz_read
// ------------

int cycle_length(int i){
	if(i<100000 && cacheStat[i])
		return cache[i];
	else if(i == 1)
		return 1;
	else{
		if(i % 2 == 0)
			return 1+cycle_length(i>>1);
		else
			return 2+cycle_length(i+(i>>1)+1);
	}
}

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
	if(i>j){
		j=i^j;
		i=i^j;
		j=i^j;	
	}
	int highest = 0;
	while(i <= j){
		int temp = cycle_length(i);
		if(i <100000 && !cacheStat[i]){
			cacheStat[i] = true;
			cache[i]=temp;
		}
		if(temp > highest)
			highest = temp;
		i++;
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

