#pragma once
#include <iostream>
#include "cpr/cpr.h"
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
    std::string command;
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

void ex2() {
    cpr::Response r = cpr::Get(cpr::Url("https://httpbin.org/html"),
                               cpr::Payload({{"accept", "text/html"}}));

    for(unsigned long long i = r.text.find("<h1>") + 4; i < r.text.find("</h1>"); i++)
    {
        std::cout << r.text[i];
    }

}

void ex3()
{
    cpr::Response response;
    std::string command, str_arg;
    std::vector <cpr::Pair> pairs;
    do 
    {
        std::cin >> command;

        if(!compare(command, "post") && !compare(command, "get"))
        {
            std::cin >> str_arg;
        }

        if(compare(command, "post"))
        {
            //post
            cpr::Payload payload_arg (pairs.begin(), pairs.end());
            response = cpr::Post(cpr::Url("https://httpbin.org/post"),payload_arg);
            break;
        }
        else if(compare(command, "get"))
        {
            std::string part_path ="?";
            for(int i = 0; i < pairs.size(); i++)
            {
                part_path += pairs[i].key + '=' + pairs[i].value;
                if(i + 1 != pairs.size()) part_path += "&";
            }
            response = cpr::Get(cpr::Url("https://httpbin.org/get" + part_path));
            break;
        }
        else
        {
            cpr::Pair temp(command, str_arg);
            pairs.push_back(temp);
        }
    } while (true);
    std::cout << response.text << std::endl;
}

void do_ex() {
    void (*ex)();
    ex = ex3;
    ex();
}