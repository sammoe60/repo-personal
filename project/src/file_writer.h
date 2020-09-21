/**
 * @file file_writer.h
 *
 * @brief This class writes parsed data from a container to a file.
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_FILE_WRITER_H_
#define SRC_FILE_WRITER_H_

#include <bits/stdc++.h>

#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <list>
#include <string>

class FileWriter {
 public:
  /**
  * @brief Gets an instance of FileWriter
  *
  * @return FileWriter: pointer to the FileWriter object
  */
  static FileWriter *GetInstance();
  /**
   * @brief Writes the parsed data from the container to a file.
   *
  */
  void Write(std::string s, std::vector<std::string> vec);
  /**
  * @brief parses the string returned by the ostringstream object (that contains
  * the information from the Report method) and stores parsed data into a
  * container to be able to write the data to a file
  *
  * @param[in] a pointer to an ostream object
  *
  * @return Vector of strings: vector containing strings where each string is a
  * piece of the desired information to be parsed
  */
  std::vector<std::string> ProcessOutput(std::ostringstream *ostream);

 private:
  FileWriter();
  static FileWriter *instance;
  std::ofstream myfile;
};
// Init ptr to zero so it can be initialized in first call to getInstance
#endif  // SRC_FILE_WRITER_H_
