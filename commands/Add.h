#ifndef ADD_H
#define ADD_H

#include "ICommand.h"
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
class Add : public ICommand {
private:
    /** Pointer to the user data access layer interface */
    std::unique_ptr<IUserDAL> userDb;
    std::unique_ptr<IMovieDAL> movieDb;
    bool isValidCommand(const std::string& command);
    void addMovies(int userID, vector<int> movieIDs);

public:
    /**
     * @brief Constructs an Add command
     * @param userDb Pointer to the user database interface
     */
    Add(std::unique_ptr<IUserDAL> userDb, std::unique_ptr<IMovieDAL> movieDb);
    std::string getCommandName() const override;

    /**
     * @brief Executes the add user command
     * 
     * Prompts for user information and adds the new user to the database
     * @param inputLine The input line containing user information
     */
    void execute(std::string inputLine) override;

    void print(std::ostream& os) const override;
};

#endif
