//
// Created by sword on 2024/11/10.
//

#include <OTP.h>

Bob::Bob() {
  length_ = 0;
  decryptor_ = OTP_Decryption();
}

Bob::Bob(const size_t &length, const std::vector<bool> &key) {
  length_ = length;
  decryptor_ = OTP_Decryption(length_, key);
}

std::vector<bool> Bob::Obtain_Message(const std::vector<bool> &ciphertext) {
  return decryptor_.Decrypt(ciphertext);
}
