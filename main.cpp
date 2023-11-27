#include "movie.h"
#include "tree.h"
#include "database.h"

//libaries
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <sstream>
#include <fstream>

using namespace std;

int main() {

    MovieDatabase movieDB;

    //If the provided credentials match ("User123" and "TrialPass"), it grants access to the system; otherwise, it prompts for re-entry.
    LoginPage:
        string UserID;
        string Userpass;
        cout << "\n";
        cout << "Enter User ID: ";
        cin >> UserID;
        cout << "\nEnter Password: ";
        cin >> Userpass;
        cout << endl;
        
        if (UserID == "User123") {
            if (Userpass == "TrialPass"){
              cout << "Logged in!\n";
              goto repeater;
            }
            else {
                cout << "--------------------------------\n";
                cout << "|  Wrong password. Try again.  |\n";
                cout << "--------------------------------" << endl;
                goto LoginPage;
            }

        } else {
            cout << "--------------------------------\n";
            cout << "|  Unregistered ID, Try again. |\n";
            cout << "--------------------------------" << endl;
            goto LoginPage;
        }

repeater:
    int genrenum;
    int regionnum;

    cout << "********************************************************************" << endl;
    cout << "*                                                                  *" << endl;
    cout << "*                        W E L C O M E   T O                       *" << endl;
    cout << "*                                                                  *" << endl;
    cout << "*               _    _  ____  ____  __    ____  _  _               *\n";
    cout << "*              ( \\/\\/ )( ___)( ___)(  )  (_  _)( \\/ )              *\n";
    cout << "*               )    (  )__)  )__)  )(__  _)(_  )  (               *\n";
    cout << "*              (__/\\__)(____)(__)  (____)(____)(_/\\_)              *\n";
    cout << "*                                                                  *" << endl;
    cout << "*                                                                  *" << endl;
    cout << "*             Your Ultimate Entertainment Destination!             *" << endl;
    cout << "*                                                                  *" << endl;
    cout << "*           Enjoy a world of movies, TV shows, and more!           *" << endl;
    cout << "*                Sit back, relax, and let the WEFLIX               *" << endl;
    cout << "*                         experience begin.                        *" << endl;
    cout << "*                                                                  *" << endl;
    cout << "********************************************************************" << endl;
    cout << "" << endl;
    
    cout << endl;
    cout << "============================================================\n";
    cout << "=================== WEFLIX SEARCH ENGINE ===================\n";
    cout << "|                     1. Title                             |\n";
    cout << "|                     2. Rating                            |\n";
    cout << "|                     3. Genre                             |\n";
    cout << "|                     4. Region                            |\n";
    cout << "|                     5. Search History                    |\n";
    cout << "============================================================\n";
    cout << endl;
    cout << "Enter search term by entering a corresponding number: ";
    string searchTerm;
    int InputValue;
    cin >> InputValue;

    // Searching for movies based on user input
    if (InputValue == 1) {
        cout << endl;
        cout << "Enter title: ";
        cin >> searchTerm;
        cout << endl;
        movieDB.searchByTitle(searchTerm);
    }
    else if (InputValue == 2) {
        //Prompts user to search via rating
        int minRating;
        cout << endl;
        cout << "Enter minimum rating: ";
        cin >> minRating;
        cout << endl;
        movieDB.searchByRating(minRating);
    }
    else if (InputValue == 3) {
        // Action, anime, comedy, Children & Family, crime, drama, fantasy, horror, musical, romance, sci-fi, sports, teen, thriller, classic
        cout << endl;
        cout << "============================================================\n";
        cout << "======================= Movie by Genre =====================\n";
        cout << "|                     1. Action                            |\n";
        cout << "|                     2. Anime                             |\n";
        cout << "|                     3. Comedy                            |\n";
        cout << "|                     4. Children & Family                 |\n";
        cout << "|                     5. Crime                             |\n";
        cout << "|                     6. Drama                             |\n";
        cout << "|                     7. Fantasy                           |\n";
        cout << "|                     8. Horror                            |\n";
        cout << "|                     9. Musical                           |\n";
        cout << "|                     10. Romance                          |\n";
        cout << "|                     11. Sci-Fi                           |\n";
        cout << "|                     12. Sports                           |\n";
        cout << "|                     13. Teen                             |\n";
        cout << "|                     14. Thriller                         |\n";
        cout << "|                     15. Classics                         |\n";
        cout << "============================================================\n";
        cout << endl;
        cout << "Enter genre via a corresponding number: ";
        cin >> genrenum;
        cout << endl;
        
        //Prompts user to enter an input number to search via genre type
        if (genrenum >= 1 && genrenum <= 15) {
            vector<string> genres = {
                "Action", "Anime", "Comedy", "Children & Family", "Crime", "Drama", "Fantasy", "Horror",
                "Musical", "Romance", "Sci-Fi", "Sports", "Teen", "Thriller", "Classic"
            };\

            cout << "Searching for " << genres[genrenum - 1] << "\n" << endl;
            movieDB.searchByGenre(genres[genrenum - 1]);
        }
        else {
            cout << "Invalid genre selection.\n";
        }

    }
    else if (InputValue == 4) {
        // Movie index via Region - Asia (1) Europe (2) America (3) Indonesia (4) Korea (5) China (6) Thailand (7) Japan (8)
        //Prompts user to enter an input to search via region
        cout << endl;
        cout << "============================================================\n";
        cout << "====================== Movie by Region =====================\n";
        cout << "|                     1. Asia                              |\n";
        cout << "|                     2. Europe                            |\n";
        cout << "|                     3. America                           |\n";
        cout << "|                     4. Indonesia                         |\n";
        cout << "|                     5. Korea                             |\n";
        cout << "|                     6. China                             |\n";
        cout << "|                     7. Thailand                          |\n";
        cout << "|                     8. Japan                             |\n";
        cout << "============================================================\n";
        cout << endl;
        cout << "Enter movie by region via a corresponding number: ";
        cin >> regionnum;
        cout << endl;


        if (regionnum >= 1 && regionnum <= 8) {
            vector<string> regions = {
                "Asia", "Europe", "America", "Indonesia", "Korea", "China", "Thailand", "Japan"
            };

            cout << "Searching for " << regions[regionnum - 1] << "\n" << endl;
            movieDB.searchByRegion(regions[regionnum - 1]);
        }
        else {
            cout << "Invalid region selection.\n";
        }

    }
    else if(InputValue == 5){
        movieDB.displaySearchHistory();
    }
    else {
        cout << "Invalid search term. Please enter 'title', 'rating', 'genre', or 'region'.\n";
    }

    //Prompt for users to search again from the beginning or exit
    string RepeatInput;
    cout << endl;
    cout << "Would you like to go back to the main menu? (Y/N): ";
    cin >> RepeatInput;
    cout << endl;

    if (RepeatInput == "Y") {
        goto repeater;
    }
    else {
        cout << endl;
        cout << "Thank you for using this program!\n";

        return 0;
    }
}
