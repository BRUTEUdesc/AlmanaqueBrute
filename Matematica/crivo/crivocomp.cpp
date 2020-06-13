const long long LIM = 1000000;

bool isComposed[LIM];

void sieve(){
  isComposed[0] = true;
  isComposed[1] = true;
  long long sq = sqrt(LIM);
  for(long long i = 2; i <= sq; i++){
    if(!isComposed[i]){
      for (long long j =  i * i; j < LIM; j+= i) {
        isComposed[j] = true;
      }
    }
  }
  return;
}
