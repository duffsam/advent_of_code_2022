#include <stdio.h>
#include <iostream>
#include <filesystem>
#include <vector>
#include <string>
#include <fstream>
#include <map>

enum outcome
{
    win = 6,
    loss = 0,
    draw = 3
};

enum rock_paper_scissors
{
    rock = 1,
    paper = 2,
    scissors = 3
};

struct scores
{
    int player_a_score;
    int player_b_score;
};

typedef std::map<char, rock_paper_scissors> rps_hashmap;

/// @brief Implements the game logic of rock paper scissors.
/// @param map a hashmap to correlate the correct characters to rock, paper and scissors.
/// @param player_a the char encoded input of player_a's selection (rock, paper or scissors)
/// @param player_b the char encoded input of player_b's selection (rock, paper or scissors)
/// @return a struct of both players scores
scores play_game(rps_hashmap map,
    char player_a,
    char player_b)
{
    if ((map[player_a] == rock) && (map[player_b] == rock))
    {
        return { draw + map[player_a],
                draw + map[player_b] };
    }
    else if ((map[player_a] == rock) && (map[player_b] == paper))
    {
        return { loss + map[player_a],
                win + map[player_b] };
    }
    else if ((map[player_a] == rock) && (map[player_b] == scissors))
    {
        return { win + map[player_a],
                loss + map[player_b] };
    }
    else if ((map[player_a] == scissors) && (map[player_b] == rock))
    {
        return { loss + map[player_a],
                win + map[player_b] };
    }
    else if ((map[player_a] == scissors) && (map[player_b] == paper))
    {
        return { win + map[player_a],
                loss + map[player_b] };
    }
    else if ((map[player_a] == scissors) && (map[player_b] == scissors))
    {
        return { draw + map[player_a],
                draw + map[player_b] };
    }
    else if ((map[player_a] == paper) && (map[player_b] == rock))
    {
        return { win + map[player_a],
                loss + map[player_b] };
    }
    else if ((map[player_a] == paper) && (map[player_b] == paper))
    {
        return { draw + map[player_a],
                draw + map[player_b] };
    }
    else if ((map[player_a] == paper) && (map[player_b] == scissors))
    {
        return { loss + map[player_a],
                win + map[player_b] };
    }
    else
    {
        std::cout << "Player A: " << std::string(1, player_a) << std::endl;
        std::cout << "Player B: " << std::string(1, player_b) << std::endl;
        throw new std::invalid_argument("Data is not in the correct format");
    }
}

int main(void)
{
    // Build Hash Map
    rps_hashmap map;
    map['A'] = rock;
    map['B'] = paper;
    map['C'] = scissors;
    map['X'] = rock;
    map['Y'] = paper;
    map['Z'] = scissors;

    // Get Input
    std::ifstream ReadInput;
    ReadInput.open("./inputs/input.txt");
    if (!ReadInput.good())
    {
        std::cout << "Unable to open text file" << std::endl;
        return -1;
    }

    int my_score = 0;
    std::string buff;
    while (std::getline(ReadInput, buff))
    {
        scores r = play_game(map, buff[0], buff[2]);
        my_score += r.player_b_score;
    }

    std::cout << "My score is: " << my_score << std::endl;

    return 0;
}