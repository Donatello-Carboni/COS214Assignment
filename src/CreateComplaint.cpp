#include "CreateComplaint.h"
#include <iostream>

Report* CreateComplaint::buildReport(int Happy)
{
    std::string read;
    if(Inspection==false){
        std::cout << yellow << bold << "|  + Report Creation happening"<<std::endl << reset;
        std::cin>>read;
    }
     std::string head;
     std::string body;
    if(Happy>50){
        if(this->Inspection==false){
            std::cout << yellow << bold << "|  + " << white << "Happy Customer could have otherwise been an unhappy customer" << std::endl << reset;
            std::cin>>read;
        }
        head="Happy Customer";
        body="Customer was happy with their order";
        return new Review(head,body,Happy);
    }
    else{
        if(this->Inspection==false){
            std::cout << yellow << bold << "|  + " << white << "Unhappy Customer could have otherwise been an happy customer" << std::endl << reset;
            std::cin>>read;
        }
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
{   std::string read;
    if(Inspection==false){
        std::cout << yellow << bold << "|  + " << magenta << "Report command" << std::endl << reset;
        std::cin>>read;
    }
    Manager::getManager().addReport(this->buildReport(happy));
    if(Inspection==false){
        std::cout << yellow << bold << "|  + " << magenta << "Report added" << std::endl << reset;
        Manager::getManager().toString();
        std::cin>>read;
        Inspection=true;
    }
    
}


CreateComplaint::CreateComplaint()
{
    
}
