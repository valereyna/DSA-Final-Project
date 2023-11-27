#ifndef MOVIEH
#define MOVIEH

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <sstream>
#include <fstream>

using namespace std;

class Movie {
//Movie search by categories.
public:
    string title;
    string genre;
    double rating;
    string region;

    Movie(const string& t, const string& g, double r, const string& reg)
        : title(t), genre(g), rating(r), region(reg) {}

    static Movie fromString(const string& movieStr){
        istringstream ss(movieStr);
        string title, genre, region;
        double rating;
        getline(ss, title, ',');
        getline(ss, genre, ',');
        ss >> rating;
        ss.ignore();  // Ignore the comma
        getline(ss, region);
        return Movie(title, genre, rating, region);
    }
    
};

#endif
