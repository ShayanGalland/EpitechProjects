#include <iostream>
#include <fstream>

int cat(char *fileName)
{
    std::ifstream file;
    if(fileName == nullptr) {
        file.open("/dev/stdin");
    } else {
        file.open(fileName);
    }
    if (file.good()) {
        std::cout << file.rdbuf();
        return 0;
    } else {
        std::cerr << "MyCat: " << (fileName == nullptr ? "-" : fileName) << ": No such file or directory" <<std::endl;
        return 84;
    }
}

int main(int argc, char *argv[])
{
    int ret = 0;
    if (argc == 1) {
        return cat(nullptr);
    } else {
        for (int i = 1; i < argc; i++) {
            if(argv[i] == std::string("<")) {
                if(i + 1 < argc) {
                    cat(argv[i+1]);
                } else {
                    std::cerr << "MyCat: " << "- : No such file or directory" <<std::endl;
                    return 84;
                }
            } else {
                ret = cat(argv[i]);
                if (ret == 84)
                    return 84;
            }
        }
    }
    return 0;
}