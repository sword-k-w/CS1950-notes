//
// Created by sword on 2024/11/14.
//

#include <Salsa20.h>
#include <random>
#include <ctime>

std::vector<unsigned int> PRG::nonce_;

void PRG::Init() {
  nonce_.resize(2);
  std::mt19937 rnd(time(nullptr));
  for (int i = 0; i < 2; ++i) {
    nonce_[i] = rnd();
  }
}

unsigned int PRG::LeftShift(const unsigned int &x, const unsigned int &y) {
  return (x << y) | (x >> 32 - y);
}

void PRG::Transform(std::vector<unsigned> &state, const unsigned int &a, const unsigned int &b, const unsigned int &c, const unsigned int &d) {
  state[a] ^= LeftShift(state[b] + state[c], 7);
  state[d] ^= LeftShift(state[a] + state[b], 9);
  state[c] ^= LeftShift(state[d] + state[a], 13);
  state[b] ^= LeftShift(state[c] + state[d], 18);
}

std::vector<unsigned int> PRG::Generate(const size_t &length, const std::vector<unsigned int> &key) {
  std::vector<unsigned int> key_stream;
  unsigned long long loop_cnt = 0;
  while (key_stream.size() < length) {
    std::vector<unsigned int> origin_state(16);
    origin_state[0] = 0x61707865;
    for (int i = 1; i < 5; ++i) {
      origin_state[i] = key[i - 1];
    }
    origin_state[5] = 0x3320646e;
    for (int i = 6; i < 8; ++i) {
      origin_state[i] = nonce_[i - 6];
    }
    origin_state[8] = loop_cnt & 0xffffffff;
    origin_state[9] = loop_cnt >> 32;
    ++loop_cnt;
    origin_state[10] = 0x79622d32;
    for (int i = 11; i < 15; ++i) {
      origin_state[i] = key[i - 11];
    }
    origin_state[15] = 0x6b206574;

    auto cur_state = origin_state;
    for (int i = 0; i < 10; ++i) {
      Transform(cur_state, 4, 0, 12, 8);
      Transform(cur_state, 9, 5, 1, 13);
      Transform(cur_state, 14, 10, 6, 2);
      Transform(cur_state, 3, 15, 11, 7);
      Transform(cur_state, 1, 2, 3, 0);
      Transform(cur_state, 6, 7, 4, 5);
      Transform(cur_state, 11, 8, 9, 10);
      Transform(cur_state, 12, 13, 14, 15);
    }

    for (int i = 0; i < 16; ++i) {
      key_stream.emplace_back(origin_state[i] + cur_state[i]);
    }
  }
  return key_stream;
}

