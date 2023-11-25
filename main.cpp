#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

class Movie {
public:
    std::string title;
    std::string genre;
    double rating;
    std::string region;

    Movie(const std::string& t, const std::string& g, double r, const std::string& reg)
        : title(t), genre(g), rating(r), region(reg) {}
};

class TreeNode {
public:
    Movie data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const Movie& m) : data(m), left(nullptr), right(nullptr) {}
};

class MovieDatabase {
private:
    TreeNode* root;
    std::queue<std::string> searchHistory;

    void addToTree(TreeNode*& node, const Movie& movie) {
        if (node == nullptr) {
            node = new TreeNode(movie);
        } else if (movie.title < node->data.title) {
            addToTree(node->left, movie);
        } else {
            addToTree(node->right, movie);
        }
    }

    void searchByTitleRecursive(TreeNode* node, const std::string& searchTerm) {
        if (node != nullptr) {
            if (node->data.title.find(searchTerm) != std::string::npos) {
                displayMovieDetails(node->data);
            }
            if (searchTerm < node->data.title) {
                searchByTitleRecursive(node->left, searchTerm);
            } else {
                searchByTitleRecursive(node->right, searchTerm);
            }
        }
    }

    void searchByRatingRecursive(TreeNode* node, double minRating, std::vector<Movie>& matchingMovies) {
        if (node != nullptr) {
            if (node->data.rating >= minRating) {
                matchingMovies.push_back(node->data);
            }
            searchByRatingRecursive(node->left, minRating, matchingMovies);
            searchByRatingRecursive(node->right, minRating, matchingMovies);
        }
    }

    void searchByGenreRecursive(TreeNode* node, const std::string& searchTerm) {
        if (node != nullptr) {
            if (node->data.genre.find(searchTerm) != std::string::npos) {
                displayMovieDetails(node->data);
            }
            searchByGenreRecursive(node->left, searchTerm);
            searchByGenreRecursive(node->right, searchTerm);
        }
    }

