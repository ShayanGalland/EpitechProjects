#include "include/My.hpp"

static void display_help()
{
    std::cout << "Please use it like this :" << std::endl;
    std::cout << "  ./MyGKrellm [OPTIONS]" << std::endl;
    std::cout << "  -h : display help" << std::endl;
    std::cout << "  -g : display graphique" << std::endl;
    std::cout << "  -c : display in terminal" << std::endl;
}

int main(int ac, char **av, char **env)
{
    if (ac > 3 || ac == 1) {
        display_help();
        return 84;
    }
    if (av[1][0] == '-' && av[1][1] == 'h') {
        display_help();
        return 0;
    }
    if (env == NULL) {
        std::cout << "the env is NULL" << std::endl;
        return 84;
    }
    if (av[1][0] == '-' && av[1][1] == 'g')
        graphical();
    else if (av[1][0] == '-' && av[1][1] == 'c')
        ncurse(env);
    else {
        std::cout << "Please enter valid argument, try ./MyGKrellm -h" << std::endl;
        return 84;
    }
    return 0;
}