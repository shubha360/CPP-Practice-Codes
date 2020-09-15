#include<iostream>
#include<vector>
#include "MovieList.h"
#include "Movie.h"

MovieList :: MovieList() {

    movieList = {};
}

void MovieList :: displayList() {

    if (movieList.size() == 0) {
        std :: cout << "List is currently empty." << std :: endl;
        return;
    }
    
    std :: cout << "\t Movie Name \t Realese Year \t Watch Count" << std :: endl;
    std :: cout << std :: endl;
    
    for (size_t i = 0; i < movieList.size(); i++) {
        std :: cout << "\t";
        std :: cout << movieList[i].getMovieName();
        std :: cout << "\t";
        std :: cout << movieList[i].getReleaseYear();
        std :: cout << "\t";
        std :: cout << movieList[i].getWatchCount();
        std :: cout << std :: endl;
    }
}

void MovieList :: addMovie(std :: string movieName, short releaseDate, int watchCount) {

    Movie movie(movieName, releaseDate, watchCount);

    if(movieList.size() == 0) {

        movieList.push_back(movie);
        std :: cout << movieName;
        std :: cout << " is added to list." << std :: endl;
    }

    else {
        
        for(int i = 0; i < movieList.size(); i++) {

            if(movieList[i].getMovieName() == movieName) {
                std :: cout << movieName;
                std :: cout << " is already in the list." << std :: endl;
                return;
            }
        }
    movieList.push_back(movie);
    std :: cout << movieName;
    std :: cout << " is added to list." << std :: endl;
    }
}

void MovieList :: incrementWatch(std :: string movieName) {

    if(movieList.size() == 0)
        std :: cout << "Movie list is currently empty." << std :: endl;

    else {

        for(int i = 0; i < movieList.size(); i++) {

            if(movieList[i].getMovieName() == movieName) {
                movieList[i].incrementWatchCount();
                return;
            }
        }
        std :: cout << "Movie is not in the list." << std :: endl;
    }
}