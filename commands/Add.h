#ifndef ADD_H
#define ADD_H

#include "ICommand.h"
#include <vector>
#include <sstream>
#include "../DataAccessLayer.h"

using namespace std;

/**
 * @brief Command class for adding a new user to the system
 * 
 * Implements the Icommand interface to provide user addition functionality.
 * Uses IUserDAL for database operations.
 */
class Add : public ICommand {
private:
/** Pointer to the user data access layer interface */
    vector<int> getMovieIds(istringstream& iss);
    void addMovies(int userID, vector<int> movieIDs);
    DataAccessLayer *dal;

public:
    /**
     * @brief Construct a new Add object
     *
     * @param dal The data access layer object
     */
    Add(DataAccessLayer *dal);

    /**
     * @brief Executes the add user command
     * 
     * Prompts for user information and adds the new user to the database
     * @param inputLine The input line containing user information
     */
    void execute(std::string inputLine) override;

    void print(std::ostream& os) const override;
    string getCommandName() const override;
};

#endif
