#include "movie.h"
#include "database.h"
#include "tree.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    MovieDatabase movieDB;

    // List of movies to add
    vector<Movie> moviesToAdd = {
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

    cout << endl;
    cout << "============================================================\n";
    cout << "====================WEFLIX SEARCH ENGINE====================\n";
    cout << "|                     1. Title                             |\n";
    cout << "|                     2. Rating                            |\n";
    cout << "|                     3. Genre                             |\n";
    cout << "|                     4. Region                            |\n";
    cout << "|                     5. Search History                    |\n";
    cout << "============================================================\n\n";
    cout << "Enter search term by entering a corresponding number:";
    string searchTerm;
    int InputValue;
    cin >> InputValue;

    // Searching for movies based on user input
    if (InputValue == 1) {
        cout << "Enter title: ";
        cin >> searchTerm;
        movieDB.searchByTitle(searchTerm);
    }
    else if (InputValue == 2) {
        //Prompts user to search via rating
        int minRating;
        cout << "Enter minimum rating: ";
        cin >> minRating;
        movieDB.searchByRating(minRating);
    }
    else if (InputValue == 3) {
        // Action, anime, comedy, Children & Family, crime, drama, fantasy, horror, musical, romance, sci-fi, sports, teen, thriller, classic
        cout << "Enter genre via a corresponding number: \nAction (1)\nAnime (2)\nComedy (3)\nChildren & Family (4)\nCrime (5)\nDrama (6)\nFantasy (7)\nHorror (8)\nMusical (9)\nRomance (10)\nSci-fi(11)\nSports (12)\nTeen (13)\nThriller (14)\nClassic (15)\n\n";

        cout << "Enter your input: ";
        cin >> genrenum;
        //Prompts user to enter an input number to search via genre type
        if (genrenum >= 1 && genrenum <= 15) {
            vector<string> genres = {
                "Action", "Anime", "Comedy", "Children & Family", "Crime", "Drama", "Fantasy", "Horror",
                "Musical", "Romance", "Sci-Fi", "Sports", "Teen", "Thriller", "Classic"
            };
            cout << "Searching for " << genres[genrenum - 1] << "\n\n";
            movieDB.searchByGenre(genres[genrenum - 1]);
        } else {
            cout << "Invalid genre selection.\n";
        }

    }
    else if (InputValue == 4) {
        // Movie index via Region - Asia (1) Europe (2) USA (3) Indonesia (4) Korea (5) China (6) Thailand (7) Japan (8)
        //Prompts user to enter an input to search via region
        cout << "Movie index via Region - \nAsia (1) \nEurope (2) \nUSA (3)\nIndonesia (4) \nKorea (5) \nChina (6) \nThailand (7)\nJapan (8)\n\n";
        cout << "Enter your input for the search: ";
        cin >> regionnum;

        if (regionnum >= 1 && regionnum <= 8) {
            vector<string> regions = {
                "Asia", "Europe", "USA", "Indonesia", "Korea", "China", "Thailand", "Japan"
            };
            cout << "Searching for " << regions[regionnum - 1] << "\n\n";
            movieDB.searchByRegion(regions[regionnum - 1]);
        } else {
            cout << "Invalid region selection.\n";
        }

    }
    else if(InputValue == 5){
        movieDB.displaySearchHistory();
    }
        else {
        cout << "Invalid search term. Please enter 'title', 'rating', 'genre', or 'region'.\n";
    }
//Prompt for users to search again frm the beginning
    string RepeatInput;
    cout << "Would you like to go back to the main menu? (yes/no): ";
    cin >> RepeatInput;
    cout << endl;

    if (RepeatInput == "yes") {
        goto repeater;
    } else {
        cout << "Thank you for using this program!\n";

        return 0;
    }
}
