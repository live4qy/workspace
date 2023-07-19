#include <bits/stdc++.h>

int main() {
  int i;
  while(std::cin>>i, !std::cin.eof()) {
    if (std::cin.bad()) {
      // 不可恢复的错误  
      std::cout << "std::cin is bad." << std::endl;
      break;
    } else if (std::cin.fail()) {
      // 格式错误
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "data format error, please try again." << std::endl;
      continue;
    }
    std::cout << i << std::endl; 
  }
  std::cout << "process complete." << std::endl;
  return 0;
}