//
// Created by sword on 2024/11/10.
//

#ifndef OTP_H
#define OTP_H

#include <vector>
#include <cstddef>

class OTP_Encryption {
private:
  size_t length_;
  std::vector<bool> key_;
public:
  OTP_Encryption();
  OTP_Encryption(const size_t &, const std::vector<bool> &);
  std::vector<bool> Encrypt(const std::vector<bool> &);
};

class OTP_Decryption {
private:
  size_t length_;
  std::vector<bool> key_;
public:
  OTP_Decryption();
  OTP_Decryption(const size_t &, const std::vector<bool> &);
  std::vector<bool> Decrypt(const std::vector<bool> &);
};

class Alice {
private:
  friend class OTP_Encyption;
  size_t length_;
  std::vector<bool> message_;
  OTP_Encryption encryptor_;
public:
  Alice();
  Alice(const size_t &, const std::vector<bool> &);
  std::vector<bool> Transmit();
  bool Check(const std::vector<bool> &);
};

class Bob {
private:
  friend class OTP_Decryption;
  size_t length_;
  OTP_Decryption decryptor_;
public:
  Bob();
  Bob(const size_t &, const std::vector<bool> &);
  std::vector<bool> Obtain_Message(const std::vector<bool> &);
};

#endif //OTP_H
