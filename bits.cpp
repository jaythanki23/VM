#include <iostream>
#include <bitset>

using namespace std;

void left_shift_bits(unsigned short num, int bits) {
  bitset<16> bit{num};
  cout << bit << " : " << num << endl;
  
  unsigned short left_shifted_num = num << bits;
  bitset<16> left_shifted_bit{left_shifted_num};
  cout << left_shifted_bit << " : " << left_shifted_num << endl;
}

void and_bits(unsigned int num1, unsigned int num2) {
  bitset<16> bit1{num1};
  cout << bit1 << " : " << num1 << endl;

  bitset<16> bit2{num2};
  cout << bit2 << " : " << num2 << endl;

  unsigned int and_num = num1 & num2;
  bitset<16> and_bit{and_num};
  cout << and_bit << " : " << and_num << endl;
}

void or_bits(unsigned int num1, unsigned int num2) {
  bitset<16> bit1{num1};
  cout << bit1 << " : " << num1 << endl;

  bitset<16> bit2{num2};
  cout << bit2 << " : " << num2 << endl;

  unsigned int and_num = num1 | num2;
  bitset<16> and_bit{and_num};
  cout << and_bit << " : " << and_num << endl;
}

void pos_and_neg(int num, int neg_num) {
  cout << bitset<4>(num) << endl;
  cout << bitset<4>(neg_num) << endl;
  cout << bitset<4>(11) << endl;
}

void right_shift_bits(uint16_t num, int bits) {
  cout << bitset<16>(num) << endl;
  for(int i = 1; i <= 12; i++) {
    uint16_t right_shifted_bits = num >> i;
    cout << bitset<16>(right_shifted_bits) << endl;
  }
  
}

int main() {
  // left_shift_bits(6, 1);
  // and_bits(6, 12);
  // or_bits(6, 12);

  // int num = 4;
  // bitset<sizeof(int) * 16> bit{num};
  // cout << bit << " : " << num << endl;

  // unsigned int val = 4;
  // bitset<16> bit_val{val};
  // cout << bit_val << " : " << val << endl;

  // pos_and_neg(5, -5);
  // right_shift_bits(5445, 12);

  // int num = 32;
  // cout << hex << num << endl;

  cout << 0x7 << endl;
  
}