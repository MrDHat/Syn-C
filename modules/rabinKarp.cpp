#include<stdio.h> 
#include<string>
#include<cmath>					//Do not forget to add -lm while compiling the code to enable cmath
#include "modules.h"
using namespace std ;

int rabinKarp(string T, string P){
	
	
	int n, m, d, p, q, h, t ;
	
	int i, s, j ;				//Iterators
	
	int flag = 0 ;				//Naive search flag, if = 0 then match else no match
	
	const char *text = T.c_str() ;
	const char *pattern = P.c_str() ;
	
	q = 13 ;
	d = 10 ;
	
	
	n = T.length();
	m = P.length();
	h = pow(d,m-1);
	h = h % q ;
	
	
	
	p = 0 ;
	t = 0 ;
	
	for(i = 1; i<=m ; i++){			//Preprocessing
		p = (d*p + pattern[i]) ;
		p = p % q ;
		t = d*t + text[i] ; 
		t = t % q ;
	}
	
	for(s = 0; s<=n-m ; s++){
		if(p == t){
			for(j = 1 ; j<=m ; j++){
			  if(pattern[i] != text[s+i]){
				flag = 1 ; 
				break ;
			  }
			}
			if(flag == 0){
				return s ;	//Match found with shift s
			}
			else
				flag = 0 ;	//Continue, match not found
		}
		
		if(s < n-m){
			t = (d*(t-text[s+1]*h) + text[s+m+1]) ;
			t = t % q ;
		}
	}
}
