#include <cstdio>
#include <cstring>
#include <iostream>

static bool IsSmallAlpha(const char ch) { return ch >= 'a' && ch <= 'z'; }
static bool IsDigit(const char ch) { return ch >= '0' && ch <= '9'; }

// 字符串转权制
static int CharToWeight(const char ch) {
  if (IsSmallAlpha(ch)) {
    return ch - 'a';
  } else if (IsDigit(ch)) {
    return ch - '0';
  }
  return 0;
}

// 输入版本号合法检测
// Return -1: 非法 0: 合法
static int ErrCheckVersion(const char *version) {
  if (version == nullptr) {
    return -1;
  }
  size_t dot_num = 0, i = 0;
  while (version[i] != '\0') {
    if (version[i] == '.') {
      if (0 != i && (IsDigit(version[i + 1]))) {
        ++dot_num;
      } else {
        return -1;
      }
    } else if (!IsDigit(version[i])) {
      // 非阶段标识号不允许非数字
      if (dot_num < 2) {
        return -1;
      } else if (!(IsSmallAlpha(version[i]) || version[i] == ' ' ||
                   version[i] == '-' || version[i] == '_')) {
        // 阶段标识允许带字母和 - 和 _
        return -1;
      }
    }
    ++i;
  }
  return (i == 0) ? -1 : 0;
}

// Input: 接收两个GUN风格版本号
// Example 1.2.3a
// Return: 如果1: version1 > version2, 0: version1 == version2
//           -1: version1 < version2, -2: 输入参数错误
int CompareVersion(const char *version1, const char *version2) {
  // 判断输入的字符串是否合法
  if (ErrCheckVersion(version1) || ErrCheckVersion(version2)) {
    return -2;
  }
  size_t version1_len = strlen(version1);
  size_t version2_len = strlen(version2);

  size_t sum_version1 = 0, index1 = 0;
  size_t sum_version2 = 0, index2 = 0;

  while (index1 < version1_len || index2 < version2_len) {
    // 版本1权值计算
    while (index1 < version1_len && version1[index1] != '.') {
      sum_version1 = sum_version1 * 10 + CharToWeight(version1[index1]);
      ++index1;
    }
    // 版本2权制计算
    while (index2 < version2_len && version2[index2] != '.') {
      sum_version2 = sum_version2 * 10 + CharToWeight(version2[index2]);
      ++index2;
    }
    // 相等则进行下一轮比较
    if (sum_version1 > sum_version2) {
      return 1;
    } else if (sum_version1 < sum_version2) {
      return -1;
    }
    sum_version1 = 0;
    sum_version2 = 0;
    ++index1;
    ++index2;
  }
  return 0;
}

int main() {
  auto result = CompareVersion("1.0.0", "1.0.0");
  std::cout << result << std::endl;
  result = CompareVersion("1.1", "1.1.1");
  std::cout << result << std::endl;
  result = CompareVersion("1.2.3a", "1.2.3a");
  std::cout << result << std::endl;
  result = CompareVersion("1.1.0a", "1.1.2b");
  std::cout << result << std::endl;
  result = CompareVersion("0.2.0 a", "1.0.1");
  std::cout << result << std::endl;
  result = CompareVersion("1.2.0 beta", "1.2.0 build-13124");
  std::cout << result << std::endl;
  result = CompareVersion("", "");
  std::cout << result << std::endl;
  result = CompareVersion(NULL, "1");
  std::cout << result << std::endl;
  result = CompareVersion(nullptr, "1");
  std::cout << result << std::endl;
  result = CompareVersion("1.1.。", "1");
  std::cout << result << std::endl;
  result = CompareVersion("1.1.1", "1.0.v");
  std::cout << result << std::endl;
  result = CompareVersion("1.1.1", "1.0.11");
  std::cout << result << std::endl;
  result = CompareVersion("1...", "1.0.11");
  std::cout << result << std::endl;
  result = CompareVersion("1.1..", "1.0.11");
  std::cout << result << std::endl;
  result = CompareVersion("---1", "1.0.11");
  std::cout << result << std::endl;
  result = CompareVersion("1.1..", "1.0.11");
  std::cout << result << std::endl;
  result = CompareVersion("1.0.1.1", "1.0.11");
  std::cout << result << std::endl;
  result = CompareVersion("1.1.1.051021_beta_b", "1.1.1.051021_beta_b");
  std::cout << result << std::endl;
  return 0;
}
