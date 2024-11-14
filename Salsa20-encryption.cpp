//
// Created by sword on 2024/11/10.
//

#include <Salsa20.h>
#include <cassert>

Salsa20_Encryption::Salsa20_Encryption() {
  length_ = 0;
  key_ = {};
}

Salsa20_Encryption::Salsa20_Encryption(const size_t &length, const std::vector<unsigned int> &key) {
  length_ = length;
  key_ = key;
}

std::vector<unsigned int> Salsa20_Encryption::Encrypt(const std::vector<unsigned int> &message) {
  assert(length_ == message.size());
  std::vector<unsigned int> cyphertext(length_);
  for (int i = 0; i < length_; ++i) {
    cyphertext[i] = message[i] ^ key_[i];
  }
  return cyphertext;
}