#include <iostream>
#include <cstring>
using namespace std;

string getuserinput()
{
    string input;
    cout<<" You: ";
    getline(cin, input);
    return(input);
}

string getresponse(string userinput)
{
    if(userinput == "hi" || userinput == "hello")
    {
        return "Hello! How can I help you!";
    }
    else if(userinput == "How are you")
    {
        return "I am fine, but I am just a chatbot I dont  have feelings";
    }
    else
    {
        return "please enter valid input";
    }
}

int main()
{
    string userinput;
    cout<<"Welcome to elementary chatbot!"<<endl;
    cout<<"You can start chatting. Type 'Bye' to exit."<<endl;

    while(true)
    {
        userinput = getuserinput();
        if(userinput == "Bye")
        {
            cout<<"Good bye! Have a nice Day";
            break;
        }
        string response = getresponse(userinput);
        cout<<"Chatbox:"<<response<<endl;
    }
}