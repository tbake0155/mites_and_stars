//
// Author: Timothy Baker
// cs361: Assignment 2
//"A story of Mites and Stars"
//
//node.cpp

////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "node.h"

     ///////////////////////////////////////////////////////////////////
	// remove mites and stars that leave, bye bye and GodSpeed
     ///////////////////////////////////////////////////////////////////
	//
	// remove movers
	void node::remove_movers()
	{
		planet_stars_itr=planet_stars.begin();
		while(planet_stars_itr!=planet_stars.end())
		{
			
			/*
				star* new_moon=*planet_stars_itr;
				star blood_moon=*new_moon;
				if(star_has_moved(blood_moon)==true)
				{
					planet_stars.remove(*planet_stars_itr);
				}
			*/
				planet_stars_itr++;
			
		}
		if(planet_mites.size()!=0)
		{
			planet_mites_itr=planet_mites.begin();
			while(planet_mites_itr!=planet_mites.end())
			{
				/*if(*planet_mites_itr==NULL){continue;}
				else
				{
					mite* fright_mite=*planet_mites_itr;
					mite mighty_mite=*fright_mite;
					if(mite_has_moved(mighty_mite)==true)
					{
						planet_mites.remove(*planet_mites_itr);

					}
				}*/
				planet_mites_itr++;
			}
		}
	}
	// find if the mite has moved by comparing x,y,z
	bool node::mite_has_moved(mite mite)
	{
		if(x==mite.get_x())
		{
			if(y==mite.get_y())
			{
				if(z==mite.get_z())
				{	
					return false;
				}
			}
		}
		return true;
	}
	// find if the star has moved by comparing x,y,z
	bool node::star_has_moved(star star)
	{
		if(x==star.get_x())
		{
			if(y==star.get_y())
			{
				if(z==star.get_z())
				{	
					return false;
				}
			}
		}
		return true;
	}


     ///////////////////////////////////////////////////////////////////
	// 
     ///////////////////////////////////////////////////////////////////

