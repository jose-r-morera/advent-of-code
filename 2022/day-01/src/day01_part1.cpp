/**
 * Advent of code 2022
 *
 * --- Day 1: Calorie Counting ---
 *
 * @author José Ramón Morera Campos
 * @date   Saturday 3, December 2022
 * @file   AI_day01_part1.cpp
 * @brief  Determines the number of calories carried by the elf carrying the
 *         most calories. Takes as a command line parameter the name of the file
 *         containing the input. Input file: each line contains the calories
 *         of one item. Items carried by each Elf are separated by blank lines.
 *
 * @see    https://adventofcode.com/2022/day/1
 */

#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
  // We only need to consider the total calories of the Elf with the most.
  int max_calories{};
  int current_elf_calories{};

  // Read input from file
  const std::string kInputFileName{argv[1]}; 
  std::ifstream input_file{kInputFileName};
  std::string line{};

  while (std::getline(input_file, line)) {
    if (line.length() > 0) {
      current_elf_calories += stoi(line);
    } else {
      /// Check the calories of current elf against the maximum
      if (current_elf_calories > max_calories) {
        max_calories = current_elf_calories;
      }

      current_elf_calories = 0;
    }
  }

  std::cout << "The elf carrying the most calories carries " << max_calories << " calories.\n";

  return 0;
}