//
// Author: Timothy Baker
// cs361: Assignment 2
// Of Mites and Stars
//
// universe.cpp

////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "universe.h"
#include <iostream>
#include <chrono>
#include <math.h>

	/////////////////////////////////////////////////////////////////////
     // making a universe was never so easy
     /////////////////////////////////////////////////////////////////////
     //
	// create random distribution variable for x, y, z coordinate system
	uniform_int_distribution<int> universe_dist_0(-100, 101);
	uniform_int_distribution<int> universe_dist_1(-500, 501);
	uniform_int_distribution<int> universe_dist_2(-5000, 5001);
	uniform_int_distribution<int> universe_dist_3(-50000, 50001);
	uniform_int_distribution<int> universe_dist_4(-500000, 500001);
     // create random distribution variables for number of planets
	uniform_int_distribution<int> planets_dist_0(4, 10);
	uniform_int_distribution<int> planets_dist_1(40, 81);
	uniform_int_distribution<int> planets_dist_2(400, 801);
	uniform_int_distribution<int> planets_dist_3(4000, 8001);
	uniform_int_distribution<int> planets_dist_4(40000, 80001);
	// create random distribution variables for number of stars
	uniform_int_distribution<int> stars_dist_0(1, 1);
	uniform_int_distribution<int> stars_dist_1(2, 8);
	uniform_int_distribution<int> stars_dist_2(20, 51);
	uniform_int_distribution<int> stars_dist_3(200, 501);
	uniform_int_distribution<int> stars_dist_4(2000, 5001);
	// create random distribution variables for number of mites
	uniform_int_distribution<int> mites_dist_0(4, 4);
	uniform_int_distribution<int> mites_dist_1(10, 31);
	uniform_int_distribution<int> mites_dist_2(100, 301);
	uniform_int_distribution<int> mites_dist_3(1000, 3001);
	uniform_int_distribution<int> mites_dist_4(10000, 30001);

     /////////////////////////////////////////////////////////////////////
     // gif maker
     /////////////////////////////////////////////////////////////////////
     //
	void * gif_maker()
	{
		system("convert -loop 0 *.png universe.gif");
	}

     /////////////////////////////////////////////////////////////////////
     // patients, prints '#' while gif_maker is running THREADED
     /////////////////////////////////////////////////////////////////////
     //
	void * patients(thread * thread)
	{	
		while(thread->joinable())
		{
			cout<<"#"<<flush;
			this_thread::sleep_for(chrono::milliseconds(500));
		}
	}

     /////////////////////////////////////////////////////////////////////
     // set max range
     /////////////////////////////////////////////////////////////////////
     //
	void universe::max_range(int s)
	{
		double max_x, min_x, max_y, min_y, max_z, min_z;
		max_x=min_x=max_y=min_y=max_z=min_z=0;
		if (s==0)
		{
			max_x=max_y=max_z=100;
			min_x=min_y=max_z=-100;
		}
		if (s==1)
		{
			max_x=max_y=max_z=500;
			min_x=min_y=min_z=-500;
		}
		if (s==2)
		{
			max_x=max_y=max_z=5000;
			min_x=min_y=min_z=-5000;
		}
		if (s==3)
		{
			max_x=max_y=max_z=50000;
			min_x=min_y=min_z=-50000;
		}
		if (s==4)
		{
			max_x=max_y=max_z=500000;
			min_x=min_y=min_z=-500000;
		}

		longest_possible=sqrt(pow((max_x-min_x),2.0)+pow((max_y-min_y),2.0)+ pow((max_z-min_z),2.0));
	}

     /////////////////////////////////////////////////////////////////////
     // set size, and therefore units and max range
     /////////////////////////////////////////////////////////////////////
     //
	void universe::set_size(int s)
	{
		size=s; 
		if(size==0){units=120;}
		if(size==1){units=600;}
		if(size==2){units=6000;}
		if(size==3){units=60000;}
		if(size==4){units=600000;}

	}

     /////////////////////////////////////////////////////////////////////
     // make sure all links are within range
     /////////////////////////////////////////////////////////////////////
     //

	double universe::range_finder_double(node * planet, node * link)
	{
		double distance=sqrt(pow((planet->get_x()-link->get_x()),2.0)+pow((planet->get_x()-link->get_y()),2.0)+ pow((planet->get_z()-link->get_z()),2.0));

		return distance/longest_possible;
	}
     /////////////////////////////////////////////////////////////////////
     // generate random x, y, and z coordinate
     /////////////////////////////////////////////////////////////////////
     //
     void find_xyz(int seeding_size, default_random_engine * random_engine, int &x, int &y, int &z) 
     {
          if(seeding_size==0)
          {
              x=universe_dist_0(*random_engine);
              y=universe_dist_0(*random_engine);
              z=universe_dist_0(*random_engine);
          }
          if(seeding_size==1)
          {
              x=universe_dist_1(*random_engine);
              y=universe_dist_1(*random_engine);
              z=universe_dist_1(*random_engine);
          }
		if(seeding_size==2)
          {
              x=universe_dist_2(*random_engine);
              y=universe_dist_2(*random_engine);
              z=universe_dist_2(*random_engine);
          }
          if(seeding_size==3)
          {
              x=universe_dist_3(*random_engine);
              y=universe_dist_3(*random_engine);
              z=universe_dist_3(*random_engine);
          }          
          if(seeding_size==4)
          {
              x=universe_dist_4(*random_engine);
              y=universe_dist_4(*random_engine);
              z=universe_dist_4(*random_engine);
          }
      }

     /////////////////////////////////////////////////////////////////////
     // generate random planet size based on user input
     /////////////////////////////////////////////////////////////////////
     //
	int find_planets_size(default_random_engine * random_engine, int seeding_size)
     {
          int planet_size=0;

		if(seeding_size==0)
		{  
               planet_size=planets_dist_0(*random_engine);
		}
		if(seeding_size==1)
		{  
               planet_size=planets_dist_1(*random_engine);
		}
		if(seeding_size==2)
		{
               planet_size=planets_dist_2(*random_engine);
		}
	     if(seeding_size==3)
		{
               planet_size=planets_dist_3(*random_engine);
		}
		if(seeding_size==4)
		{
               planet_size=planets_dist_4(*random_engine);
		}
		return planet_size;
	}

     /////////////////////////////////////////////////////////////////////
     // generate random mites size based on user input
     /////////////////////////////////////////////////////////////////////
     //
	int find_mites_size(int seeding_size, default_random_engine * random_engine)
	{
          int mites_size=0;

		if(seeding_size==0)
		{  
               mites_size=mites_dist_0(*random_engine);
		}
		if(seeding_size==1)
		{  
               mites_size=mites_dist_1(*random_engine);
		}
		if(seeding_size==2)
		{
               mites_size=mites_dist_2(*random_engine);
		}
	     if(seeding_size==3)
		{
               mites_size=mites_dist_3(*random_engine);
		}
		if(seeding_size==4)
		{
               mites_size=mites_dist_4(*random_engine);
		}
		return mites_size;
	}

     /////////////////////////////////////////////////////////////////////
     // generate random stars size based on user input
     /////////////////////////////////////////////////////////////////////
     //
	int find_stars_size(int seeding_size, default_random_engine * random_engine)
	{
          int stars_size=0;
		if(seeding_size==0)
		{  
               stars_size=stars_dist_0(*random_engine);
		}
		if(seeding_size==1)
		{  
               stars_size=stars_dist_1(*random_engine);
		}
		if(seeding_size==2)
		{
               stars_size=stars_dist_2(*random_engine);
		}
	     if(seeding_size==3)
		{
               stars_size=stars_dist_3(*random_engine);
		}
		if(seeding_size==4)
		{
               stars_size=stars_dist_4(*random_engine);
		}
		return stars_size;
	}
     /////////////////////////////////////////////////////////////////////
     // convert user input for universe size to display variable
     /////////////////////////////////////////////////////////////////////
     //
     int find_units(int seeding_size)
	{
          int units=0;

		if(seeding_size==0)
		{
               units=100;
	     }
		if(seeding_size==1)
		{
               units=500;
	     }
		if(seeding_size==2)
		{
               units=5000;
	     }
		if(seeding_size==3)
		{
               units=50000;
	     }
		if(seeding_size==4)
		{
               units=500000;
	     }
		return units;
	}

     /////////////////////////////////////////////////////////////////////
     // while loops to increment the clock for all universal objects
     /////////////////////////////////////////////////////////////////////
     //
	// planet time incrementer
	void * planets_tick_tock(list<node>* planets)
	{
		list<node>::iterator planets_itr;		

          planets_itr=planets->begin();
		while(planets_itr!=planets->end())
		{
			planets_itr->slipping_time();		
			planets_itr++;
		}
	}
	// mites time incrementer
	void * mites_tick_tock(list<mite>* mites, list<node>* planets, default_random_engine* random_engine, universe * universal)
	{
		// local variables
		list<node>::iterator planets_itr;
		list<mite>::iterator mites_itr; 
		list<node*>::iterator links_itr;
		list<node*> journey;
		list<node*>::iterator journey_itr;
		node* my_planet;
		node* planet_1;
		node* planet_2;
		bool a_new_path=false;
		bool path_less_traveled=false;
		bool a_new_node=false;
		int old_node_id=0;
	     int new_node_id=0;
		int max_size=0;

          // LET THE BEAST WALK AMONGST THEM
          mites_itr=mites->begin();
		while(mites_itr!=mites->end())
		{
			journey.clear();
			planets_itr=planets->begin();
			while(planets_itr!=planets->end())
			{
				if(mites_itr->get_current_node_id()==planets_itr->get_id())
				{
					my_planet=&*planets_itr;
					break;
				}
				planets_itr++;
			}
			uniform_int_distribution<int> tick_tock_dist(0,planets->size());
			planets_itr=planets->begin(); //reset, recycle, reuse
			links_itr=my_planet->get_planet_links()->begin();
			while(links_itr!=my_planet->get_planet_links()->end())
			{
				journey.push_back(*links_itr);
				links_itr++;
			}
/*
			for(int i=0;i<tick_tock_dist(*random_engine);i++)
			{
				planets_itr++;
			}
			links_itr=my_planet->get_planet_links()->begin();

			while(links_itr!=my_planet->get_planet_links()->end())
			{
				if(planets_itr->get_id()==(*links_itr)->get_id())
				{
					a_new_path=false;
				}
				links_itr++;
			}
			if(planets_itr->get_id()==my_planet->get_id())
			{
				a_new_path=false;
			}
			if(universal->range_finder_double(&*planets_itr, my_planet)>0.12)
			{
				a_new_path=false;
			}
			if(a_new_path=true)
			{
				path_less_traveled=true;
				journey.push_back(
			}
*/		
			a_new_path=false;
			// randomly pick a new path or an existing path, with equal chance of every path

			if(journey.size()==0)
			{
				journey.push_back(my_planet);
			}
			path_less_traveled=false;
			uniform_int_distribution<int> path_dist(0, journey.size());
			journey_itr=journey.begin();
			for(int j=0;j<path_dist(*random_engine);j++)
			{
				journey_itr++;
			}
			
			mites_itr->slipping_time((*journey_itr)->get_x(),(*journey_itr)->get_y(),(*journey_itr)->get_z(),(*journey_itr)->get_id(),a_new_node, old_node_id, new_node_id);	
			
			if(a_new_node==true)
			{
				//add new link between planets
				planets_itr=planets->begin();
				while(planets_itr!=planets->end())
				{
					if(planets_itr->get_id()==mites_itr->get_current_node_id())
					{
						planet_1=&*planets_itr;
					}
					if(planets_itr->get_id()==mites_itr->get_next_node_id())
					{
						planet_2=&*planets_itr;
					}
					planets_itr++;
				}
				if(planet_1->get_id()!=planet_2->get_id())
				{
					planet_1->add_link(planet_2);
				}
			}	
			mites_itr++;
		}
	}

	// stars time incrementer
	void * stars_tick_tock(list<star>* stars, list<node>* planets, default_random_engine* random_engine)
	{ /*
		// local variables
		list<node>::iterator planets_itr;
		list<star>::iterator stars_itr; 
		list<node*>::iterator links_itr;
		list<node*> journey;
		list<node*>::iterator journey_itr;
		node* my_planet;

          // SO THEY MAY KNOW FEAR
          stars_itr=stars->begin();
		while(stars_itr!=stars->end())
		{
			journey.clear();
			my_planet=NULL;
			cout<<journey.size()<<endl;
			
			planets_itr=planets->begin();
			while(planets_itr!=planets->end())
			{
				if(stars_itr->get_current_node_id()==planets_itr->get_id())
				{
					my_planet=&*planets_itr;
				}
				planets_itr++;
			}
			uniform_int_distribution<int> tick_tock_dist(0,planets->size());
			planets_itr=planets->begin(); //reset, recycle, reuse
			links_itr=my_planet->get_planet_links()->begin();
			cout<<&*links_itr<<endl;
			while(links_itr!=my_planet->get_planet_links()->end())
			{
				journey.push_back(*links_itr);
				links_itr++;
			}

			// randomly pick an existing path, with equal chance of every path
			uniform_int_distribution<int> path_dist(0, journey.size());
			cout<<journey.size()<<endl;

			if(journey.size()==1)
			{
				journey_itr=journey.begin();
			}
			if(journey.size()==0)
			{
				journey.push_back(my_planet);
				journey_itr=journey.begin();
			}
			else if(journey.size()>1)
			{
				journey_itr=journey.begin();
				for(int j=0;j<path_dist(*random_engine);j++)
				{
					journey_itr++;
				}
			}
			cout<<&*journey_itr<<" "<<(*journey_itr)->get_id()<<endl;
			stars_itr->slipping_time((*journey_itr)->get_x(),(*journey_itr)->get_y(),(*journey_itr)->get_z(),(*journey_itr)->get_id());		

			stars_itr++;
		}*/

	}

     /////////////////////////////////////////////////////////////////////
     // if i/clock == x/44, where x={1...44}, will return true
     /////////////////////////////////////////////////////////////////////
     //
	bool update_user(int clock, int i)
	{
		if(i==clock/44){return true;}
		if(i==1*clock/44){return true;}
		if(i==2*clock/44){return true;}
		if(i==3*clock/44){return true;}
		if(i==4*clock/44){return true;}
		if(i==5*clock/44){return true;}
		if(i==6*clock/44){return true;}
		if(i==7*clock/44){return true;}
		if(i==8*clock/44){return true;}
		if(i==9*clock/44){return true;}
		if(i==10*clock/44){return true;}
		if(i==11*clock/44){return true;}
		if(i==12*clock/44){return true;}
		if(i==13*clock/44){return true;}
		if(i==14*clock/44){return true;}
		if(i==15*clock/44){return true;}
		if(i==16*clock/44){return true;}
		if(i==17*clock/44){return true;}
		if(i==18*clock/44){return true;}
		if(i==19*clock/44){return true;}
		if(i==20*clock/44){return true;}
		if(i==21*clock/44){return true;}
		if(i==22*clock/44){return true;}
		if(i==23*clock/44){return true;}
		if(i==24*clock/44){return true;}
		if(i==25*clock/44){return true;}
		if(i==26*clock/44){return true;}
		if(i==27*clock/44){return true;}
		if(i==28*clock/44){return true;}
		if(i==29*clock/44){return true;}
		if(i==30*clock/44){return true;}
		if(i==31*clock/44){return true;}
		if(i==32*clock/44){return true;}
		if(i==33*clock/44){return true;}
		if(i==34*clock/44){return true;}
		if(i==35*clock/44){return true;}
		if(i==36*clock/44){return true;}
		if(i==37*clock/44){return true;}
		if(i==38*clock/44){return true;}
		if(i==39*clock/44){return true;}
		if(i==40*clock/44){return true;}
		if(i==41*clock/44){return true;}
		if(i==42*clock/44){return true;}
		if(i==43*clock/44){return true;}
		if(i==44*clock/44){return true;}
		return false;
	}


