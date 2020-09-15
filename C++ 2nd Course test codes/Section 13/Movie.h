#ifndef _MOVIE_H_
#define _MOVIE_H_
#include<string>

class Movie {

    private :

        std :: string movieName;
        short releaseYear;
        int watchCount;

    public :

        Movie(std :: string movieName, short releaseYear, int watchCount);
        std :: string getMovieName () const;
        short getReleaseYear() const;
        int getWatchCount() const;
        void incrementWatchCount();
};

#endif
