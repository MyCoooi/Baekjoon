#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  cin.tie(0) -> sync_with_stdio(false);

  int N;
  cin >> N;

  double maxScore = -1.0;
  double score[1001];
  for (int i = 0; i < N; i++){
    cin >> score[i];
    maxScore = max(score[i], maxScore);
  }
  double sum = 0;
  for (int i = 0; i < N; i++) {
    score[i] = (score[i] / maxScore) * 100;
    sum += score[i];
  }
  double result = sum / (double)N;
  std::cout << std::setprecision(16);
  cout << result << '\n';
}