#ifndef COMMAND_H
#define COMMAND_H
#include <string>
/**
 * @brief Abstract class defining a command.
 */
class Command {
public:
    /**
     * @brief Default constructor for the Command class.
     */
    Command() {};

    /**
     * @brief Virtual method to execute the command.
     */
    virtual void execute() = 0;
};

#endif
