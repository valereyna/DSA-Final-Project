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
        Movie("Jurassic World", "Action", 6.9, "America"),
        Movie("Train to Busan", "Action", 7.6, "Korea"),
        Movie("Uncharted", "Action", 6.3, "America"),
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
        Movie("Mr. & Mrs. Smith", "Action/Comedy", 6.5, "Region"),
        Movie("John Wick", "Action/Thriller", 7.4, "Region"),
        Movie("Bullet Train", "Action/Thriller", 7.3, "Region"),
        Movie("47 Ronin", "Action/Fantasy", 6.2, "Region"),
        Movie("Snow White and the Huntsman", "Action/Fantasy", 6.1, "Region"),
        Movie("The School for Good and Evil", "Fantasy", 5.9, "Region"),
        Movie("Assassin’s Creed", "Action/Adventure", 5.6, "Region"),
        Movie("Snake Eyes", "Action/Adventure", 5.4, "Region"),
        Movie("Transformers: The Last Knight", "Action/Sci-Fi", 5.2, "Region"),
        Movie("Teenage Mutant Ninja Turtles: Out of the Shadows", "Action/Adventure", 5.9, "Region"),
        Movie("Power Rangers", "Action/Adventure", 5.9, "Region"),
        Movie("Stand by Me Doraemon", "Animation", 7.3, "Japan"),
        Movie("Stand by Me Doraemon 2", "Animation", 7.5, "Japan"),
        Movie("A Silent Voice", "Anime", 8.1, "Japan"),
        Movie("A Whisker Away", "Anime", 6.7, "Japan"),
        Movie("Howl's Moving Castle", "Animation", 8.2, "Japan"),
        Movie("Spirited Away", "Animation", 8.6, "Japan"),
        Movie("Ponyo", "Animation", 7.6, "Japan"),
        Movie("When Marnie Was There", "Animation", 7.6, "Japan"),
        Movie("Oshi No Ko", "Anime", 8.5, "Japan"),
        Movie("Sailor Moon Eternal", "Anime", 7.0, "Japan"),
        Movie("200 Pounds Beauty", "Drama", 6.7, "South Korea"),
        Movie("SpongeBob SquarePants", "Animation", 8.2, "United States"),
        Movie("The SpongeBob Movie: Sponge on the Run", "Animation", 5.9, "United States"),
        Movie("Kung Fu Panda 3", "Animation", 7.1, "United States"),
        Movie("Kung Fu Panda: The Dragon Knight", "Animation", 6.0, "United States"),
        Movie("Madagascar", "Animation", 6.9, "United States"),
        Movie("Shrek", "Animation", 7.9, "United States"),
        Movie("Shrek 2", "Animation", 7.3, "United States"),
        Movie("Shrek the Third", "Animation", 6.1, "United States"),
        Movie("Hotel Transylvania", "Animation", 7.0, "United States"),
        Movie("Hotel Transylvania 2", "Animation", 6.6, "United States"),
        Movie("Hotel Transylvania 3: Summer Vacation", "Animation", 6.3, "United States"),
        Movie("The Secret Life of Pets", "Animation", 6.5, "United States"),
        Movie("The Smurfs", "Animation", 6.5, "United States"),
        Movie("Smurfs: The Lost Village", "Animation", 6.0, "United States"),
        Movie("Sherina’s Adventure", "Family", 7.8, "Indonesia"),
        Movie("Hachi: A Dog's Tale", "Drama", 8.1, "United States"),
        Movie("Barbie: Princess Charm School", "Animation", 6.6, "United States"),
        Movie("Barbie: Life in the Dreamhouse", "Animation", 7.5, "United States"),
        Movie("Barbie: A Touch of Magic", "Animation", 7.0, "United States"),
        Movie("Barbie in a Mermaid Tale", "Animation", 6.3, "United States"),
        Movie("Barbie Spy Squad", "Animation", 5.5, "United States"),
        Movie("Barbie Princess Adventure", "Animation", 5.5, "United States"),
        Movie("The Adventures of Sharkboy and Lavagirl 3-D", "Family", 3.7, "United States"),
        Movie("Spy Kids", "Family", 5.6, "United States"),
        Movie("Miraculous: Ladybug & Cat Noir, the Movie", "Animation", 6.1, "France"),
        Movie("The Swan Princess", "Animation", 6.4, "United States"),
        Movie("How to Train Your Dragon 2", "Animation", 7.8, "United States"),
        Movie("The Lorax", "Animation", 6.4, "United States"),
        Movie("The Boss Baby: Back in Business", "Animation", 6.5, "United States"),
        Movie("Ice Cold: Murder, Coffee and Jessica Wongso", "Crime", 6.0, "Indonesia"),
        Movie("Money Heist", "Crime", 8.2, "Spain"),
        Movie("Stealing Raden Saleh", "Drama", 7.3, "Indonesia"),
        Movie("Dahmer - Monster: The Jeffrey Dahmer Story", "Crime", 7.9, "United States"),
        Movie("Knives Out", "Mystery", 7.9, "United States"),
        Movie("Glass Onion", "Mystery", 7.1, "United States"),
        Movie("Ocean's Eleven", "Crime", 7.7, "United States"),
        Movie("Inside Man", "Crime", 7.6, "United States"),
        Movie("The Bank Job", "Crime", 7.2, "United Kingdom"),
        Movie("Public Enemies", "Crime", 7.0, "United States"),
        Movie("The Dark Knight", "Action", 9.0, "United States"),
        Movie("Batman Begins", "Action", 8.2, "United States"),
        Movie("Sherlock Holmes", "Mystery", 7.6, "United States"),
        Movie("American Gangster", "Crime", 7.8, "United States"),
        Movie("Man on Fire", "Action", 7.7, "United States"),
        Movie("Divergent", "Sci-Fi", 6.6, "America"),
        Movie("Spider-Man: Into the Spider-Verse", "Sci-Fi", 8.4, "America"),
        Movie("Spider-Man: Across the Spider-Verse", "Sci-Fi", 8.7, "America"),
        Movie("The Amazing Spider-Man ", "Sci-Fi", 6.9, "America"),
        Movie("The Amazing Spider-Man ", "Sci-Fi", 6.6, "America"),
        Movie("Stranger Things", "Sci-Fi", 8.7, "America"),
        Movie("World War Z ", "Sci-Fi", 7.0, "America"),
        Movie("Alice in Borderland ", "Sci-Fi", 7.7, "Japan"),
        Movie("The Umbrella Academy ", "Sci-Fi", 7.9, "America"),
        Movie("Jumper ", "Sci-Fi", 6.1, "America"),
        Movie("Home ", "Sci-Fi", 6.5, "America"),
        Movie("The In Between ", "Sci-Fi", 5.9, "America"),
        Movie("Next Gen ", "Sci-Fi", 6.6, "America"),
        Movie("Astro Boy ", "Sci-Fi", 6.2, "Japan"),
        Movie("The Mitchells vs the Machines  ", "Sci-Fi", 7.6, "America"),
        Movie("Blue Lock ", "Sports", 8.3, "Japan"),
        Movie("Haikyu!!", "Sports", 8.7, "Japan"),
        Movie("Beckham ", "Sports", 8.2, "Europe"),
        Movie("Home Team ", "Sports", 6.0, "America"),
        Movie("Coach Carter ", "Sports", 7.3, "America"),
        Movie("Turbo ", "Sports", 6.4, "America"),
        Movie("No Limit ", "Sports", 5.8, "America"),
        Movie("Concussion ", "Sports", 7.1, "America"),
        Movie("We Are Moluccans ", "Sports", 7.9, "Indonesia"),
        Movie("Zero to Hero ", "Sports", 6.7, "China"),
        Movie("Caught by a Wave ", "Sports", 5.8, "Europe"),
        Movie("Gridirion Gang ", "Sports", 7.0, "America"),
        Movie("Dream ", "Sports", 6.5, "Korea"),
        Movie("Everest ", "Sports", 7.1, "America"),
        Movie("Brothers ", "Sports", 6.4, "Asia"),
        Movie("Mean Girls ", "Teen", 7.1, "America"),
        Movie("Five Feet Apart ", "Teen", 7.2, "America"),
        Movie("Gossip Girl ", "Teen", 7.5, "America"),
        Movie("To All the Boys I’ve Loved Before ", "Teen", 7.0, "America"),
        Movie("Shadow and Bone ", "Teen", 7.6, "America"),
        Movie("Riverdale ", "Teen", 6.5, "America"),
        Movie("Wednesday ", "Teen", 8.1, "America"),
        Movie("13 Reasons Why ", "Teen", 7.5, "America"),
        Movie("Dora and the Lost City of Gold ", "Teen", 6.1, "America"),
        Movie("Tall Girl ", "Teen", 6.2, "America"),
        Movie("Ocean Waves", "Teen", 6.6, "Japan"),
        Movie("Rim of the World", "Teen", 5.2, "America"),
        Movie("Do Revenge ", "Teen", 6.3, "America"),
        Movie("Squid Game", "Thriller", 8.0, "Korea"),
        Movie("Unlocked", "Thriller", 6.4, "Korea"),
        Movie("Death Note", "Thriller", 8.9, "Japan"),
        Movie("Ballerina", "Thriller", 6.2, "Korea"),
        Movie("Locked In", "Thriller", 5.1, "America"),
        Movie("Carter", "Thriller", 5.1, "Korea"),
        Movie("Extraction II", "Thriller", 7.0, "America"),
        Movie("65", "Thriller", 5.4, "America"),
        Movie("Athena", "Thriller", 6.8, "Europe"),
        Movie("The Good Nurse", "Thriller", 6.8, "America"),
        Movie("Kill Boksoon", "Thriller", 6.6, "Korea"),
        Movie("Army of Thieves", "Thriller", 6.4, "America"),
        Movie("Forrest Gump", "Classics", 8.8, "America"),
        Movie("Top Gun", "Classics", 6.9, "America"),
        Movie("Jaws", "Classics", 8.1, "America"),
        Movie("Kiki's Delivery Service", "Classics", 7.8, "Japan"),
        Movie("Only Yesterday", "Classics", 7.6, "Japan"),
        Movie("My Neighbor Totoro", "Classics", 8.1, "Japan"),
        Movie("Princess Mononoke", "Classics", 8.3, "Japan"),
        Movie("Nausicaä of the Valley of the Wind", "Classics", 8.0, "Japan"),
        Movie("Tiga Dara", "Classics", 7.9, "Indonesia"),
        Movie("Catatan Si Boy", "Classics", 6.6, "Indonesia"),
        Movie("Catatan Si Boy 2", "Classics", 6.5, "Indonesia"),
        Movie("Tjoet Nja Dhien", "Classics", 8.0, "Indonesia"),
        Movie("An Autumn’s Tale", "Classics", 7.6, "China"),
        Movie("The Killer", "Classics", 7.8, "China"),
        Movie("Check Store Next Door", "Drama", 7.8, "Indonesia"),
        Movie("Ada Apa Dengan Cinta", "Romance", 7.7, "Indonesia"),
        Movie("Milly & Mamet", "Romance", 7.3, "Indonesia"),
        Movie("All of Us Are Dead", "Teen", 7.5, "Korea"),
        Movie("#Alive", "Horror", 6.3, "Korea"),
        Movie("Sweet Home", "Horror", 7.3, "Korea"),
        Movie("Business Proposal", "Romance", 8.1, "Korea"),
        Movie("The Call", "Thriller", 7.1, "Korea"),
        Movie("Tokyo Ghoul", "Action", 7.7, "Japan"),
        Movie("Gudetama", "Anime", 7.3, "Japan"),
        Movie("Jujutsu Kaisen", "Anime", 8.6, "Japan"),
        Movie("Double World", "Action", 6.1, "China"),
        Movie("A Chinesse Odyssey: Part One - Pandora’s Box", "Action", 7.5, "China"),
        Movie("Marry My Dead Body", "Drama", 7.1, "China"),
        Movie("The Karate Kid", "Drama", 6.2, "China"),
        Movie("Bad Genius", "Drama", 7.6, "Thailand"),
        Movie("Hunger", "Drama", 6.6, "Thailand"),
        Movie("Bridgerton", "Romance", 7.4, "Europe"),
        Movie("Queen Charlotte: A Bridgerton Story", "Romance", 7.4, "Europe"),
        Movie("Peaky Blinders", "Drama", 8.8, "Europe"),
        Movie("22 July", "Crime", 6.8, "Europe"),
        Movie("The Takedown", "Comedy", 5.8, "Europe"),
        Movie("The Gray Man", "Thriller", 6.5, "America"),
        Movie("Nowhere", "Thriller", 6.3, "Europe"),
        Movie("Against The Ice", "Drama", 6.5, "Europe"),
        Movie("Call Me by Your Name", "Drama", 7.8, "Europe"),
        Movie("How To Be Really Bad", "Comedy", 6.3, "Europe"),
        Movie("Birdbox", "Horror", 6.6, "America"),
        Movie("Asphalt Burning", "Action", 5.2, "Europe"),
        Movie("The Two Popes", "Drama", 7.6, "America"),
        Movie("Mudbound", "Drama", 7.4, "America"),
        Movie("Isi & Ossi", "Romance", 6.4, "Europe"),
        Movie("Je Suis Karl", "Drama", 5.5, "Europe"),
        Movie("Layer Cake", "Crime", 7.3, "Europe"),
        Movie("Rising High", "Comedy", 6.0, "Europe"),
        Movie("Paris is Us", "Drama", 4.6, "Europe"),
        Movie("I Lost My Body", "Romance", 7.5, "Europe"),
        Movie("The Four of Us", "Comedy", 5.3, "Europe"),
        Movie("Julie & Julia", "Drama", 7.0, "America"),
        Movie("11M: Terror in Madrid", "Drama", 6.8, "Europe"),
        Movie("Rumspringa", "Comedy", 5.4, "Europe"),
        Movie("My Brother, My Sister", "Drama", 6.0, "Europe"),
        Movie("The Binding", "Horror", 4.8, "Europe"),
        Movie("The Queen’s Gambit", "Drama", 8.5, "America"),
        Movie("Pitch Perfect", "Musical", 7.1, "America"),
        Movie("Bohemian Rapsody", "Musical", 7.9, "America"),
        Movie("Sing", "Musical", 7.1, "America"),
        Movie("Trolls", "Musical", 6.4, "America"),
        Movie("Trolls Holiday", "Musical", 6.1, "America"),
        Movie("Trolls: The Beat Goes On!", "Musical", 6.0, "America"),
        Movie("Roald Dahl’s Matilda The Musical", "Musical", 7.0, "America"),
        Movie("13: The Musical", "Musical", 5.3, "America"),
        Movie("Taylor Swift: Reputation Stadium Tour", "Musical", 8.4, "America"),
        Movie("Miss Americana", "Musical", 7.4, "America"),
        Movie("Ouija: Origin of Evil", "Horror", 6.2, "America"),
        Movie("The Pope’s Exorcist", "Horror", 6.1, "America"),
        Movie("The Devil On Trial", "Horror", 5.6, "America"),
        Movie("The Exorcism of Emily Rose", "Horror", 6.7, "America"),
        Movie("Incantation", "Horror", 6.2, "China"),
        Movie("A Quiet Place Part II", "Horror", 7.2, "America"),
        Movie("The Silence", "Horror", 5.3, "America"),


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
    cout << "=================== WEFLIX SEARCH ENGINE ===================\n";
    cout << "|                     1. Title                             |\n";
    cout << "|                     2. Rating                            |\n";
    cout << "|                     3. Genre                             |\n";
    cout << "|                     4. Region                            |\n";
    cout << "|                     5. Search History                    |\n";
    cout << "============================================================\n\n";
    cout << "Enter search term by entering a corresponding number: ";
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
        cout << "============================================================\n\n";
        cout << "Enter genre via a corresponding number: ";
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
        cout << "============================================================\n\n";
        cout << "Enter movie by region via a corresponding number: ";
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
