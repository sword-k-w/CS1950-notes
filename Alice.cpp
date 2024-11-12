//
// Created by sword on 2024/11/10.
//

#include <OTP.h>
#include <random>

Alice::Alice() {
  length_ = 0;
  message_ = {};
}

Alice::Alice(const size_t &length, const std::vector<bool> &key) {
  length_ = length;
  message_.resize(length_);
  std::mt19937 rnd(time(nullptr));
  std::uniform_int_distribution<int> zero_one(0, 1);
  for (size_t i = 0; i < length; ++i) {
    message_[i] = zero_one(rnd);
  }
  encryptor_ = OTP_Encryption(length_, key);
}

std::vector<bool> Alice::Transmit() {
  return encryptor_.Encrypt(message_);
}

bool Alice::Check(const std::vector<bool> &b_message) {
  for (int i = 0; i < length_; ++i) {
    if (message_[i] != b_message[i]) {
      return false;
    }
  }
  return true;
}