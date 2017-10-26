// Roulette Bet Simulator.cpp : Defines the entry point for the console application.
//
// A program to simulate Roulette table betting

#include "stdafx.h"


int main()
{
	// Seed RNG
	srand(time(NULL));

	// Create vector array of winning numbers
	std::vector<int> winners;
	for (int i = 1; i < 25; i++) { winners.push_back(i); }

	// Construct 2/3rds bet
	RouletteSim::style* two_thirds = new RouletteSim::style(winners, 3, 2, "two thirds");
	
	// Open file for writing results
	std::ofstream SimData;

	// Generate a number of players who will play for a finite number of spins (or until stop loss is reached)
	int n_players = 100;
	for (int j = 1; j <= n_players; j++) {

		std::string player_tag = "player" + std::to_string(j);
		// generate player
		RouletteSim::player* person = new RouletteSim::player(200, 10, 80, player_tag);

		// Simulate a player playing for a number of spins
		for (int i = 0; i < 100; i++) {
			RouletteSim::spin(person, two_thirds);
			if (!person->Continue()) { break; }
			else {}
		}
		// Output result from each player
		std::cout << person->getCash() << std::endl;
		// Clean person
		delete person;
	}

	delete two_thirds;

    return 0;
}




