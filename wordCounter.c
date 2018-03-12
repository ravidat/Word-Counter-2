#include <stdio.h>


int countWords(int idx, char **argv){
	FILE *fp;
	if(idx == -1){ 
		fp = fopen("file.txt","r");
	}
	else{
		fp = fopen(argv[idx],"r");
	}
      int c;
 	  int ans =0;
  	  while((c = fgetc(fp)) != EOF){
	       if(c != ' ' && c !='\n' && c != '\t'){
		   ans++;
	  	   c = fgetc(fp);
	           while(c != ' ' && c !='\n' && c != '\t'){
	   	       		c = fgetc(fp);
	   	  		}
  	      }
      }
  	 printf("%d \n",ans);
	fclose(fp);
	 return 0;
}  

int countChars(int idx, char **argv){
	FILE *fp;
	if(idx == -1){ 
		fp = fopen("file.txt","r");
	}
	else{
		fp = fopen(argv[idx],"r");
	}
          int c;
 	  int ans =0;
  	  while( (c = fgetc(fp)) != EOF){
	       if(c != ' ' && c !='\n' && c != '\t'){
		   ans++;
  	      }
          }
  	 printf("%d \n",ans);
	fclose(fp);	
	return 0;
}

int longestWord(int idx, char **argv){
	FILE *fp;
	if(idx == -1){ 
		fp = fopen("file.txt","r");
	}
	else{
		fp = fopen(argv[idx],"r");
	}
          int c;
 	  int tmp = 0;
	  int ans = 0;
  	  while( (c = fgetc(fp)) != EOF){
	       if(c != ' ' && c !='\n' && c != '\t'){
		   tmp++;
	  	   c = fgetc(fp);
	           while(c != ' ' && c !='\n' && c != '\t'){
		       tmp++; 
	   	       c = fgetc(fp);
	   	  }
		   if(tmp>ans){
		    ans=tmp;
		   }
		tmp=0;
  	      }
          }
  	 printf("%d \n",ans);
	fclose(fp);	
	return 0;
}

int countLines(int idx, char **argv){
	FILE *fp;
	if(idx == -1){ 
		fp = fopen("file.txt","r");
	}
	else{
		fp = fopen(argv[idx],"r");
	}
      int c;
 	  int ans =0;
  	  while( (c = fgetc(fp)) != EOF){
	       if(c =='\n'){
		   ans++;
  	      }
      }
  	 printf("%d \n",ans);
	fclose(fp);	
	return 0;
}


int main(int argc, char **argv){
	int fileIdx=-1;
	for (int i=1 ; i<argc ; i++){
		if(strcmp(argv[i],"-i")==0){
			fileIdx = ++i;
			break;
		}
	}
		if(fileIdx == -1){
			FILE *fp;
			fp = fopen("file.txt" , "w+");
			int c;
			while((c = fgetc(stdin)) != EOF){
				fputc(c	,fp);
			}
			fclose(fp); 
		}
		if(argc == 1)
			countWords(fileIdx , argv);
		else{

		for(int i=1 ; i<argc ; i++){
		   if (strcmp(argv[i],"-w")==0){
			   countWords(fileIdx , argv);
		   }
		   else if ((strcmp(argv[i],"-c")==0)){
			   countChars(fileIdx , argv);
		   }
		   else if ((strcmp(argv[i],"-l"))==0){
			   longestWord(fileIdx , argv);
		   }  
		   else if ((strcmp(argv[i],"-n"))==0){
			   countLines(fileIdx , argv);
		   }  	   	
		   }
		}
    return 0; 
}

