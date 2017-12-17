

int Lowbit(int t) //×îÐ¡ÃÝ2^k
{ 
    return t & ( t ^ ( t - 1 ) );   //»òt^(-t)
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