#include <cstdio>
#include <sys/types.h>

int * seqTemp = nullptr;
int64_t cnt = 0;

void mergeSort(int *seq, const int &lo, const int &hi) {
	if (hi <= lo) {
		return ;
	}
	auto mi = (lo + hi) >> 1;
	mergeSort(seq, lo, mi);
	mergeSort(seq, mi + 1, hi);
	int p = lo, q = mi + 1;
	for (int i = lo; i <= hi; ++i) {
		if ((q > hi || seq[p] <= seq[q]) && (p <= mi)){
			seqTemp[i] = seq[p++];
		} else {
			seqTemp[i] = seq[q++];
			cnt += mi - p + 1;
		}
	}
	for (int i = lo; i <= hi; ++i) {
		seq[i] = seqTemp[i];
	}
}

long long getAnswer(int *sequence, int n) {
	mergeSort(sequence, 0, n - 1);
	return cnt;
}

int main() {
	int n;
    scanf("%d", &n);
	auto seq = new int[n];
	seqTemp = new int[n];;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &seq[i]);
    }
	auto ans = getAnswer(seq, n);
	printf("%lld\n", ans);
	delete []seq;
    return 0;
}
