#ifndef ADD_H
#define ADD_H

#include "Icommand.h"
#include <vector>
#include "../IUserDAL.h"
#include "../IMovieDAL.h"

using namespace std;

/**
 * @brief Command class for adding a new user to the system
 * 
 * Implements the Icommand interface to provide user addition functionality.
 * Uses IUserDAL for database operations.
 */
class Add : public Icommand {
private:
    /** Pointer to the user data access layer interface */
    IUserDAL* userDb;
    IMovieDAL* movieDb;
    bool isValidCommand(const std::string& command);
    void updateUser(User user, Movie movie);
    void addMovies(int userID, vector<int> movieIDs);

public:
    /**
     * @brief Constructs an Add command
     * @param userDb Pointer to the user database interface
     */
    Add(IUserDAL* userDb, IMovieDAL* movieDb);

    /**
     * @brief Executes the add user command
     * 
     * Prompts for user information and adds the new user to the database
     * @param inputLine The input line containing user information
     */
    void execute(std::string inputLine) override;

    void print(std::ostream& os) const override;

    std::string getCommandName() const override;
};

#endif
