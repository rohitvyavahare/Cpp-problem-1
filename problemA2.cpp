
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class SRMCards{

public:

	int maxTurns(vector<int> cards){


		/*

        Time complexity with sortin approach is O(nlogn) where n length of vecotr.

		sort(cards.begin(), cards.end());
		int i;
		for (i = 0; i < cards.size()-1; i++){
			

			if (cards.at(i + 1) == cards.at(i) + 1){
				i++;
			}
			count++;
		}

		if (i == cards.size() - 1){
			count++;
		}

		*/		

		/*

		Followinf approach use O(n) time where n is length of vecotr.
		*/
		map <int, bool > maps_of_cards;
		int count = 0;
		int reverse_count = 0;

		maps_of_cards = getMap(cards);

		count = getCount(cards, maps_of_cards);

		reverse(cards.begin(), cards.end());

		maps_of_cards = getMap(cards);

		reverse_count = getCount(cards, maps_of_cards);
		
		if (reverse_count > count)
			return reverse_count;
		return count;

	}


private:

	/*
	   getMap method return map with vector elemets as keys and set its values to true
	   
	*/

	map <int, bool > getMap(vector<int> cards){

		map <int, bool > maps_of_cards;
		for (int i = 0; i < cards.size(); i++){

			maps_of_cards[cards.at(i)] = true;

		}

		return maps_of_cards;
	}

	/*

	getCount method return largest poosible number of turns
	
	*/

	int getCount(vector <int> cards, map <int, bool> maps_of_cards){

		int count = 0;

		for (int i = 0; i < cards.size(); i++){

			if (maps_of_cards[cards.at(i)]){

				if (maps_of_cards[cards.at(i) + 1]){

					maps_of_cards[cards.at(i) + 1] = false;
				}

				if (maps_of_cards[cards.at(i) - 1]){

					maps_of_cards[cards.at(i) - 1] = false;

				}

				count++;
				maps_of_cards[cards.at(i)] = false;
			}

		
		}

		return count;
	}

};




int _tmain(int argc, _TCHAR* argv[])
{

	SRMCards srm;
	
	
	cout<< srm.maxTurns({ 498, 499 })<<endl;
	cout << srm.maxTurns({ 491, 492, 495, 497, 498, 499 }) << endl;
	cout << srm.maxTurns({ 100, 200, 300, 400 }) << endl;
	cout << srm.maxTurns({ 11, 12, 102, 13, 100, 101, 99, 9, 8, 1 }) << endl;
	cout << srm.maxTurns({ 118, 321, 322, 119, 120, 320 }) << endl;
	cout << srm.maxTurns({ 10, 11, 12, 13, 14, 1, 2, 3, 4, 5, 6, 7, 8, 9 }) << endl;
	getchar();
	return 0;
}

