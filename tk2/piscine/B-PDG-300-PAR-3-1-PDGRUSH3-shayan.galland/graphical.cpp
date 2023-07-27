#include <SFML/Graphics.hpp>
#include <iostream>
#include "datas.hpp"

void graphical()
{
    Stats stats;
    sf::Font font;
    bool all = true;
    bool graph = false;
    bool ram = false;
    bool cpu = false;
    int ramPercent;
    int y;

    sf::RenderWindow window(sf::VideoMode(600, 350), "GKrellM");
    window.setFramerateLimit(240);
    if (!font.loadFromFile("8_bit.ttf")) {
        std::cerr << "Failed to load font\n";
        return;
    }
    sf::Text cpuT;
    cpuT.setFont(font);
    cpuT.setCharacterSize(11);
    cpuT.setString("CPU Usage: " + std::to_string(stats.get_cpu_usage()));
    cpuT.setPosition(sf::Vector2f(10, 10));

    std::array<int, 4UL> cpuUsagePerCore = stats.get_cpu_usage_per_core();
    std::string cpuUsagePerCoreText = "CPU Usage Per Core: ";
    for (long unsigned int i = 0; i < cpuUsagePerCore.size(); i++) {
        cpuUsagePerCoreText += std::to_string(cpuUsagePerCore[i]);
        if (i < cpuUsagePerCore.size() - 1)
            cpuUsagePerCoreText += ", ";
    }

    sf::Text cpuUPCT;
    cpuUPCT.setFont(font);
    cpuUPCT.setCharacterSize(11);
    cpuUPCT.setString(cpuUsagePerCoreText);
    cpuUPCT.setPosition(sf::Vector2f(10, 40));

    sf::Text cpuNT;
    cpuNT.setFont(font);
    cpuNT.setCharacterSize(11);
    cpuNT.setString("CPU Name: " + stats.get_cpu_name());
    cpuNT.setPosition(sf::Vector2f(10, 70));

    sf::Text cpuCT;
    cpuCT.setFont(font);
    cpuCT.setCharacterSize(11);
    cpuCT.setString("CPU Cores: " + std::to_string(stats.get_cpu_cores()));
    cpuCT.setPosition(sf::Vector2f(10, 100));

    sf::Text cpuTT;
    cpuTT.setFont(font);
    cpuTT.setCharacterSize(11);
    cpuTT.setString("CPU Threads: " + std::to_string(stats.get_cpu_threads()));
    cpuTT.setPosition(sf::Vector2f(10, 130));

    sf::Text krnlT;
    krnlT.setFont(font);
    krnlT.setCharacterSize(11);
    krnlT.setString("Kernel: " + stats.get_kernel());
    krnlT.setPosition(sf::Vector2f(10, 160));

    sf::Text cpuFT;
    cpuFT.setFont(font);
    cpuFT.setCharacterSize(11);
    cpuFT.setString("CPU Frequency: " + std::to_string(stats.get_cpu_frequency()));
    cpuFT.setPosition(sf::Vector2f(10, 190));

    sf::Text cpuTPT;
    cpuTPT.setFont(font);
    cpuTPT.setCharacterSize(11);
    cpuTPT.setString("CPU Temperature: " + std::to_string(stats.get_cpu_temperature()));
    cpuTPT.setPosition(sf::Vector2f(10, 220));

    sf::Text RamT;
    RamT.setFont(font);
    RamT.setCharacterSize(11);
    RamT.setString("Total RAM: " + std::to_string(stats.get_total_ram()));
    RamT.setPosition(sf::Vector2f(10, 250));

    sf::Text ramFT;
    ramFT.setFont(font);
    ramFT.setCharacterSize(11);
    ramFT.setString("Free Ram: " + std::to_string(stats.get_ram_free()));
    ramFT.setPosition(sf::Vector2f(10, 280));

    sf::Text ramUT;
    ramUT.setFont(font);
    ramUT.setCharacterSize(11);
    ramUT.setString("Ram used: " + std::to_string(stats.get_total_ram() - stats.get_ram_free()));

    sf::Text ramFPT;
    ramFPT.setFont(font);
    ramFPT.setCharacterSize(11);
    ramFPT.setString("Free Ram %: " + std::to_string((stats.get_ram_free() * 100) / stats.get_total_ram()));

    sf::Text ramUPT;
    ramUPT.setFont(font);
    ramUPT.setCharacterSize(11);
    ramUPT.setString("Ram used %: " + std::to_string(((stats.get_total_ram() - stats.get_ram_free()) * 100) / stats.get_total_ram()));

    sf::Text uptT;
    uptT.setFont(font);
    uptT.setCharacterSize(11);
    uptT.setString("Uptime: " + std::to_string(stats.get_up_time()));

    sf::Color myColor(178, 240, 0, 100);

    sf::RectangleShape button(sf::Vector2f(150, 70));
    button.setFillColor(myColor);
    button.setPosition(sf::Vector2f(0, 300));

    sf::Text changeText;
    changeText.setFont(font);
    changeText.setCharacterSize(14);
    changeText.setString("General");
    changeText.setFillColor(sf::Color::Black);
    changeText.setPosition(sf::Vector2f(16, 320));

    sf::RectangleShape button1(sf::Vector2f(150, 70));
    button1.setFillColor(myColor);
    button1.setPosition(sf::Vector2f(155, 300));

    sf::Text changeText1;
    changeText1.setFont(font);
    changeText1.setCharacterSize(14);
    changeText1.setString("RAM");
    changeText1.setFillColor(sf::Color::Black);
    changeText1.setPosition(sf::Vector2f(195, 320));

    sf::RectangleShape button2(sf::Vector2f(150, 70));
    button2.setFillColor(myColor);
    button2.setPosition(sf::Vector2f(310, 300));

    sf::Text changeText2;
    changeText2.setFont(font);
    changeText2.setCharacterSize(14);
    changeText2.setString("CPU");
    changeText2.setFillColor(sf::Color::Black);
    changeText2.setPosition(sf::Vector2f(360, 320));

    sf::RectangleShape button3(sf::Vector2f(150, 70));
    button3.setFillColor(myColor);
    button3.setPosition(sf::Vector2f(465, 300));

    sf::Text changeText3;
    changeText3.setFont(font);
    changeText3.setCharacterSize(14);
    changeText3.setString("GRAPH");
    changeText3.setFillColor(sf::Color::Black);
    changeText3.setPosition(sf::Vector2f(490, 320));


    sf::Text ramText;
    ramText.setFont(font);
    ramText.setCharacterSize(11);
    ramText.setFillColor(sf::Color::White);
    ramText.setPosition(10, 10);

    sf::VertexArray line(sf::LinesStrip, 100);
    int xPos = 175;
    int yPos = 300;

    while (window.isOpen()) {
        sf::Event event;

        cpuT.setString("CPU Usage: " + std::to_string(stats.get_cpu_usage()));
        std::array<int, 4UL> cpuUsagePerCore = stats.get_cpu_usage_per_core();
        std::string cpuUsagePerCoreText = "CPU Usage Per Core: ";
        for (long unsigned int i = 0; i < cpuUsagePerCore.size(); i++) {
            cpuUsagePerCoreText += std::to_string(cpuUsagePerCore[i]);
            if (i < cpuUsagePerCore.size() - 1)
                cpuUsagePerCoreText += ", ";
        }
        cpuUPCT.setString(cpuUsagePerCoreText);
        cpuNT.setString("CPU Name: " + stats.get_cpu_name());
        cpuCT.setString("CPU Cores: " + std::to_string(stats.get_cpu_cores()));
        cpuTT.setString("CPU Threads: " + std::to_string(stats.get_cpu_threads()));
        krnlT.setString("Kernel: " + stats.get_kernel());
        cpuFT.setString("CPU Frequency: " + std::to_string(stats.get_cpu_frequency()));
        cpuTPT.setString("CPU Temperature: " + std::to_string(stats.get_cpu_temperature()));
        RamT.setString("Total RAM: " + std::to_string(stats.get_total_ram()));
        ramFT.setString("Free Ram: " + std::to_string(stats.get_ram_free()));
        ramUPT.setString("Ram used %: " + std::to_string(((stats.get_total_ram() - stats.get_ram_free()) * 100) / stats.get_total_ram()) + "%");
        ramFPT.setString("Free Ram %: " + std::to_string((stats.get_ram_free() * 100) / stats.get_total_ram()) + "%");
        ramUT.setString("Ram used: " + std::to_string(stats.get_total_ram() - stats.get_ram_free()));
        uptT.setString("Uptime: " + std::to_string(stats.get_up_time()));
        ramPercent = ((stats.get_total_ram() - stats.get_ram_free()) * 100) / stats.get_total_ram();
        ramText.setString("Ram used %: " + std::to_string(ramPercent));

        window.clear(sf::Color::Blue);

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                if (button.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        all = true;
                        graph = false;
                        ram = false;
                        cpu = false;
                }
                if (button1.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        all = false;
                        graph = false;
                        ram = true;
                        cpu = false;
                }
                if (button2.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        all = false;
                        graph = false;
                        ram = false;
                        cpu = true;
                }
                if (button3.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        all = false;
                        graph = true;
                        ram = false;
                        cpu = false;
                }
            }
        }
        if (all == true) {
            cpuNT.setPosition(sf::Vector2f(10, 10));
            krnlT.setPosition(sf::Vector2f(10, 40));
            cpuUPCT.setPosition(sf::Vector2f(10, 70));
            cpuCT.setPosition(sf::Vector2f(10, 100));
            cpuTT.setPosition(sf::Vector2f(10, 130));
            uptT.setPosition(sf::Vector2f(10, 160));
            cpuFT.setPosition(sf::Vector2f(10, 190));
            cpuTPT.setPosition(sf::Vector2f(10, 220));
            RamT.setPosition(sf::Vector2f(10, 250));
            ramFT.setPosition(sf::Vector2f(10, 280));

            window.draw(cpuUPCT);
            window.draw(uptT);
            window.draw(RamT);
            window.draw(cpuNT);
            window.draw(cpuCT);
            window.draw(cpuTT);
            window.draw(krnlT);
            window.draw(cpuFT);
            window.draw(cpuTPT);
            window.draw(ramFT);
        }
        if (ram == true) {
            RamT.setPosition(sf::Vector2f(10, 10));
            ramFT.setPosition(sf::Vector2f(10, 40));
            ramUT.setPosition(sf::Vector2f(10, 70));
            ramFPT.setPosition(sf::Vector2f(10, 100));
            ramUPT.setPosition(sf::Vector2f(10, 130));

            window.draw(ramUPT);
            window.draw(ramFPT);
            window.draw(ramUT);
            window.draw(RamT);
            window.draw(ramFT);
        }

        if (cpu == true) {
            cpuUPCT.setPosition(sf::Vector2f(10, 10));
            cpuT.setPosition(sf::Vector2f(10, 40));
            cpuNT.setPosition(sf::Vector2f(10, 70));
            cpuCT.setPosition(sf::Vector2f(10, 100));
            cpuTT.setPosition(sf::Vector2f(10, 130));
            cpuFT.setPosition(sf::Vector2f(10, 160));
            cpuTPT.setPosition(sf::Vector2f(10, 190));

            window.draw(cpuUPCT);
            window.draw(cpuT);
            window.draw(cpuNT);
            window.draw(cpuCT);
            window.draw(cpuTT);
            window.draw(cpuFT);
            window.draw(cpuTPT);
        }

        if (graph == true) {
            for (int i = 0; i < 100; ++i) {
                y = yPos - (ramPercent * (yPos - 50) / 100);
                line[i].position = sf::Vector2f(xPos + i, y);
                line[i].color = sf::Color::White;
            }
            window.draw(ramText);
            window.draw(line);
        }

        window.draw(button);
        window.draw(changeText);
        window.draw(button1);
        window.draw(changeText1);
        window.draw(button2);
        window.draw(changeText2);
        window.draw(button3);
        window.draw(changeText3);
        window.display();
    }
}
