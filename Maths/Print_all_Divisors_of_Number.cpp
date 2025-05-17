#include<iostream>
#include<vector>
using namespace std;

void Divisors_of_a_Number(int n,vector<int>&div){
    // for(int i=1;i<=sqrt(n);i++){
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            div.push_back(i);
            if(n/i!=i){
                div.push_back(n/i);
            }
        }
    }
}

bool isPrime(int n){
    int cnt=0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            cnt++;
            if(n/i!=i){
                cnt++;
            }
        }
        if(cnt>2)return false;
    }
    return true;
}
// void primeFactors(int n,vector<int>&ans){//this func take O(n*sqrt(n))tc which is not good
//     for(int i=2;i<=n;i++){
//         if(n%i==0){
//             if(isPrime(i))ans.push_back(i);
//         }
//     }
// }

// void primeFactors(int n,vector<int>&ans){//(reduced tc)this func take O(sqrt(n)*2*sqrt(n))tc which is not good
//     for(int i=2;i*i<=n;i++){
//         if(n%i==0){
//             if(isPrime(i))ans.push_back(i);
//             if(n/i!=i){
//                 if(isPrime(n/i)) ans.push_back(n/i);
//             }
//         }
        
//     }
// }

// void primeFactors(int n,vector<int>&ans){//reduce tc but takes O(n) for some numbers soe optimize this
//     for(int i=2;i<=n;i++){
//         if(n%i==0){
//             ans.push_back(i);
//             while(n%i==0){
//                 n=n/i;
//             }
//         }
//     }
// }

void primeFactors(int n,vector<int>&ans){//reduce tc  takes O(sqrt(n)*log(n)) best tc
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            ans.push_back(i);
            while(n%i==0){
                n=n/i;
            }
        }
    }
    if(n!=1)ans.push_back(n);
}
int Power_Exponentiation(int x,int n){
    int ans=1;
    int m=n;
    while(m>0){
        if(m%2==1){
            ans=ans*x;
            m=m-1;
        }
        else{
            m=m/2;
            x=x*x;
        }
        if(m<0){
            ans=1/ans;
        }
    }
    return ans;
}

int Sieve_of_Eratosthenes_prime(int n,vector<int>&prime){
    for(int i=0;i<=n;i++)prime[i]=1;
    
    prime[0] = prime[1] = 0; // 0 and 1 are not prime
    for(int i=2;i*i<=n;i++){ // O(sqrt(n))
        if(prime[i]==1){
            for(int j=i*i;j<=n;j+=i){ //O(log(log(n)))
                prime[j]=0;
            }
        }
    }
}

int main()
{
    // int n,x;
    // vector<int>divisors;
    // vector<int>prime_factors;
    // cout<<"enter the number:";
    // cin>>n;
    // Divisors_of_a_Number(n,divisors);

    // for(int i=0;i<divisors.size();i++){
    //     cout<<divisors[i]<<" ";
    // }
    // if(isPrime(n)){
    //     cout<<"entered number is prime number"<<endl;
    // }
    // else{
    //     cout<<"entered number is not prime number"<<endl;
    // }
    // primeFactors(n,prime_factors);
    // for(int i=0;i<prime_factors.size();i++){
    //     cout<<prime_factors[i]<<" ";
    // }
    // cout<<"Enter the n:";
    // cin>>n;
    // cout<<"Enter the x:";
    // cin>>x;
    // int ans=Power_Exponentiation(x,n);
    // cout<<"The power exponentiation of "<<x<<" pow "<<n<<" is:"<<ans;


    // Sieve of Eratosthenes
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    vector<int> prime(n + 1);
    Sieve_of_Eratosthenes_prime(n, prime);

    cout << "Prime numbers up to " << n << ":\n";
    for (int i = 2; i <= n; i++) {
        if (prime[i] == 1) {
            cout << i << " ";
        }
    }
    return 0;
}