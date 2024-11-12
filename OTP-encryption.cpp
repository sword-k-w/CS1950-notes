//
// Created by sword on 2024/11/10.
//

#include <OTP.h>
#include <cassert>

OTP_Encryption::OTP_Encryption() {
  length_ = 0;
  key_ = {};
}

OTP_Encryption::OTP_Encryption(const size_t &length, const std::vector<bool> &key) {
  length_ = length;
  key_ = key;
}

std::vector<bool> OTP_Encryption::Encrypt(const std::vector<bool> &message) {
  assert(length_ == message.size());
  std::vector<bool> cyphertext(length_);
  for (int i = 0; i < length_; ++i) {
    cyphertext[i] = message[i] ^ key_[i];
  }
  return cyphertext;
}