    void searchByRegionRecursive(TreeNode* node, const std::string& searchTerm) {
        if (node != nullptr) {
            if (node->data.region.find(searchTerm) != std::string::npos) {
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

    void searchByTitle(const std::string& searchTerm) {
        searchHistory.push(searchTerm);
        searchByTitleRecursive(root, searchTerm);
    }

    void searchByRating(double minRating) {
        std::vector<Movie> matchingMovies;
        searchHistory.push(std::to_string(minRating));
        searchByRatingRecursive(root, minRating, matchingMovies);

        std::sort(matchingMovies.begin(), matchingMovies.end(), [](const Movie& a, const Movie& b) {
            return a.rating > b.rating;
        });

        for (const auto& movie : matchingMovies) {
            displayMovieDetails(movie);
        }
    }

    void searchByGenre(const std::string& searchTerm) {
        searchHistory.push(searchTerm);
        searchByGenreRecursive(root, searchTerm);
    }

    void searchByRegion(const std::string& searchTerm) {
        searchHistory.push(searchTerm);
        searchByRegionRecursive(root, searchTerm);
    }

    void displayMovieDetails(const Movie& movie) {
        std::cout << "Title: " << movie.title << "\nGenre: " << movie.genre
                  << "\nRating: " << movie.rating << "\nRegion: " << movie.region << "\n\n";
    }

    void displaySearchHistory(){
        std::cout << "\nSearch History:\n";\
        std::queue<std::string> tempQueue = searchHistory;
        while (!tempQueue.empty()){
            std::cout << tempQueue.front() << " ";
            tempQueue.pop();
        }
        std::cout << "\n\n";
    }
};

int main() {
    MovieDatabase movieDB;

    // List of movies to add
    std::vector<Movie> moviesToAdd = {
        Movie("Jurassic World", "Action", 6.9, "USA"),
        Movie("Train to Busan", "Action", 7.6, "Korea"),
        Movie("Uncharted", "Action", 6.3, "USA"),
        Movie("Demon Slayer", "Anime", 8.6, "Japan"),
        Movie("Attack on Titan", "Anime", 9.0, "Japan"),
        Movie("Spy x Family", "Anime", 8.4, "Japan"),
        Movie("Imperfect", "Romance", 7.7, "Indonesia"),
        Movie("Anne with an E", "Drama", 8.6, "America"),
        Movie("Monster Hunter", "Fantasy", 5.2, "America"),
        Movie("Girl From Nowhere", "Teen", 7.6, "Thailand"),
        Movie("Police Story", "Classics", 7.5, "China"),
        Movie("Cigarette Girl", "Romance", 8.3, "Indonesia"),
        Movie("Pride and Prejudice", "Drama", 7.8, "Europe"),
        // Add more movies here...
    };

    // Loop to add movies
    for (const auto& movie : moviesToAdd) {
        movieDB.addMovie(movie);
    }

repeater:
    int genrenum;
    int regionnum;

    std::cout << "============================================================";
    std::cout << "====================WEFLIX SEARCH ENGINE====================";
    std::cout << "|  Enter search term by entering a corresponding number:   |";
    std::cout << "|                         1. Title                         |";
    std::cout << "|                         2. Rating                        |";
    std::cout << "|                         3. Genre                         |";
    std::cout << "|                         4. Region                        |";
    std::cout << "============================================================";
    std::string searchTerm;
    int InputValue;
    std::cin >> InputValue;

    // Searching for movies based on user input
    if (InputValue == 1) {
        std::cout << "Enter title: ";
        std::cin >> searchTerm;
        movieDB.searchByTitle(searchTerm);
    }
    else if (InputValue == 2) {
        double minRating;
        std::cout << "Enter minimum rating: ";
        std::cin >> minRating;
        movieDB.searchByRating(minRating);
    }
    else if (InputValue == 3) {
        // Action, anime, comedy, Children & Family, crime, drama, fantasy, horror, musical, romance, sci-fi, sports, teen, thriller, classic
        std::cout << "Enter genre via a corresponding number: \nAction (1)\nAnime (2)\nComedy (3)\nChildren & Family (4)\nCrime (5)\nDrama (6)\nFantasy (7)\nHorror (8)\nMusical (9)\nRomance (10)\nSci-fi(11)\nSports (12)\nTeen (13)\nThriller (14)\nClassic (15)\n\n";

        std::cout << "Enter your input: ";
        std::cin >> genrenum;

        if (genrenum >= 1 && genrenum <= 15) {
            std::vector<std::string> genres = {
                "Action", "Anime", "Comedy", "Children & Family", "Crime", "Drama", "Fantasy", "Horror",
                "Musical", "Romance", "Sci-Fi", "Sports", "Teen", "Thriller", "Classic"
            };
            std::cout << "Searching for " << genres[genrenum - 1] << "\n\n";
            movieDB.searchByGenre(genres[genrenum - 1]);
        } else {
            std::cout << "Invalid genre selection.\n";
        }

    }
    else if (InputValue == 4) {
        // Movie index via Region - Asia (1) Europe (2) USA (3) Indonesia (4) Korea (5) China (6) Thailand (7) Japan (8)
        std::cout << "Movie index via Region - \nAsia (1) \nEurope (2) \nUSA (3)\nIndonesia (4) \nKorea (5) \nChina (6) \nThailand (7)\nJapan (8)\n\n";
        std::cout << "Enter your input for the search: ";
        std::cin >> regionnum;

        if (regionnum >= 1 && regionnum <= 8) {
            std::vector<std::string> regions = {
                "Asia", "Europe", "USA", "Indonesia", "Korea", "China", "Thailand", "Japan"
            };
            std::cout << "Searching for " << regions[regionnum - 1] << "\n\n";
            movieDB.searchByRegion(regions[regionnum - 1]);
        } else {
            std::cout << "Invalid region selection.\n";
        }

    }
    else if(InputValue == 5){
        movieDB.displaySearchHistory();
    }
        else {
        std::cout << "Invalid search term. Please enter 'title', 'rating', 'genre', or 'region'.\n";
    }

    std::string RepeatInput;
    std::cout << "Would you like to go back to the main menu? (yes/no): ";
    std::cin >> RepeatInput;

    if (RepeatInput == "yes") {
        goto repeater;
    } else {
        std::cout << "Thank you for using this program!\n";

        return 0;
    }
}
