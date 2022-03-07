#include <iostream>

using namespace std;

// ws: word string, ps: pattern string
void findString(string ws, string ps) {
  int wsSize = ws.size();
  int psSize = ps.size();

  int wsHash = 0;
  int psHash = 0;
  int power = 1; 

  for(int i = 0; i <= wsSize - psSize; i++) {
    if (i == 0) {
      for (int j = 0; j < psSize; j++) {
        wsHash += ws[psSize - 1 - j] * power;
        psHash += ps[psSize - 1 - j] * power;
        if (j < psSize - 1) power *= 3;
      }
    } else {
      wsHash = 3 * (wsHash - ws[i - 1] * power) + ws[psSize - 1 + i];
    }
    if (wsHash == psHash) {
      bool isFind = true;
      // 우연히 해시값이 겹친 경우
      for (int j = 0; i < psSize; j++) {
        if (ws[i + j] != ps[j]) {
          isFind = false;
          break;
        }
      }
      if (isFind) {
        cout << wsHash << " " << psHash << endl;
        printf("Found in %d \n", i + 1);
      }
    }
  }
}
int main() {
  string ws = "AABDCDABD";
  string ps = "ABD";
  findString(ws, ps);
}