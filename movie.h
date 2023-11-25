#ifndef MOVIEH
#define MOVIEH

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Movie {
//Movie search categories.
public:
    string title;
    string genre;
    double rating;
    string region;

    Movie(const string& t, const string& g, double r, const string& reg)
        : title(t), genre(g), rating(r), region(reg) {}
};

#endif
