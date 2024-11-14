//
// Created by sword on 2024/11/10.
//

#include <Salsa20.h>
#include <cassert>
#include <iostream>

Salsa20_Decryption::Salsa20_Decryption() {
  length_ = 0;
  key_ = {};
}

Salsa20_Decryption::Salsa20_Decryption(const size_t &length, const std::vector<unsigned int> &key) {
  length_ = length;
  key_ = key;
}

std::vector<unsigned int> Salsa20_Decryption::Decrypt(const std::vector<unsigned int> &ciphertext) {
  assert(length_ == ciphertext.size());
  std::vector<unsigned int> message(length_);
  auto key_stream = PRG::Generate(length_, key_);
  for (int i = 0; i < length_; ++i) {
    message[i] = ciphertext[i] ^ key_stream[i];
  }
  return message;
}



