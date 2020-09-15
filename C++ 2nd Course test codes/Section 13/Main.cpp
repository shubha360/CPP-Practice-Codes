#include<iostream>
#include "Movie.cpp"
#include "MovieList.cpp"

int main() {

    MovieList myMovies;

    myMovies.addMovie("Memento", 2000, 3);
    myMovies.addMovie("Inception", 2010, 4);
    myMovies.addMovie("The Prestige", 2006, 3);

    myMovies.addMovie("Memento", 2000, 1);

    myMovies.displayList();

    myMovies.incrementWatch("Man of Steel");

    myMovies.incrementWatch("Inception");

    myMovies.displayList();

    return 0;
}