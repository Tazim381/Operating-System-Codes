#include<stdio.h>

int arrival[100], burst[100], turn[100], wait[100], dburst[100];
int queue[100];
int n, mn, i,node,  j, ind, cnt,next;
const int  mod = 100;
int qfront = 0, qback = 0;
int nxt[100], ch[100];
int tm, num;
double avgw =0.0, avgt =0.0;
void pop()
{
  qback++;
  qback = qback%mod;
}
void push(int n)
{
    queue[qfront++] = n;
   qfront = qfront%mod;
}
int front(){
	return queue[qback];
}

int main()
{
  printf("Number of process: ");
  scanf("%d", &n);
  puts("Arrival time  Burst time");
  for(i=1; i<=n; i++){
	scanf("%d%d", &arrival[i], &burst[i]);
	ch[i] = 0;
	dburst[i] = burst[i];
	}


 for(i=1; i<=n; i++){
	 mn = 100000, ind = -1;
         for(j = 1; j<=n; j++){
		if(arrival[j]<mn && ch[j]==0)
			mn = arrival[j], ind = j;
		}
           
	if(ind!=-1) ch[ind] = 1, nxt[i] = ind;
	}
 tm = arrival[nxt[1]], num = n, next = 1;
 cnt = 0;
 while(num!=0){ 
	while(next<=n && tm==arrival[nxt[next]]) push(nxt[next++]);
        tm++;
	if(qback==qfront) continue;
	node = front();
        printf("(%d %d)\n", node, tm);
	cnt++;
        burst[node]--;
        if(burst[node]==0) {
		num--;
		cnt = 0;
		pop();
	        turn[node] = tm - arrival[node];
		wait[node] = turn[node] - dburst[node];	
		}
	if(cnt==7){
	cnt = 0;
	pop();
	while(next<=n && tm==arrival[nxt[next]]) push(nxt[next++]);
	push(node);
	}
	
	}
puts("");
      avgw = 0.0, avgt =0.0;
     for(i=1; i<=n; i++) avgw+=wait[i], avgt+=turn[i];
	avgw/=n, avgt/=n;
   for(i=1; i<=n; i++)
	printf("%d  %d %d %d\n", arrival[i], dburst[i], wait[i], turn[i]);
}
