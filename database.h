#ifndef DATABASEH
#define DATABASEH

#include "tree.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iomanip>

using namespace std;

class MovieDatabase {
    private:
        TreeNode* root;
        queue<string> searchHistory;

        void addToTree(TreeNode*& node, const Movie& movie) {
            if (node == nullptr) {
                node = new TreeNode(movie);
            } else if (movie.title < node->data.title) {
                addToTree(node->left, movie);
            } else {
                addToTree(node->right, movie);
            }
        }

        void searchByTitleRecursive(TreeNode* node, const string& searchTerm) {
            if (node != nullptr) {
                if (node->data.title.find(searchTerm) != string::npos) {
                    displayMovieDetails(node->data);
                }
                if (searchTerm < node->data.title) {
                    searchByTitleRecursive(node->left, searchTerm);
                } else {
                    searchByTitleRecursive(node->right, searchTerm);
                }
            }
        }

        void searchByRatingRecursive(TreeNode* node, int minRating, vector<Movie>& matchingMovies) {
            if (node != nullptr) {
                if (node->data.rating >= minRating) {
                    matchingMovies.push_back(node->data);
                }
                searchByRatingRecursive(node->left, minRating, matchingMovies);
                searchByRatingRecursive(node->right, minRating, matchingMovies);
            }
        }

        void searchByGenreRecursive(TreeNode* node, const string& searchTerm) {
            if (node != nullptr) {
                if (node->data.genre.find(searchTerm) != string::npos) {
                    displayMovieDetails(node->data);
                }
                searchByGenreRecursive(node->left, searchTerm);
                searchByGenreRecursive(node->right, searchTerm);
            }
        }

        void searchByRegionRecursive(TreeNode* node, const string& searchTerm) {
            if (node != nullptr) {
                if (node->data.region.find(searchTerm) != string::npos) {
                    displayMovieDetails(node->data);
                }
                searchByRegionRecursive(node->left, searchTerm);
                searchByRegionRecursive(node->right, searchTerm);
            }
        }

    public:
        MovieDatabase() : root(nullptr) {}

        void addMovie(const Movie& movie) {
            addToTree(root, movie);
        }

        void searchByTitle(const string& searchTerm) {
            searchHistory.push(searchTerm);
            searchByTitleRecursive(root, searchTerm);
        }

        void searchByRating(int minRating) {
            vector<Movie> matchingMovies;
            searchHistory.push(to_string(minRating));
            searchByRatingRecursive(root, minRating, matchingMovies);

            sort(matchingMovies.begin(), matchingMovies.end(), [](const Movie& a, const Movie& b) {
                return a.rating > b.rating;
            });

            for (const auto& movie : matchingMovies) {
                displayMovieDetails(movie);
            }
        }

        void searchByGenre(const string& searchTerm) {
            searchHistory.push(searchTerm);
            searchByGenreRecursive(root, searchTerm);
        }

        void searchByRegion(const string& searchTerm) {
            searchHistory.push(searchTerm);
            searchByRegionRecursive(root, searchTerm);
        }

        void displayMovieDetails(const Movie& movie) {
            cout << "Title: " << movie.title << "\nGenre: " << movie.genre
                    << "\nRating: " << movie.rating << "\nRegion: " << movie.region << "\n\n";
        }

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