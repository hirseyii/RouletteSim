// Roulette Bet Simulator.cpp : Defines the entry point for the console application.
//
// A program to simulate Roulette table betting

#include "stdafx.h"
#include <ctime>


int main()
{
	// Seed RNG
	srand(time(NULL));

	// Create vector array of winning numbers
	std::vector<int> winners;
	for (int i = 1; i < 25; i++) { winners.push_back(i); }

	// Construct 2/3rds bet
	RouletteSim::style* two_thirds = new RouletteSim::style(winners, 3, 2, "two thirds");
	RouletteSim::player* player1 = new RouletteSim::player(200,10, "player1");
	
	for (int i = 0; i < 100; i++) {
		RouletteSim::spin(player1, two_thirds);
	}

	
	delete player1;
	delete two_thirds;

    return 0;
}



