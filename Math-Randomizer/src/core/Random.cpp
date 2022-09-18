#include "Random.h"

class Error {
 private:
  std::string msg_;

 public:
  Error(const std::string &msg);
  ~Error();
  std::string getMsg() const;
};

Error::Error(const std::string &msg) : msg_(msg) {}

Error::~Error() {}

std::string Error::getMsg() const { return msg_; }

std::vector<std::string> init() {
  std::fstream fin("data.txt", std::ios::in);
  if (fin.fail()) throw Error("Opening File: data.txt has failed!");

  std::string input;
  std::vector<std::string> data;

  while (std::getline(fin, input)) {
    data.push_back(input);
  }
  fin.close();

  return data;
}

int main() {
  std::vector<std::string> data;
  try {
    data = init();
  } catch (const Error &err) {
    std::cout << err.getMsg() << "\n";
    return -1;
  }

  srand(time(nullptr));
  int section;
  int problem;
  const int NUMBER_OF_PROBLEMS = 10;

  for (int i = 0; i < NUMBER_OF_PROBLEMS; i++) {
    section = rand() % data.size();
    problem = rand() % 80 + 1;
    std::cout << "Attempt: " << data.at(section) << ", problem: " << problem << "\n";
  }
  return 0;
}
