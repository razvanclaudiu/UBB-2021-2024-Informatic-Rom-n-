sum1(N,R):-
	R is (N * (N+1))/2.

sum2(0,0).
sum2(N,R):-
	N1 is N-1,
	sum2(N1,R1),
	R is R1 + N.
