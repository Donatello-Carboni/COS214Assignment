#ifndef MANAGER_H
#define MANAGER_H

#include <vector>
#include "Report.h"

/**
 * @brief Class representing a Manager responsible for handling reports.
 */
class Manager {
private:
    std::vector<Report*> reports; /**< A collection of reports. */

    Manager() {} // Private constructor
    ~Manager(); // Destructor

    // Disallow copy constructor and assignment operator
    Manager(const Manager& other) = delete;
    Manager& operator=(const Manager& other) = delete;

public:
    /**
     * @brief Method to add a report to the manager's collection.
     * @param report - Pointer to the Report object to add.
     */
    void addReport(Report* report);

    /**
     * @brief Method to display information about the reports.
     */
    void toString() const;

    /**
     * @brief Method to access the Manager instance (Singleton pattern).
     * @return Reference to the Manager object.
     */
    static Manager& getManager();
};

#endif
