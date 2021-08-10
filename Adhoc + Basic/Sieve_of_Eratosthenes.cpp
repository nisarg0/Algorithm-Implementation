/*Questions solved
	precomputation					-> 	O(N(lnlnN))
1.	is n a prime					->	O(1)
2.	factors of some F				->	O(ln NF)
3.	primes between a range			->	O(range)
4.	smallest prime greater than k	->	O(ln k)
*/

#include<bits/stdc++.h>

using namespace std;
#define LIM 10000

bool isComposite[LIM];
int factor[LIM];	//stores one of the factor of the indx, we can find other factor easily
vector<int> primes;	//stores list of primes in LIM

int main() 
{
	int i;
	//PreComputation
	isComposite[1]=true; //assume for simplicity as 1 is NOT PRIME.
	for(int i=2;i<sqrt(LIM);i++)
	{
		if(isComposite[i])	continue;
		for(int j=2*i; j<LIM; j += i)	//move by i steps at once
		{
			isComposite[j]=true;

			if(factor[j] == 0)	factor[j]=i;	
		}
	}

	for(i=3;i<LIM;i+=2)
	{
		if(!isComposite[i])	primes.push_back(i);
	}


	//Q1
	int n;
	cout<<"Enter number you want to check to be prime:";
	cin>>n;
	cout<<!isComposite[n]<<endl;
	
	//Q2
	int F;
	cout<<"Enter Number you want to factorize: ";
	cin>>F;

	while (isComposite[F] and F!=1)
	{
		cout<<factor[F]<<" ";	//F = a * b  if a is a prime which is stored.
		F=F/factor[F];
	}
	cout<<F<<endl;	//final prime number.

	//Q3
	int a,b;
	cout<<"Enter range you want to check: ";
	cin>>a>>b;
	auto itr = upper_bound(primes.begin(),primes.end(),a);
	for( ; *itr <= b and itr!=primes.end() ; itr++ )
	{
		cout<<*itr<<" ";
	}

	//Q4
	int k;
	cin>>k;
	cout<<"Enter number to get just greater prime:";
	cin>>k;
	itr = upper_bound(primes.begin(),primes.end(),k);
	if(itr!=primes.end())
	cout<<*itr;


	
}




