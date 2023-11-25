#ifndef DATABASEH
#define DATABASEH

#include <iostream>
#include <string>
#include <vector>

class MovieDatabase{
    private:
        std::vector<Movie> movies;
    
    public:
        void addMovie(const Movie& movie);
        void searchByTitle(const std::string& searchTerm);
        void searchByRating(double minRating);
        void searchByGenre(const std::string& searchTerm);
        void searchByRegion(const std::string& searchTerm);
        void displayMovieDetails(const Movie& movie);
};

#endif