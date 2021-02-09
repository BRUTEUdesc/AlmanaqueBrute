int mask;
for(int sub = mask ;; sub = (sub-1)&mask){
     ...
     if(sub == 0) break;
}
