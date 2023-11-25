#ifndef MOVIEH
#define MOVIEH

#include <iostream>
#include <string>
#include <vector>

class Movie {
public:
    std::string title;
    std::string genre;
    double rating;
    std::string region;

    Movie(const std::string& t, const std::string& g, double r, const std::string& reg)
        : title(t), genre(g), rating(r), region(reg) {}
};

#endif