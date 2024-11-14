//
// Created by sword on 2024/11/10.
//

#include <OTP.h>

Bob::Bob() {
  length_ = 0;
  decryptor_ = OTP_Decryption();
}

Bob::Bob(const size_t &length, const std::vector<unsigned int> &key) {
  length_ = length;
  decryptor_ = OTP_Decryption(length_, key);
}

std::vector<unsigned int> Bob::Obtain_Message(const std::vector<unsigned int> &ciphertext) {
  return decryptor_.Decrypt(ciphertext);
}
