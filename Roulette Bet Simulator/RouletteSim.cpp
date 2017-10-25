#include "stdafx.h"

int RouletteSim::printvector(std::vector<int> matrix)
{
	for (size_t j = 0; j < matrix.size(); j++) {
		std::cout << matrix[j] << " ";
	}
	std::cout << std::endl;
	return 0;
}

int RouletteSim::spin(RouletteSim::player* person,RouletteSim::style* bet_style)
{
	int number;
	int payout;

	// Take cash
	person->addCash(-person->getBet_amount() * bet_style->getBets_placed());

	// Generate a random number
	number = rand() % 37;
	if (number > 37 || number < 0) { throw "RNG Error: Value out of bounds."; }
	
	// Calculate payout
	payout = bet_style->calc_payoutf(number) * person->getBet_amount();

	// Modify cash
	person->addCash(payout);

	return number;
}

