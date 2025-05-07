#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}
int main() {
    string userInput;
    cout << "🤖 Chatbot: Hello! Welcome to ShopEasy Customer Support. How can I help you today?\n";
    while (true) {
        cout << "You: ";
        getline(cin, userInput);

        string input = toLower(userInput);

        if (input == "hi" || input == "hello") {
            cout << "🤖 Chatbot: Hello! How can I assist you?\n";
        }
        else if (input.find("return") != string::npos) {
            cout << "🤖 Chatbot: You can return a product within 7 days from the delivery date. Please visit our 'Returns' section.\n";
        }
        else if (input.find("delivery") != string::npos) {
            cout << "🤖 Chatbot: Delivery usually takes 3 to 5 business days depending on your location.\n";
        }
        else if (input.find("ok") != string::npos) {
            cout << "🤖 Chatbot: Great...!\n";
        }
        else if (input.find("contact") != string::npos || input.find("support") != string::npos) {
            cout << "🤖 Chatbot: You can contact us at support@shopeasy.com or call 1800-123-456.\n";
        }
        else if (input == "bye" || input == "exit") {
            cout << "🤖 Chatbot: Thank you for chatting with us! Have a great day! 👋\n";
            break;
        }
        else {
            cout << "🤖 Chatbot: I'm sorry, I didn't understand that. Can you please rephrase?\n";
        }
    }

    return 0;
}


#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string tolower(string str){
    for(int i=0;i<str.length();i++){
        str[i]=tolower(str[i]);
    }
    return str;
}

int main(){
    string user;
    cout<<"Shop_Easy.";
    while(true){
        cout<<"You: ";
        getline(cin,user);
        string ip=tolower(user);
        if(ip=="hi" || ip=="hello"){
            cout<<"C: Hello..";
        }
        else if(ip.find("return")!=string::npos){
            cout<<"C: U can return it..";
        }
        else if(ip=="bye"){
            cout<<"C: Bye..";
            break;
        }
        else{
            cout<<"Sorry";
        }
    }
    return 0;
}