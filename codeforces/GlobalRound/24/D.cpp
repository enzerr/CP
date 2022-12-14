#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 5e3 + 5;

int fat[maxn], inv[maxn];
int n, p;

int binpow(int a, int pow){
	int rt = 1;
	while(pow>0){
		if(pow&1) rt = (rt*a)%p;
		a = (a*a)%p;
		pow = pow>>1;
	}

	return rt;
}

int escolhe(int a, int choose){
	return fat[a] * inv[choose]%p * inv[a-choose]%p;
}

int32_t main(){
	cin >> n >> p;
	fat[0] = 1;
	for(int i = 1; i <= n; i++){
		fat[i] = (fat[i-1]*i)%p;
	}

	inv[0] = 1;
	for(int i = 1; i <= n; i++){
		inv[i] = binpow(fat[i], p-2);
	}

	int ans = !(n&1) ? fat[n-2] : 0;
	for(int b = 2; b <= (n+1)/2; b++){
		for(int i = 0; i <= b-2; i++){
			ans += escolhe(b-2, i) * (b-(n&1)) % p * fat[n-3-i] % p;
			ans %= p;
		}
	}

	ans = (ans*n)%p;
	cout << ans << '\n';
}