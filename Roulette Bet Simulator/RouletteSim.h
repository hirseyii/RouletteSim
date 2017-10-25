#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>

namespace RouletteSim {

	// Classes ====================================================================================

	// Betting style class
	class style {
	public:
		// Constructor ----------------------------------------------------------------------------
		style(std::vector<int> winning_numbers, int multiplier, int number_of_bets = 1, std::string in_tag = "DEFAULT-STYLE") {

			std::cout << "CONSOLE>>> Generating bet style " + in_tag << std::endl;
			tag = in_tag;
			winners = winning_numbers;
			win_multiplier = multiplier;
			bets_placed = number_of_bets;

		}

		// Destructor -----------------------------------------------------------------------------
		~style() { std::cout << "CONSOLE>>> Destroying bet style " + tag << std::endl; }

		// Accessors ------------------------------------------------------------------------------
		//// get
		int getWin_multiplier() { return win_multiplier; }
		int getBets_placed() { return bets_placed; }
		std::string getTag() { return tag; }
		std::vector<int>getWinners() { return winners; }

		//// set
		void setWin_multiplier(int a) { win_multiplier = a; }
		void setBets_placed(int a) { bets_placed = a; }

		// Methods
		// Calculate payout on winning
		int calc_payoutf(int number) {

			int payout;

			// Check if won or lost
			/*NOTE end() points to one past the last element*/
			if (std::find(winners.begin(), winners.end(), number) != winners.end()) {
				// WON
				
				/*Use this to calculate payout when winning more than once is possible (evens,reds etc)*/
				payout = win_multiplier;
				
			}
			else {
				//LOST
				payout = 0;

			}
			return payout;

		}

		

	private:
		int win_multiplier;
		int bets_placed;
		std::vector<int> winners;
		std::string tag;

	};

	class player {
	public:
		// Constructor ----------------------------------------------------------------------------
		player(int in_cash, int in_amount, std::string in_tag = "DEFAULT-PLAYER") {
		
			std::cout << "CONSOLE>>> Generating player " + in_tag << std::endl;
			tag = in_tag;
			cash = in_cash;
			bet_amount = in_amount;
		}
		// Destructor -----------------------------------------------------------------------------
		~player() { std::cout << "CONSOLE>>> Destroying player " + tag << std::endl; }

		// Accessors ------------------------------------------------------------------------------
		//// get
		int getCash() { return cash; }
		int getBet_amount() { return bet_amount; }
		std::string getTag() { return tag; }

		//// set
		void setCash(int a) { cash = a; }

		// Methods --------------------------------------------------------------------------------
		// print remaining cash
		void printCash() { 
			std::cout << this->tag + " has " + std::to_string(this->cash) + " remaining" << std::endl; 
		}

		// add cash 
		void addCash(int amount) { cash += amount; }
		
		
	private:
		// Members
		int cash;
		int bet_amount;
		std::string tag;
		
	};

	// Functions ===================================================================================

	// Spin the wheeeel!!¡
	int spin(RouletteSim::player* person,RouletteSim::style* bet_style);

	// Print a vector
	int printvector(std::vector <int> matrix);

}