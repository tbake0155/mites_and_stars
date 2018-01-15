//
// Author: Timothy Baker
// cs361: Assignment 2
//"A story of Mites and Stars"
//
//universe.h

////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <random>
#include <list>
#include <thread>
#include "cthulu.h"
#include "node.h"
#include "mite.h"
#include "star.h"

using namespace std;

#ifndef UNIVERSE_H_INCLUDED
#define UNIVERSE_H_INCLUDED

	/////////////////////////////////////////////////////////////////////
	// universe class for time and universe size 
	/////////////////////////////////////////////////////////////////////
	class universe
	{
		private:
			int clock;
			int size;
			int units;
			int rare_links;
			double longest_possible;

		public:
			//constructors and destructor
			universe(){clock=size=0;longest_possible=0.0;rare_links=4;}
			~universe(){}
			//setters and getters
			int get_rare_link(){return rare_links;}
			void increment_rare_link(){rare_links--;}
			void set_clock(int c){clock=c;}
			int get_clock(){return clock;}
			void set_size(int s);
			int get_size(){return size;}
			void set_units(int u){units=u;}
			int get_units(){return units;}
	          double range_finder_double(node * planet, node * link);
			void max_range(int size);
	};

	/////////////////////////////////////////////////////////////////////
	// universal function defintions 
	/////////////////////////////////////////////////////////////////////
	void find_xyz(int seeding_size, default_random_engine * random_engine, int &x, int &y, int &z);
	int find_planets_size(default_random_engine * random_engine, int seeding_size);
	int find_mites_size(int seeding_size, default_random_engine * random_engine);
	int find_stars_size(int seeding_size, default_random_engine * random_engine);
     int find_units(int seeding_size);
	void * stars_tick_tock(list<star>* stars, list<node>* planets, default_random_engine* random_engine);
	void * mites_tick_tock(list<mite>* mites, list<node>* planets, default_random_engine* random_engine, universe * universal);
	void * planets_tick_tock(list<node>* planets);
	bool update_user(int clock, int i);
	void * gif_maker();
	void * patients(thread * thread);
	bool range_finder(node * planets, node * links);



#endif//UNIVERSE_H_INCLUDED
