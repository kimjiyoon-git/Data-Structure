//ฦ๗ภฮลอ1 



#include<stdio.h>
#include<stdlib.h>


struct Example {
	int number;
	char name[10];
};

void main()
{
	struct Example *p;
	
	p=(struct Example*)malloc(2*sizeof(struct Example ));
	if(p==NULL){
		fprintf(stderr,"Can't allocate memory \n");
		exit(1);
	}
	
	p->number=1;
	strcpy(p->name,"PARK");
	
	(p+1)->number=2;
	strcpy((p+1)->name,"KIM");
	free(p);
}
