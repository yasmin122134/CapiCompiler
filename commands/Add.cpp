#include "Add.h"
#include <stdexcept>

// Helper function to check if string is a valid positive integer
static bool isValidInteger(const string& str) {
    if(str.empty()) return false;
    // Check if first char is digit
    if(!isdigit(str[0])) return false;
    // Check rest of chars are digits
    return str.find_first_not_of("0123456789") == string::npos;
}

// Helper function to read movie IDs from input stream
static void getMovieIDs(istream& cin, vector<int>& movieIDs) {
    string input;
    char c;
    // Skip leading spaces
    while (cin.get(c) && c == ' ');
    cin.putback(c);
    
    // Read all movie IDs until end of input
    while (cin >> input) {
        if (!isValidInteger(input)) {
            throw invalid_argument("Invalid movie ID format: " + input);
        }
        movieIDs.push_back(stoi(input));
    }
}

// Constructor initializes the user database reference
Add::Add(IUserDAL* userDb) : userDb(userDb) {}

// Add multiple movies to a user's list
void Add::addMovies(int userID, vector<int> movieIDs) {
    // For each movie ID, fetch the movie and add it to the user's list
    for (int movieID : movieIDs) {
        User user = userDb->getUser(userID);
        Movie movie = movieDb->getMovie(movieID);
        userDb->addMovie(user, movie);
    }
}

// Main execution function for the Add command
void Add::execute() {
    string userIDStr;
    // Read the user ID from input
    cin >> userIDStr;
    
    // Validate user ID format
    if (!isValidInteger(userIDStr)) {
        throw invalid_argument("Invalid user ID format: " + userIDStr);
    }
    
    int userID = stoi(userIDStr);
    vector<int> movieIDs;
    
    try {
        // Get all movie IDs from the remaining input
        getMovieIDs(cin, movieIDs);
        // Process the add operation
        addMovies(userID, movieIDs);
    } catch (const invalid_argument& e) {
        throw; // Re-throw the validation error
    }
}
