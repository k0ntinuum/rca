
int value(int X[S][S], int k) {
    int r = 2 * ( k / 8 );
    int c = 2 * ( k % 8 );
    return 8*X[r][c] + 4*X[r][c+1] + 2*X[r+1][c] + X[r+1][c+1];
}

void store(int X[S][S], int k , int j )  {
	int r = 2 * ( k / 8 );
	int c = 2 * ( k % 8 );
	X[r][c] = j/8;
	j -= 8*X[r][c];
	X[r][c+1] = j/4;
	j -= 4*X[r][c+1];
	X[r+1][c] = j/2;
	j -= 2*X[r+1][c];
	X[r+1][c+1] = j;
}

void permute(int X[S][S], int f[P]) {
    int r0, r1, c0, c1, N[S][S];
    for (int i = 0; i < S; i++) for (int j = 0; j < S; j++) N[i][j] = X[i][j];
    for (int i = 0; i < S*S ; i++) {
		r0 = i/S;
		c0 = i%S;
		r1 = f[i]/S;
		c1 = f[i]%S;
		X[r1][c1] = N[r0][c0]; 
	}
}



void forward(int X[S][S], int g[G]) {
    for (int k = 0 ; k < V ; k++) store(X,  k, g[value(X, k)]);
}



