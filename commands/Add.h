#ifndef ADD_H
#define ADD_H

#include "Icommand.h"
#include <vector>
#include "IUserDAL.h"

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
    bool isValidCommand(const std::string& command);

public:
    /**
     * @brief Constructs an Add command
     * @param userDb Pointer to the user database interface
     */
    Add(IUserDAL* userDb);

    /**
     * @brief Executes the add user command
     * 
     * Prompts for user information and adds the new user to the database
     * @param inputLine The input line containing user information
     */
    void execute(std::string inputLine) override;
};

#endif
