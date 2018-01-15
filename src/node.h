//
// Author: Timothy Baker
// cs361: Assignment 2
//"A story of Mites and Stars"
//
//node.h

////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <list>
#include "mite.h"
#include "star.h"

using namespace std;

#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

     ///////////////////////////////////////////////////////////////////
	// class declaration and definition for node
     ///////////////////////////////////////////////////////////////////
	class node
	{
		private:
			int id;
			int x;
			int y;
			int z;
			int clock;
			list<mite*> planet_mites;
			list<mite*>::iterator planet_mites_itr;
			list<star*> planet_stars;
			list<star*>::iterator planet_stars_itr;
			list<node*> planet_links;
			list<node*>::iterator planet_links_itr;

		public:
			//constructors and destructor
			node(){x=y=z=clock=0;id=-1;}
			node(int ID, int i, int j, int k){id=ID;x=i;y=j;z=k;}
			~node(){}
			//setters and getters
			int get_id(){return id;}
			void set_id(int ID){id=ID;}
			int get_x(){return x;}
			int get_y(){return y;}
			int get_z(){return z;}
			void set_x(int i){x=i;}
			void set_y(int j){y=j;}
			void set_z(int k){z=k;}
			list<mite*>::iterator get_planet_mites_begin(){return planet_mites.begin();}
			list<mite*>::iterator get_planet_mites_end(){return planet_mites.end();}
			list<star*>::iterator get_planet_stars_begin(){return planet_stars.begin();}
			list<star*>::iterator get_planet_stars_end(){return planet_stars.end();}
			list<node*>::iterator get_planet_links_begin(){return planet_links.begin();}
			list<node*>::iterator get_planet_links_end(){return planet_links.end();}
			list<node*>* get_planet_links(){return &planet_links;}
			void add_mite(mite* mite){mite->set_xyz(x,y,z);mite->set_current_node_id(id);planet_mites.push_back(mite);}
			void remove_mite(mite* mite){planet_mites.remove(mite);}
			void add_star(star* star){star->set_xyz(x,y,z);star->set_current_node_id(id);planet_stars.push_back(star);}
			void remove_star(star* star){planet_stars.remove(star);}
			void add_link(node* link){link->set_link(this); planet_links.push_back(link); planet_links.unique();}
			void set_link(node* link){planet_links.push_back(link); planet_links.unique();}
			int get_clock(){return clock;}
			void set_clock(int c){clock=c;}
			// other functions
			void slipping_time(){clock++;}
			bool star_has_moved(star star);
			bool mite_has_moved(mite mite);
			void remove_movers();
			void add_newcomers(){}

	};


#endif//NODE_H_INCLUDED
