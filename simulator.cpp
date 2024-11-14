//
// Created by sword on 2024/11/10.
//

#include <OTP.h>
#include <random>
#include <ctime>

int main() {

  std::mt19937 rnd(time(nullptr));
  std::uniform_int_distribution<size_t> length_dist(10, 1000000);
  size_t length = length_dist(rnd);

  std::vector<unsigned int> key(length);
  std::uniform_int_distribution<unsigned int> zero_one(0, -1);
  for (size_t i = 0; i < length; ++i) {
    key[i] = zero_one(rnd);
  }

  Alice a(length, key);
  Bob b(length, key);

  std::vector<unsigned int> message = b.Obtain_Message(a.Transmit());

  if (a.Check(message)) {
    puts("Succeed!");
  } else {
    puts("Fail!");
  }
  return 0;
}