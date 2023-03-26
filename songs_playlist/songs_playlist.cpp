#include <iostream>
#include <list>
#include <cctype>
#include <algorithm>
#include "Song.h"


void display_menu() {
    std::cout << "\nF - Play First Song\n"
        << "N - Play Next Song\n"
        << "P - Play Previous Song\n"
        << "A - Add and Play a new Song at current location\n"
        << "L - List the current Playlist\n"
        << "======================================\n"
        << "Enter a Selection (Q to quit): ";
}

void play_current_song(Song& song) {
    std::cout << "\n"<<"Playing: " << std::endl;
    std::cout << song << std::endl;
}

void display_playlist(std::list<Song>& playlist, Song & current_song) {
    if (playlist.empty()) {
        std::cout << "Playlist is empty, Add Song" << std::endl;
    }
    for (std::list<Song>::iterator it= playlist.begin(); it != playlist.end(); ++it) {
        std::cout << *it << std::endl;
    }
    play_current_song(current_song);
}

int main()
{
   
    std::list<Song> playlist{ {"God's Plan", "Drake", 5},
        {"Never Be The Same", "Camila Cabello", 5},
        {"Pray For Me", "The Weekend and K.Lamar", 4},
        {"The Middle Zedd", "Maren Morris & Grey", 5},
    {"Wait", "Maroone 5", 4}, {"Whatever It Takes", "Imagine Dragons", 3}};

    std::list<Song>::iterator it = playlist.begin();
    display_playlist(playlist, *it);
    display_menu();
    
    char option{};

    do {
        
        std::cin >> option;
        option = tolower(option);

        if (option == 'f') {
            std::cout << "Playing First Song \n";
            play_current_song(*it);
            display_menu();
        }
        else if (option == 'n') {
            std::cout << "Playing Next Song \n";
            ++it;
            play_current_song(*it);
            display_menu();
        }
        else if (option == 'p') {
            std::cout << "Playing Previous Song \n";
            --it;
            play_current_song(*it);
            display_menu();
        }
        else if (option == 'a') {
            std::cout << "Addition and Playing new Song" << std::endl;
            std::cout << "Enter Song name: ";
            std::string song_name;
            std::cin >> song_name;
            std::cout << "Enter Artist name: ";
            std::string artist_name;
            std::cin >> artist_name;
            std::cout << "Enter Rating: ";
            int rating;
            std::cin >> rating;
            playlist.insert(it, { song_name, artist_name, rating });
            std::list<Song>::iterator it = playlist.begin();
            play_current_song(*it);
            display_menu();
        }
        else if (option == 'l') {
            std::cout << std::endl;
            display_playlist(playlist, *it);
            display_menu();
        }

    } while (option != 'q');
    std::cout << "Thanks for listening!" << std::endl;
}