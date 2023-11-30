#ifndef DATABASEH
#define DATABASEH

#include "tree.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <sstream>
#include <fstream>

using namespace std;

class MovieDatabase {
    private:
        TreeNode* root;
        queue<string> searchHistory;

	//Inserts a movie into the binary search tree based on its title
        void addToTree(TreeNode*& node, const Movie& movie) {
            if (node == nullptr) {
                node = new TreeNode(movie);
            } else if (movie.title < node->data.title) {
                addToTree(node->left, movie);
            } else {
                addToTree(node->right, movie);
            }
        }

	//Recursively searches for movies by title and populates a vector with matching movies.
        void searchByTitleRecursive(TreeNode* node, const string& searchTerm, vector<Movie>& matchingMovies) {
            if (node != nullptr) {
                if (node->data.title.find(searchTerm) != string::npos) {
                    matchingMovies.push_back(node->data);
                }
                searchByTitleRecursive(node->left, searchTerm, matchingMovies);
                searchByTitleRecursive(node->right, searchTerm, matchingMovies);
            }
        }

	//Recursively searches for movies by rating and populates a vector with matching movies.
        void searchByRatingRecursive(TreeNode* node, int minRating, vector<Movie>& matchingMovies) {
            if (node != nullptr) {
                if (node->data.rating >= minRating) {
                    matchingMovies.push_back(node->data);
                }
                searchByRatingRecursive(node->left, minRating, matchingMovies);
                searchByRatingRecursive(node->right, minRating, matchingMovies);
            }
        }

	//Recursively searches for movies by genre and populates a vector with matching movies.
        void searchByGenreRecursive(TreeNode* node, const string& searchTerm, vector<Movie>& matchingMovies) {
            if (node != nullptr) {
                if (node->data.genre.find(searchTerm) != string::npos) {
                    matchingMovies.push_back(node->data);
                }
                searchByGenreRecursive(node->left, searchTerm, matchingMovies);
                searchByGenreRecursive(node->right, searchTerm, matchingMovies);
            }
        }

	//Recursively searches for movies by region and populates a vector with matching movies.
        void searchByRegionRecursive(TreeNode* node, const string& searchTerm, vector<Movie>& matchingMovies) {
            if (node != nullptr) {
                if (node->data.region.find(searchTerm) != string::npos) {
                    matchingMovies.push_back(node->data);
                }
                searchByRegionRecursive(node->left, searchTerm, matchingMovies);
                searchByRegionRecursive(node->right, searchTerm, matchingMovies);
            }
        }

	//Function to load movies from the database to this file.
        void loadMoviesFromFile(const string& filename){
            ifstream file(filename);
            if (!file.is_open()){
                cerr << "Error: Could not open the file" << filename << endl;
                return;
            }

            string line;
            while (getline(file, line)){
                Movie movie = Movie::fromString(line);
                addMovie(movie);
            }

            file.close();
        }

    public:
	//load the movies
        MovieDatabase() : root(nullptr) {
            const string filename = "movieslists.txt";
            loadMoviesFromFile(filename);
        }

	//add the movie to the tree
        void addMovie(const Movie& movie) {
            addToTree(root, movie);
        }

        //Has a certain movie being printed out through title via input from user
        void searchByTitle(const string& searchTerm) {

            vector<Movie> matchingMovies;
            searchHistory.push(searchTerm);
            searchByTitleRecursive(root, searchTerm, matchingMovies);

		// Sort by title before displaying
            sort(matchingMovies.begin(), matchingMovies.end(), [](const Movie& a, const Movie& b) {
                return a.title < b.title;
            });

            for (size_t i = 0; i < matchingMovies.size(); ++i) {
                displayMovieDetails(i + 1, matchingMovies[i]);
            }
        }

        //Has movies being searched via rating
        void searchByRating(int minRating) {

            vector<Movie> matchingMovies;
            searchHistory.push(to_string(minRating));
            searchByRatingRecursive(root, minRating, matchingMovies);

            //Sorting system for the movies as it gets printed
            sort(matchingMovies.begin(), matchingMovies.end(), [](const Movie& a, const Movie& b) {
                return a.rating > b.rating;
            });

            for (size_t i = 0; i < matchingMovies.size(); ++i) {
                displayMovieDetails(i + 1, matchingMovies[i]);
            }
        }

        //Does a search via genre specified from the user
        void searchByGenre(const string& searchTerm) {

            vector<Movie> matchingMovies;
            searchHistory.push(searchTerm);
            searchByGenreRecursive(root, searchTerm, matchingMovies);

            // Sort by title before displaying
            sort(matchingMovies.begin(), matchingMovies.end(), [](const Movie& a, const Movie& b) {
                return a.title < b.title;
            });

            for (size_t i = 0; i < matchingMovies.size(); ++i) {
                displayMovieDetails(i + 1, matchingMovies[i]);
            }
        }

        //Does a search via region specified from the user
        void searchByRegion(const string& searchTerm) {

            vector<Movie> matchingMovies;
            searchHistory.push(searchTerm);

			    if (searchTerm == "Asia"){
                
                //Include specific searches for countries in Asia
                searchByRegionRecursive(root, "Indonesia", matchingMovies);
                searchByRegionRecursive(root, "Korea", matchingMovies);
                searchByRegionRecursive(root, "China", matchingMovies);
                searchByRegionRecursive(root, "Thailand", matchingMovies);
                searchByRegionRecursive(root, "Japan", matchingMovies);
            }
            else {
                searchByRegionRecursive(root, searchTerm, matchingMovies);
            }

			// Sort by title before displaying
            sort(matchingMovies.begin(), matchingMovies.end(), [](const Movie& a, const Movie& b) {
                return a.title < b.title;
            });

			for (size_t i = 0; i < matchingMovies.size(); ++i) {
                displayMovieDetails(i + 1, matchingMovies[i]);
            }
            
        }

        //Prints out details of the movie, ranging from title, genre, ratings, and region
        void displayMovieDetails(int number, const Movie& movie) {
            if (number <= 9) {
                cout << number << ". " << "Title : " << movie.title << "\n";
			    cout << "   Genre :" << movie.genre << "\n";
                cout << "   Rating: " << movie.rating << "\n";
			    cout << "   Region:" << movie.region << "\n" << endl;
            }
            else {
                cout << number << ". " << "Title : " << movie.title << "\n";
			    cout << "    Genre :" << movie.genre << "\n";
                cout << "    Rating: " << movie.rating << "\n";
			    cout << "    Region:" << movie.region << "\n" << endl;
            }
        }

        //Shows the search history done by the user
        void displaySearchHistory(){
            cout << "\nSearch History:\n";\
            queue<string> tempQueue = searchHistory;
            while (!tempQueue.empty()){
                cout << tempQueue.front() << " ";
                tempQueue.pop();
            }
            cout << "\n\n";
        }
};

#endif
