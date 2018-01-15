//
// Author: Timothy Baker
// cs361: Assignment 2
//"A story of Mites and Stars"
//
//cthulu.h

////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <string>

using namespace std;

#ifndef CTHULU_H_INCLUDED
#define CTHULU_H_INCLUDED


     ///////////////////////////////////////////////////////////////////
	// create class for cthulu
     ///////////////////////////////////////////////////////////////////
	class cthulu
     {
		private:
			int clock;
			string status;
			bool contentiousness;

		public:
			// constructors and destructor
			cthulu(){status="destroyer of worlds"; contentiousness=false;clock=0;}
			cthulu(string s);
			~cthulu(){}	
               // setters and getters
			std::string get_status(){return status;}
			void set_status(string s){status=s;}
               bool get_contentiousness(){return contentiousness;}
			void set_contentiousness(bool c){contentiousness=c;}
			int get_clock(){return clock;}
			void set_clock(int c){clock=c;}
			// other functions
			void * slipping_time(){clock++;}
     };

#endif//CTHULU_H_INCLUDED
