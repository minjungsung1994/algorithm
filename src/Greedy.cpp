/*
같은 말로 탐욕 알고리즘으로 불리는 그리디 알고리즘(Greedy Algorithm)은 매 선택마다 지금 당장 최적의 해를 선택해 적합한 결과를 도출하는 알고리즘입니다. 
예를 들어 서울에서 전주까지 거쳐가는 도시를 서울-수원-천안-대전-전주 라고 할 때 각각의 도시에서 출발할 때 마다  다음 도시로 갈 수 있는 도로 중 가장 짧은 도로를 선택하여 이동하는 방법입니다.
그리디 알고리즘을 적용하여 매 순간 최적의 해를 구할 수 있지만 그것을 전체 결과로 보았을 때 최적의 결과로 보기는 어렵습니다. 왜냐하면 이 알고리즘 대로 최적의 해를 구하여 (예를 들어) 10 - 10 - 10 - 300 의 경로(총 330)를 지정할 수 있지만 10 - 10 - 30 - 100의 경로(총 150)가 전체 결과로 보았을 때 더 최적의 결과가 도출되기 때문입니다. 당연히 이러한 문제에서는 그리디 알고리즘의 적용이 어렵습니다. 그러므로 그리디 알고리즘은 부분 문제의 최적 해들의 집합이 전체 문제의 해로 직결될 때 사용해야 합니다.
맨 처음 예시에서 서울에서 전주까지 가는 최단 경로를 찾고자 할 때 각 도시마다 경로가 2개씩 있으며 10 + 10 + 50 + 10 = 80으로 최단 경로를 찾을 수 있습니다. 최단 경로는 각 부분 문제인 <서울 -> 수원>의 최단 경로, <수원 -> 천안>의 최단 경로, <천안 -> 대전>의 최단 경로, <대전 -> 전주>의 최단 경로 문제의 해의 합입니다. 따라서 이러한 문제들의 최적 해결 방법은 부분 문제의 최적 해들의 집합으로 이루어지며 최적 부분구조라 이릅니다.
또 하나의 대표적인 예시로 지정된 금액에 대하여 가장 적은 개수의 화폐로 구성하는 방법의 예시(ex. 거스름돈)가 존재합니다. 거스름돈이 5620원이라고 할 때 5000원 권 1장, 500원 동전 1개, 100원 동전 1개, 10원 동전 2로 구성 가능하므로 총 개수 5가 이 문제의 최적의 해가 됩니다.
한편, 문제를 가장 짧거나 가장 길게, 극단적으로 접근한다는 점에서 정렬 기법이 적용될 수 있으며 최소 비용 신장 트리(MST)를 구하는 크루스칼 알고리즘이 이에 해당합니다.
*/

// Algorithm analysis
// Greedy algorithm

#include <iostream>
using namespace std;

int main() {
  int x = 5620;
  int result = 0;

  result += x / 10000;
  x %= 10000;
  result += x / 5000;
  x %= 5000;
  result += x / 500;
  x %= 500;
  result += x / 100;
  x %= 100;
  result += x / 50;
  x %= 50;
  result += x / 10;
  x %= 10;  

  cout << "Count: " << result;
}