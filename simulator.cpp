//
// Created by sword on 2024/11/10.
//

#include <Salsa20.h>
#include <random>
#include <ctime>

int main() {

  std::mt19937 rnd(time(nullptr));
  std::uniform_int_distribution<size_t> length_dist(10, 1000000);
  size_t length = length_dist(rnd);

  std::vector<unsigned int> key(8);
  for (size_t i = 0; i < 4; ++i) {
    key[8] = rnd();
  }

  Alice a(length, key);
  Bob b(length, key);

  PRG::Init();
  std::vector<unsigned int> message = b.Obtain_Message(a.Transmit());

  if (a.Check(message)) {
    puts("Succeed!");
  } else {
    puts("Fail!");
  }
  return 0;
}