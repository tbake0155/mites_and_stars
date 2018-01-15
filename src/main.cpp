//
// Author: Timothy Baker
// cs361: Assignment 2
//"A story of Mites and Stars"
//
//main.cpp

////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <random>
#include <ctime>
#include <list>
#include <thread>
#include <string>
#include "universe.h"
#include "cthulu.h"
#include "node.h"
#include "mite.h"
#include "star.h"

using namespace std;

int main() //main is the only universe our mites and stars will ever know
{
	///////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////                    //////////////////////////////////////////
	///////////////////////////     PHASE ONE:     ////////////////////////////////////////////
     /////////////////////////// INITIALIZING PHASE //////////////////////////////////////////////
	///////////////////////////                    ////////////////////////////////////////////////
     /////////////////////////////////////////////////////////////////////////////////////////////////

     ////////////////////////////////////////////////////////////////////
	// create instance of universe
     ////////////////////////////////////////////////////////////////////
     //
	universe universal; // holds universe specific data

     ////////////////////////////////////////////////////////////////////
	// create instance of sleeping cthulu in universe
     ////////////////////////////////////////////////////////////////////
     //
     cthulu mighty_cthulu("sleeping"); // don't wake mighty cthulu

     ////////////////////////////////////////////////////////////////////
	// create random number generator engine and variables
     ////////////////////////////////////////////////////////////////////
     //
	default_random_engine random_engine(time(NULL));
	// create random distribution variable for planetary linkage
	normal_distribution<double> link_dist(2,1);

	/////////////////////////////////////////////////////////////////////
     // ask user for seeding size 
     /////////////////////////////////////////////////////////////////////
     //
	cout<<"\n\n...WELCOME TO A STORY OF MITES AND STARS..."<<endl;
	cout<<"..........................................."<<endl;
     int* seeding_size = new int[5];  			    // so i dont waste stack memory on
	// universe size                                 // global variables
	cout<<"What universe size?(1-4)"<<endl;
	cin>>seeding_size[0];
	if(seeding_size[0]>4){seeding_size[0]=4;}
     if(seeding_size[0]<0){seeding_size[0]=1;}
	universal.set_size(seeding_size[0]);
	universal.max_range(seeding_size[0]);
	// planet distribution
     cout<<"What magnitude of planet seeding?(1-4)"<<endl;
	cin>>seeding_size[1];
	if(seeding_size[1]>4){seeding_size[1]=4;}
     if(seeding_size[1]<0){seeding_size[1]=1;}
	// star distribution
     cout<<"What magnitude of star seeding?(1-4)"<<endl;
	cin>>seeding_size[2];
	if(seeding_size[2]>4){seeding_size[2]=4;}
     if(seeding_size[2]<0){seeding_size[2]=1;}
	// mite distribution
     cout<<"What magnitude of mite seeding?(1-4)"<<endl;
	cin>>seeding_size[3]; 
	if(seeding_size[3]>4){seeding_size[3]=4;}
     if(seeding_size[3]<0){seeding_size[3]=1;}
	// time steps to proceed
	cout<<"How many time steps should the program run?"<<endl;
	cin>>seeding_size[4]; cout<<endl;
	if(seeding_size[4]<100){seeding_size[4]=100;}
	universal.set_clock(seeding_size[4]);

	/////////////////////////////////////////////////////////////////////
     // generate a list of nodes based on the user requested magnitude
     /////////////////////////////////////////////////////////////////////
     //
     list<node> planets;
	list<node>::iterator planets_itr;
	
	node* planet_ptr=NULL;

     int* planetary_configuration=new int[4];

     planetary_configuration[0]=find_planets_size(&random_engine, seeding_size[1]);
     planetary_configuration[1]=0; //x
     planetary_configuration[2]=0; //y
     planetary_configuration[3]=0; //z

     for(int i=0;i<planetary_configuration[0];i++)
     {
          find_xyz(seeding_size[0],&random_engine,planetary_configuration[1],planetary_configuration[2],planetary_configuration[3]);
          planet_ptr=new node(i, planetary_configuration[1],planetary_configuration[2],planetary_configuration[3]);
          planets.push_back(*planet_ptr);
          delete planet_ptr;
	}       
	
	/////////////////////////////////////////////////////////////////////
     // generate a list of mites
     /////////////////////////////////////////////////////////////////////
     //
     int* mites_size=new int[1];
	mites_size[0]=find_mites_size(seeding_size[3], &random_engine);

     list<mite> mites;
	list<mite>::iterator mites_itr;
	mite* mites_ptr;

     for(int i=0;i<mites_size[0];i++)
     {
          mites_ptr=new mite(&random_engine);
          mites.push_back(*mites_ptr);
          delete mites_ptr;
	} 
	delete mites_size;

	/////////////////////////////////////////////////////////////////////
     // generate a list of stars
     /////////////////////////////////////////////////////////////////////
     //
     int* stars_size=new int[1];
	stars_size[0]=find_stars_size(seeding_size[2], &random_engine);

	list<star> stars;
	list<star>::iterator stars_itr;
	star* stars_ptr;

     for(int i=0;i<stars_size[0];i++)
     {
          stars_ptr=new star();
          stars.push_back(*stars_ptr);
          delete stars_ptr;
	} 
	delete stars_size;

	/////////////////////////////////////////////////////////////////////
     // update user on all randomly generated values
     /////////////////////////////////////////////////////////////////////
     //
	cout<<"\n............UNIVERSE STATISTICS............"<<endl;
	cout<<"..........................................."<<endl;
     cout<<"Universe is "<<find_units(seeding_size[0])<<" x "<<find_units(seeding_size[0])<<" x "<<find_units(seeding_size[0])<<" units"<<endl;
     cout<<setw(8)<<left<<planets.size()<<" planets created"<<endl;
	cout<<setw(8)<<left<<stars.size()<<" stars created"<<endl;
	cout<<setw(8)<<left<<mites.size()<<" mites created"<<endl;

	/////////////////////////////////////////////////////////////////////
     // release the memory from the input variables 
     /////////////////////////////////////////////////////////////////////
     //
     //  => let my people go <=
     delete []planetary_configuration;
     delete []seeding_size;
	
	/////////////////////////////////////////////////////////////////////
     // alert user that planet seeding will begin
     /////////////////////////////////////////////////////////////////////
     //
     cout<<"\n\n.............PLANET SEEDING................"<<endl;
	cout<<"..........................................."<<endl;

	
	/////////////////////////////////////////////////////////////////////
     // set mites to their initial planet
     /////////////////////////////////////////////////////////////////////
     //
     cout<<"MITES SEEDING STARTING"<<flush;
	this_thread::sleep_for(chrono::milliseconds(200));
	cout<<"."<<flush;
	this_thread::sleep_for(chrono::milliseconds(200));
	cout<<"."<<flush;
	this_thread::sleep_for(chrono::milliseconds(200));
	cout<<"."<<flush;
	// create temp variable for planets size
	int* limit=new int[1];
	limit[0]=planets.size()+1;

	mites_itr=mites.begin();
	while(mites_itr!=mites.end())
	{
		planets_itr=planets.begin();
		uniform_int_distribution<int> planet_size_dist(0,limit[0]);
		for(int i=0;i<planet_size_dist(random_engine);i++)
		{
			planets_itr++;
		}
		if(&*mites_itr!=NULL){planets_itr->add_mite(&*mites_itr);}
		mites_itr++;
	}
	this_thread::sleep_for(chrono::milliseconds(1));
	cout<<"done"<<endl;

	/////////////////////////////////////////////////////////////////////
     // set stars to their original planet
     /////////////////////////////////////////////////////////////////////
     //
     cout<<"STARS SEEDING STARTING"<<flush;
	this_thread::sleep_for(chrono::milliseconds(200));
	cout<<"."<<flush;
	this_thread::sleep_for(chrono::milliseconds(200));
	cout<<"."<<flush;
	this_thread::sleep_for(chrono::milliseconds(200));
	cout<<"."<<flush;
	
	stars_itr=stars.begin();
	while(stars_itr!=stars.end())
	{
		planets_itr=planets.begin();
		uniform_int_distribution<int> planet_size_dist(0,limit[0]);
		for(int i=0;i<planet_size_dist(random_engine);i++)
		{
			planets_itr++;
		}
		planets_itr->add_star(&*stars_itr);
		stars_itr++;
	}
	this_thread::sleep_for(chrono::milliseconds(200));
	cout<<"done"<<endl;

	/////////////////////////////////////////////////////////////////////
     // establish initial edges between planets
     /////////////////////////////////////////////////////////////////////
     //
	cout<<"LINKS SEEDING STARTING"<<flush;
	this_thread::sleep_for(chrono::milliseconds(200));
	cout<<"."<<flush;
	this_thread::sleep_for(chrono::milliseconds(200));
	cout<<"."<<flush;
	this_thread::sleep_for(chrono::milliseconds(200));
	cout<<"."<<flush;
	
	list<node>::iterator linkage_itr;
	bool within_range=false;
	uniform_int_distribution<int> planet_size_dist(0,limit[0]);
     int* rare_link=new int;

	planets_itr=planets.begin();
	while(planets_itr!=planets.end())
	{
		for(int i=0; i<link_dist(random_engine);i++)
		{
			int everything_is_not_always_possible=0; // safety net, odds are a ... thing
			while(within_range==false)
			{
				linkage_itr=planets.begin();
				for(int j=0;j<planet_size_dist(random_engine);j++)
				{	
					linkage_itr++;
				}
				if(universal.get_rare_link()>0)
				{
					if(universal.range_finder_double(&*planets_itr, &*linkage_itr)>0.4)
					{
						universal.increment_rare_link(); // allow for up to 4 links of ULTRA rare length
						within_range=true;
				     	planets_itr->add_link(&*linkage_itr);
					}
				}
			     if( universal.range_finder_double(&*planets_itr, &*linkage_itr) <= 0.20) // links shall be no longer than				
				{													        // 20% of the longest diagonal, so
					within_range=true;										   // sayeth the lord
				     planets_itr->add_link(&*linkage_itr);
				}
				everything_is_not_always_possible++;
				if(everything_is_not_always_possible > (limit[0]*limit[0]))
				{
					within_range=true; // it's not actually true but the stupid computer doesn't know any better
				}
			}
			within_range=false;
		}
		planets_itr++;
	}
	this_thread::sleep_for(chrono::milliseconds(200));
	cout<<"done"<<endl;

	// alert user that seeding is complete
	this_thread::sleep_for(chrono::milliseconds(200));
	cout<<"SEEDING COMPLETE!!!"<<endl;

     //  => let my people go <=
	delete[] limit;
     

	///////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////                  ///////////////////////////////////////////
	////////////////////////////     PHASE TWO:   /////////////////////////////////////////////
     //////////////////////////// SIMULATION PHASE ///////////////////////////////////////////////
	////////////////////////////                  /////////////////////////////////////////////////
     /////////////////////////////////////////////////////////////////////////////////////////////////


	/////////////////////////////////////////////////////////////////////
     // begin simulation 
     /////////////////////////////////////////////////////////////////////
     //
	cout<<"\n\n..............SIMULATION..................."<<endl;
	cout<<"..........................................."<<endl;
     cout<<"SIMULATION STARTING"<<flush;
	this_thread::sleep_for(chrono::milliseconds(200));
	cout<<"."<<flush;
	this_thread::sleep_for(chrono::milliseconds(200));
	cout<<"."<<flush;
	this_thread::sleep_for(chrono::milliseconds(200));
	cout<<"."<<endl;


	for(int i=0;i<universal.get_clock();i++)
	{
		/////////////////////////////////////////////////////////////////////
     	// setup file stream, plot universe, close file stream
     	/////////////////////////////////////////////////////////////////////
     	//
		// plot planets and plot planetary linkage
		int x=i+10000000000; 
		string iteration=to_string(x);
		string png_file_name="plot_" + iteration;
		list<node*>::iterator links_itr;


		fstream planet_plot;
		planet_plot.open("gnu_planet_data.txt", ios::out);
		fstream link_plot;
		link_plot.open("gnu_link_data.txt", ios::out);

		planets_itr=planets.begin();
		while(planets_itr!=planets.end())
		{	
			planet_plot<<planets_itr->get_x()<<" "<<planets_itr->get_y()<<" "<<planets_itr->get_z()<<endl;
			planet_plot<<endl<<endl;

			links_itr=planets_itr->get_planet_links_begin();
			while(links_itr!=planets_itr->get_planet_links_end())
			{
				link_plot<<planets_itr->get_x()<<" "<<planets_itr->get_y()<<" "<<planets_itr->get_z()<<endl;
				link_plot<<(*links_itr)->get_x()<<" "<<(*links_itr)->get_y()<<" "<<(*links_itr)->get_z()<<endl;
				link_plot<<endl<<endl;
				links_itr++;
			}
			planets_itr++;
		}
		planet_plot<<flush;
		planet_plot.close();
		link_plot<<flush;
		link_plot.close();

		// plot mites
		fstream mite_plot;
		mite_plot.open("gnu_mite_data.txt", ios::out);
		mites_itr=mites.begin();
		while(mites_itr!=mites.end())
		{
			mite_plot<<mites_itr->get_x()<<" "<<mites_itr->get_y()<<" "<<mites_itr->get_z()<<endl;
			mites_itr++;
		}
		mite_plot<<flush;
		mite_plot.close();

		// plot stars
		fstream star_plot, star_test;
		star_plot.open("gnu_star_data.txt", ios::out);
		star_test.open("gnu_star_test.txt", ios::out | ios::app);
		stars_itr=stars.begin();
		while(stars_itr!=stars.end())
		{ 
			star_plot<<stars_itr->get_x()<<" "<<stars_itr->get_y()<<" "<<stars_itr->get_z()<<endl;
			star_test<<stars_itr->get_x()<<" "<<stars_itr->get_y()<<" "<<stars_itr->get_z()<<endl<<endl;
			stars_itr++;
		}
		star_test<<flush;
		star_plot<<flush;
		star_plot.close();

		// open and write to gnuplot command file
		fstream plot_command;
		plot_command.open("gnu_command.txt", ios::out);
		plot_command<<" set terminal png size 1920, 1080 enhanced font \"Helvitica, 11\""<<endl;
		plot_command<<" set output '"<<png_file_name<<".png'"<<endl;

		// set x, y, z coordinate system
		plot_command<<" set xrange [-"<<universal.get_units()<<":"<<universal.get_units()<<"]"<<endl;
		plot_command<<" set yrange [-"<<universal.get_units()<<":"<<universal.get_units()<<"]"<<endl;
		plot_command<<" set zrange [-"<<universal.get_units()<<":"<<universal.get_units()<<"]"<<endl;
		
		// plot points then lines
		plot_command<<" set output '"<<png_file_name<<".png'"<<endl;
		//plot_command<<" set pointsize 4"<<endl;
		plot_command<<" splot  \"gnu_link_data.txt\" with lines,\"gnu_planet_data.txt\" with points pointtype 7 pointsize 10,\"gnu_star_data.txt\" with points pointtype 9 pointsize 8,\"gnu_mite_data.txt\" with points pointtype 7 pointsize 4"<<endl;
		plot_command<<" quit"<<endl;
		plot_command<<flush;
		plot_command.close();
		// run gnuplot to generate png file
		system("gnuplot gnu_command.txt");


		/////////////////////////////////////////////////////////////////////
     	// increment the movement for all universal objects, tick tock
     	/////////////////////////////////////////////////////////////////////
     	//
		// use four threads, this might take a while
		thread thread_one(planets_tick_tock, &planets);              			 			 // time step planets
		thread thread_two(mites_tick_tock, &mites, &planets, &random_engine, &universal);    	 // time step mites
	     thread thread_three(stars_tick_tock, &stars, &planets, &random_engine); 	     		 // time step stars
		thread thread_four(&cthulu::slipping_time, &mighty_cthulu);  			 			 // time step cthulu
		
		thread_one.join();
		thread_two.join();
		thread_three.join();
		thread_four.join();

		/////////////////////////////////////////////////////////////////////
     	// process current situation
     	/////////////////////////////////////////////////////////////////////
     	//
		//  update planetary list of stars and mites
		planets_itr=planets.begin();
		while(planets_itr!=planets.end())
		{
			planets_itr->remove_movers();
			planets_itr->add_newcomers();
			planets_itr++;
		}
		//  stars eat

		//  mites check for companions, mate if possible 


		/////////////////////////////////////////////////////////////////////
     	// update the user on the simulation progress kindly
     	/////////////////////////////////////////////////////////////////////
     	//
		// displays a '#' if clock= x/44, where x={1,2,3...44)
		if(update_user(universal.get_clock(),i)==true)
		{
	          this_thread::sleep_for(chrono::milliseconds(10));
			cout<<"#"<<flush;
		}
	}
     // alert user that the simulation has completed
	cout<<"\nSIMULATION COMPLETE!!!"<<endl;

	/////////////////////////////////////////////////////////////////////
     // create gif from pngs (linux: lol windows)
     /////////////////////////////////////////////////////////////////////
     //
	cout<<"\n\n...............ANIMATION..................."<<endl;
	cout<<"..........................................."<<endl;
     cout<<"ANIMATION STARTING"<<flush;
	this_thread::sleep_for(chrono::milliseconds(200));
	cout<<"."<<flush;
	this_thread::sleep_for(chrono::milliseconds(200));
	cout<<"."<<flush;
	this_thread::sleep_for(chrono::milliseconds(200));
	cout<<"."<<endl;;

	thread thread_one(gif_maker);
	thread thread_two(patients, &thread_one);

	thread_one.join();
	thread_two.join();
	cout<<"\nANIMATION COMPLETE!!!"<<endl;


	/////////////////////////////////////////////////////////////////////
     // alert the user that the program is exiting normally
     /////////////////////////////////////////////////////////////////////
     //
	cout<<"\nCheck for output Files...";
	cout<<"Program is exiting...\n"<<endl;

	return 0;
}
