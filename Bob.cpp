//
// Created by sword on 2024/11/10.
//

#include <Salsa20.h>

Bob::Bob() {
  length_ = 0;
  decryptor_ = Salsa20_Decryption();
}

Bob::Bob(const size_t &length, const std::vector<unsigned int> &key) {
  length_ = length;
  decryptor_ = Salsa20_Decryption(length_, key);
}

std::vector<unsigned int> Bob::Obtain_Message(const std::vector<unsigned int> &ciphertext) {
  return decryptor_.Decrypt(ciphertext);
}
