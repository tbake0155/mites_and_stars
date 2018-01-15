//
// Author: Timothy Baker
// cs361: Assignment 2
//"A story of Mites and Stars"
//
//mite.cpp

////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "mite.h"
#include <iostream>

     ///////////////////////////////////////////////////////////////////
	// create random statistics factors for a new mite
     ///////////////////////////////////////////////////////////////////
	normal_distribution<double> mite_speed_factor(8,2);
	normal_distribution<double> mite_tough_factor(1.0,0.2);
	normal_distribution<double> mite_evasive_factor(1.0, 0.2);
     
	///////////////////////////////////////////////////////////////////
	// initializing contructor, used in main for initial build of mites
     ///////////////////////////////////////////////////////////////////
	//
     mite::mite(default_random_engine* random_engine)
	{
		at_node=false; 
		companion=false;
		hatched=true; 
		x=y=z=0; 
		last_node_id=current_node_id=-2; 
		clock=0;
		speed=mite_speed_factor(*random_engine);
		while(speed<=0)
		{
			speed=mite_speed_factor(*random_engine);
		}
		evasive=mite_evasive_factor(*random_engine);
		tough=mite_tough_factor(*random_engine);
	}

     ///////////////////////////////////////////////////////////////////
	// egg-hatched mite constructor, used by a hatching egg (aw so cute)
     ///////////////////////////////////////////////////////////////////
	//
	egg::egg(double i, double j, double k, int id, double s, double e, double t)
	{
		companion=false; 
		hatched=false; 
		turns_to_hatch=0;
		last_node_id=0; 
		clock=0; 
		at_node=true; 
		current_node_id=id; 
		x=i; y=j; z=k;
		speed=s;
		evasive=e;
		tough=t;
	}

     ///////////////////////////////////////////////////////////////////
	// mite procreation definition
     ///////////////////////////////////////////////////////////////////
	//
	void mite::mite_procreation(list<mite> mites, list<mite*> mites_ptr)
	{
		mite* mite_egg_ptr = new egg(x, y, z, current_node_id,speed, evasive, tough);
		mites.push_back(*mite_egg_ptr);
		mites_ptr.push_back(&(mites.back()));
		delete mite_egg_ptr;
	}

     ///////////////////////////////////////////////////////////////////
	// move definition
     ///////////////////////////////////////////////////////////////////
	//
	void mite::move()
	{
		x=a + x;
		y=b + y;
		z=c + z;
	}

     ///////////////////////////////////////////////////////////////////
	// time incrementation for mites///////////////////////////////////
	//
	void mite::slipping_time(double i, double j, double k, int id, bool& new_node, int& link_node_id, int& new_node_id)
	{
		if(((x>=nx-10 && x <=nx+10) && (y>=ny-10 && y <=ny+10) && (z>=nz-10 && z <=nz+10)) || (clock==0))
		{
			if(clock!=0)
			{
				link_node_id=last_node_id;
				new_node_id=current_node_id;
				x=nx;y=ny;z=nz; //gravity got them
			}

			if(companion==true)
			{
				companion=false;
			}
			if(1)
			{
				set_next_node_xyz(i, j, k);
		          distance=sqrt(pow((x-nx),2.0)+pow((y-ny),2.0)+ pow((z-nz),2.0));
				pace=distance/speed;

				a=(nx-x)/pace;
				b=(ny-y)/pace;
				c=(nz-z)/pace;

				last_node_id=current_node_id;
				if(clock!=0)
				{
					current_node_id=next_node_id;
				}
				next_node_id=id;
				new_node=true;
			}
		}
		else
		{
			move(); 
		}
		clock++;
	}

	void egg::slipping_time(double i, double j, double k, int id, bool& new_node, int& link_node_id, int& new_node_id)
	{
		if(clock=0)
		{
			set_next_node_xyz(i,j,k);
			set_next_node_id(id);
		}
		clock++;
		if(hatched==false)	
		{
			minus_turns_to_hatch();
		}
		if(hatched==true)
		{
			if(x!=nx && y!=ny && z!=nz)
			{
				move(); 
			}
			else
			{
				link_node_id=last_node_id;
				new_node_id=current_node_id;
				new_node=true;
				if(companion==true)
				{
					companion=false;
				}
				else
				{
					last_node_id=current_node_id;
					set_next_node_xyz(i, j, k);
					set_next_node_id(id);
				}
			}
		}
	}

