#include<iostream>
#include<cmath>
#include<vector>
#include<set>
using namespace std; 
  
bool IsPrime(unsigned n) {
  if (n <= 1) return false;
  if(n==2) return true;
  if (n % 2 == 0) return false;
  for (auto j=3; j<=sqrt(n); j++) {
    if (n%j==0) {
      return false;
    }
  }      
  return true;
}

set <unsigned> rotate (unsigned n)
{
	unsigned size=0, tmp=n;
  while(tmp)
	  if(tmp>0)
		{
            tmp/=10;
            size+=1;
		}
    tmp=n;
    set <unsigned> numbers={n};
    for(auto i=0; i< size-1; ++i)
	{
        unsigned carry = tmp%10;
        tmp/=10;
        tmp+=carry*pow(10,(size-1));
		numbers.insert(tmp);
	}
    return numbers;
}
 
int main() 
{ 
	
	set<unsigned> cirPrimes;
	for(auto i=2; i<1000000; ++i)
	{
		if(!IsPrime(i)) continue;
		set<unsigned>::iterator it = cirPrimes.find(i);
		if(it != cirPrimes.end()) continue;
		set<unsigned> rot=rotate(i);
		bool flag = true;
		for(auto item : rot)
			if(!IsPrime(item))
			{
				flag = false;
				break;
			}
		if(flag)
		for(auto item : rot)
			cirPrimes.insert(item);
		
	}
	//for(auto i : cirPrimes)
	//	cout << i << endl;
	
	cout<<"Sol.: " << cirPrimes.size() << endl;
	
	return 0; 
}
