#include <cstdio>

struct student {
    int id;
    int score, ds_score, al_score;
    student() {}
    void set(int i, int d, int a) {
        id = i;
        ds_score = d;
        al_score = a;
        score = ds_score + al_score;
    }
    student &operator=(student const &st) {
        id = st.id;
        ds_score = st.ds_score;
        al_score = st.al_score;
        score = st.score;
        return *this;
    }
};

bool comp(student const &st1, student const &st2) {
    if (st1.score > st2.score) {
        return true;
    } else if (st1.score == st2.score) {
        return st1.al_score > st2.al_score;
    }
    return false;
}

void swap(student *a, student *b) {
    student e = *a;
    *a = *b;
    *b = e;
}

int bubbleSort(student array[], int lo, int hi) {
    bool sorted = false;
    int last = hi, count = 0;
    while (lo < hi && !sorted) {
        sorted = true;
        for (int i = lo + 1; i < last; ++i) {
            if (comp(array[i], array[i - 1])) {
                swap(&array[i], &array[i - 1]);
                ++count;
            }
            sorted = false;
        }
        --last;
    }
    return count;
}

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    auto st = new student[n];
    for (int i = 0; i < n; ++i) {
        int ds, al;
        scanf("%d %d", &al, &ds);
        st[i].set(i + 1, ds, al);
    }

    auto count = bubbleSort(st, 0, n);
    for (int i = 0; i < n; ++i) {
        printf("%d %d %d %d\n", st[i].id, st[i].score, st[i].al_score,
               st[i].ds_score);
    }
    printf("%d\n", count);

    return 0;
}
