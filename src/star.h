//
// Author: Timothy Baker
// cs361: Assignment 2
//"A story of Mites and Stars"
//
//star.h

////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <list>
#include <math.h>
#include <random>

#ifndef STAR_H_INCLUDED
#define STAR_H_INCLUDED

	///////////////////////////////////////////////////////////////////
	// class declaration and definition for star
     ///////////////////////////////////////////////////////////////////
	//
	class star
	{
		private:
			double x; //current location
			double y;
			double z;
			double nx; //next node
			double ny;
			double nz;
			double a=0.0;
			double b=0.0;
			double c=0.0;
			double speed;
			double distance;
			double pace;
			bool at_node;
			bool predation;
			int last_node_id;
			int current_node_id;
			int next_node_id;
			int clock;
		
		public:
			//constructors and destructor
			star(){at_node=predation=false; x=y=z=0; last_node_id=current_node_id=-2;speed=5; distance=pace=0.0; clock=0;}
			~star(){}
			//setters and getters
			bool get_at_node(){return at_node;}
			void set_at_node(bool a){at_node=a;}
			bool get_predation(){return predation;}
			void set_predation(bool p){predation=p;}
			double get_x(){return x;}
			double get_y(){return y;}
			double get_z(){return z;}
			void set_x(double i){x=i;}
			void set_y(double j){y=j;}
			void set_z(double k){z=k;}
			double get_pace(){return pace;}
			void set_pace(double p){pace=p;}
			void set_xyz(double i, double j, double k){x=i; y=j; z=k;}
			int get_last_node_id(){return last_node_id;}
			void set_last_node_id(int i){last_node_id=i;}
			int get_current_node_id(){return current_node_id;}
			void set_current_node_id(int i){current_node_id=i;}
			int get_next_node_id(){return last_node_id;}
			void set_next_node_id(int i){next_node_id=i;}
			int get_clock(){return clock;}
			void set_clock(int c){clock=c;}
			double get_nx(){return nx;}
			double get_ny(){return ny;}
			double get_nz(){return nz;}
			void set_next_node_xyz(double i, double j, double k){nx=i;ny=j;nz=k;}
			//other functions
	          void slipping_time(double i, double j, double k, int id);
			void move();
	};
	
#endif//STAR_H_INCLUDED
