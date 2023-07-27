#include "../include/Circuit.hpp"

#include <iostream>
#include <algorithm>

#include "../include/Component/true.hpp"
#include "../include/Component/false.hpp"
#include "../include/Component/input.hpp"
#include "../include/Component/output.hpp"
#include "../include/Component/clock.hpp"

#include "../include/Component/and.hpp"
#include "../include/Component/or.hpp"
#include "../include/Component/xor.hpp"
#include "../include/Component/not.hpp"

#include "../include/Component/4001.hpp"
#include "../include/Component/4081.hpp"
#include "../include/Component/4011.hpp"
#include "../include/Component/4030.hpp"
#include "../include/Component/4069.hpp"
#include "../include/Component/4071.hpp"



namespace nts
{
    std::unique_ptr<IComponent> Circuit::createComponent(const std::string &type)
    {
        if (type == "input")
            return std::unique_ptr<nts::IComponent>(new CInput());
        else if (type == "output")
            return std::unique_ptr<nts::IComponent>(new COutput());
        else if(type == "true")
            return std::unique_ptr<nts::IComponent>(new CTrue());
        else if(type == "false")
            return std::unique_ptr<nts::IComponent>(new CFalse());
        else if(type == "clock")
            return std::unique_ptr<nts::IComponent>(new CClock());
        else if(type == "and")
            return std::unique_ptr<nts::IComponent>(new CAnd());
        else if(type == "or")
            return std::unique_ptr<nts::IComponent>(new COr());
        else if(type == "xor")
            return std::unique_ptr<nts::IComponent>(new CXor());
        else if(type == "not")
            return std::unique_ptr<nts::IComponent>(new CNot());
        else if(type == "4001")
            return std::unique_ptr<nts::IComponent>(new C4001());
        else if(type == "4081")
            return std::unique_ptr<nts::IComponent>(new C4081());
        else if(type == "4011")
            return std::unique_ptr<nts::IComponent>(new C4011());
        else if(type == "4030")
            return std::unique_ptr<nts::IComponent>(new C4030());
        else if(type == "4069")
            return std::unique_ptr<nts::IComponent>(new C4069());
        else if(type == "4071")
            return std::unique_ptr<nts::IComponent>(new C4071());
        else
            exit(84);
/*
        if(type == "4008")
            return std::unique_ptr<nts::IComponent>();
        if(type == "4013")
            return std::unique_ptr<nts::IComponent>();
        if(type == "4017")
            return std::unique_ptr<nts::IComponent>();
        if(type == "4040")
            return std::unique_ptr<nts::IComponent>();
        if(type == "4094")
            return std::unique_ptr<nts::IComponent>();
        if(type == "4512")
            return std::unique_ptr<nts::IComponent>();
        if(type == "4514")
            return std::unique_ptr<nts::IComponent>();
        if(type == "4801")
            return std::unique_ptr<nts::IComponent>();
        if(type == "2716")
            return std::unique_ptr<nts::IComponent>();

        */
        return std::unique_ptr<nts::IComponent>(nullptr);
    }

    void Circuit::Display()
    {
        std::cout << "tick: " << _tick << std::endl;
        std::cout << "input(s):" << std::endl;


        std::vector<std::string> keys_c;
        keys_c.reserve(_components.size());
        for (auto& pair : _components) {
            keys_c.push_back(pair.first);
        }
        std::sort(keys_c.begin(), keys_c.end());
        for (auto it = keys_c.begin(); it != keys_c.end(); ++it) {
            auto clock = dynamic_cast<CClock*>(_components[*it].get());
            if (clock != nullptr) {
                std::cout << "  " << *it << ": ";
                clock->Print();
                std::cout << std::endl;
            }
        }





        std::vector<std::string> keys;
        keys.reserve(_components.size());
        for (auto& pair : _components) {
            keys.push_back(pair.first);
        }
        std::sort(keys.begin(), keys.end());
        for (auto it = keys.begin(); it != keys.end(); ++it) {
            auto input = dynamic_cast<CInput*>(_components[*it].get());
            if (input != nullptr) {
                std::cout << "  " << *it << ": ";
                input->Print();
                std::cout << std::endl;
            }
        }


        std::vector<std::string> keys2;
        keys2.reserve(_components.size());

        for (auto& pair : _components) {
            keys2.push_back(pair.first);
        }
        std::sort(keys2.begin(), keys2.end());
        std::cout << "output(s):" << std::endl;
        for (auto it = keys2.begin(); it != keys2.end(); ++it) {
            auto output = dynamic_cast<COutput*>(_components[*it].get());
            if (output != nullptr) {
                std::cout << "  " << *it << ": ";
                output->Print();
                std::cout << std::endl;
            }
        }


    }
    void Circuit::SetInput(std::string input_name, nts::Tristate value)
    {

        auto input = dynamic_cast<CInput*>(_components[input_name].get());
        input->SetValue(value);

    }


    void Circuit::init_circuit()
    {
        auto chipsetConfig = _config.GetChipsetsConfig();
        auto linkConfig = _config.GetLinksConfig();

        //error gestion
        if (chipsetConfig.empty())
            exit(84);
        if (chipsetConfig.size() - 1 != linkConfig.size())
            exit(84);
        int same = 0;
        bool gate = false;
        for (auto it = chipsetConfig.begin(); it != chipsetConfig.end(); it++)
        {
            for (auto it2 = linkConfig.begin(); it2 != linkConfig.end(); it2++)
            {
                if (it->first == it2->first.first)
                    same++;

            }
        }
        std::string diferent = linkConfig.begin()->second.first;
        for (auto it = linkConfig.begin(); it != linkConfig.end(); it++)
        {
            if (it->second.first != diferent)
                exit(84);
        }
        for (auto it = chipsetConfig.begin(); it != chipsetConfig.end(); it++)
        {
            for (auto it2 = linkConfig.begin(); it2 != linkConfig.end(); it2++)
            {
                if (it->first == it2->second.first)
                    gate = true;
            }
        }
        if (!gate)
            exit(84);
        if (same != linkConfig.size())
            exit(84);
        //start init
        for(auto it = chipsetConfig.begin(); it != chipsetConfig.end(); it++)
        {   //Premier boucle => on recupere les composents qu on a lu dans la confi et on les mets dans le circuit. Avec un dict comme ça on peut y accèder par leur name
            _components[it->first] = std::move(createComponent(it->second));
        }
        for(auto it = linkConfig.begin(); it != linkConfig.end(); it++)
        {
            //Deuxième boucle => on recuper les links et on lies les composents entre eux
            _components[it->first.first]->setLink(it->first.second, *_components[it->second.first], it->second.second);
            _components[it->second.first ]->setLink(it->second.second, *_components[it->first.first], it->first.second);
        }
    }

}


