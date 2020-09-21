/**
 * @file file_writer.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
*/
#include "src/file_writer.h"

FileWriter *FileWriter::instance = 0;

FileWriter::FileWriter() {
  myfile.open("BusData.csv", std::ofstream::trunc);
  myfile.close();
  myfile.open("PassData.csv", std::ofstream::trunc);
  myfile.close();
}

FileWriter* FileWriter::GetInstance() {
  if (!instance) {
    instance = new FileWriter;
  }
  return instance;
}

void FileWriter::Write(std::string s, std::vector<std::string> vec) {
  myfile.open(s, std::ofstream::app);
  for (std::vector<std::string>::iterator it = vec.begin();
  it != vec.end(); it++) {
    myfile << *it << ',';
  }
  myfile << '\n';
  myfile.close();
}

std::vector<std::string>
FileWriter::ProcessOutput(std::ostringstream *ostream) {
  std::vector<std::string> vec;
  std::string s = ostream->str();
  std::istringstream ss(s);
  do {
    std::string word;
    ss >> word;
    vec.push_back(word);
  } while (ss);
  return vec;
}
