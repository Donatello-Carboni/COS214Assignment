#include "CreateComplaint.h"
#include <iostream>

Report* CreateComplaint::buildReport(int Happy)
{
     std::string head;
     std::string body;
    if(Happy>50){
        head="Happy Customer";
        body="Customer was happy with their order";
        return new Review(head,body,Happy);
    }
    else{
        head="Unhappy Customer";
        body="Customer has a complaint";
        
        // Define a list of possible complaint messages
    std::vector<std::string> complaintMessages = {
        "Food was cold and tasteless.",
        "Service was slow and unfriendly.",
        "Order was incorrect and missing items.",
        "Restaurant was dirty and unorganized.",
        "The quality of the food was terrible.",
    };

    // Generate a random index to select a complaint message
    int randomIndex = std::rand() % complaintMessages.size();

    // Return the randomly selected complaint message
    std::string complaint=complaintMessages[randomIndex];  
    return new Complaint(head,body,complaint);
        
    }
}
void CreateComplaint::setHappy(int Happy){
    this->happy=Happy;
}
void CreateComplaint::execute()
{
    Manager::getManager().addReport(this->buildReport(happy));
    std::cout<<"Report added"<<std::endl;
}


CreateComplaint::CreateComplaint()
{
    
}
