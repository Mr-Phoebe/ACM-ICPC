

int Lowbit(int t) //��С��2^k
{ 
    return t & ( t ^ ( t - 1 ) );   //��t^(-t)
} 

int Sum(int end) 
{ 
    int sum = 0; 
    while(end > 0) 
    { 
        sum += in[end]; 
        end -= Lowbit(end); 
    } 
    return sum; 
} 

void plus(int pos , int num) 
{ 
    while(pos <= n) 
    { 
          in[pos] += num; 
          pos += Lowbit(pos); 
    } 
} 