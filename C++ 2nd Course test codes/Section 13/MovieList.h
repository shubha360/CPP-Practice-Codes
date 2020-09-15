#ifndef _MOVIELIST_H_
#define _MOVIELIST_H_

#include<string>
#include<vector>
#include "Movie.h"

class MovieList {

    private :
        
        std :: vector<Movie> movieList;

    public :

        MovieList();
        void displayList();
        void addMovie(std :: string movieName, short releaseDate, int watchCount);
        void incrementWatch(std :: string movieName);
};

#endif