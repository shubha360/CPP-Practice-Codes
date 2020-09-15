#include<iostream>
#include "Movie.h"

Movie :: Movie(std :: string movieName, short releaseYear, int watchCount) {

    this -> movieName = movieName;
    this -> releaseYear = releaseYear;
    this -> watchCount = watchCount;
}

std :: string Movie :: getMovieName() const {
    return movieName;
}

short Movie :: getReleaseYear() const {
    return releaseYear;
}

int Movie :: getWatchCount() const {
    return watchCount;
}

void Movie :: incrementWatchCount() {

    watchCount += 1;
}