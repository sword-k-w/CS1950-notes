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
  std::vector<unsigned int> key_;
public:
  OTP_Encryption();
  OTP_Encryption(const size_t &, const std::vector<unsigned int> &);
  std::vector<unsigned int> Encrypt(const std::vector<unsigned int> &);
};

class OTP_Decryption {
private:
  size_t length_;
  std::vector<unsigned int> key_;
public:
  OTP_Decryption();
  OTP_Decryption(const size_t &, const std::vector<unsigned int> &);
  std::vector<unsigned int> Decrypt(const std::vector<unsigned int> &);
};

class Alice {
private:
  friend class OTP_Encyption;
  size_t length_;
  std::vector<unsigned int> message_;
  OTP_Encryption encryptor_;
public:
  Alice();
  Alice(const size_t &, const std::vector<unsigned int> &);
  std::vector<unsigned int> Transmit();
  bool Check(const std::vector<unsigned int> &);
};

class Bob {
private:
  friend class OTP_Decryption;
  size_t length_;
  OTP_Decryption decryptor_;
public:
  Bob();
  Bob(const size_t &, const std::vector<unsigned int> &);
  std::vector<unsigned int> Obtain_Message(const std::vector<unsigned int> &);
};

#endif //OTP_H
