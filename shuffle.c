void shuffle(int* f, int l) {
    int j = 0;int t = 0;
    for (int i = l - 1; i > 0; i -= 1) {
        j = arc4random_uniform(i+1);
        t = f[i];f[i] = f[j];f[j] = t;
    }
}

void permutize(int* f, int l) {
    for (int i = 0; i < l; i++) f[i] = i;
    shuffle(f, l);
}

int index(int* f, int k, int l) {
    for (int i = 0; i < l; i++)
        if (f[i] == k ) return i;
    return -1;
}
void invert(int* f, int* g, int l) {
    for (int i = 0; i < l; i++) g[i] = index(f, i, l);
}
void compose(int* f, int* g, int* h, int l) {
    for (int i = 0; i < l; i++) h[i] = f[g[i]];
}

void randomize(int X[S][S]) {
    for (int i = 0; i < S; i++) 
        for (int j = 0; j < S; j++)
            X[i][j] = arc4random_uniform(B);
}
void seed(int X[S][S]) {
    for (int i = 0; i < S; i++) 
        for (int j = 0; j < S; j++)
            X[i][j] = (i % 2);
}
// func inverse_permutation(f [P]int) [P]int {
// 	var g [P]int
// 	for i := 0; i < P; i++ {
// 		g[i] = slices.Index(f[:], i)
// 	}
// 	return g
// }

// void check_text_equality(const i64 u[T], const i64 v[T] ) {
// 	for (i64 i = 0; i < T; i++) if (u[i] != v[i]) printf("inequality found at symbol %lld \n",i);
// }

// void record_difference(i64* x, const i64* y, const i64* z) {
//     for (i64 i = 0; i < T; i++) x[i] = (y[i] != z[i]);
// }

// void copy_text(i64 d[T] , i64 s[T]) {
// 	for (i64 i = 0; i < T; i++) d[i] = s[i];
// }

