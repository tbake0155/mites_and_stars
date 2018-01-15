//
// Author: Timothy Baker
// cs361: Assignment 2
//"A story of Mites and Stars"
//
//mite.h

////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <list>
#include <random>
#include <math.h>

using namespace std;

#ifndef MITE_H_INCLUDED
#define MITE_H_INCLUDED

	///////////////////////////////////////////////////////////////////
	// class declaration and definition for mite
     ///////////////////////////////////////////////////////////////////
	//
	class mite
	{
		protected:
			double x; //current location
			double y;
			double z;
			double nx; //next node
			double ny;
			double nz;
			double a=0.0;
			double b=0.0;
			double c=0.0;
			double distance;
			double speed;
			double pace;
			double evasive;
			double tough;
			bool hatched;
			bool companion;
			bool at_node;
			int last_node_id;
			int current_node_id;
			int next_node_id;
			int clock;
		
		public:
			//constructors and destructor
			mite(){x=y=z=speed=evasive=tough=0;last_node_id=current_node_id=-2;clock=0;hatched=companion=at_node=false;}
			mite(default_random_engine * random_engine);
			~mite(){}
			//setters and getters
			bool get_at_node(){return at_node;}
			void set_at_node(bool a){at_node=a;}
			bool get_companion(){return companion;}
			void set_companion(bool s){companion=s;}
			bool get_hatched(){return hatched;}
			void set_hatched(bool h){hatched=h;}
			double get_pace(){return pace;}
			void set_pace(double p){pace=p;}
			double get_x(){return x;}
			double get_y(){return y;}
			double get_z(){return z;}
			void set_x(double i){x=i;}
			void set_y(double j){y=j;}
			void set_z(double k){z=k;}
			double get_nx(){return nx;}
			double get_ny(){return ny;}
			double get_nz(){return nz;}
			double get_distance(){return distance;}
			void set_distance(double d){distance=d;}
			void set_xyz(double i, double j, double k){x=i; y=j; z=k;}
			int get_last_node_id(){return last_node_id;}
			void set_last_node_id(int i){last_node_id=i;}
			int get_current_node_id(){return current_node_id;}
			void set_current_node_id(int i){current_node_id=i;}
			int get_next_node_id(){return last_node_id;}
			void set_next_node_id(int i){next_node_id=i;}
			void set_next_node_xyz(double i, double j, double k){nx=i;ny=j;nz=k;}
			int get_clock(){return clock;}
			void set_clock(int c){clock=c;}
			//other functions
			void mite_procreation(list<mite> mites, list<mite*> mites_ptr);
			virtual void slipping_time(double i, double j, double k, int id, bool& new_node, int& link_node_id, int& old_node_id);
			void move();
	};
	
	class egg: public mite
	{
		private:
			int turns_to_hatch;	
		public:
			//constructors and destructor
			egg(){} // a babe without a name
			egg(double i, double j, double k, int id, double s, double e, double t);
			~egg(){}
			//setters and getters
			int get_turns_to_hatch(){return turns_to_hatch;}
			void set_turns_to_hatch(int t){turns_to_hatch=t;}
			//other functions
			void minus_turns_to_hatch(){if(turns_to_hatch>0){turns_to_hatch--;}if(turns_to_hatch==0){hatched=true;}}
	          void slipping_time(double i, double j, double k, int id, bool& new_node, int& link_node_id, int& old_node_id);
	};

#endif//MITE_H_INCLUDED

