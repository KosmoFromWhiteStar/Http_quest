#include <iostream>
#include <cpr/cpr.h>
#include <string>

bool compare(std::string inP_word, std::string command)
{
    for (int i = 0; i < inP_word.length() && i < command.length(); i++)
    {
        if (inP_word[i] != command[i])
        {
            return false;
        }
    }
    return true;
}

void ex1() {
    std::string t_url = "https://httpbin.org";
    std::string command = "";
    cpr::Response r;
    do{
        std::cout << "Input command: " << std::endl;
        std::cin >> command;

        if(compare(command, "get"))
        {
            r = cpr::Get(cpr::Url(t_url + "/get"));
        }
        if(compare(command, "post"))
        {
            r = cpr::Post(cpr::Url(t_url+"/post"),
                          cpr::Payload({{"name", "Kosmo"}, {"Yes?", "Yes"}}));

        }
        if(compare(command, "delete"))
        {
            r = cpr::Delete(cpr::Url(t_url + "/delete"));
        }
        if(compare(command, "put"))
        {
            r = cpr::Put(cpr::Url(t_url + "/put"));
        }

        std::cout << r.text << std::endl;
    } while (!compare(command, "exit"));
}

void ex2()
{
    cpr::Response r = cpr::Get(cpr::Url("https://httpbin.org/html"));

    std::cout << r.text << std::endl;

}