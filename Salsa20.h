//
// Created by sword on 2024/11/10.
//

#ifndef Salsa20_H
#define Salsa20_H

#include <vector>
#include <cstddef>

class PRG {
private:
  static std::vector<unsigned int> nonce_;
public:
  static void Init();
  static unsigned int LeftShift(const unsigned int&, const unsigned int &);
  static void QuarterRound(std::vector<unsigned int>&, const unsigned int &, const unsigned int &, const unsigned int &, const unsigned int &);
  static std::vector<unsigned int> Generate(const size_t &, const std::vector<unsigned int>&);
};

class Salsa20_Encryption {
private:
  size_t length_;
  std::vector<unsigned int> key_;
public:
  Salsa20_Encryption();
  Salsa20_Encryption(const size_t &, const std::vector<unsigned int> &);
  std::vector<unsigned int> Encrypt(const std::vector<unsigned int> &);
};

class Salsa20_Decryption {
private:
  size_t length_;
  std::vector<unsigned int> key_;
public:
  Salsa20_Decryption();
  Salsa20_Decryption(const size_t &, const std::vector<unsigned int> &);
  std::vector<unsigned int> Decrypt(const std::vector<unsigned int> &);
};

class Alice {
private:
  friend class Salsa20_Encyption;
  size_t length_;
  std::vector<unsigned int> message_;
  Salsa20_Encryption encryptor_;
public:
  Alice();
  Alice(const size_t &, const std::vector<unsigned int> &);
  std::vector<unsigned int> Transmit();
  bool Check(const std::vector<unsigned int> &);
};

class Bob {
private:
  friend class Salsa20_Decryption;
  size_t length_;
  Salsa20_Decryption decryptor_;
public:
  Bob();
  Bob(const size_t &, const std::vector<unsigned int> &);
  std::vector<unsigned int> Obtain_Message(const std::vector<unsigned int> &);
};

#endif //Salsa20_H