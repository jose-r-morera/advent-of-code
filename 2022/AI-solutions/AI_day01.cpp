/**
* Advent of code 2022 - AI VERSION
* 
* --- Day 1: Calorie Counting ---
*
* @author José Ramón Morera Campos
* @date   Saturday 3, December 2022
* @file   AI_day01_part1.cpp
*
* Code proposed by OpenAI's chatgpt
* @see https://chat.openai.com
*      https://adventofcode.com/2022/day/1
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
  // Parse input to extract list of foods and their Calories
  std::vector<std::vector<int>> elves; // list of Elves and their food items
  std::vector<int> current_elf; // list of food items for the current Elf
  std::string line;

  // Open input file
  std::ifstream input_file("input.txt");

  // Read each line of input until we reach the end of the input
  while (std::getline(input_file, line)) {
    if (line == "") { // If the line is empty, this indicates the end of the current Elf's inventory
      elves.push_back(current_elf); // Add the current Elf's inventory to the list of Elves
      current_elf.clear(); // Clear the current Elf's inventory
    } else {
      current_elf.push_back(std::stoi(line)); // Convert the food item's Calories to an integer and add it to the current Elf's inventory
    }
  }

  // Find Elf carrying the most Calories
  int most_calories = 0; // The maximum number of Calories carried by any Elf
  std::vector<int> most_calories_elf; // The Elf carrying the most Calories

  // Iterate over the list of Elves
  for (const auto& elf : elves) {
    int total_calories = 0; // Total number of Calories carried by the current Elf

    // Iterate over the food items in the current Elf's inventory
    // and sum their Calories
    for (const auto& calorie : elf) {
      total_calories += calorie;
    }

    // If the current Elf is carrying more Calories than the previous
    // Elf with the most Calories, update the maximum number of Calories
    // and the Elf carrying the most Calories
    if (total_calories > most_calories) {
      most_calories = total_calories;
      most_calories_elf = elf;
    }
  }

  // Print the result
  std::cout << "The Elf carrying the most Calories is carrying " << most_calories << " Calories." << std::endl;

  return 0;
}