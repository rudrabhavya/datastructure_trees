#include<stdio.h>
int q[20],top=-1,front=-1,rear=-1,a[20][20],v[20],stack[20];
void bfs(int s,int n){
	int p,i;
	enqueue(s);
	v[s]=1;
	p=dequeue();
	if(p!=0)
	printf(" %d",p);
	while(p!=0){
		for(i=1;i<=n;i++)
			if((a[p][i]!=0)&&(v[i]==0)){
				enqueue(i);
				v[i]=1;
			}
		p=dequeue();
		if(p!=0)
			printf(" %d ",p);
	}
	for(i=1;i<=n;i++)
		if(v[i]==0)
			bfs(i,n);
}
void enqueue(int z){
	if(rear==19)
		printf("QUEUE FULL");
	else{
		if(rear==-1){
			q[++rear]=z;
			front++;
		}
	else
		q[++rear]=z;
	}
}
int dequeue(){
	int k;
	if((front>rear)||(front==-1))
		return(0);
	else{
		k=q[front++];
		return(k);
	}
}
void dfs(int s,int n){
	int i,k;
	push(s);
	v[s]=1;
	k=pop();
	if(k!=0)
		printf(" %d ",k);
	while(k!=0){
		for(i=1;i<=n;i++)
			if((a[k][i]!=0)&&(v[i]==0)){
				push(i);
				v[i]=1;
			}
		k=pop();
		if(k!=0)
			printf(" %d ",k);
	}
	for(i=1;i<=n;i++)
		if(v[i]==0)
			dfs(i,n);
}
void push(int z){
	if(top==19)
		printf("Stack overflow ");
	else
		stack[++top]=z;
}
int pop(){
	int k;
	if(top==-1)
		return(0);
	else{
		k=stack[top--];
		return(k);
	}
}
void main(){
	int n,i,s,ch,j,c=1;
	printf("Enter the number of vertices:");
	scanf("%d",&n);
	printf("Enter adjacency matrix:\n");
	for(i=1;i<=n;i++){
	for(j=1;j<=n;j++)
	scanf("%d",&a[i][j]);
	}
while (c==1){
	for(i=1;i<=n;i++)
		v[i]=0;
	printf("\nMENU");
	printf("\n1.BFS\n2.DFS\n3.exit");
	printf("\nEnter your choice");
	scanf("%d",&ch);
	printf("Enter source vertex:");
	scanf("%d",&s);
	switch(ch){
		case 1:bfs(s,n);
		break;
		case 2:dfs(s,n);
		break;
		case 3:exit(0);
		case 4:printf("Invalid choice");
	}
	printf("\nDo you want to continue:");
	scanf("%d",&c);
	}
}

