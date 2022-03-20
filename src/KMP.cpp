// Algorithm analysis
// KMP algorithm

#include <iostream>
#include <vector>
using namespace std;

vector<int> makeTable(string fs) {
  int fsSize = fs.size();
  vector<int> table(fsSize, 0);
  int wsIndex = 0;
  for(int fsIndex = 1; fsIndex < fsSize; fsIndex++) {
    while(wsIndex > 0 && fs[fsIndex] != fs[fsIndex]) {
      wsIndex = table[wsIndex - 1];
    }
    if (fs[fsIndex] == fs[wsIndex]) {
      table[fsIndex] = ++wsIndex;
    }
  }
  return table;
}

void KMP(string ws, string fs) {
  vector<int> table = makeTable(fs);
  int wsSize = ws.size();
  int fsSize = fs.size();
  int fsIndex = 0;
  for(int wsIndex = 0; wsIndex < ws.size(); wsIndex++) {
    while(fsIndex > 0 && ws[wsIndex] != fs[fsIndex]) {
      fsIndex = table[fsIndex - 1];
    }
    if(ws[wsIndex] == fs[fsIndex]) {
      if(fsIndex == fsSize - 1) {
        printf("%d번째에서 발견\n", wsIndex - fsSize + 2);
      } else {
        fsIndex++;
      }
    }
  }
}

int main() {
	string ws = "BABADCABABCABADCABA";
	string fs = "ABADCABA";
	
	vector<int> table = makeTable(fs);
	for (int i = 0; i < table.size(); i++) {
		printf("%d ", table[i]);
	}
	printf("\n");
	KMP(ws, fs);
}